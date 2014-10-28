/**************************************************************************************************
// file:	Engine\Math\CMiscMath.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the misc mathematics class
 **************************************************************************************************/
#include "CMiscMath.h"

#include "CVector2D.h"
#include "CVector3D.h"

A2DE_BEGIN

namespace Math {

    namespace {
        /// <summary> The meter to pixel scale ratio </summary>
        double WORLD_SCALE = 0.01;
    }

double a2de::Math::DegreeToRadian(double degree) {
    return degree * A2DE_RADIAN;
}

double RadianToDegree(double radian) {
    return radian * A2DE_DEGREE;
}

PolarCoordinate CartesianToPolar(const CartesianCoordinate& coordinate) {
    PolarCoordinate polar;
    polar.first = std::sqrt((coordinate.first * coordinate.first) + (coordinate.second * coordinate.second));
    polar.second = std::atan2(coordinate.second, coordinate.first);
    return polar;
}

CartesianCoordinate PolarToCartesian(const PolarCoordinate& coordinate) {
    CartesianCoordinate cartesian;
    cartesian.first = coordinate.first * std::cos(coordinate.second);
    cartesian.second = coordinate.first * std::sin(coordinate.second);
    return cartesian;
}

bool IsEqual(double a, double b) {
    double ZERO_DELTA_EPSILON = 0.0001;
    return std::fabs(a - b) <= ZERO_DELTA_EPSILON;
}

void SetWorldScale(double scale) {
    WORLD_SCALE = scale;
}

double ToWorldScale(double pixel) {
    return pixel * WORLD_SCALE;
}

double ToScreenScale(double meter) {
    return meter / WORLD_SCALE;
}

a2de::Vector2D ToWorldScale(const a2de::Vector2D& pixel) {
    return pixel * WORLD_SCALE;
}

a2de::Vector2D ToScreenScale(const a2de::Vector2D& meter) {
    return meter / WORLD_SCALE;
}

a2de::Vector3D ToWorldScale(const a2de::Vector3D& pixel) {
    return pixel * WORLD_SCALE;
}

a2de::Vector3D ToScreenScale(const a2de::Vector3D& meter) {
    return meter / WORLD_SCALE;
}

} //End namespace Math

A2DE_END