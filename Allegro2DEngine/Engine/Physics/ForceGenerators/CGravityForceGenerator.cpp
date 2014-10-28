/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\CGravityForceGenerator.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the gravity force generator class
 **************************************************************************************************/
#include "CGravityForceGenerator.h"

#include "../../Math/CMiscMath.h"
#include "../../a2de_objects.h"
#include <algorithm>
#include <utility>

A2DE_BEGIN

    double GravityForceGenerator::DEFAULT_GRAVITY_VALUE = 9.80665;
const Vector2D GravityForceGenerator::DEFAULT_GRAVITY_VECTOR(0.0, DEFAULT_GRAVITY_VALUE);

GravityForceGenerator::GravityForceGenerator()
    : ADTForceGenerator(), _gravity(DEFAULT_GRAVITY_VECTOR) { }

GravityForceGenerator::GravityForceGenerator(double x, double y)
    : ADTForceGenerator(), _gravity(x, y) { }

GravityForceGenerator::GravityForceGenerator(const Vector2D& gravity)
    : ADTForceGenerator(), _gravity(gravity) { }

GravityForceGenerator::GravityForceGenerator(const GravityForceGenerator& other)
    : ADTForceGenerator(other), _gravity(other._gravity) { }

GravityForceGenerator::~GravityForceGenerator() {
    /* DO NOTHING */
}

GravityForceGenerator& GravityForceGenerator::operator=(const GravityForceGenerator& rhs) {
    if(this == &rhs) return *this;

    ADTForceGenerator::operator=(rhs);
    this->_gravity = rhs._gravity;

    return *this;
}


double GravityForceGenerator::GetXGravityValue() const {
    return _gravity.GetX();
}

double GravityForceGenerator::GetXGravityValue() {
    return static_cast<const GravityForceGenerator&>(*this).GetXGravityValue();
}

double GravityForceGenerator::GetYGravityValue() const {
    return _gravity.GetY();
}

double GravityForceGenerator::GetYGravityValue() {
    return static_cast<const GravityForceGenerator&>(*this).GetYGravityValue();
}

void GravityForceGenerator::SetGravity(const Vector2D& gravity) {
    _gravity = gravity;
}

void GravityForceGenerator::SetGravity(double x, double y) {
    SetGravity(Vector2D(x, y));
}

void GravityForceGenerator::SetXGravity(double x) {
    SetGravity(x, GetYGravityValue());
}

void GravityForceGenerator::SetYGravity(double y) {
    SetGravity(GetXGravityValue(), y);
}

void GravityForceGenerator::Update(double /*deltaTime*/) {

    if(_subscribers.empty()) return;

    std::for_each(_subscribers.begin(), _subscribers.end(), [&](Object* elem) {
        if(elem == nullptr) return;
        a2de::RigidBody* body = elem->GetBody();
        if(body == nullptr) return;
        body->ApplyForce(_gravity * body->GetGravityModifier() * body->GetMass(), 0.0);
    });
}

a2de::Vector2D GravityForceGenerator::GetGravityValue() const {
    return _gravity;
}

a2de::Vector2D GravityForceGenerator::GetGravityValue() {
    return static_cast<const GravityForceGenerator&>(*this).GetGravityValue();
}


A2DE_END
