#ifndef A2DE_CRODFORCEGENERATOR_H
#define A2DE_CRODFORCEGENERATOR_H

#include "../../a2de_vals.h"

#include "ADTForceGenerator.h"

A2DE_BEGIN

class RodForceGenerator : public ADTForceGenerator {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 11/3/2014.</remarks>
     * <param name="length">The length.</param>
     **************************************************************************************************/
    RodForceGenerator(double length);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 11/3/2014.</remarks>
     **************************************************************************************************/
    virtual ~RodForceGenerator();

    /**************************************************************************************************
     * <summary>Updates the attached bodies.</summary>
     * <remarks>Casey Ugone, 10/26/2014.</remarks>
     * <param name="deltaTime">The delta time.</param>
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

    /// <summary> The length of the rod </summary>
    double _length;

    /// <summary> The bodies attached to the rod ends </summary>
    std::pair<Object*, Object*> _rod_ends;

    //RegisterBody unavailable for Rods!
    bool RegisterBody(Object* body);

    //UnregisterBody unavailable for Rods!
    void UnregisterBody(Object* body);   
};

A2DE_END

#endif // CRODFORCEGENERATOR_H
