#ifndef A2DE_CJOYSTICKINPUTHANDLER_H
#define A2DE_CJOYSTICKINPUTHANDLER_H

#include <functional>
#include <vector>

#include "../a2de_vals.h"
#include "CInputHandler.h"

#include <allegro5/joystick.h>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>A joystick input handler.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 * <seealso cref="T:InputHandler"/>
 **************************************************************************************************/
class JoystickInputHandler : public InputHandler {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    JoystickInputHandler();

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~JoystickInputHandler();

    /**************************************************************************************************
     * <summary>Handles the event described by ev.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="ev">[in,out] If non-null, the ev.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool HandleEvent(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Callback, called when the  joystick is moved.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="axis_callback">The axis callback.</param>
     **************************************************************************************************/
    void SetAxisCallback(const std::function<bool(ALLEGRO_EVENT*)> axis_callback);

    /**************************************************************************************************
     * <summary>Callback, called when a joystick button is pressed.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="buttondown_callback">The buttondown callback.</param>
     **************************************************************************************************/
    void SetButtonDownCallback(const std::function<bool(ALLEGRO_EVENT*)> buttondown_callback);

    /**************************************************************************************************
     * <summary>Callback, called when a joystick button is released.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="buttonup_callback">The buttonup callback.</param>
     **************************************************************************************************/
    void SetButtonUpCallback(const std::function<bool(ALLEGRO_EVENT*)> buttonup_callback);

    /**************************************************************************************************
     * <summary>Callback, called when a joystick configuration event is processed.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="configure_callback">The configure callback.</param>
     **************************************************************************************************/
    void SetConfigurationCallback(const std::function<bool(ALLEGRO_EVENT*)> configure_callback);

protected:
private:

    /**************************************************************************************************
     * <summary>The axis event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _axis_event_callback;

    /**************************************************************************************************
     * <summary>The buttondown event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _buttondown_event_callback;

    /**************************************************************************************************
     * <summary>The buttonup event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _buttonup_event_callback;

    /**************************************************************************************************
     * <summary>The configure event callback.</summary>
     **************************************************************************************************/
    std::function<bool(ALLEGRO_EVENT*)> _configure_event_callback;

};

A2DE_END

#endif // CJOYSTICKINPUTHANDLER_H
