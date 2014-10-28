/**************************************************************************************************
// file:	Engine\Math\CVector2D.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the vector 2 d class
 **************************************************************************************************/
#ifndef A2DE_CVECTOR2D_H
#define A2DE_CVECTOR2D_H

#include "../a2de_vals.h"
#include "CMiscMath.h"

A2DE_BEGIN

class Vector3D;

class Vector2D {

public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 7/8/2012.</remarks>
     **************************************************************************************************/
    Vector2D();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 7/8/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    Vector2D(double x, double y);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 7/8/2012.</remarks>
     * <param name="vector">The vector.</param>
     **************************************************************************************************/
    Vector2D(const Vector2D& vector);
    
    /**************************************************************************************************
     * <summary>Constructor. Constructs a 3D Vector from a 2D Vector.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <remarks>The resulting vecotr will be [x, y] and the z-value will be dropped.</remarks>
     * <param name="v2d">The 3D Vector.</param>
     **************************************************************************************************/
    Vector2D(const Vector3D& v3d);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="magnitude_and_angle">The magnitude and angle.</param>
     **************************************************************************************************/
    Vector2D(const a2de::Math::PolarCoordinate& magnitude_and_angle);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 7/8/2012.</remarks>
     **************************************************************************************************/
    ~Vector2D();

    /**************************************************************************************************
     * <summary>Gets the x coordinate.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX() const;

    /**************************************************************************************************
     * <summary>Gets the x coordinate.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX();

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY();

    /**************************************************************************************************
     * <summary>Gets the length of the vector.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <returns>The length.</returns>
     **************************************************************************************************/
    double GetLength() const;

    /**************************************************************************************************
     * <summary>Gets the length of the vector.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <returns>The length.</returns>
     **************************************************************************************************/
    double GetLength();

    /**************************************************************************************************
     * <summary>Gets the length squared.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <returns>The length squared.</returns>
     **************************************************************************************************/
    double GetLengthSquared() const;

    /**************************************************************************************************
     * <summary>Gets the length squared.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <returns>The length squared.</returns>
     **************************************************************************************************/
    double GetLengthSquared();


    /**************************************************************************************************
     * <summary>Calculates the dot product of two vectors.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="other">The other vector.</param>
     * <returns>The scalar of the operation.</returns>
     **************************************************************************************************/
    double DotProduct(const Vector2D& rhs) const;

    /**************************************************************************************************
     * <summary>Dot product.</summary>
     * <remarks>Casey Ugone, 7/8/2012.</remarks>
     * <param name="a">a.</param>
     * <param name="b">The.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    static double DotProduct(const Vector2D& a, const Vector2D& b);

    /**************************************************************************************************
     * <summary>Normalizes the vector.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <returns>A Vector2D representing the normalized version of the vector. If the length is zero, then an Exception is thrown.</returns>
     **************************************************************************************************/
    Vector2D Normalize() const;

    /**************************************************************************************************
     * <summary>Normalizes a 2D vector.</summary>
     * <remarks>Casey Ugone, 7/28/2012.</remarks>
     * <param name="v">The vector to normalize.</param>
     **************************************************************************************************/
    static void Normalize(Vector2D& v);

    /**************************************************************************************************
     * <summary>Gets the positive normal.</summary>
     * <remarks>Casey Ugone, 6/28/2013.</remarks>
     * <returns>The positive normal.</returns>
     **************************************************************************************************/
    Vector2D GetLeftNormal() const;

    /**************************************************************************************************
     * <summary>Gets the positive normal.</summary>
     * <remarks>Casey Ugone, 6/28/2013.</remarks>
     * <returns>The positive normal.</returns>
     **************************************************************************************************/
    Vector2D GetLeftNormal();

    /**************************************************************************************************
     * <summary>Gets the negative normal.</summary>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     * <returns>The negative normal.</returns>
     **************************************************************************************************/
    Vector2D GetRightNormal() const;

    /**************************************************************************************************
     * <summary>Gets the negative normal.</summary>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     * <returns>The negative normal.</returns>
     **************************************************************************************************/
    Vector2D GetRightNormal();

    /**************************************************************************************************
     * <summary>Gets the projection of this vector onto the argument vector.</summary>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     * <param name="b">The vector to project against.</param>
     * <returns>The projection result.</returns>
     **************************************************************************************************/
    Vector2D GetProjection(const Vector2D& b);

    /**************************************************************************************************
     * <summary>Gets the projection of vector a on b.</summary>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     * <param name="a">The input vector.</param>
     * <param name="b">The vector to project against.</param>
     * <returns>The projection of a on b.</returns>
     **************************************************************************************************/
    static Vector2D GetProjection(const Vector2D& a, const Vector2D& b);

    /**************************************************************************************************
     * <summary>Gets the projection of this vector onto the x-axis.</summary>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     * <returns>The projection result.</returns>
     **************************************************************************************************/
    Vector2D GetProjectionOnXAxis();

    /**************************************************************************************************
     * <summary>Gets the projection of this vector onto the y-axis.</summary>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     * <returns>The projection result.</returns>
     **************************************************************************************************/
    Vector2D GetProjectionOnYAxis();

    /**************************************************************************************************
     * <summary>Gets the positive normal.</summary>
     * <remarks>Casey Ugone, 6/28/2013.</remarks>
     * <returns>The positive normal.</returns>
     **************************************************************************************************/
    Vector2D GetNormal() const;

    /**************************************************************************************************
     * <summary>Gets the positive normal.</summary>
     * <remarks>Casey Ugone, 6/28/2013.</remarks>
     * <returns>The positive normal.</returns>
     **************************************************************************************************/
    Vector2D GetNormal();

    /**************************************************************************************************
     * <summary>Gets the angle of the vector.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <returns>The angle.</returns>
     **************************************************************************************************/
    double GetAngle() const;

    /**************************************************************************************************
     * <summary>Gets the angle.</summary>
     * <remarks>Casey Ugone, 8/10/2012.</remarks>
     * <returns>The angle.</returns>
     **************************************************************************************************/
    double GetAngle();

    /**************************************************************************************************
     * <summary>Gets an angle of a vector.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <param name="v">The vector.</param>
     * <returns>The angle of the vector.</returns>
     **************************************************************************************************/
    static double GetAngle(const Vector2D& v);

    /**************************************************************************************************
     * <summary>Gets an angle from this Vector to another Vector.</summary>
     * <remarks>Casey Ugone, 2/14/2012.</remarks>
     * <param name="b">The vector to measure against.</param>
     * <returns>The angle between this vector and the argument vector in radians.</returns>
     **************************************************************************************************/
    double GetAngleFrom(const Vector2D& b);

     /**************************************************************************************************
      * <summary>Gets an angle between two Vectors.</summary>
      * <remarks>Casey Ugone, 2/14/2012.</remarks>
      * <param name="a">The first of the two vectors.</param>
      * <param name="b">The second of the two vectors.</param>
      * <returns>The angle between vector A and vector B in radians.</returns>
      **************************************************************************************************/
     static double GetAngleFrom(const Vector2D& b, const Vector2D& a);

    /**************************************************************************************************
     * <summary>Gets the rotation angle that 'target' should face to be pointed towards 'source'.</summary>
     * <remarks>Casey Ugone, 8/1/2012.</remarks>
     * <param name="target">The target vector position.</param>
     * <param name="source">The source vector position.</param>
     * <returns>The facing angle in radians.</returns>
     **************************************************************************************************/
    static double GetFacingAngle(const Vector2D& target, const Vector2D& source);

    /**************************************************************************************************
     * <summary>Gets the vector that points from 'target' to 'source'.</summary>
     * <remarks>Casey Ugone, 8/1/2012.</remarks>
     * <param name="target">The target vector.</param>
     * <param name="source">The origin vector.</param>
     * <returns>The facing vector.</returns>
     **************************************************************************************************/
    static Vector2D GetFacingVector(const Vector2D& target, const Vector2D& source);

    /**************************************************************************************************
     * <summary>Gets an equivalent 3D vector in homogeneous coordinates</summary>
     * <remarks>Casey Ugone, 9/19/2014.</remarks>
     * <returns>The vector in 3D homogeneous coordinates.</returns>
     **************************************************************************************************/
    Vector3D GetHomogeneous() const;

    /**************************************************************************************************
     * <summary>Gets the homogeneous.</summary>
     * <remarks>Casey Ugone, 9/19/2014.</remarks>
     * <returns>The vector in 3D homogeneous coordinates.</returns>
     **************************************************************************************************/
    Vector3D GetHomogeneous();

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    Vector2D& operator=(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 6/13/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Vector2D& rhs) const;

    /**************************************************************************************************
     * <summary>Inequality operator</summary>
     * <remarks>Casey Ugone, 7/9/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered not equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Inequality operator</summary>
     * <remarks>Casey Ugone, 6/13/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered not equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Vector2D& rhs) const;

    /**************************************************************************************************
     * <summary>Addition assignment operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator+=(double scalar);

    /**************************************************************************************************
     * <summary>Subtraction assignment operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator-=(double scalar);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator*=(double scalar);

    /**************************************************************************************************
     * <summary>Division assignment operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator/=(double scalar);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator+(const Vector2D& rhs) const;

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 8/10/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator+(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator-(const Vector2D& rhs) const;

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 8/10/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator-(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 8/11/2012.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator-() const;

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 9/19/2014.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator-();

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator*(const Vector2D& rhs) const;

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 8/10/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator*(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator/(const Vector2D& rhs) const;

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 8/10/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D operator/(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Addition assignment operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator+=(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Subtraction assignment operator.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator-=(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator*=(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Division assignment operator.</summary>
     * <remarks>Casey Ugone, 8/9/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector2D& operator/=(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Implicit Vector3D converter.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    operator Vector3D();

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The first value.</param>
     * <param name="scalar_rhs">A value to add to it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator+(const Vector2D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The first value.</param>
     * <param name="v_rhs">     A value to add to it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator+(double scalar_lhs, const Vector2D& v_rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The first value.</param>
     * <param name="scalar_rhs">A value to subtract from it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator-(const Vector2D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The first value.</param>
     * <param name="v_rhs">     A value to subtract from it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator-(double scalar_lhs, const Vector2D& v_rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The first value to multiply.</param>
     * <param name="scalar_rhs">The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator*(const Vector2D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The first value to multiply.</param>
     * <param name="v_rhs">     The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator*(double scalar_lhs, const Vector2D& v_rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The numerator.</param>
     * <param name="scalar_rhs">The denominator.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator/(const Vector2D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The numerator.</param>
     * <param name="v_rhs">     The denominator.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator/(double scalar_lhs, const Vector2D& v_rhs);

protected:

    /**************************************************************************************************
     * <summary>Sets the x coordinate.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets the y coordinate.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetY(double y);

    /**************************************************************************************************
     * <summary>Sets the terminal point.</summary>
     * <remarks>Casey Ugone, 8/19/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <param name="z">The z coordinate.</param>
     **************************************************************************************************/
    void SetTerminal(double x, double y);

    /// <summary> The terminal point x-coordinate.</summary>
    double _x;
    /// <summary> The terminal point y-coordinate.</summary>
    double _y;
    /// <summary> The angle of the vector in radians. </summary>
    double _angle;

private:
};


A2DE_END

#endif