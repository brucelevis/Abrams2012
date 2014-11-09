#ifndef A2DE_KEYBOARDINPUTHANDLER_H
#define A2DE_KEYBOARDINPUTHANDLER_H

#include <bitset>
#include <functional>

#include "../a2de_vals.h"
#include "CInputHandler.h"

#include <allegro5/keyboard.h>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>A keyboard input handler.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 * <seealso cref="T:InputHandler"/>
 **************************************************************************************************/
class KeyboardInputHandler : public InputHandler {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    KeyboardInputHandler();

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~KeyboardInputHandler();

    /**************************************************************************************************
     * <summary>Handles the event described by ev.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">[in,out] If non-null, the ev.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool HandleEvent(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Callback, called when a key char event is handled.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="keychar_callback">The keychar callback.</param>
     **************************************************************************************************/
    void SetKeyCharCallback(const std::function<bool(ALLEGRO_EVENT*)>& keychar_callback);

    /**************************************************************************************************
     * <summary>Callback, called when a key is pressed.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="keydown_callback">The keydown callback.</param>
     **************************************************************************************************/
    void SetKeyDownCallback(const std::function<bool(ALLEGRO_EVENT*)>& keydown_callback);

    /**************************************************************************************************
     * <summary>Callback, called when a key is released.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="keyup_callback">The keyup callback.</param>
     **************************************************************************************************/
    void SetKeyUpCallback(const std::function<bool(ALLEGRO_EVENT*)>& keyup_callback);

    /**************************************************************************************************
     * <summary>Queries whether or not the key has just been pressed.</summary>
     * <remarks>Casey Ugone, 10/31/2014.</remarks>
     * <param name="keycode">The keycode.</param>
     * <returns>true if it is, false if it is not.</returns>
     **************************************************************************************************/
    bool KeyDown(int keycode);

    /**************************************************************************************************
    * <summary>Queries whether or not the key is held down.</summary>
    * <remarks>Casey Ugone, 10/31/2014.</remarks>
    * <param name="keycode">The keycode.</param>
    * <returns>true if it is, false if it is not.</returns>
     **************************************************************************************************/
    bool KeyPress(int keycode);

    /**************************************************************************************************
    * <summary>Queries whether or not the key has just been released.</summary>
    * <remarks>Casey Ugone, 10/31/2014.</remarks>
    * <param name="keycode">The keycode.</param>
    * <returns>true if it is, false if it is not.</returns>
     **************************************************************************************************/
    bool KeyUp(int keycode);

    /**************************************************************************************************
     * <summary>Updates the keyboard state.</summary>
     * <remarks>Casey Ugone, 11/3/2014.</remarks>
     **************************************************************************************************/
    void Update();

protected:
private:

    /**************************************************************************************************
     * <summary>The keychar event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _keychar_event_callback;

    /**************************************************************************************************
     * <summary>The keydown event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _keydown_event_callback;

    /**************************************************************************************************
     * <summary>The keyup event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _keyup_event_callback;

    std::bitset<ALLEGRO_KEY_MAX> _previous_keys;
    std::bitset<ALLEGRO_KEY_MAX> _current_keys;

};

A2DE_END

#endif // KEYBOARDINPUTHANDLER_H