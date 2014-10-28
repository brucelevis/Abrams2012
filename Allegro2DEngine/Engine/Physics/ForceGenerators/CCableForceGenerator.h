#ifndef A2DE_CCABLEFORCEGENERATOR_H
#define A2DE_CCABLEFORCEGENERATOR_H

#include "../../a2de_vals.h"
#include "ADTForceGenerator.h"

A2DE_BEGIN

class CableForceGenerator : public ADTForceGenerator {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/26/2014.</remarks>
     **************************************************************************************************/
    CableForceGenerator(double length);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/26/2014.</remarks>
     **************************************************************************************************/
    virtual ~CableForceGenerator();

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

    /// <summary> The length of the cable </summary>
    double _length;

    /// <summary> The bodies attached to the cable ends </summary>
    std::pair<Object*, Object*> _cable_ends;

    //RegisterBody unavailable for Cables!
    bool RegisterBody(Object* body);

    //UnregisterBody unavailable for Cables!
    void UnregisterBody(Object* body);
};

A2DE_END

#endif // CCABLEFORCEGENERATOR_H
