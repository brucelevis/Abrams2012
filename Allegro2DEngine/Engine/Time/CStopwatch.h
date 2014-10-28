/**************************************************************************************************
// file:	Engine\Time\CStopwatch.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the stopwatch class
 **************************************************************************************************/
#ifndef A2DE_CSTOPWATCH_H
#define A2DE_CSTOPWATCH_H

#include "../a2de_vals.h"
#include "ADTtime.h"

A2DE_BEGIN

class StopWatch : public ADTTime {

public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    StopWatch();

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual ~StopWatch();

    /**************************************************************************************************
     * <summary>Starts this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    void Start();

    /**************************************************************************************************
     * <summary>Restarts this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    void Restart();

    /**************************************************************************************************
     * <summary>Stops this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    void Stop();

    /**************************************************************************************************
     * <summary>Resets this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    void Reset();

    /**************************************************************************************************
     * <summary>Calculates the elapsed time.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateElapsedTime();

    /**************************************************************************************************
     * <summary>Gets the elapsed time in seconds.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The elapsed time in seconds.</returns>
     **************************************************************************************************/
    virtual double GetElapsedTimeInSeconds();

    /**************************************************************************************************
     * <summary>Gets the elapsed time in milliseconds.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The elapsed time in milliseconds.</returns>
     **************************************************************************************************/
    virtual double GetElapsedTimeInMilliseconds();

protected:

private:

};

A2DE_END

#endif