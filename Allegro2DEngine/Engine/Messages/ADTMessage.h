/**************************************************************************************************
// file:	Engine\Messages\ADTMessage.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the adt message class
 **************************************************************************************************/
#ifndef A2DE_ADTMESSAGE_H
#define A2DE_ADTMESSAGE_H

#include "../a2de_vals.h"
#include <ctime>
#include "../Time/CStopwatch.h"

A2DE_BEGIN

class Message {

public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="gameTime">[in,out] Time of the game.</param>
     **************************************************************************************************/
    Message(StopWatch& gameTime);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 12/22/2013.</remarks>
     **************************************************************************************************/
    virtual ~Message()=0;

    /**************************************************************************************************
     * <summary>Less-than comparison operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    bool operator<(const Message& rhs);

    /**************************************************************************************************
     * <summary>Less-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator<=(const Message& rhs);

    /**************************************************************************************************
     * <summary>Greater-than comparison operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than to the second.</returns>
     **************************************************************************************************/
    bool operator>(const Message& rhs);

    /**************************************************************************************************
     * <summary>Greater-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator>=(const Message& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Message& rhs);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     **************************************************************************************************/
    bool operator!=(const Message& rhs);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Message& operator=(const Message& rhs);

    /**************************************************************************************************
     * <summary>Gets the message index.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <returns>The message index.</returns>
     **************************************************************************************************/
    unsigned long GetMessageIndex() const;

    /**************************************************************************************************
     * <summary>Gets the message index.</summary>
     * <remarks>Casey Ugone, 9/1/2013.</remarks>
     * <returns>The message index.</returns>
     **************************************************************************************************/
    unsigned long GetMessageIndex();

    /**************************************************************************************************
     * <summary>Gets the creation time.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <returns>The creation time.</returns>
     **************************************************************************************************/
    double GetCreationTime() const;

    /**************************************************************************************************
     * <summary>Gets the creation time.</summary>
     * <remarks>Casey Ugone, 9/1/2013.</remarks>
     * <returns>The creation time.</returns>
     **************************************************************************************************/
    double GetCreationTime();

protected:
private:
    /// <summary> The current index </summary>
    static unsigned long _current_index;
    /// <summary> Zero-based index of the message </summary>
    unsigned long _message_index;
    /// <summary> Time of the creation </summary>
    double _creation_time;

};


A2DE_END

#endif