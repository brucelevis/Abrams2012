/**************************************************************************************************
// file:	Engine\Games\ADTGame.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the Game abstract data type.
 **************************************************************************************************/
#ifndef A2DE_ADTGAME_H
#define A2DE_ADTGAME_H

#include "../a2de_vals.h"
#include "../GFX/CGameWindow.h"
#include "../Time/CStopwatch.h"
#include <allegro5/events.h>


A2DE_BEGIN

class InputHandler;
class KeyboardInputHandler;
class MouseInputHandler;
class JoystickInputHandler;

class Game {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <param name="window">The window to attach to this game. !The game will take ownership of the pointer!</param>
     **************************************************************************************************/
    Game(a2de::GameWindow* window);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <param name="frame_rate">    The number of frames per second in frames.</param>
     * <param name="max_frame_time">The maximum allowed time between frames in seconds.</param>
     * <param name="window">The window to attach to this game. !The game will take ownership of the pointer!</param>
     **************************************************************************************************/
    Game(double frame_rate, double max_frame_time, a2de::GameWindow* window);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     **************************************************************************************************/
    virtual ~Game();

    /**************************************************************************************************
     * <summary>Runs the game.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <param name="argc">The argc parameter from main.</param>
     * <param name="argv">The argv parameter from main</param>
     **************************************************************************************************/
    void Run(int argc, char** argv);

    /**************************************************************************************************
     * <summary>Initialization phase method. A method to set up any variables, etc. before the main loop starts.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <param name="argc">The argc parameter from main.</param>
     * <param name="argv">The argv parameter from main</param>
     * <returns>true if it successfully initializes, false if it does not.</returns>
     **************************************************************************************************/
    virtual bool Initialize(int argc, char** argv)=0;

    /**************************************************************************************************
     * <summary>Processing phase method. This method is called as many times as needed per frame to keep the frame rate as close to the defined frame rate as
     * possible.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <param name="gameTime"> The elapsed time of the game.</param>
     * <param name="deltaTime">The time between frames in seconds.</param>
     **************************************************************************************************/
    virtual void Processing(a2de::StopWatch& gameTime, double deltaTime)=0;

    /**************************************************************************************************
     * <summary>Rendering phase method. This method is called once per frame.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <param name="gameTime"> The elapsed time of the game.</param>
     * <param name="deltaTime">The time between frames in seconds.</param>
     **************************************************************************************************/
    virtual void Render(a2de::StopWatch& gameTime, double deltaTime)=0;

    /**************************************************************************************************
     * <summary>Clean up phase method. This method is called after the game loop to free up any memory. The user is responsible for deleting any
     * heap-allocated variables from Initialize here.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     **************************************************************************************************/
    virtual void CleanUp()=0;

    /**************************************************************************************************
     * <summary>Key Down event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     * <remarks>This method defaults to handling KEY_ESCAPE events as quitting the game.</remarks>
     **************************************************************************************************/
    virtual bool KeyDown(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Key Up event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool KeyUp(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Key Char event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool KeyChar(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Mouse Axis event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool MouseMove(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Mouse Button Down event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool MouseButtonDown(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Mouse Button Up event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool MouseButtonUp(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Mouse Warp event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool MouseWarp(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Mouse Leave Display event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool MouseLeave(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Mouse Enter Display event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool MouseEnter(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Joystick Axis event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool JoystickAxis(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Joystick Button Down event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool JoystickButtonDown(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Joystick Button Up event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">The event to process.</param>
     * <returns>true if the event was handled, false if it was not.</returns>
     **************************************************************************************************/
    virtual bool JoystickButtonUp(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Joystick Configuration event handler.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">[in,out] If non-null, the ev.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     * <remarks>This method defaults to calling al_reconfigure_joysticks</remarks>
     **************************************************************************************************/
    virtual bool JoystickConfiguration(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Gets the game window.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>null if it fails, else the window.</returns>
     **************************************************************************************************/
    a2de::GameWindow* GetWindow() const;

    /**************************************************************************************************
     * <summary>Gets the game window.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>null if it fails, else the window.</returns>
     **************************************************************************************************/
    a2de::GameWindow* GetWindow();

    /**************************************************************************************************
     * <summary>Quits the game.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     **************************************************************************************************/
    void Quit();

    /**************************************************************************************************
     * <summary>Query if the game is quitting.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>true if quitting, false if not.</returns>
     **************************************************************************************************/
    bool IsQuitting() const;

    /**************************************************************************************************
     * <summary>Query if the game is quitting.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>true if quitting, false if not.</returns>
     **************************************************************************************************/
    bool IsQuitting();

    /**************************************************************************************************
     * <summary>Gets the elapsed time the game window has been open.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>The game time.</returns>
     **************************************************************************************************/
    const a2de::StopWatch& GetGameTime() const;

    /**************************************************************************************************
     * <summary>Gets the elapsed time the game window has been open.</summary>
     * <remarks>Casey Ugone, 1/3/2013.</remarks>
     * <returns>The game time.</returns>
     **************************************************************************************************/
    a2de::StopWatch& GetGameTime();

    /**************************************************************************************************
     * <summary>Gets the KeyboardInputHandler object</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The keyboard input handler.</returns>
     **************************************************************************************************/
    const a2de::KeyboardInputHandler& GetKeyboardInputHandler() const;

    /**************************************************************************************************
     * <summary>Gets the KeyboardInputHandler object</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The keyboard input handler.</returns>
     **************************************************************************************************/
    a2de::KeyboardInputHandler& GetKeyboardInputHandler();

    /**************************************************************************************************
     * <summary>Gets the MouseInputHandler object</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The mouse input handler.</returns>
     **************************************************************************************************/
    const a2de::MouseInputHandler& GetMouseInputHandler() const;

    /**************************************************************************************************
     * <summary>Gets the MouseInputHandler object</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The mouse input handler.</returns>
     **************************************************************************************************/
    a2de::MouseInputHandler& GetMouseInputHandler();

    /**************************************************************************************************
     * <summary>Gets the JoystickInputHandler object</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The joystick input handler.</returns>
     **************************************************************************************************/
    const a2de::JoystickInputHandler& GetJoystickInputHandler() const;

    /**************************************************************************************************
     * <summary>Gets the JoystickInputHandler object</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The joystick input handler.</returns>
     **************************************************************************************************/
    a2de::JoystickInputHandler& GetJoystickInputHandler();

protected:

private:

    /**************************************************************************************************
     * <summary>Main loop.</summary>
     * <remarks>Casey Ugone, 11/23/2013.</remarks>
     **************************************************************************************************/
    void MainLoop();

    /**************************************************************************************************
     * <summary>Initialises the gamewindow for use.</summary>
     * <remarks>Casey Ugone, 11/23/2013.</remarks>
     * <param name="window">[in,out] If non-null, the window.</param>
     **************************************************************************************************/
    void init(a2de::GameWindow* window);

    /**************************************************************************************************
     * <summary>Uninitialises the gamewindow.</summary>
     * <remarks>Casey Ugone, 11/23/2013.</remarks>
     **************************************************************************************************/
    void deinit();

    /// <summary> The time between frames in seconds.</summary>
    double _FRAME_RATE;
    /// <summary> Maximum allowed time between frames </summary>
    double _MAX_FRAME_TIME;
    /// <summary> Time since the last frame.</summary>
    double _deltaTime;
    /// <summary> Elapsed game time</summary>
    a2de::StopWatch _gameTime;
    /// <summary> The game window </summary>
    a2de::GameWindow* _gameWindow;
    /// <summary> true if is quitting </summary>
    bool _isQuitting;

    ///<summary>The input handler chain head.</summary>
    a2de::InputHandler* _input_handler;

    ///<summary>The keyboard input handler.</summary>
    a2de::KeyboardInputHandler* _keyboard_input_handler;

    ///<summary>The mouse input handler.</summary>
    a2de::MouseInputHandler* _mouse_input_handler;

    ///<summary>The joystick input handler.</summary>
    a2de::JoystickInputHandler* _joystick_input_handler;

};

/**************************************************************************************************
 * <summary>The function bound to key down event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool KeyDown(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to key up event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool KeyUp(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to key char event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool KeyChar(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to mouse axis event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool MouseMove(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to mouse button down event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool MouseButtonDown(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to mouse button up event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool MouseButtonUp(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to mouse warped event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool MouseWarp(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to mouse leave display event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool MouseLeave(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to mouse enter display event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool MouseEnter(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to joystick axis event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool JoystickAxis(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to joystick button down event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool JoystickButtonDown(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to joystick button up event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool JoystickButtonUp(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

/**************************************************************************************************
 * <summary>The function bound to joystick configuration event callbacks.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
bool JoystickConfiguration(a2de::Game* game_instance, ALLEGRO_EVENT* ev);

A2DE_END

#endif