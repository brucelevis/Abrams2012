/**************************************************************************************************
// file:	Engine\Time\CStopwatch.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the stopwatch class
 **************************************************************************************************/
#include "CStopwatch.h"

A2DE_BEGIN

StopWatch::StopWatch() : ADTTime() {
    /* DO NOTHING. ALL INITIALIZATION HAPPENS IN BASE CLASS */
}
StopWatch::~StopWatch() {
    _startTime = -1;
    _endTime = -1;
    _deltaTime = -1.0;
    _isRunning = false;
}

void StopWatch::Start() {
    if(_isRunning == true) return;
    _startTime = clock();
    _isRunning = true;
}
void StopWatch::Stop() {
    if(_isRunning == false) return;
    _isRunning = false;
    CalculateElapsedTime();
}
void StopWatch::Restart() {
    Reset();
    Start();
}
void StopWatch::Reset() {
    Stop();
    _startTime = 0;
    _endTime = 0;
    _deltaTime = 0.0;
}
void StopWatch::CalculateElapsedTime() {
    _endTime = clock();
    _deltaTime = difftime(_startTime, _endTime);
}

double StopWatch::GetElapsedTimeInSeconds() {
    CalculateElapsedTime();
    return -ADTTime::GetElapsedTimeInSeconds();
}
double StopWatch::GetElapsedTimeInMilliseconds() {
    CalculateElapsedTime();
    return -ADTTime::GetElapsedTimeInMilliseconds();
}

A2DE_END