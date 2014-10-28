#include "CMouseInputHandler.h"

#include "CMouse.h"
#include "../Math/CVector4D.h"

A2DE_BEGIN
    
MouseInputHandler::MouseInputHandler(Mouse* mouse) :
InputHandler(),
_move_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_buttonup_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_buttondown_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_warp_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_leavedisplay_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_enterdisplay_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_mouse(mouse)
{
    /* DO NOTHING */
}

MouseInputHandler::~MouseInputHandler() {
    delete _mouse;
}

bool MouseInputHandler::HandleEvent(ALLEGRO_EVENT* ev) {
    if(ev == nullptr) return false;

    //Mouse only warps when *user* calls SetPosition.
    _mouse->_mickeys = a2de::Vector4D(ev->mouse.dx, ev->mouse.dy, ev->mouse.dz, ev->mouse.dw);
    _mouse->_position = a2de::Vector4D(ev->mouse.x, ev->mouse.y, ev->mouse.z, ev->mouse.w);
    _mouse->Update();

    switch(ev->type) {
    case ALLEGRO_EVENT_MOUSE_AXES:
        return _move_event_callback(ev);
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
        return _buttondown_event_callback(ev);
    case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
        return _buttonup_event_callback(ev);
    case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
        return _enterdisplay_event_callback(ev);
    case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
        return _leavedisplay_event_callback(ev);
    case ALLEGRO_EVENT_MOUSE_WARPED:
        return _warp_event_callback(ev);
    default:
        return false;
    }

}

void MouseInputHandler::SetMouseMoveCallback(const std::function<bool(ALLEGRO_EVENT*)> move_event_callback) {
    _move_event_callback = move_event_callback;
}

void MouseInputHandler::SetMouseButtonDownCallback(const std::function<bool(ALLEGRO_EVENT*)> buttondown_event_callback) {
    _buttondown_event_callback = buttondown_event_callback;
}

void MouseInputHandler::SetMouseButtonUpCallback(const std::function<bool(ALLEGRO_EVENT*)> buttonup_event_callback) {
    _buttonup_event_callback = buttonup_event_callback;
}

void MouseInputHandler::SetMouseWarpCallback(const std::function<bool(ALLEGRO_EVENT*)> warp_event_callback) {
    _warp_event_callback = warp_event_callback;
}

void MouseInputHandler::SetMouseLeaveCallback(const std::function<bool(ALLEGRO_EVENT*)> leavedisplay_event_callback) {
    _leavedisplay_event_callback = leavedisplay_event_callback;
}

void MouseInputHandler::SetMouseEnterCallback(const std::function<bool(ALLEGRO_EVENT*)> enterdisplay_event_callback) {
    _enterdisplay_event_callback = enterdisplay_event_callback;
}

const Mouse* MouseInputHandler::GetMouse() const {
    return _mouse;
}

Mouse* MouseInputHandler::GetMouse() {
    return const_cast<Mouse*>(static_cast<const MouseInputHandler&>(*this).GetMouse());
}

A2DE_END