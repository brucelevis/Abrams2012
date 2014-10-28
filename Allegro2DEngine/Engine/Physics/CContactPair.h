/**************************************************************************************************
// file:	Engine\Physics\CContactPair.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the contact pair class
 **************************************************************************************************/
#ifndef CCONTACTPAIR_H
#define CCONTACTPAIR_H

#include "../a2de_vals.h"
#include <utility>
#include "CWorld.h"

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Contact pair. </summary>
 * <remarks>Casey Ugone, 5/8/2013.</remarks>
 **************************************************************************************************/
class RigidBody;

/**************************************************************************************************
 * <summary>Contact pair. </summary>
 * <remarks>Casey Ugone, 5/8/2013.</remarks>
 **************************************************************************************************/
class ContactPair {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="contactA">[in,out] If non-null, the contact a.</param>
     * <param name="contactB">[in,out] If non-null, the contact b.</param>
     **************************************************************************************************/
    ContactPair(a2de::RigidBody* contactA, a2de::RigidBody* contactB);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    ContactPair(const ContactPair& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    ContactPair& operator=(const ContactPair& rhs);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     **************************************************************************************************/
    ~ContactPair();
    
    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const ContactPair& rhs) const;

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     **************************************************************************************************/
    bool operator!=(const ContactPair& rhs) const;

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const ContactPair& rhs);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     **************************************************************************************************/
    bool operator!=(const ContactPair& rhs);

    /**************************************************************************************************
     * <summary>Less-than comparison operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    bool operator<(const ContactPair& rhs);

    /**************************************************************************************************
     * <summary>Less-than comparison operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="lhs">The first instance to compare.</param>
     * <param name="rhs">The second instance to compare.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    friend bool operator<(const ContactPair& lhs, const ContactPair& rhs);

    /**************************************************************************************************
     * <summary>Gets the first body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the first body.</returns>
     **************************************************************************************************/
    const a2de::RigidBody* GetFirstBody() const;

    /**************************************************************************************************
     * <summary>Gets the first body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the first body.</returns>
     **************************************************************************************************/
    a2de::RigidBody* GetFirstBody();

    /**************************************************************************************************
     * <summary>Gets the second body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the second body.</returns>
     **************************************************************************************************/
    const a2de::RigidBody* GetSecondBody() const;

    /**************************************************************************************************
     * <summary>Gets the second body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the second body.</returns>
     **************************************************************************************************/
    a2de::RigidBody* GetSecondBody();

protected:
private:
    /// <summary> The contacts </summary>
    std::pair<a2de::RigidBody*, a2de::RigidBody*> _contacts;

    /// <summary>World Class</summary>
    friend a2de::World;
};

A2DE_END

#endif // CCONTACTPAIR_H