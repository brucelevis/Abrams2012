#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "../a2de_vals.h"

#include <allegro5/events.h>


A2DE_BEGIN

/**************************************************************************************************
 * <summary>An input handler.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
class InputHandler {
public:
    InputHandler();
    virtual ~InputHandler();

    /**************************************************************************************************
     * <summary>Send an event down the chain.</summary>
     * <remarks>Casey Ugone, 10/18/2014.</remarks>
     * <param name="ev">[in,out] The event.</param>
     **************************************************************************************************/
    virtual void ProcessEvent(ALLEGRO_EVENT* ev);

    /**************************************************************************************************
     * <summary>Sets the next handler in the chain.</summary>
     * <remarks>Casey Ugone, 10/18/2014.</remarks>
     * <remarks>Handler does not own the pointer to the next handler.</remarks>
     * <param name="next_handler">The next handler. Setting it to nullptr ends the chain.</param>
     **************************************************************************************************/
    virtual void SetNext(InputHandler* next_handler);

    /**************************************************************************************************
     * <summary>Handles the event described by ev.</summary>
     * <remarks>Casey Ugone, 10/18/2014.</remarks>
     * <param name="ev">The event to handle.</param>
     **************************************************************************************************/
    virtual bool HandleEvent(ALLEGRO_EVENT* ev)=0;

protected:

    /**************************************************************************************************
     * <summary>The next handler in the chain.</summary>
     **************************************************************************************************/
    InputHandler* _next_handler;

private:

};

A2DE_END

#endif // INPUTHANDLER_H
