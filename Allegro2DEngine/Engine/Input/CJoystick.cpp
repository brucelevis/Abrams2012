/**************************************************************************************************
// file:	Engine\Input\CJoystick.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the joystick class
 **************************************************************************************************/
#include "CJoystick.h"
//
//#include "../a2de_exceptions.h"
//
//A2DE_BEGIN
//
//int Joystick::_totaljoysticks = 0;
//int Joystick::_numjoysticks = 0;
//int Joystick::_curjoystick = 0;
//
//Joystick::Joystick() {
//	_totaljoysticks = num_joysticks;
//	_joyNumber = _curjoystick;
//	_numButtons = joy[_joyNumber].num_buttons;
//	_numSticks = joy[_joyNumber].num_sticks;
//
//    for(int i = 0; i < _numButtons; ++i) {
//        JOYSTICK_BUTTON_INFO prev_joy_info;
//        _prevButtons.push_back(prev_joy_info);
//        JOYSTICK_BUTTON_INFO cur_joy_info;
//        _curButtons.push_back(cur_joy_info);
//    }
//
//    for(int i = 0; i < _numSticks; ++i) {
//        JOYSTICK_STICK_INFO prev_joy_info;
//        _prevSticks.push_back(prev_joy_info);
//        JOYSTICK_STICK_INFO cur_joy_info;
//        _curSticks.push_back(cur_joy_info);
//    }
//
//	++_numjoysticks;
//	++_curjoystick;
//}
//
//Joystick* Joystick::CreateJoystick() {
//    int numJoysticks = GetNumJoysticks();
//	if(numJoysticks > 0) {
//		if(_numjoysticks > _totaljoysticks) {
//            return nullptr;
//		}
//		return new Joystick();
//	} else {
//		return nullptr;
//	}
//}
//Joystick::~Joystick() {
//
//    _prevButtons.erase(_prevButtons.begin(), _prevButtons.end());
//    _curButtons.erase(_curButtons.begin(), _curButtons.end());
//    _prevSticks.erase(_prevSticks.begin(), _prevSticks.end());
//    _curSticks.erase(_curSticks.begin(), _curSticks.end());
//	--_numjoysticks;
//	if(_numjoysticks == 0) {
//		remove_joystick();
//	}
//}
//
//void Joystick::Update() {
//    //If all joysticks were deleted remove input and do nothing.
//	if(_numjoysticks == 0) {
//		remove_joystick();
//		return;
//	}
//
//    //Update state information
//	if(poll_joystick() < 0) {
//        throw InputNotAvailableException("Joystick");
//    }
//    for(int i = 0; i < _numButtons; ++i) {
//		_prevButtons[i].b = _curButtons[i].b;
//		_prevButtons[i].name = _curButtons[i].name;
//
//		_curButtons[i].b = joy[_joyNumber].button[i].b;
//		_curButtons[i].name = joy[_joyNumber].button[i].name;
//	}
//	for(int i = 0; i < _numSticks; ++i) {
//		for(int j = 0; j < joy[_joyNumber].stick[i].num_axis; ++j) {
//			_prevSticks[i].axis[j].name = _curSticks[i].axis[j].name;
//			_prevSticks[i].axis[j].pos = _curSticks[i].axis[j].pos;
//			_prevSticks[i].axis[j].d1 = _curSticks[i].axis[j].d1;
//			_prevSticks[i].axis[j].d2 = _curSticks[i].axis[j].d2;
//
//			_curSticks[i].axis[j].name = joy[_joyNumber].stick[i].axis[j].name;
//			_curSticks[i].axis[j].pos = joy[_joyNumber].stick[i].axis[j].pos;
//			_curSticks[i].axis[j].d1 = joy[_joyNumber].stick[i].axis[j].d1;
//			_curSticks[i].axis[j].d2 = joy[_joyNumber].stick[i].axis[j].d2;
//		}
//		_prevSticks[i].flags = _curSticks[i].flags;
//		_prevSticks[i].name = _curSticks[i].name;
//
//		_curSticks[i].flags = joy[_joyNumber].stick[i].flags;
//		_curSticks[i].name = joy[_joyNumber].stick[i].name;
//	}
//}
//int Joystick::GetNumJoysticks() {
//	if(install_joystick(JOY_TYPE_DIRECTX)) {
//		return 0;
//	}
//	return (num_joysticks);
//}
//int Joystick::GetNumButtons() {
//	return (_numButtons);
//}
//int Joystick::GetNumSticks() {
//	return (_numSticks);
//}
//std::string Joystick::GetButtonName(Joystick::BUTTONS button) {
//	return (_curButtons[button].name);
//}
//int Joystick::GetFlagValue() {
//	return (joy[_joyNumber].flags);
//}
//int Joystick::GetStickFlagValue(Joystick::STICKS stick) {
//	return (_curSticks[stick].flags);
//}
//std::string Joystick::GetStickName(Joystick::STICKS stick) {
//	return (_curSticks[stick].name);
//}
//
//bool Joystick::ButtonDown(Joystick::BUTTONS button) {
//	return (!_prevButtons[button].b && _curButtons[button].b);
//}
//bool Joystick::ButtonPress(Joystick::BUTTONS button) {
//	return (_prevButtons[button].b && _curButtons[button].b);
//}
//bool Joystick::ButtonUp(Joystick::BUTTONS button) {
//	return (_prevButtons[button].b && !_curButtons[button].b);
//}
//bool Joystick::IsButtonPressed() {
//	for(int i = 0; i < _numButtons; ++i) {
//		if(_curButtons[i].b) return true;
//	}
//	return false;
//}
//int Joystick::GetStickXAxis(Joystick::STICKS stick) {
//    return GetSensitivity(stick, Joystick::AXIS_X);
//}
//int Joystick::GetStickYAxis(Joystick::STICKS stick) {
//    return GetSensitivity(stick, Joystick::AXIS_Y);
//}
//int Joystick::GetStickZAxis(Joystick::STICKS stick) {
//    return GetSensitivity(stick, Joystick::AXIS_Z);
//}
//bool Joystick::StickPushedLeft(Joystick::STICKS stick) {
//	return (joy[_joyNumber].stick[stick].axis[Joystick::AXIS_X].d1 != 0);
//}
//bool Joystick::StickPushedRight(Joystick::STICKS stick) {
//	return (joy[_joyNumber].stick[stick].axis[Joystick::AXIS_X].d2 != 0);
//}
//bool Joystick::StickPushedUp(Joystick::STICKS stick) {
//	return (joy[_joyNumber].stick[stick].axis[Joystick::AXIS_Y].d1 != 0);
//}
//bool Joystick::StickPushedDown(Joystick::STICKS stick) {
//	return (joy[_joyNumber].stick[stick].axis[Joystick::AXIS_Y].d2 != 0);
//}
//bool Joystick::StickZAxisLeft(Joystick::STICKS stick) {
//	return (joy[_joyNumber].stick[stick].axis[Joystick::AXIS_Z].d2 != 0);
//}
//bool Joystick::StickZAxisRight(Joystick::STICKS stick) {
//	return (joy[_joyNumber].stick[stick].axis[Joystick::AXIS_Z].d1 != 0);
//}
//int Joystick::GetSensitivity(Joystick::STICKS stick, Joystick::AXIS axis) {
//	return (joy[_joyNumber].stick[stick].axis[axis].pos);
//}
//
//A2DE_END