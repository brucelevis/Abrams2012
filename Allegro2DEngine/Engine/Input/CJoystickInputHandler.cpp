#include "CJoystickInputHandler.h"

#include <vector>
#include <algorithm>

A2DE_BEGIN


JoystickInputHandler::JoystickInputHandler() :
InputHandler(),
_axis_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_buttondown_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_buttonup_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_configure_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; })
{
    /* DO NOTHING */
}

JoystickInputHandler::~JoystickInputHandler() { /* DO NOTHING */ }


bool JoystickInputHandler::HandleEvent(ALLEGRO_EVENT* ev) {
    if(ev == nullptr) return false;

    switch(ev->type) {
    case ALLEGRO_EVENT_JOYSTICK_AXIS:
        return _axis_event_callback(ev);
    case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
        return _buttondown_event_callback(ev);
    case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
        return _buttonup_event_callback(ev);
    case ALLEGRO_EVENT_JOYSTICK_CONFIGURATION:
        return _configure_event_callback(ev);
    default:
        return false;
    }
}

void JoystickInputHandler::SetAxisCallback(const std::function<bool(ALLEGRO_EVENT*)> axis_callback) {
    _axis_event_callback = axis_callback;
}

void JoystickInputHandler::SetButtonDownCallback(const std::function<bool(ALLEGRO_EVENT*)> buttondown_callback) {
    _buttondown_event_callback = buttondown_callback;
}

void JoystickInputHandler::SetButtonUpCallback(const std::function<bool(ALLEGRO_EVENT*)> buttonup_callback) {
    _buttonup_event_callback = buttonup_callback;
}

void JoystickInputHandler::SetConfigurationCallback(const std::function<bool(ALLEGRO_EVENT*)> configure_callback) {
    _configure_event_callback = configure_callback;
}


A2DE_END