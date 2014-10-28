/**************************************************************************************************
// file:	Engine\Input\CMouseInputHandler.h
//
// summary:	Declares the mouse input handler class
 **************************************************************************************************/
#ifndef A2DE_MOUSEINPUTHANDLER_H
#define A2DE_MOUSEINPUTHANDLER_H

#include <functional>

#include "../a2de_vals.h"
#include "CInputHandler.h"

#include <allegro5/mouse.h>
#include <allegro5/mouse_cursor.h>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>A mouse.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 * <seealso cref="T:InputHandler"/>
 **************************************************************************************************/
class Mouse;

/**************************************************************************************************
 * <summary>A mouse input handler.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 * <seealso cref="T:InputHandler"/>
 **************************************************************************************************/
class MouseInputHandler : public InputHandler {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="mouse">[in,out] If non-null, the mouse.</param>
     **************************************************************************************************/
    MouseInputHandler(Mouse* mouse);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~MouseInputHandler();

    /**************************************************************************************************
     * <summary>Handles the event described by ev.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">[in,out] If non-null, the ev.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool HandleEvent(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Callback, called when the a mouse is moved.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="move_event_callback">The move event callback.</param>
     **************************************************************************************************/
    void SetMouseMoveCallback(const std::function<bool(ALLEGRO_EVENT*)> move_event_callback);

    /**************************************************************************************************
     * <summary>Callback, called when a mouse button is pressed.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="buttondown_event_callback">The buttondown event callback.</param>
     **************************************************************************************************/
    void SetMouseButtonDownCallback(const std::function<bool(ALLEGRO_EVENT*)> buttondown_event_callback);

    /**************************************************************************************************
     * <summary>Callback, called when a mouse button is released.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="buttonup_event_callback">The buttonup event callback.</param>
     **************************************************************************************************/
    void SetMouseButtonUpCallback(const std::function<bool(ALLEGRO_EVENT*)> buttonup_event_callback);

    /**************************************************************************************************
     * <summary>Callback, called when the mouse is warped.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="warp_event_callback">The warp event callback.</param>
     **************************************************************************************************/
    void SetMouseWarpCallback(const std::function<bool(ALLEGRO_EVENT*)> warp_event_callback);

    /**************************************************************************************************
     * <summary>Callback, called when the mouse leaves the display.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="leavedisplay_event_callback">The leavedisplay event callback.</param>
     **************************************************************************************************/
    void SetMouseLeaveCallback(const std::function<bool(ALLEGRO_EVENT*)> leavedisplay_event_callback);

    /**************************************************************************************************
     * <summary>Callback, called when the mouse enters the display.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="enterdisplay_event_callback">The enterdisplay event callback.</param>
     **************************************************************************************************/
    void SetMouseEnterCallback(const std::function<bool(ALLEGRO_EVENT*)> enterdisplay_event_callback);

    /**************************************************************************************************
     * <summary>Gets the mouse.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the mouse.</returns>
     **************************************************************************************************/
    const Mouse* GetMouse() const;

    /**************************************************************************************************
     * <summary>Gets the mouse.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the mouse.</returns>
     **************************************************************************************************/
    Mouse* GetMouse();

protected:
private:

    /**************************************************************************************************
     * <summary>The buttondown event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _buttondown_event_callback;

    /**************************************************************************************************
     * <summary>The buttonup event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _buttonup_event_callback;

    /**************************************************************************************************
     * <summary>The move event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _move_event_callback;

    /**************************************************************************************************
     * <summary>The warp event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _warp_event_callback;

    /**************************************************************************************************
     * <summary>The enterdisplay event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _enterdisplay_event_callback;

    /**************************************************************************************************
     * <summary>The leavedisplay event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _leavedisplay_event_callback;

    /**************************************************************************************************
     * <summary>The mouse.</summary>
     **************************************************************************************************/
    a2de::Mouse* _mouse;

};

A2DE_END

#endif // KEYBOARDINPUTHANDLER_H