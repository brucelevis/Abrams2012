#include "CInputHandler.h"

A2DE_BEGIN


InputHandler::InputHandler() : _next_handler(nullptr) { /* DO NOTHING */ }

InputHandler::~InputHandler() { /* DO NOTHING */ }

void InputHandler::ProcessEvent(ALLEGRO_EVENT* ev) {
    if(ev == nullptr) return;

    if(this->HandleEvent(ev)) return;
    
    if(_next_handler) _next_handler->ProcessEvent(ev);
}

void InputHandler::SetNext(InputHandler* next_handler) {
    _next_handler = next_handler;
}


A2DE_END