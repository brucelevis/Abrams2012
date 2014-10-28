/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\CDragForceGenerator.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the drag force generator class
 **************************************************************************************************/
#include "CDragForceGenerator.h"

#include "../../a2de_objects.h"
#include "../../a2de_math.h"
#include <algorithm>

A2DE_BEGIN

void DragForceGenerator::Update(double /*deltaTime*/) {

    if(_subscribers.empty()) return;
    std::for_each(_subscribers.begin(), _subscribers.end(), [&](Object* elem) {
        if(elem == nullptr) return;

        a2de::RigidBody* body = elem->GetBody();
        if(body == nullptr) return;

        Vector2D force = body->GetVelocity();

        double dragCoeff = force.GetLength();
        if(a2de::Math::IsEqual(dragCoeff, 0.0)) return;

        dragCoeff = _coefficients.first * dragCoeff + _coefficients.second * dragCoeff * dragCoeff;

        a2de::Vector2D::Normalize(force);
        force *= (-dragCoeff);
        body->ApplyForce(force, 0.0);
    });
}

DragForceGenerator::DragForceGenerator() : ADTForceGenerator(), _coefficients(0.0, 0.0) { /* DO NOTHING */ }

DragForceGenerator::DragForceGenerator(double linear_coefficient, double quadratic_coefficient) : ADTForceGenerator(), _coefficients(linear_coefficient, quadratic_coefficient) { /* DO NOTHING */ }

DragForceGenerator::DragForceGenerator(const DragForceGenerator& other) : ADTForceGenerator(other), _coefficients(other._coefficients) { /* DO NOTHING */ }

DragForceGenerator& DragForceGenerator::operator=(const DragForceGenerator& rhs) {
    if(this == &rhs) return *this;

    ADTForceGenerator::operator=(rhs);
    this->_coefficients = rhs._coefficients;

    return *this;
}

DragForceGenerator::~DragForceGenerator() {
    /* DO NOTHING */
}

void DragForceGenerator::SetLinearCoefficient(double linear_coefficient) {
    _coefficients.first = linear_coefficient;
}

double DragForceGenerator::GetLinearCoefficient() const {
    return _coefficients.first;
}

double DragForceGenerator::GetLinearCoefficient() {
    return static_cast<const DragForceGenerator&>(*this).GetLinearCoefficient();
}

void DragForceGenerator::SetQuadraticCoefficient(double quadratic_coefficient) {
    _coefficients.second = quadratic_coefficient;
}

double DragForceGenerator::GetQuadraticCoefficient() const {
    return _coefficients.second;
}

double DragForceGenerator::GetQuadraticCoefficient() {
    return static_cast<const DragForceGenerator&>(*this).GetQuadraticCoefficient();
}


A2DE_END