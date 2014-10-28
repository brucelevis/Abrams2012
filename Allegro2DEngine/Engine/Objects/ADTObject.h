/************************************************************************/
/* DISABLE VS2010 and earlier bug                                       */
/************************************************************************/
#if defined(_MSC_VER) && (_MSC_VER <= 1600)
#  pragma warning(disable:4505)
#endif
/**************************************************************************************************
// file:	Engine\Objects\ADTObject.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the adt object class
 **************************************************************************************************/
#ifndef A2DE_ADTOBJECT_H
#define A2DE_ADTOBJECT_H

#include "../a2de_vals.h"
#include "../Physics/CRigidBody.h"
#include "../Physics/IUpdatable.h"
#include "../GFX/IDrawable.h"

A2DE_BEGIN

class Object : public IUpdatable, public IDrawable {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    Object();

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Object(const Object& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Object& operator=(const Object& rhs);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~Object() =0;

    /**************************************************************************************************
     * <summary>Updates the object given the time between frames.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="deltaTime">The time between frames.</param>
     **************************************************************************************************/
    virtual void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Sets the rigidbody given a definition.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="body">The body definition to use.</param>
     **************************************************************************************************/
    virtual void SetBody(const a2de::RigidBodyDef& body);

    /**************************************************************************************************
     * <summary>Gets the body.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the body.</returns>
     **************************************************************************************************/
    virtual const a2de::RigidBody* GetBody() const;

    /**************************************************************************************************
     * <summary>Gets the body.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the body.</returns>
     **************************************************************************************************/
    virtual a2de::RigidBody* GetBody();

    /**************************************************************************************************
     * <summary>Draws the body given a destination.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="dest">[in,out] If non-null, destination for the.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest);


protected:
private:
};

A2DE_END

#endif