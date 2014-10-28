/**************************************************************************************************
// file:	Engine\Time\ADTtime.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the ad ttime class
 **************************************************************************************************/
#include "ADTtime.h"

A2DE_BEGIN

clock_t ADTTime::GetStartTime() const {
    return _startTime;
}
clock_t ADTTime::GetStartTime() {
    return static_cast<const ADTTime&>(*this).GetStartTime();
}

double ADTTime::GetStartTimeInSeconds() const {
    return static_cast<double>((_startTime / CLOCKS_PER_SEC));
}
double ADTTime::GetStartTimeInSeconds() {
    return static_cast<const ADTTime&>(*this).GetStartTimeInSeconds();
}

clock_t ADTTime::GetEndTime() const {
    return _endTime;
}
clock_t ADTTime::GetEndTime() {
    return static_cast<const ADTTime&>(*this).GetEndTime();
}

double ADTTime::GetEndTimeInSeconds() const {
    return static_cast<double>((_endTime / CLOCKS_PER_SEC));
}
double ADTTime::GetEndTimeInSeconds() {
    return static_cast<const ADTTime&>(*this).GetEndTimeInSeconds();
}

double ADTTime::GetElapsedTimeInSeconds() {
    return _deltaTime / CLOCKS_PER_SEC;
}
double ADTTime::GetElapsedTimeInMilliseconds() {
    return _deltaTime;
}

bool ADTTime::IsRunning() const {
    return _isRunning;
}
bool ADTTime::IsRunning() {
    return static_cast<const ADTTime&>(*this).IsRunning();
}

ADTTime::ADTTime() : _isRunning(false), _startTime(-1), _endTime(-1), _deltaTime(-1.0) { }

ADTTime::~ADTTime() {
    _isRunning = false;
    _startTime = -1;
    _endTime = -1;
    _deltaTime = -1.0;
}

A2DE_END