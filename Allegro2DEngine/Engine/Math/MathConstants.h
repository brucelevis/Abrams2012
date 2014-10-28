/**************************************************************************************************
// file:	Engine\Math\MathConstants.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the mathematics constants class
 **************************************************************************************************/
#ifndef A2DE_MATH_CONSTANTS_H
#define A2DE_MATH_CONSTANTS_H

#include "../a2de_vals.h"

A2DE_BEGIN
    
namespace Math {

static const long A2DE_INFINITY = LONG_MAX;
static const long A2DE_NEG_INFINITY = LONG_MIN;

//Copies of Math.h defines in case not defined.
static const double A2DE_E = 2.718281828459045;
static const double A2DE_LOG2E = 1.442695040888963;
static const double A2DE_LOG10E = 0.434294481903251;
static const double A2DE_LN2 = 0.693147180559945;
static const double A2DE_LN10 = 2.302585092994045;
static const double A2DE_PI = 3.141592653589793;
static const double A2DE_PI_2 = 1.570796326794896;
static const double A2DE_PI_4 = 0.785398163397448;
static const double A2DE_1_PI = 0.318309886183790;
static const double A2DE_2_PI = 0.636619772367581;
static const double A2DE_2_SQRTPI = 1.128379167095512;
static const double A2DE_SQRT2 = 1.414213562373095;
static const double A2DE_SQRT1_2 = 0.707106781186547;

/// <summary>Ratio of 1 radian as defined in degrees.</summary>
static const double A2DE_DEGREE = 57.29577951308232;

/// <summary>Ratio of 1 degree as defined in radians.</summary>
static const double A2DE_RADIAN = 0.017453292519943;


/// <summary>Ratio of 1 degree as defined in fixed integer angles.</summary>
static const double A2DE_ALLEGRO_DEGREE = 0.711111111111111;

/// <summary>Ratio of 1 radian as defined in fixed integer angles.</summary>
static const double A2DE_ALLEGRO_RADIAN = 40.74366543152520;


/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 1.</summary>
static const double A2DE_1PI_6 = 0.523598775598298;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 1.</summary>
static const double A2DE_1PI_4 = A2DE_PI_4;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 1.</summary>
static const double A2DE_1PI_3 = 1.047197551196597;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 1.</summary>
static const double A2DE_1PI_2 = A2DE_PI_2;


/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 2.</summary>
static const double A2DE_2PI_3 = 2.094395102393195;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 2.</summary>
static const double A2DE_3PI_4 = 2.356194490192344;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 2.</summary>
static const double A2DE_5PI_6 = 2.617993877991494;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 2.</summary>
static const double A2DE_2PI_2 = A2DE_PI;


/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 3.</summary>
static const double A2DE_7PI_6 = 3.665191429188092;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 3.</summary>
static const double A2DE_5PI_4 = 3.926990816987241;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 3.</summary>
static const double A2DE_4PI_3 = 4.188790204786390;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 3.</summary>
static const double A2DE_3PI_2 = 4.712388980384689;


/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 4.</summary>
static const double A2DE_5PI_3 = 5.235987755982988;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 4.</summary>
static const double A2DE_7PI_4 = 5.497787143782138;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 4.</summary>
static const double A2DE_11PI_6 = 5.75958653158128;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 4.</summary>
static const double A2DE_4PI_2 = 6.283185307179586;
/// <summary>Trig-specific defines. Unit Unit Circle radian definitions. Quadrant 4.</summary>
static const double A2DE_2PI = A2DE_4PI_2;

}

A2DE_END

#endif