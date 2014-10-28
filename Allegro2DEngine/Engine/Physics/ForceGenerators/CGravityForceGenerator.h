/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\CGravityForceGenerator.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the gravity force generator class
 **************************************************************************************************/
#ifndef A2DE_CGRAVITYHANDLER_H
#define A2DE_CGRAVITYHANDLER_H

#include "../../a2de_vals.h"
#include "../../Math/CVector2D.h"

#include "ADTForceGenerator.h"

A2DE_BEGIN

class GravityForceGenerator : public ADTForceGenerator {

public:

    /// <summary> The default gravity value: 9.80665 Newtons </summary>
    static double DEFAULT_GRAVITY_VALUE;
    /// <summary> The default gravity vector [0.0, 9.80665] </summary>
    static const Vector2D DEFAULT_GRAVITY_VECTOR;

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     **************************************************************************************************/
    GravityForceGenerator();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    GravityForceGenerator(double x, double y);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="gravity">The gravity.</param>
     **************************************************************************************************/
    GravityForceGenerator(const Vector2D& gravity);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     **************************************************************************************************/
    virtual ~GravityForceGenerator();

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    GravityForceGenerator(const GravityForceGenerator& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    GravityForceGenerator& operator=(const GravityForceGenerator& rhs);

    /**************************************************************************************************
     * <summary>Gets the gravity value in the X direction.</summary>
     * <remarks>Casey Ugone, 2/15/2012.</remarks>
     * <returns>The gravity value in the X direction.</returns>
     **************************************************************************************************/
    double GetXGravityValue() const;

    /**************************************************************************************************
     * <summary>Get x coordinate gravity value.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The x coordinate gravity value.</returns>
     **************************************************************************************************/
    double GetXGravityValue();

    /**************************************************************************************************
     * <summary>Gets the gravity value in the Y direction.</summary>
     * <remarks>Casey Ugone, 2/15/2012.</remarks>
     * <returns>The gravity value in the Y direction.</returns>
     **************************************************************************************************/
    double GetYGravityValue() const;

    /**************************************************************************************************
     * <summary>Get y coordinate gravity value.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The y coordinate gravity value.</returns>
     **************************************************************************************************/
    double GetYGravityValue();

    /**************************************************************************************************
     * <summary>Gets the gravity value.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The gravity value.</returns>
     **************************************************************************************************/
    Vector2D GetGravityValue() const;

    /**************************************************************************************************
     * <summary>Gets the gravity value.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The gravity value.</returns>
     **************************************************************************************************/
    Vector2D GetGravityValue();

    /**************************************************************************************************
     * <summary>Updates this object.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     **************************************************************************************************/
    virtual void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Sets a gravity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="gravity">The gravity.</param>
     **************************************************************************************************/
    void SetGravity(const Vector2D& gravity);

    /**************************************************************************************************
     * <summary>Sets a gravity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetGravity(double x, double y);

    /**************************************************************************************************
     * <summary>Sets an x coordinate gravity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetXGravity(double x);

    /**************************************************************************************************
     * <summary>Sets a y coordinate gravity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetYGravity(double y);

protected:
private:
    /// <summary> The gravity </summary>
    Vector2D _gravity;

};

A2DE_END

#endif