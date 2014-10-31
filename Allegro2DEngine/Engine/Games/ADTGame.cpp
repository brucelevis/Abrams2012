/**************************************************************************************************
// file:	Engine\Games\ADTGame.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the adt game class
 **************************************************************************************************/
#include "ADTGame.h"

#include "../a2de_exceptions.h"

#include <allegro5/display.h>
#include <allegro5/altime.h>
#include <allegro5/timer.h>
#include <allegro5/drawing.h>


#include "../Input/CInputHandler.h"
#include "../Input/CKeyboardInputHandler.h"
#include "../Input/CMouseInputHandler.h"
#include "../Input/CJoystickInputHandler.h"

#include "../Input/CMouse.h"

A2DE_BEGIN

Game::Game(a2de::GameWindow* window) : _FRAME_RATE(1.0 / 60.0), _MAX_FRAME_TIME(_FRAME_RATE * 2.0), _deltaTime(0.01), _gameTime(), _gameWindow(nullptr), _isQuitting(false), _input_handler(nullptr), _keyboard_input_handler(nullptr), _mouse_input_handler(nullptr), _joystick_input_handler(nullptr) {
    try {
        init(window);
    } catch(...) {
        throw;
    }
}

Game::Game(double frame_rate, double max_frame_time, a2de::GameWindow* window) : _FRAME_RATE(1.0 / frame_rate), _MAX_FRAME_TIME(max_frame_time), _deltaTime(0.01), _gameTime(), _gameWindow(nullptr), _isQuitting(false), _input_handler(nullptr), _keyboard_input_handler(nullptr), _mouse_input_handler(nullptr), _joystick_input_handler(nullptr) {
    try {
        init(window);
    } catch(...) {
        throw;
    }
}

Game::~Game() {
    deinit();
}

void Game::init(a2de::GameWindow* window) {
    try {
        if(window == nullptr) throw a2de::Exception("GameWindow must not be null.");
        _gameWindow = window;
        _gameWindow->ShowWindow();
        
        _keyboard_input_handler = new a2de::KeyboardInputHandler();

        a2de::Mouse* mouse = a2de::Mouse::CreateMouse(window->GetDisplay());
        _mouse_input_handler = new a2de::MouseInputHandler(mouse);
        mouse = nullptr;

        _joystick_input_handler = new a2de::JoystickInputHandler();

        _keyboard_input_handler->SetNext(_mouse_input_handler);
        _mouse_input_handler->SetNext(_joystick_input_handler);

        _input_handler = _keyboard_input_handler;

    } catch(...) {
        deinit();
        throw;
    }
}

void Game::deinit() {

    delete _joystick_input_handler;
    delete _keyboard_input_handler;
    delete _mouse_input_handler;

    _input_handler = nullptr;

    delete _gameWindow;
    _gameWindow = nullptr;
}

void Game::MainLoop() {


    ALLEGRO_EVENT_QUEUE* e = al_create_event_queue();
    al_register_event_source(e, al_get_keyboard_event_source());
    al_register_event_source(e, al_get_mouse_event_source());
    al_register_event_source(e, al_get_joystick_event_source());

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();

    double currentTime = al_get_time();
    double accumulator = _deltaTime;
    _gameTime.Start();
    while(!_isQuitting) {
        ALLEGRO_EVENT ev;
        while(al_peek_next_event(e, &ev)) {
            _input_handler->ProcessEvent(&ev);
            al_drop_next_event(e);
        }

        this->GetKeyboardInputHandler().Update();

        //Keyboard input callbacks
        this->GetKeyboardInputHandler().SetKeyDownCallback(std::bind(&a2de::KeyDown, this, &ev));
        this->GetKeyboardInputHandler().SetKeyCharCallback(std::bind(&a2de::KeyChar, this, &ev));
        this->GetKeyboardInputHandler().SetKeyUpCallback(std::bind(&a2de::KeyUp, this, &ev));

        //Mouse input callbacks
        this->GetMouseInputHandler().SetMouseMoveCallback(std::bind(&a2de::MouseMove, this, &ev));
        this->GetMouseInputHandler().SetMouseButtonDownCallback(std::bind(&a2de::MouseButtonDown, this, &ev));
        this->GetMouseInputHandler().SetMouseButtonUpCallback(std::bind(&a2de::MouseButtonUp, this, &ev));
        this->GetMouseInputHandler().SetMouseWarpCallback(std::bind(&a2de::MouseWarp, this, &ev));
        this->GetMouseInputHandler().SetMouseLeaveCallback(std::bind(&a2de::MouseLeave, this, &ev));
        this->GetMouseInputHandler().SetMouseEnterCallback(std::bind(&a2de::MouseEnter, this, &ev));

        //Joystick input callbacks
        this->GetJoystickInputHandler().SetAxisCallback(std::bind(&a2de::JoystickAxis, this, &ev));
        this->GetJoystickInputHandler().SetButtonDownCallback(std::bind(&a2de::JoystickButtonDown, this, &ev));
        this->GetJoystickInputHandler().SetButtonUpCallback(std::bind(&a2de::JoystickButtonUp, this, &ev));
        this->GetJoystickInputHandler().SetConfigurationCallback(std::bind(&a2de::JoystickConfiguration, this, &ev));


        double newTime = al_get_time();
        double frameTime = (newTime - currentTime);
        if(frameTime > _MAX_FRAME_TIME) frameTime = _MAX_FRAME_TIME;
        currentTime = newTime;
        accumulator += frameTime;
        while(accumulator >= _deltaTime) {
            this->Processing(_gameTime, _deltaTime);
            accumulator -= _deltaTime;
        }
        this->Render(_gameTime, _deltaTime);
    }
    _gameTime.Stop();

    al_unregister_event_source(e, al_get_keyboard_event_source());
    al_unregister_event_source(e, al_get_mouse_event_source());
    al_unregister_event_source(e, al_get_joystick_event_source());


    //_gameTime.Start();
    //double currentTime = al_get_time();
    //double accumulator = _deltaTime;
    //while(!_isQuitting) {
    //    double newTime = al_get_time();
    //    double frameTime = (newTime - currentTime);
    //    if(frameTime > _MAX_FRAME_TIME) frameTime = _MAX_FRAME_TIME;
    //    currentTime = newTime;
    //    accumulator += frameTime;
    //    while(accumulator >= _deltaTime) {
    //        this->Processing(_gameTime, _deltaTime);
    //        accumulator -= _deltaTime;
    //    }
    //    this->Render(_gameTime, _deltaTime);
    //}
    //_gameTime.Stop();
}

void Game::Run(int argc, char** argv) {
    if(this->Initialize(argc, argv)) MainLoop();
    this->CleanUp();
}

bool Game::Initialize(int /*argc*/, char** /*argv*/) {
    return true;
}

void Game::Processing(a2de::StopWatch& /*gameTime*/, double /*deltaTime*/) {

}

void Game::Render(a2de::StopWatch& /*gameTime*/, double /*deltaTime*/) {

}

void Game::CleanUp() {

}

a2de::GameWindow* Game::GetWindow() const {
    return _gameWindow;
}

a2de::GameWindow* Game::GetWindow() {
    return static_cast<const Game&>(*this).GetWindow();
}

bool Game::IsQuitting() const {
    return _isQuitting;
}

bool Game::IsQuitting() {
    return static_cast<const Game&>(*this).IsQuitting();
}

void Game::Quit() {
    _isQuitting = true;
}

const a2de::StopWatch& Game::GetGameTime() const {
    return _gameTime;
}

a2de::StopWatch& Game::GetGameTime() {
    return const_cast<a2de::StopWatch&>(static_cast<const Game&>(*this).GetGameTime());
}

const a2de::KeyboardInputHandler& Game::GetKeyboardInputHandler() const {
    return *_keyboard_input_handler;
}

a2de::KeyboardInputHandler& Game::GetKeyboardInputHandler() {
    return const_cast<KeyboardInputHandler&>(static_cast<const Game&>(*this).GetKeyboardInputHandler());
}

const a2de::JoystickInputHandler& Game::GetJoystickInputHandler() const {
    return *_joystick_input_handler;
}

a2de::JoystickInputHandler& Game::GetJoystickInputHandler() {
    return const_cast<JoystickInputHandler&>(static_cast<const Game&>(*this).GetJoystickInputHandler());
}

const a2de::MouseInputHandler& Game::GetMouseInputHandler() const {
    return *_mouse_input_handler;
}

a2de::MouseInputHandler& Game::GetMouseInputHandler() {
    return const_cast<MouseInputHandler&>(static_cast<const Game&>(*this).GetMouseInputHandler());
}

bool Game::KeyDown(ALLEGRO_EVENT* ev) {
    if(ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        this->Quit();
        return true;
    }
    return false;
}

bool Game::KeyUp(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::KeyChar(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::MouseMove(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::MouseButtonDown(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::MouseButtonUp(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::MouseWarp(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::MouseLeave(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::MouseEnter(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::JoystickAxis(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::JoystickButtonDown(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::JoystickButtonUp(ALLEGRO_EVENT* /*ev*/) {
    return false;
}

bool Game::JoystickConfiguration(ALLEGRO_EVENT* /*ev*/) {
    al_reconfigure_joysticks();
    return true;
}


bool KeyDown(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->KeyDown(ev);
}

bool KeyUp(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->KeyUp(ev);
}

bool KeyChar(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->KeyChar(ev);
}

bool MouseMove(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->MouseMove(ev);
}

bool MouseButtonDown(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->MouseButtonDown(ev);
}

bool MouseButtonUp(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->MouseButtonUp(ev);
}

bool MouseWarp(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->MouseWarp(ev);
}

bool MouseLeave(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->MouseLeave(ev);
}

bool MouseEnter(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->MouseEnter(ev);
}

bool JoystickAxis(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->JoystickAxis(ev);
}

bool JoystickButtonDown(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->JoystickButtonDown(ev);
}

bool JoystickButtonUp(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->JoystickButtonUp(ev);
}

bool JoystickConfiguration(Game* game_instance, ALLEGRO_EVENT* ev) {
    if(game_instance == nullptr) return false;
    return game_instance->JoystickConfiguration(ev);
}


A2DE_END
