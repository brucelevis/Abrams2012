/**************************************************************************************************
// file:	Engine\Physics\CPhysicsArea.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the physics area class
 **************************************************************************************************/
#ifndef A2DE_CPHYSICSAREA_H
#define A2DE_CPHYSICSAREA_H

#include "../a2de_vals.h"
#include "CTrigger.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Physics area. </summary>
 * <remarks>Casey Ugone, 5/8/2013.</remarks>
 * <seealso cref="Trigger<RigidBody*>"/>
 **************************************************************************************************/
class Object;

/**************************************************************************************************
 * <summary>Physics area. </summary>
 * <remarks>Casey Ugone, 5/8/2013.</remarks>
 * <seealso cref="Trigger<RigidBody*>"/>
 **************************************************************************************************/
class Vector2D;

/**************************************************************************************************
 * <summary>Physics area. </summary>
 * <remarks>Casey Ugone, 5/8/2013.</remarks>
 * <seealso cref="Trigger<RigidBody*>"/>
 **************************************************************************************************/
class GravityForceGenerator;

/**************************************************************************************************
 * <summary>Physics area. </summary>
 * <remarks>Casey Ugone, 5/8/2013.</remarks>
 * <seealso cref="Trigger<RigidBody*>"/>
 **************************************************************************************************/
class DragForceGenerator;

/**************************************************************************************************
 * <summary>Physics area. </summary>
 * <remarks>Casey Ugone, 5/8/2013.</remarks>
 * <seealso cref="Trigger<RigidBody*>"/>
 **************************************************************************************************/
class PhysicsArea : public Trigger<Object*> {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     **************************************************************************************************/
    PhysicsArea();

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     **************************************************************************************************/
    virtual ~PhysicsArea();

    /**************************************************************************************************
     * <summary>Updates the given deltaTime.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    virtual void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Executes the enter action.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="entered_object">[in,out] If non-null, the entered object.</param>
     **************************************************************************************************/
    virtual void OnEnter(Object* entered_object);

    /**************************************************************************************************
     * <summary>Executes the tick action.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="object">[in,out] If non-null, the object.</param>
     **************************************************************************************************/
    virtual void OnTick(Object* object);

    /**************************************************************************************************
     * <summary>Executes the exit action.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="exited_object">[in,out] If non-null, the exited object.</param>
     **************************************************************************************************/
    virtual void OnExit(Object* exited_object);

    /**************************************************************************************************
     * <summary>Sets a gravity.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="gravity">The gravity.</param>
     **************************************************************************************************/
    void SetGravity(const a2de::Vector2D& gravity);

    /**************************************************************************************************
     * <summary>Sets a drag coefficients.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="k1k2">The second k 1k.</param>
     **************************************************************************************************/
    void SetDragCoefficients(const a2de::Vector2D& k1k2);

protected:
    /// <summary> The gravity </summary>
    a2de::GravityForceGenerator* _gravity;
    /// <summary> The drag </summary>
    a2de::DragForceGenerator* _drag;
private:

};

A2DE_END

#endif // CPHYSICSAREA_H