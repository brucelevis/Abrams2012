/**************************************************************************************************
// file:	Engine\Physics\CContactData.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the contact data class
 **************************************************************************************************/
#ifndef A2DE_CCONTACTDATA_H
#define A2DE_CCONTACTDATA_H

#include "../a2de_vals.h"

#include "../Math/CVector2D.h"

A2DE_BEGIN

class RigidBody;

class ContactData {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="contact_point">     The contact point.</param>
     * <param name="contact_normal">    The contact normal.</param>
     * <param name="penetration_amount">The penetration amount.</param>
     * <param name="body_one">          The body one.</param>
     * <param name="body_two">          The body two.</param>
     **************************************************************************************************/
    ContactData(const a2de::Vector2D& contact_point, const a2de::Vector2D& contact_normal, double penetration_amount, a2de::RigidBody& body_one, a2de::RigidBody& body_two);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    ContactData(const ContactData& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    ContactData& operator=(const ContactData& rhs);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    ~ContactData();

    /**************************************************************************************************
     * <summary>Gets contact point.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The contact point.</returns>
     **************************************************************************************************/
    a2de::Vector2D GetContactPoint() const;

    /**************************************************************************************************
     * <summary>Gets contact point.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The contact point.</returns>
     **************************************************************************************************/
    a2de::Vector2D GetContactPoint();

    /**************************************************************************************************
     * <summary>Gets contact normal.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The contact normal.</returns>
     **************************************************************************************************/
    a2de::Vector2D GetContactNormal() const;

    /**************************************************************************************************
     * <summary>Gets contact normal.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The contact normal.</returns>
     **************************************************************************************************/
    a2de::Vector2D GetContactNormal();

    /**************************************************************************************************
     * <summary>Gets penetration amount.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The penetration amount.</returns>
     **************************************************************************************************/
    double GetPenetrationAmount() const;

    /**************************************************************************************************
     * <summary>Gets penetration amount.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The penetration amount.</returns>
     **************************************************************************************************/
    double GetPenetrationAmount();

    /**************************************************************************************************
     * <summary>Gets body one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The body one.</returns>
     **************************************************************************************************/
    const a2de::RigidBody& GetBodyOne() const;

    /**************************************************************************************************
     * <summary>Gets body one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The body one.</returns>
     **************************************************************************************************/
    a2de::RigidBody& GetBodyOne();

    /**************************************************************************************************
     * <summary>Gets body two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The body two.</returns>
     **************************************************************************************************/
    const a2de::RigidBody& GetBodyTwo() const;

    /**************************************************************************************************
     * <summary>Gets body two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The body two.</returns>
     **************************************************************************************************/
    a2de::RigidBody& GetBodyTwo();

protected:
private:

    /**************************************************************************************************
     * <summary>The contact point.</summary>
     **************************************************************************************************/
    a2de::Vector2D _contact_point;

    /**************************************************************************************************
     * <summary>The contact normal.</summary>
     **************************************************************************************************/
    a2de::Vector2D _contact_normal;

    /**************************************************************************************************
     * <summary>The penetration amount.</summary>
     **************************************************************************************************/
    double _penetration_amount;

    /**************************************************************************************************
     * <summary>The body one.</summary>
     **************************************************************************************************/
    a2de::RigidBody& _body_one;

    /**************************************************************************************************
     * <summary>The body two.</summary>
     **************************************************************************************************/
    a2de::RigidBody& _body_two;
};

A2DE_END

#endif // CCONTACTDATA_H