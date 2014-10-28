/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\CDragForceGenerator.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the drag force generator class
 **************************************************************************************************/
#ifndef A2DE_CDRAGHANDLER_H
#define A2DE_CDRAGHANDLER_H

#include "../../a2de_vals.h"
#include "../../Math/CVector2D.h"
#include <utility>

#include "ADTForceGenerator.h"

A2DE_BEGIN

class DragForceGenerator : public ADTForceGenerator {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    DragForceGenerator();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="linear_coefficient">   The linear coefficient.</param>
     * <param name="quadratic_coefficient">The quadratic coefficient.</param>
     **************************************************************************************************/
    DragForceGenerator(double linear_coefficient, double quadratic_coefficient);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="other">The other force generator.</param>
     **************************************************************************************************/
    DragForceGenerator(const DragForceGenerator& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    DragForceGenerator& operator=(const DragForceGenerator& rhs);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    virtual ~DragForceGenerator();

    /**************************************************************************************************
     * <summary>Updates all registerd bodies by deltaTime.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    virtual void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Sets the linear coefficient constant.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="linear_coefficient">The linear coefficient.</param>
     **************************************************************************************************/
    void SetLinearCoefficient(double linear_coefficient);

    /**************************************************************************************************
     * <summary>Gets the quadratic coefficient.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The quadratic coefficient.</returns>
     **************************************************************************************************/
    double GetLinearCoefficient() const;

    /**************************************************************************************************
     * <summary>Gets the linear coefficient.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The quadratic coefficient.</returns>
     **************************************************************************************************/
    double GetLinearCoefficient();

    /**************************************************************************************************
     * <summary>Sets the quadratic coefficient.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="quadratic_coefficient">The quadratic coefficient.</param>
     **************************************************************************************************/
    void SetQuadraticCoefficient(double quadratic_coefficient);

    /**************************************************************************************************
     * <summary>Gets the quadratic coefficient.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The quadratic coefficient.</returns>
     **************************************************************************************************/
    double GetQuadraticCoefficient() const;

    /**************************************************************************************************
     * <summary>Gets the quadratic coefficient.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The quadratic coefficient.</returns>
     **************************************************************************************************/
    double GetQuadraticCoefficient();

protected:
private:
    /// <summary> _coefficients.first: the linear coefficient
    //            _coefficients.second: the quadratic coefficient
    /// </summary>
    std::pair<double, double> _coefficients;
};

A2DE_END

#endif // CDRAGHANDLER_H
