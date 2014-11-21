/**************************************************************************************************
// file:	Engine\Physics\CContactData.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the contact data class
 **************************************************************************************************/
#include "CContactData.h"

#include "CRigidBody.h"

A2DE_BEGIN

ContactData::ContactData(const a2de::Vector2D& contact_point, const a2de::Vector2D& contact_normal, double penetration_amount, a2de::RigidBody& body_one, a2de::RigidBody& body_two)
: _contact_point(contact_point), _contact_normal(contact_normal), _penetration_amount(penetration_amount), _body_one(body_one), _body_two(body_two)
{
    /* DO NOTHING */
}

ContactData::ContactData(const ContactData& other)
: _contact_point(other._contact_point), _contact_normal(other._contact_normal), _penetration_amount(other._penetration_amount), _body_one(other._body_one), _body_two(other._body_two) {
    /* DO NOTHING */
}

ContactData& ContactData::operator=(const ContactData& rhs) {
    if(this == &rhs) return *this;

    this->_contact_point = rhs._contact_point;
    this->_contact_normal = rhs._contact_normal;
    this->_penetration_amount = rhs._penetration_amount;
    this->_body_one = rhs._body_one;
    this->_body_two = rhs._body_two;

    return *this;
}

ContactData::~ContactData() {
    /* DO NOTHING */
}

a2de::Vector2D ContactData::GetContactPoint() const {
    return _contact_point;
}

a2de::Vector2D ContactData::GetContactPoint() {
    return static_cast<const ContactData&>(*this).GetContactPoint();
}

a2de::Vector2D ContactData::GetContactNormal() const {
    return _contact_normal;
}

a2de::Vector2D ContactData::GetContactNormal() {
    return static_cast<const ContactData&>(*this).GetContactNormal();
}

double ContactData::GetPenetrationAmount() const {
    return _penetration_amount;
}

double ContactData::GetPenetrationAmount() {
    return static_cast<const ContactData&>(*this).GetPenetrationAmount();
}

const a2de::RigidBody& ContactData::GetBodyOne() const {
    return _body_one;
}

a2de::RigidBody& ContactData::GetBodyOne() {
    return const_cast<a2de::RigidBody&>(static_cast<const ContactData&>(*this).GetBodyOne());
}

const a2de::RigidBody& ContactData::GetBodyTwo() const {
    return _body_two;
}

a2de::RigidBody& ContactData::GetBodyTwo() {
    return const_cast<a2de::RigidBody&>(static_cast<const ContactData&>(*this).GetBodyTwo());
}

A2DE_END