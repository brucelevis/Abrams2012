/**************************************************************************************************
// file:	Engine\Math\CMiscMath.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the misc mathematics class
 **************************************************************************************************/
#ifndef A2DE_CMATH_H
#define A2DE_CMATH_H

#include "../a2de_vals.h"
#include "MathConstants.h"

#include <cmath>
#include <utility>

A2DE_BEGIN

class Vector2D;
class Vector3D;

namespace Math {

    /**************************************************************************************************
     * <summary>Defines an alias representing the polar coordinate. .</summary>
     * <param name="PolarCoordinate.first">The magnitude of the coordinate.</param>
     * <param name="PolarCoordinate.second">The angle of the coordinate in RADIANS relative to the positive x-axis.</param>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef std::pair<double, double> PolarCoordinate;

    /**************************************************************************************************
     * <summary>Defines an alias representing the cartesian coordinate. .</summary>
     * <param name="CartesianCoordinate.first">The x-coordinate of the coordinate.</param>
     * <param name="CartesianCoordinate.second">The y-coordinate of the coordinate.</param>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef std::pair<double, double> CartesianCoordinate;

    /**************************************************************************************************
     * <summary>Converts Degrees to Radians.</summary>
     * <remarks>Casey Ugone, 2/10/2012.</remarks>
     * <param name="degree">The degree value to convert.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    double DegreeToRadian(double degree);

    /**************************************************************************************************
     * <summary>Converts Radians to Degrees.</summary>
     * <remarks>Casey Ugone, 7/8/2012.</remarks>
     * <param name="radian">The radian value to convert.</param>
     * <returns>A double describing the value of the radian input in degrees.</returns>
     **************************************************************************************************/
    double RadianToDegree(double radian);

    /**************************************************************************************************
     * <summary>Converts a Cartesian coordinate to a Polar coordinate.</summary>
     * <remarks>Casey Ugone, 7/13/2012.</remarks>
     * <param name="value">The coordinate.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    PolarCoordinate CartesianToPolar(const CartesianCoordinate& coordinate);

    /**************************************************************************************************
     * <summary>Converts a Polar coordinate to a Cartesian coordinate.</summary>
     * <remarks>Casey Ugone, 7/13/2012.</remarks>
     * <param name="coordinate">The coordinate.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    CartesianCoordinate PolarToCartesian(const PolarCoordinate& coordinate);

    /**************************************************************************************************
     * <summary>Query if 'a' is equal to 'b'.</summary>
     * <remarks>Casey Ugone, 7/15/2012.</remarks>
     * <param name="a">The first double.</param>
     * <param name="b">The second double.</param>
     * <returns>true if equal, false if not.</returns>
     **************************************************************************************************/
    bool IsEqual(double a, double b);

    /**************************************************************************************************
     * <summary>Sets the world scale.</summary>
     * <remarks>Casey Ugone, 5/2/2013.</remarks>
     * <param name="scale">The scale.</param>
     **************************************************************************************************/
    void SetWorldScale(double scale);

    /**************************************************************************************************
     * <summary>Converts a pixel to a world scale.</summary>
     * <remarks>Casey Ugone, 5/6/2013.</remarks>
     * <param name="pixel">The pixel.</param>
     * <returns>This object as a double.</returns>
     **************************************************************************************************/
    double ToWorldScale(double pixel);

    /**************************************************************************************************
     * <summary>Converts a meter to a screen scale.</summary>
     * <remarks>Casey Ugone, 5/6/2013.</remarks>
     * <param name="meter">The meter.</param>
     * <returns>This object as a double.</returns>
     **************************************************************************************************/
    double ToScreenScale(double meter);

    /**************************************************************************************************
     * <summary>Converts the meters to a screen scale.</summary>
     * <remarks>Casey Ugone, 5/6/2013.</remarks>
     * <param name="meters">The meters.</param>
     * <returns>This object as an a2de::Vector2D.</returns>
     **************************************************************************************************/
    a2de::Vector2D ToScreenScale(const a2de::Vector2D& meters);

    /**************************************************************************************************
     * <summary>Converts the pixels to a world scale.</summary>
     * <remarks>Casey Ugone, 5/6/2013.</remarks>
     * <param name="pixels">The pixels.</param>
     * <returns>This object as an a2de::Vector2D.</returns>
     **************************************************************************************************/
    a2de::Vector2D ToWorldScale(const a2de::Vector2D& pixels);

    /**************************************************************************************************
     * <summary>Converts the meters to a screen scale.</summary>
     * <remarks>Casey Ugone, 5/6/2013.</remarks>
     * <param name="meters">The meters.</param>
     * <returns>This object as an a2de::Vector3D.</returns>
     **************************************************************************************************/
    a2de::Vector3D ToScreenScale(const a2de::Vector3D& meters);

    /**************************************************************************************************
     * <summary>Converts the pixels to a world scale.</summary>
     * <remarks>Casey Ugone, 5/6/2013.</remarks>
     * <param name="pixels">The pixels.</param>
     * <returns>This object as an a2de::Vector3D.</returns>
     **************************************************************************************************/
    a2de::Vector3D ToWorldScale(const a2de::Vector3D& pixels);

}

A2DE_END

#endif