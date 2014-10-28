/**************************************************************************************************
// file:	Engine\Physics\CRigidBody.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the rigid body class
 **************************************************************************************************/
#ifndef A2DE_CRIGIDBODY_H
#define A2DE_CRIGIDBODY_H

#include "../a2de_vals.h"
#include <iostream>
#include <utility>
#include "CRigidBodyState.h"

#include "../Physics/IUpdatable.h"
#include "../Physics/IBoundingBox.h"
#include "../Physics/AABB.h"
#include "../Physics/OBB.h"

A2DE_BEGIN

class StopWatch;
class Rectangle;

struct RigidBodyDef {
    RigidBodyDef() : mass(0.0),
                     gravity_mod_x(0.0),
                     gravity_mod_y(1.0),
                     position_x(0.0),
                     position_y(0.0),
                     velocity_x(0.0),
                     velocity_y(0.0),
                     restitution(1.0),
                     static_friction(0.0),
                     kinetic_friction(0.0) {
        /* DO NOTHING */
    }
    double mass;
    double gravity_mod_x;
    double gravity_mod_y;
    double position_x;
    double position_y;
    double velocity_x;
    double velocity_y;
    double restitution;
    double static_friction;
    double kinetic_friction;
};

/**************************************************************************************************
 * <summary>Rigid body.</summary>
 * <remarks>Casey Ugone, 8/3/2011.</remarks>
 **************************************************************************************************/
class RigidBody : public IUpdatable {

public:

    /// <summary>The mass equivalency tolerance. A tolerance where if the
    ///          absolute value of the difference between the mass of two bodies
    ///          is below this value then they are considered equal.
    /// </summary>
    static double MASS_EQUIVALENCY_TOLERANCE;

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 8/15/2013.</remarks>
     * <param name="body_definition">The body definition.</param>
     **************************************************************************************************/
    RigidBody(const RigidBodyDef& body_definition);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 6/14/2013.</remarks>
     * <param name="mass">            The mass.</param>
     * <param name="gravModX">        The grav modifier x coordinate.</param>
     * <param name="gravModY">        The grav modifier y coordinate.</param>
     * <param name="restitution">     The restitution.</param>
     * <param name="static_friction"> The static friction.</param>
     * <param name="kinetic_friction">The kinetic friction.</param>
     **************************************************************************************************/
    RigidBody(double mass, double gravModX, double gravModY, double restitution, double static_friction, double kinetic_friction);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 8/13/2012.</remarks>
     * <param name="mass">    The mass.</param>
     * <param name="gravMod"> The gravity coefficient modifier.</param>
     * <param name="material">The material.</param>
     **************************************************************************************************/
    RigidBody(double mass, const Vector2D& gravMod, const PhysicsMaterial& material);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 8/13/2012.</remarks>
     * <param name="mass">    The mass.</param>
     * <param name="gravModX">The gravity coefficient modifier for the x direction.</param>
     * <param name="gravModY">The gravity coefficient modifier for the y direction.</param>
     * <param name="material">The material.</param>
     **************************************************************************************************/
    RigidBody(double mass, double gravModX, double gravModY, const PhysicsMaterial& material);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the RigidBody class.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="state">The state.</param>
     **************************************************************************************************/
    RigidBody(const State& state);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the RigidBody class.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="other">The body.</param>
     **************************************************************************************************/
    RigidBody(const RigidBody& other);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    ~RigidBody();

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    RigidBody& operator=(const RigidBody& rhs);

    /**************************************************************************************************
     * <summary>Changes the tolerance that determines if two bodies are equal. See description of MASS_EQUIVALENCY_TOLERANCE.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="value">A double that describes the amount of allowable difference.</param>
     **************************************************************************************************/
    static void SetMassEquivalencyTolerance(double value);

    /**************************************************************************************************
     * <summary>Get the x coordinate position.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <returns>The x coordinate position.</returns>
     **************************************************************************************************/
    double GetXPosition() const;

    /**************************************************************************************************
     * <summary>Get x coordinate position.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The x coordinate position.</returns>
     **************************************************************************************************/
    double GetXPosition();

    /**************************************************************************************************
     * <summary>Get the y coordinate position.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <returns>The y coordinate position.</returns>
     **************************************************************************************************/
    double GetYPosition() const;

    /**************************************************************************************************
     * <summary>Get y coordinate position.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The y coordinate position.</returns>
     **************************************************************************************************/
    double GetYPosition();

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 3/10/2012.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    const Vector2D& GetPosition() const;

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    Vector2D& GetPosition();

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetPosition(double x, double y);

    /**************************************************************************************************
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPosition(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Sets the x coordinate position.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetXPosition(double x);

    /**************************************************************************************************
     * <summary>Sets the y coordinate position.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetYPosition(double y);

    /**************************************************************************************************
     * <summary>Gets the velocity in the X direction.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <returns>The x direction velocity.</returns>
     **************************************************************************************************/
    double GetXVelocity() const;

    /**************************************************************************************************
     * <summary>Get x coordinate velocity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The x coordinate velocity.</returns>
     **************************************************************************************************/
    double GetXVelocity();

    /**************************************************************************************************
     * <summary>Gets the velocity in the Y direction.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <returns>The y direction velocity.</returns>
     **************************************************************************************************/
    double GetYVelocity() const;

    /**************************************************************************************************
     * <summary>Get y coordinate velocity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The y coordinate velocity.</returns>
     **************************************************************************************************/
    double GetYVelocity();

    /**************************************************************************************************
     * <summary>Gets the velocity.</summary>
     * <remarks>Casey Ugone, 3/10/2012.</remarks>
     * <returns>The velocity.</returns>
     **************************************************************************************************/
    Vector2D GetVelocity() const;

    /**************************************************************************************************
     * <summary>Gets the velocity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The velocity.</returns>
     **************************************************************************************************/
    Vector2D GetVelocity();

    /**************************************************************************************************
     * <summary>Gets the acceleration in the X direction.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <returns>The x direction acceleration.</returns>
     **************************************************************************************************/
    double GetXAcceleration() const;

    /**************************************************************************************************
     * <summary>Get x coordinate acceleration.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The x coordinate acceleration.</returns>
     **************************************************************************************************/
    double GetXAcceleration();

    /**************************************************************************************************
     * <summary>Gets the acceleration in the Y direction.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <returns>The y direction acceleration.</returns>
     **************************************************************************************************/
    double GetYAcceleration() const;

    /**************************************************************************************************
     * <summary>Get y coordinate acceleration.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The y coordinate acceleration.</returns>
     **************************************************************************************************/
    double GetYAcceleration();

    /**************************************************************************************************
     * <summary>Gets the acceleration.</summary>
     * <remarks>Casey Ugone, 3/10/2012.</remarks>
     * <returns>The acceleration.</returns>
     **************************************************************************************************/
    Vector2D GetAcceleration() const;

    /**************************************************************************************************
     * <summary>Gets the acceleration.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The acceleration.</returns>
     **************************************************************************************************/
    Vector2D GetAcceleration();

    /**************************************************************************************************
     * <summary>Sets the velocity in the X direction.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="x">The velocity in the X direction.</param>
     **************************************************************************************************/
    void SetXVelocity(double x);

    /**************************************************************************************************
     * <summary>Sets the velocity in the Y direction.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="y">The velocity in the Y direction.</param>
     **************************************************************************************************/
    void SetYVelocity(double y);

    /**************************************************************************************************
     * <summary>Sets the velocity.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="x">The velocity in the X direction.</param>
     * <param name="y">The velocity in the Y direction.</param>
     **************************************************************************************************/
    void SetVelocity(double x, double y);

    /**************************************************************************************************
     * <summary>Sets a velocity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="velocity">The velocity.</param>
     **************************************************************************************************/
    void SetVelocity(const Vector2D& velocity);

    /**************************************************************************************************
     * <summary>Sets an acceleration.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="acceleration">The acceleration.</param>
     **************************************************************************************************/
    void SetAcceleration(const Vector2D& acceleration);

    /**************************************************************************************************
     * <summary>Sets an acceleration.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetAcceleration(double x, double y);

    /**************************************************************************************************
     * <summary>Sets an x coordinate acceleration.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetXAcceleration(double x);

    /**************************************************************************************************
     * <summary>Sets a y coordinate acceleration.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetYAcceleration(double y);

    /**************************************************************************************************
     * <summary>Get x coordinate gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The x coordinate gravity modifier.</returns>
     **************************************************************************************************/
    double GetXGravityModifier() const;

    /**************************************************************************************************
     * <summary>Get x coordinate gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The x coordinate gravity modifier.</returns>
     **************************************************************************************************/
    double GetXGravityModifier();

    /**************************************************************************************************
     * <summary>Sets an x coordinate gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetXGravityModifier(double x);

    /**************************************************************************************************
     * <summary>Get y coordinate gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The y coordinate gravity modifier.</returns>
     **************************************************************************************************/
    double GetYGravityModifier() const;

    /**************************************************************************************************
     * <summary>Get y coordinate gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The y coordinate gravity modifier.</returns>
     **************************************************************************************************/
    double GetYGravityModifier();

    /**************************************************************************************************
     * <summary>Sets a y coordinate gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetYGravityModifier(double y);

    /**************************************************************************************************
     * <summary>Gets the gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The gravity modifier.</returns>
     **************************************************************************************************/
    Vector2D GetGravityModifier() const;

    /**************************************************************************************************
     * <summary>Gets the gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The gravity modifier.</returns>
     **************************************************************************************************/
    Vector2D GetGravityModifier();

    /**************************************************************************************************
     * <summary>Sets a gravity modifier.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetGravityModifier(double x, double y);

    /**************************************************************************************************
     * <summary>Applies the force described by force.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="force">The force.</param>
     **************************************************************************************************/
    void ApplyForce(const Vector2D& force, double duration);

    /**************************************************************************************************
     * <summary>Applies the force.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void ApplyForce(double x, double y, double duration);

    /**************************************************************************************************
     * <summary>Applies the x coordinate force described by x.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void ApplyXForce(double x, double duration);

    /**************************************************************************************************
     * <summary>Applies the y coordinate force described by y.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void ApplyYForce(double y, double duration);

    /**************************************************************************************************
     * <summary>Applies the impulse described by impulse.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="impulse">The impulse.</param>
     **************************************************************************************************/
    void ApplyImpulse(const Vector2D& impulse);

    /**************************************************************************************************
     * <summary>Applies the impulse.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void ApplyImpulse(double x, double y);

    /**************************************************************************************************
     * <summary>Applies the x coordinate impulse described by x.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void ApplyXImpulse(double x);

    /**************************************************************************************************
     * <summary>Applies the y coordinate impulse described by y.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void ApplyYImpulse(double y);

    /**************************************************************************************************
     * <summary>Less-than comparison operator. A RigidBody is considered less than another if its mass is less than that of another.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    bool operator<(const RigidBody& rhs) const;

    /**************************************************************************************************
     * <summary>Greater-than comparison operator. A RigidBody is considered greater than another if its mass is greater than that of another.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than to the second.</returns>
     **************************************************************************************************/
    bool operator>(const RigidBody& rhs) const;

    /**************************************************************************************************
     * <summary>Equality operator. A RigidBody is considered equal to another if the absolute value of the difference between its mass and another is less than
     * the defined MASS_EQUIVALENCY_TOLERANCE.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const RigidBody& rhs) const;

    /**************************************************************************************************
     * <summary>Inequality operator. A RigidBody is considered not equal to another if the absolute value of the difference between its mass and another is not
     * less than the defined MASS_EQUIVALENCY_TOLERANCE.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered inequivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const RigidBody& rhs) const;

    /**************************************************************************************************
     * <summary>Less-than-or-equal comparison operator. A RigidBody is considered less than or equal to another if the absolute value of the difference between
     * its mass and another is not greater than the defined MASS_EQUIVALENCY_TOLERANCE.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator<=(const RigidBody& rhs) const;

    /**************************************************************************************************
     * <summary>Greater-than-or-equal comparison operator. A RigidBody is considered greater than or equal to another if the absolute value of the difference
     * between its mass and another is not less than the defined MASS_EQUIVALENCY_TOLERANCE.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator>=(const RigidBody& rhs) const;

    /**************************************************************************************************
     * <summary>Gets the mass.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <returns>The mass in kilograms.</returns>
     **************************************************************************************************/
    double GetMass() const;

    /**************************************************************************************************
     * <summary>Gets the mass.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The mass.</returns>
     **************************************************************************************************/
    double GetMass();

    /**************************************************************************************************
     * <summary>Sets the mass.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="mass">The mass in kilograms.</param>
     **************************************************************************************************/
    void SetMass(double mass);

    /**************************************************************************************************
     * <summary>Updates the physical properties of this object.</summary>
     * <remarks>Casey Ugone, 8/3/2011.</remarks>
     * <param name="deltaTime">Current change in time.</param>
     **************************************************************************************************/
    void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Clears the forces list.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    void ClearForces();

    /**************************************************************************************************
     * <summary>Clears the impulses list.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    void ClearImpulses();

    /**************************************************************************************************
     * <summary>Sets the physics material.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="material">The material.</param>
     **************************************************************************************************/
    void SetMaterial(const PhysicsMaterial& material);

    /**************************************************************************************************
     * <summary>Gets the restitution.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The restitution.</returns>
     **************************************************************************************************/
    double GetRestitution() const;

    /**************************************************************************************************
     * <summary>Gets the restitution.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The restitution.</returns>
     **************************************************************************************************/
    double GetRestitution();

    /**************************************************************************************************
     * <summary>Sets the restitution.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="restitution">The restitution.</param>
     **************************************************************************************************/
    void SetRestitution(double restitution);

    /**************************************************************************************************
     * <summary>Gets the friction.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The friction.</returns>
     **************************************************************************************************/
    double GetStaticFriction() const;

    /**************************************************************************************************
     * <summary>Gets the friction.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The friction.</returns>
     **************************************************************************************************/
    double GetStaticFriction();

    /**************************************************************************************************
     * <summary>Sets the friction.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="friction">The friction.</param>
     **************************************************************************************************/
    void SetStaticFriction(double friction);

    /**************************************************************************************************
     * <summary>Gets the friction.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The friction.</returns>
     **************************************************************************************************/
    double GetKineticFriction() const;

    /**************************************************************************************************
     * <summary>Gets the friction.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The friction.</returns>
     **************************************************************************************************/
    double GetKineticFriction();

    /**************************************************************************************************
     * <summary>Sets the friction.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="friction">The friction.</param>
     **************************************************************************************************/
    void SetKineticFriction(double friction);

    /**************************************************************************************************
     * <summary>Sets the bounding rectangle.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="bounding_rectangle">[in,out] If non-null, the bounding rectangle.</param>
     **************************************************************************************************/
    void SetBoundingRectangle(IBoundingBox* bounding_rectangle);

    /**************************************************************************************************
     * <summary>Gets the bounding shape.</summary>
     * <remarks>Casey Ugone, 4/24/2013.</remarks>
     * <returns>null if it fails, else the collision shape.</returns>
     **************************************************************************************************/
    const IBoundingBox* GetBoundingRectangle() const;

    /**************************************************************************************************
     * <summary>Gets the bounding shape.</summary>
     * <remarks>Casey Ugone, 4/24/2013.</remarks>
     * <returns>null if it fails, else the collision shape.</returns>
     **************************************************************************************************/
    IBoundingBox* GetBoundingRectangle();

    /**************************************************************************************************
     * <summary>Sets a collision shape.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="shape">[in,out] If non-null, the shape.</param>
     **************************************************************************************************/
    void SetCollisionShape(Shape* shape);

    /**************************************************************************************************
     * <summary>Gets the collision shape.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the collision shape.</returns>
     **************************************************************************************************/
    const Shape* GetCollisionShape() const;

    /**************************************************************************************************
     * <summary>Gets the collision shape.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the collision shape.</returns>
     **************************************************************************************************/
    Shape* GetCollisionShape();

    /**************************************************************************************************
     * <summary>Sets a damper.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="value">The value.</param>
     **************************************************************************************************/
    void SetDamper(double value);

    /**************************************************************************************************
     * <summary>Gets the damper.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The damper.</returns>
     **************************************************************************************************/
    double GetDamper() const;

    /**************************************************************************************************
     * <summary>Gets the damper.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The damper.</returns>
     **************************************************************************************************/
    double GetDamper();

    /**************************************************************************************************
     * <summary>Wakes this object.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Wake();

    /**************************************************************************************************
     * <summary>Sleeps this object.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Sleep();

    /**************************************************************************************************
     * <summary>Query if this object is active.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>true if active, false if not.</returns>
     **************************************************************************************************/
    bool IsActive() const;

    /**************************************************************************************************
     * <summary>Query if this object is active.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>true if active, false if not.</returns>
     **************************************************************************************************/
    bool IsActive();

protected:

private:
    /// <summary> The current State </summary>
    State _curState;

};

A2DE_END

#endif