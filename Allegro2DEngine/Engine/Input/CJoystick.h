/**************************************************************************************************
// file:	Engine\Input\CJoystick.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the joystick class
 **************************************************************************************************/
#ifndef A2DE_CJOYSTICK_H
#define A2DE_CJOYSTICK_H

#include "../a2de_vals.h"

//gfx and system includes required for joystick include to compile.
//Yay for bad 3rd party development!
#include <allegro5/joystick.h>
#include <utility>
#include <string>
#include <vector>

A2DE_BEGIN

class Joystick {
//
//public:
//
//    /**************************************************************************************************
//     * <summary>Values that represent AXIS. </summary>
//     * <remarks>Casey Ugone, 7/7/2012.</remarks>
//     **************************************************************************************************/
//	typedef enum AXIS {
//		AXIS_X = 0,
//		AXIS_Y,
//		AXIS_Z,
//		AXIS_PITCH = AXIS_X,
//		AXIS_YAW = AXIS_Y,
//		AXIS_ROLL = AXIS_Z,
//	};
//
//    /**************************************************************************************************
//     * <summary>Values that represent BUTTONS. </summary>
//     * <remarks>Casey Ugone, 7/7/2012.</remarks>
//     **************************************************************************************************/
//	typedef enum BUTTONS {
//		BUTTON0 = 0,
//		BUTTON1,
//		BUTTON2,
//		BUTTON3,
//		BUTTON4,
//		BUTTON5,
//		BUTTON6,
//		BUTTON7,
//		BUTTON8,
//		BUTTON9,
//		BUTTON10,
//		BUTTON11,
//		BUTTON12,
//		BUTTON13,
//		BUTTON14,
//		BUTTON15,
//		BUTTON16,
//		BUTTON17,
//		BUTTON18,
//		BUTTON19,
//		BUTTON20,
//		BUTTON21,
//		BUTTON22,
//		BUTTON23,
//		BUTTON24,
//		BUTTON25,
//		BUTTON26,
//		BUTTON27,
//		BUTTON28,
//		BUTTON29,
//		BUTTON30,
//		BUTTON31,
//	};
//
//    /**************************************************************************************************
//     * <summary>Values that represent STICKS. </summary>
//     * <remarks>Casey Ugone, 7/7/2012.</remarks>
//     **************************************************************************************************/
//	typedef enum STICKS {
//		STICK0 = 0,
//		STICK1,
//		STICK2,
//		STICK3,
//		STICK4,
//	};
//
//    //Hardware-specific indicators.
//    //XBOX 360 Controllers.
//    const static Joystick::BUTTONS XBOX_360_BUTTON_A     = Joystick::BUTTON0;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_B     = Joystick::BUTTON1;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_X     = Joystick::BUTTON2;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_Y     = Joystick::BUTTON3;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_LB    = Joystick::BUTTON4;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_RB    = Joystick::BUTTON5;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_BACK  = Joystick::BUTTON6;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_START = Joystick::BUTTON7;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_L3    = Joystick::BUTTON8;
//    const static Joystick::BUTTONS XBOX_360_BUTTON_R3    = Joystick::BUTTON9;
//    const static Joystick::STICKS XBOX_360_STICK         = Joystick::STICK0;
//    const static Joystick::STICKS XBOX_360_HAT_SWITCH    = Joystick::STICK1;
//
//    /**************************************************************************************************
//     * <summary>Creates a joystick.</summary>
//     * <remarks>Casey Ugone, 7/7/2012.</remarks>
//     * <returns>null if it fails, else.</returns>
//     **************************************************************************************************/
//	static Joystick* CreateJoystick();
//
//    /**************************************************************************************************
//     * <summary>Destructor.</summary>
//     * <remarks>Casey Ugone, 7/7/2012.</remarks>
//     **************************************************************************************************/
//	~Joystick();
//
//    /**************************************************************************************************
//     * <summary>Updates this object.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     **************************************************************************************************/
//	void Update();
//
//    /**************************************************************************************************
//     * <summary>Gets the number of joysticks.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <returns>The number joysticks.</returns>
//     **************************************************************************************************/
//	static int GetNumJoysticks();
//
//    /**************************************************************************************************
//     * <summary>Gets the flag value.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <returns>The flag value.</returns>
//     **************************************************************************************************/
//	int GetFlagValue();
//
//    /**************************************************************************************************
//     * <summary>Gets the number of buttons.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <returns>The number of buttons.</returns>
//     **************************************************************************************************/
//	int GetNumButtons();
//
//    /**************************************************************************************************
//     * <summary>Gets the number of sticks.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <returns>The number of sticks.</returns>
//     **************************************************************************************************/
//	int GetNumSticks();
//
//    /**************************************************************************************************
//     * <summary>Gets a button's name.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="button">The button.</param>
//     * <returns>The button name.</returns>
//     **************************************************************************************************/
//	std::string GetButtonName(Joystick::BUTTONS button);
//
//    /**************************************************************************************************
//     * <summary>Gets a stick's flag value.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick.</param>
//     * <returns>The stick flag value.</returns>
//     **************************************************************************************************/
//	int GetStickFlagValue(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Gets a stick's name.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick.</param>
//     * <returns>The stick name.</returns>
//     **************************************************************************************************/
//	std::string GetStickName(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Queries if a button was just pressed.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="button">The button to check.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool ButtonDown(Joystick::BUTTONS button);
//
//    /**************************************************************************************************
//     * <summary>Queries if a button is held down.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="button">The button.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool ButtonPress(Joystick::BUTTONS button);
//
//    /**************************************************************************************************
//     * <summary>Queries if a button was just released.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="button">The button to check.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool ButtonUp(Joystick::BUTTONS button);
//
//    /**************************************************************************************************
//     * <summary>Query if any button is pressed.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <returns>true if any button is pressed, false if not.</returns>
//     **************************************************************************************************/
//	bool IsButtonPressed();
//
//    /**************************************************************************************************
//     * <summary>Gets a stick's x axis sensitivity value.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>The stick's x axis value.</returns>
//     **************************************************************************************************/
//	int GetStickXAxis(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Gets a stick's y axis sensitivity value.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>The stick's y axis value.</returns>
//     **************************************************************************************************/
//	int GetStickYAxis(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Gets a stick's z axis sensitivity value.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <remarks>The value reported is usually mutually exclusive in that if the stick is moved in one direction it can not be moved in the other at the same
//     * time. X-Box 360 controllers report the use of the shoulder triggers as one Z axis movement, one being negative and the other being positive. If both are
//     * pressed at the same time this method and the equivalent GetSensitivity()
//     * method will return zero.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>The stick's z axis value.</returns>
//     **************************************************************************************************/
//	int GetStickZAxis(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Queries if the requested stick has its X Axis moved left.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool StickPushedLeft(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Queries if the requested stick has its X Axis moved right.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool StickPushedRight(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Queries if the requested stick has its Y Axis moved up.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool StickPushedUp(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Queries if the requested stick has its Y Axis moved down.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool StickPushedDown(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Queries if the requested stick has its Z axis moved to the left.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool StickZAxisLeft(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Queries if the requested stick has its Z axis moved to the right.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <returns>true if it succeeds, false if it fails.</returns>
//     **************************************************************************************************/
//	bool StickZAxisRight(Joystick::STICKS stick);
//
//    /**************************************************************************************************
//     * <summary>Gets the requested sensitivity value of the requested Axis of the requested stick.</summary>
//     * <remarks>Casey Ugone, 8/20/2011.</remarks>
//     * <param name="stick">The stick to check.</param>
//     * <param name="axis"> The axis to check.</param>
//     * <returns>The sensitivity of the stick in the requested axis.</returns>
//     **************************************************************************************************/
//	int GetSensitivity(Joystick::STICKS stick, Joystick::AXIS axis);
//
//private:
//
//    /**************************************************************************************************
//     * <summary>Default constructor. Use Named constructor.</summary>
//     * <remarks>Casey Ugone, 9/3/2012.</remarks>
//     **************************************************************************************************/
//    Joystick();
//    /// <summary> The totaljoysticks </summary>
//    static int _totaljoysticks;
//    /// <summary> The numjoysticks </summary>
//    static int _numjoysticks;
//    /// <summary> The curjoystick </summary>
//    static int _curjoystick;
//    /// <summary> The joy number </summary>
//    int _joyNumber;
//    /// <summary> Number of buttons </summary>
//    int _numButtons;
//    /// <summary> Number of sticks </summary>
//    int _numSticks;
//    /// <summary> The previous buttons </summary>
//    std::vector<JOYSTICK_BUTTON_INFO> _prevButtons;
//    /// <summary> The current buttons </summary>
//    std::vector<JOYSTICK_BUTTON_INFO> _curButtons;
//
//    /// <summary> The previous sticks </summary>
//    std::vector<JOYSTICK_STICK_INFO> _prevSticks;
//    /// <summary> The current sticks </summary>
//    std::vector<JOYSTICK_STICK_INFO> _curSticks;
//
};

A2DE_END

#endif