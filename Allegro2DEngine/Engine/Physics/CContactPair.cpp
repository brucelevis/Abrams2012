/**************************************************************************************************
// file:	Engine\Physics\CContactPair.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the contact pair class
 **************************************************************************************************/
#include "CContactPair.h"

#include "CRigidBody.h"

A2DE_BEGIN

ContactPair::ContactPair(a2de::RigidBody* contactA, a2de::RigidBody* contactB) : _contacts(contactA, contactB) {
    /* DO NOTHING */
}

ContactPair::ContactPair(const ContactPair& other) : _contacts(other._contacts) {
    /* DO NOTHING */
}

ContactPair& ContactPair::operator=(const ContactPair& rhs) {
    if(this == &rhs) return *this;

    this->_contacts.first = rhs._contacts.first;
    this->_contacts.second = rhs._contacts.second;

    return *this;
}

ContactPair::~ContactPair() {
    _contacts.first = nullptr;
    _contacts.second = nullptr;
}

bool ContactPair::operator==(const ContactPair& rhs) const {
    if(this == &rhs) return true;

    bool is_equal = (this->_contacts.first == rhs._contacts.first && this->_contacts.second == rhs._contacts.second);
    bool is_inverse = (this->_contacts.second == rhs._contacts.first && this->_contacts.first == rhs._contacts.second);

    return (is_equal || is_inverse);
}

bool ContactPair::operator!=(const ContactPair& rhs) const {
    return !(*this == rhs);
}

bool ContactPair::operator==(const ContactPair& rhs) {
    return static_cast<const ContactPair&>(*this).operator==(rhs);
}

bool ContactPair::operator!=(const ContactPair& rhs) {
    return static_cast<const ContactPair&>(*this).operator!=(rhs);
}

bool ContactPair::operator<(const ContactPair& rhs) {
    return this->_contacts < rhs._contacts;
}
bool operator<(const ContactPair& lhs, const ContactPair& rhs) {
    return const_cast<ContactPair&>(lhs).operator<(rhs);
}

const a2de::RigidBody* ContactPair::GetFirstBody() const {
    return _contacts.first;
}

a2de::RigidBody* ContactPair::GetFirstBody() {
    return const_cast<a2de::RigidBody*>(static_cast<const ContactPair&>(*this).GetFirstBody());
}

const a2de::RigidBody* ContactPair::GetSecondBody() const {
    return _contacts.second;
}

a2de::RigidBody* ContactPair::GetSecondBody() {
    return const_cast<a2de::RigidBody*>(static_cast<const ContactPair&>(*this).GetSecondBody());
}


A2DE_END