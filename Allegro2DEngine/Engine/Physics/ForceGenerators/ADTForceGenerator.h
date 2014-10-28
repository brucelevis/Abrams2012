/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\ADTForceGenerator.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the adt force generator class
 **************************************************************************************************/
#ifndef A2DE_ADTFORCEGENERATOR_H
#define A2DE_ADTFORCEGENERATOR_H

#include <list>

#include "../../a2de_vals.h"
#include "../../a2de_objects.h"


A2DE_BEGIN

class Object;

class ADTForceGenerator : public Object {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    ADTForceGenerator();

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    ADTForceGenerator(const ADTForceGenerator& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    ADTForceGenerator& operator=(const ADTForceGenerator& rhs);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    virtual ~ADTForceGenerator();

    /**************************************************************************************************
     * <summary>Registers the body described by body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="body">[in,out] If non-null, the body.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RegisterBody(Object* body);

    /**************************************************************************************************
     * <summary>Unregisters the body described by body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="body">[in,out] If non-null, the body.</param>
     **************************************************************************************************/
    void UnregisterBody(Object* body);

    /**************************************************************************************************
     * <summary>Updates all registered bodies by deltaTime.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    virtual void Update(double deltaTime)=0;

protected:
    /// <summary> The subscribers </summary>
    std::list<Object*> _subscribers;
private:
    
};

A2DE_END

#endif // IFORCEGENERATOR_H