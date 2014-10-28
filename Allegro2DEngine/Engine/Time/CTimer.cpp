/**************************************************************************************************
// file:	Engine\Time\CTimer.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the timer class
 **************************************************************************************************/
#include "CTimer.h"

A2DE_BEGIN

Timer::Timer() : ADTTime() {
    /* DO NOTHING. ALL INITIALIZATION IN BASE CLASS */
}
Timer::~Timer() {
    _startTime = -1;
    _endTime = -1;
    _deltaTime = -1.0;
    _isRunning = false;
}

void Timer::Start() {
    if(_isRunning) return;
    _isRunning = true;
    _startTime = clock();
}

void Timer::Stop() {
    if(!_isRunning) return;
    _isRunning = false;
    _endTime = clock();
    CalculateElapsedTime();
}
void Timer::Reset() {
    Stop();
    _isRunning = false;
    _startTime = 0;
    _endTime = 0;
    _deltaTime = 0;
}
void Timer::Restart() {
    Reset();
    Start();
}
void Timer::CalculateElapsedTime() {
    _endTime = clock();
    _deltaTime = difftime(_endTime, _startTime);
}

double Timer::GetElapsedTimeInSeconds() {
    CalculateElapsedTime();
    return ADTTime::GetElapsedTimeInSeconds();
}

double Timer::GetElapsedTimeInMilliseconds() {
    CalculateElapsedTime();
    return ADTTime::GetElapsedTimeInMilliseconds();
}

A2DE_END