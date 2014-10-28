/**************************************************************************************************
// file:	Engine\Physics\CFluidPhysicsArea.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the fluid physics area class
 **************************************************************************************************/
#ifndef A2DE_CFLUIDPHYSICSAREA_H
#define A2DE_CFLUIDPHYSICSAREA_H

#include "../a2de_vals.h"
#include "CPhysicsArea.h"

A2DE_BEGIN

class Vector2D;
class Object;

class FluidPhysicsArea : public PhysicsArea {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 5/7/2013.</remarks>
     * <param name="density">The density of the fluid at 1 meter depth.</param>
     * <param name="gravity">The gravity current gravity value of the world.</param>
     **************************************************************************************************/
    FluidPhysicsArea(double density, const a2de::Vector2D& gravity);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 5/7/2013.</remarks>
     **************************************************************************************************/
    virtual ~FluidPhysicsArea();

    /**************************************************************************************************
     * <summary>Updates the given deltaTime.</summary>
     * <remarks>Casey Ugone, 5/7/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    virtual void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Method that executes for every body that enters the area.</summary>
     * <remarks>Casey Ugone, 5/7/2013.</remarks>
     * <param name="entered_object">[in,out] If non-null, the entered object.</param>
     **************************************************************************************************/
    virtual void OnEnter(Object* entered_object);

    /**************************************************************************************************
     * <summary>Method that executes for every body for each game loop that the body remains in the area.</summary>
     * <remarks>Casey Ugone, 5/7/2013.</remarks>
     * <param name="object">[in,out] If non-null, the object.</param>
     **************************************************************************************************/
    virtual void OnTick(Object* object);

    /**************************************************************************************************
     * <summary>Method that executes for every body that leaves the area.</summary>
     * <remarks>Casey Ugone, 5/7/2013.</remarks>
     * <param name="exited_object">[in,out] If non-null, the exited object.</param>
     **************************************************************************************************/
    virtual void OnExit(Object* exited_object);

protected:
private:
    double _density;
};

A2DE_END

#endif // CFLUIDPHYSICSAREA_H