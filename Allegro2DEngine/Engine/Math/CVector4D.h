/**************************************************************************************************
// file:	Engine\Math\CVector3D.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the vector 3 d class
 **************************************************************************************************/
#ifndef A2DE_CVECTOR4D_H
#define A2DE_CVECTOR4D_H


#include "../a2de_vals.h"


A2DE_BEGIN

class Vector2D;
class Vector3D;

class Vector4D {

public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    Vector4D();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    Vector4D(double x, double y);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <param name="z">The z coordinate.</param>
     **************************************************************************************************/
    Vector4D(double x, double y, double z);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     *
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     *
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <param name="z">The z coordinate.</param>
     * <param name="w">The w coordinate.</param>
     **************************************************************************************************/
    Vector4D(double x, double y, double z, double w);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     *
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     *
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Vector4D(const Vector4D& other);

    /**************************************************************************************************
     * <summary>Constructor. Constructs a 4D Vector from a 3D Vector.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="v3d">The other 3D vector.</param>
     **************************************************************************************************/
    Vector4D(const Vector3D& v3d);

    /**************************************************************************************************
     * <summary>Constructor. Constructs a 4D Vector from a 2D Vector.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <remarks>The resulting vecotr will be [x, y, 0].</remarks>
     * <param name="v2d">The 2D Vector.</param>
     **************************************************************************************************/
    Vector4D(const Vector2D& v2d);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    ~Vector4D();

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY() const;

    /**************************************************************************************************
     * <summary>Get z coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The z coordinate.</returns>
     **************************************************************************************************/
    double GetZ() const;

    /**************************************************************************************************
     * <summary>Get w coordinate.</summary>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     * <returns>The w coordinate.</returns>
     **************************************************************************************************/
    double GetW() const;

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX();

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY();

    /**************************************************************************************************
     * <summary>Get z coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The z coordinate.</returns>
     **************************************************************************************************/
    double GetZ();

    /**************************************************************************************************
     * <summary>Gets w coordinate.</summary>
     *
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     *
     * <returns>The w coordinate.</returns>
     **************************************************************************************************/
    double GetW();

    /**************************************************************************************************
     * <summary>Gets the length.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length.</returns>
     **************************************************************************************************/
    double GetLength() const;

    /**************************************************************************************************
     * <summary>Gets the length.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length.</returns>
     **************************************************************************************************/
    double GetLength();

    /**************************************************************************************************
     * <summary>Gets the length squared.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length squared.</returns>
     **************************************************************************************************/
    double GetLengthSquared() const;

    /**************************************************************************************************
     * <summary>Gets the length squared.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length squared.</returns>
     **************************************************************************************************/
    double GetLengthSquared();

    /**************************************************************************************************
     * <summary>Returns the result of Normalizing the vector.</summary>
     * <remarks>Casey Ugone, 6/24/2013.</remarks>
     * <returns>.</returns>
     **************************************************************************************************/
    Vector4D Normalize() const;

    /**************************************************************************************************
     * <summary>Normalizes the vector in-place.</summary>
     * <remarks>Casey Ugone, 6/24/2013.</remarks>
     * <param name="v">[in,out] The v.</param>
     **************************************************************************************************/
    static void Normalize(Vector4D& v);

    /**************************************************************************************************
     * <summary>Dot product between b and this vector.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="b">The b vector.</param>
     * <returns>The scalar product between the b vector and this vector.</returns>
     **************************************************************************************************/
    double DotProduct(const Vector4D& b);

    /**************************************************************************************************
     * <summary>Dot product between a and b.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="a">The a vector.</param>
     * <param name="b">The b vector.</param>
     * <returns>The scalar product between the two vectors.</returns>
     **************************************************************************************************/
    static double DotProduct(const Vector4D& a, const Vector4D& b);
    
    /**************************************************************************************************
     * <summary>Converts this vector into an equivalent vector in homogeneous coordinates.</summary>
     * <remarks>If the W value is zero, the vector is assumed to be a direction vector and no changes are made.</remarks>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     *
     * <returns>The vector in 4D homogeneous coordinates.</returns>
     **************************************************************************************************/
    static void GetHomogeneous(a2de::Vector4D& v);

    /**************************************************************************************************
     * <summary>Gets an equivalent 4D vector in homogeneous coordinates</summary>
     * <remarks>If the W value is zero, the vector is assumed to be a direction vector and no changes are made.</remarks>
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     *
     * <returns>The vector in 4D homogeneous coordinates.</returns>
     **************************************************************************************************/
    Vector4D GetHomogeneous() const;

    /**************************************************************************************************
     * <summary>Gets the homogeneous.</summary>
     * <remarks>If the W value is zero, the vector is assumed to be a direction vector and no changes are made.</remarks>
     * <remarks>Casey Ugone, 6/4/2014.</remarks>
     * <returns>The homogeneous.</returns>
     **************************************************************************************************/
    Vector4D GetHomogeneous();

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Vector4D& operator=(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/27/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Vector4D& operator=(const Vector3D& rhs);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/27/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Vector4D& operator=(const Vector2D& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     **************************************************************************************************/
    bool operator!=(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Addition assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator+=(double scalar);

    /**************************************************************************************************
     * <summary>Subtraction assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator-=(double scalar);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator*=(double scalar);

    /**************************************************************************************************
     * <summary>Division assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator/=(double scalar);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator+(const Vector4D& rhs) const;

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator+(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator-(const Vector4D& rhs) const;

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator-(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator-() const;

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 9/19/2014.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator-();

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator*(const Vector4D& rhs) const;

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator*(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator/(const Vector4D& rhs) const;

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator/(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Addition assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator+=(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Subtraction assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator-=(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator*=(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Division assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D& operator/=(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 5/27/2014.</remarks>
     * <param name="lhs">The left hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator-(const Vector4D& lhs);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The first value.</param>
     * <param name="scalar_rhs">A value to add to it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator+(const Vector4D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The first value.</param>
     * <param name="v_rhs">     A value to add to it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator+(double scalar_lhs, const Vector4D& v_rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The first value.</param>
     * <param name="scalar_rhs">A value to subtract from it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator-(const Vector4D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The first value.</param>
     * <param name="v_rhs">     A value to subtract from it.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator-(double scalar_lhs, const Vector4D& v_rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The first value to multiply.</param>
     * <param name="scalar_rhs">The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator*(const Vector4D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The first value to multiply.</param>
     * <param name="v_rhs">     The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator*(double scalar_lhs, const Vector4D& v_rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="v_lhs">     The numerator.</param>
     * <param name="scalar_rhs">The denominator.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator/(const Vector4D& v_lhs, double scalar_rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="scalar_lhs">The numerator.</param>
     * <param name="v_rhs">     The denominator.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator/(double scalar_lhs, const Vector4D& v_rhs);



protected:

    /**************************************************************************************************
     * <summary>Sets the x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets the y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetY(double y);

    /**************************************************************************************************
     * <summary>Sets the z coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="z">The z coordinate.</param>
     **************************************************************************************************/
    void SetZ(double z);

    /**************************************************************************************************
     * <summary>Sets the w coordinate.</summary>
     *
     * <remarks>Casey Ugone, 3/26/2014.</remarks>
     *
     * <param name="w">The w coordinate.</param>
     **************************************************************************************************/
    void SetW(double w);

    /**************************************************************************************************
     * <summary>Sets the terminal point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <param name="z">The z coordinate.</param>
     * <param name="w">The w coordinate.</param>
     **************************************************************************************************/
    void SetTerminal(double x, double y, double z, double w);

private:
    /// <summary> The terminal point x-coordinate. </summary>
    double _x;
    /// <summary> The terminal point y-coordinate. </summary>
    double _y;
    /// <summary> The terminal point z-coordinate. </summary>
    double _z;
    /// <summary> The terminal point w-coordinate.</summary>
    double _w;

};

A2DE_END

#endif