/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\CSpringForceGenerator.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the spring force generator class
 **************************************************************************************************/
#ifndef A2DE_CSPRINGFORCEGENERATOR_H
#define A2DE_CSPRINGFORCEGENERATOR_H

#include "../../a2de_vals.h"
#include "../../Math/CVector2D.h"
#include <utility>

#include "ADTForceGenerator.h"

A2DE_BEGIN


class Object;

class SpringForceGenerator : public ADTForceGenerator {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    SpringForceGenerator();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="k">The spring constant.</param>
     **************************************************************************************************/
    SpringForceGenerator(double k);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="k">          The spring constant.</param>
     * <param name="rest_length">The rest length of the spring in meters.</param>
     **************************************************************************************************/
    SpringForceGenerator(double k, double rest_length);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 6/18/2013.</remarks>
     * <param name="k">                 The spring constant.</param>
     * <param name="rest_length">       The rest length of the spring in meters.</param>
     * <param name="compression_length">The minimum length of the spring at full compression in meters.</param>
     **************************************************************************************************/
    SpringForceGenerator(double k, double rest_length, double compression_length);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    virtual ~SpringForceGenerator();
    
    /**************************************************************************************************
     * <summary>Updates the bodies attached.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    virtual void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Attach first end to a body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="body">[in,out] If non-null, the body to attach.</param>
     **************************************************************************************************/
    void AttachFirstEndTo(a2de::Object* body);

    /**************************************************************************************************
     * <summary>Attach second end to a body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="body">[in,out] If non-null, the body.</param>
     **************************************************************************************************/
    void AttachSecondEndTo(a2de::Object* body);

    /**************************************************************************************************
     * <summary>Detach first end.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    void DetachFirstEnd();

    /**************************************************************************************************
     * <summary>Detach second end.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    void DetachSecondEnd();


protected:
private:
    /// <summary> The stiffness constant value.</summary>
    double _k;
    /// <summary> The rest length of the spring </summary>
    double _rest_length;
    /// <summary> The minimum length of the spring at maximum compression. </summary>
    double _compression_length;
    /// <summary> The bodies attached to the spring ends </summary>
    std::pair<Object*, Object*> _spring_ends;

    //RegisterBody unavailable for Springs!
    bool RegisterBody(Object* body);

    //UnregisterBody unavailable for Springs!
    void UnregisterBody(Object* body);
};

A2DE_END

#endif // CSPRINGFORCEGENERATOR_H
