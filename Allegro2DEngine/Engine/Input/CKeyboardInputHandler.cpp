#include "CKeyboardInputHandler.h"

A2DE_BEGIN

bool a2de::KeyboardInputHandler::HandleEvent(ALLEGRO_EVENT* ev) {
    if(ev == nullptr) return false;

    switch(ev->type) {
    case ALLEGRO_EVENT_KEY_DOWN:
        return _keydown_event_callback(ev);
    case ALLEGRO_EVENT_KEY_CHAR:
        return _keychar_event_callback(ev);
    case ALLEGRO_EVENT_KEY_UP:
        return _keyup_event_callback(ev);
    default:
        return false;
    }
}

a2de::KeyboardInputHandler::KeyboardInputHandler() :
InputHandler(),
_keychar_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_keyup_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; }),
_keydown_event_callback([](ALLEGRO_EVENT* /*ev*/) { return false; })
{ /* DO NOTHING */ }

a2de::KeyboardInputHandler::~KeyboardInputHandler() { /* DO NOTHING */ }


void KeyboardInputHandler::SetKeyCharCallback(const std::function<bool(ALLEGRO_EVENT*)>& keychar_callback) {
    _keychar_event_callback = keychar_callback;
}

void KeyboardInputHandler::SetKeyDownCallback(const std::function<bool(ALLEGRO_EVENT*)>& keydown_callback) {
    _keydown_event_callback = keydown_callback;
}

void KeyboardInputHandler::SetKeyUpCallback(const std::function<bool(ALLEGRO_EVENT*)>& keyup_callback) {
    _keyup_event_callback = keyup_callback;
}

bool KeyboardInputHandler::KeyDown(int keycode) {
    return !_previous_keys[keycode] && _current_keys[keycode];
}

bool KeyboardInputHandler::KeyPress(int keycode) {
    return _previous_keys[keycode] && _current_keys[keycode];
}

bool KeyboardInputHandler::KeyUp(int keycode) {
    return _previous_keys[keycode] && !_current_keys[keycode];
}

void KeyboardInputHandler::Update() {
    ALLEGRO_KEYBOARD_STATE state;
    al_get_keyboard_state(&state);

    _previous_keys = _current_keys;

    for(std::size_t i = 0; i < ALLEGRO_KEY_MAX; ++i) {
        _current_keys[i] = al_key_down(&state, i);
    }
}

A2DE_END