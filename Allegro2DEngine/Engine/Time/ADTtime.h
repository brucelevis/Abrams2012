/**************************************************************************************************
// file:	Engine\Time\ADTtime.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the ad ttime class
 **************************************************************************************************/
#ifndef A2DE_ADTTIME_H
#define A2DE_ADTTIME_H

#include "../a2de_vals.h"
#include <ctime>

A2DE_BEGIN

class ADTTime {

public:

    /**************************************************************************************************
     * <summary>Gets the start time.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The start time.</returns>
     **************************************************************************************************/
    clock_t GetStartTime() const;

    /**************************************************************************************************
     * <summary>Gets the start time.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The start time.</returns>
     **************************************************************************************************/
    clock_t GetStartTime();

    /**************************************************************************************************
     * <summary>Gets the start time in seconds.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The start time in seconds.</returns>
     **************************************************************************************************/
    double GetStartTimeInSeconds() const;

    /**************************************************************************************************
     * <summary>Gets the start time in seconds.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The start time in seconds.</returns>
     **************************************************************************************************/
    double GetStartTimeInSeconds();

    /**************************************************************************************************
     * <summary>Gets the end time.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end time.</returns>
     **************************************************************************************************/
    clock_t GetEndTime() const;

    /**************************************************************************************************
     * <summary>Gets the end time.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end time.</returns>
     **************************************************************************************************/
    clock_t GetEndTime();

    /**************************************************************************************************
     * <summary>Gets the end time in seconds.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end time in seconds.</returns>
     **************************************************************************************************/
    double GetEndTimeInSeconds() const;

    /**************************************************************************************************
     * <summary>Gets the end time in seconds.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end time in seconds.</returns>
     **************************************************************************************************/
    double GetEndTimeInSeconds();

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

    /**************************************************************************************************
     * <summary>Calculates the elapsed time.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateElapsedTime()=0;

    /**************************************************************************************************
     * <summary>Query if this object is running.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>true if running, false if not.</returns>
     **************************************************************************************************/
    bool IsRunning() const;

    /**************************************************************************************************
     * <summary>Query if this object is running.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>true if running, false if not.</returns>
     **************************************************************************************************/
    bool IsRunning();

    /**************************************************************************************************
     * <summary>Starts this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void Start()=0;

    /**************************************************************************************************
     * <summary>Restarts this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void Restart()=0;

    /**************************************************************************************************
     * <summary>Stops this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void Stop()=0;

    /**************************************************************************************************
     * <summary>Resets this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void Reset()=0;

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    ADTTime();

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual ~ADTTime();
protected:

    /// <summary> true if is running </summary>
    bool _isRunning;
    /// <summary> The start time </summary>
    clock_t _startTime;
    /// <summary> The end time </summary>
    clock_t _endTime;
    /// <summary> Time of the delta </summary>
    double _deltaTime;

private:

};

A2DE_END

#endif