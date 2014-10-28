/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\CSpringForceGenerator.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the spring force generator class
 **************************************************************************************************/
#include "CSpringForceGenerator.h"

#include "../../a2de_objects.h"
#include "../../Math/CMiscMath.h"

#include <algorithm>

A2DE_BEGIN

void SpringForceGenerator::Update(double /*deltaTime*/) {

    if(_spring_ends.first == nullptr || _spring_ends.second == nullptr) return;
    a2de::RigidBody* first_body = _spring_ends.first->GetBody();
    a2de::RigidBody* second_body = _spring_ends.second->GetBody();
    if(first_body == nullptr || second_body == nullptr) return;

    a2de::Vector2D left_direction(first_body->GetPosition() - second_body->GetPosition());
    a2de::Vector2D right_direction(second_body->GetPosition() - first_body->GetPosition());

    double left_magnitude = left_direction.GetLength();
    if(a2de::Math::IsEqual(std::abs(left_magnitude), _rest_length) == false) {
        double current_compression = left_magnitude - _rest_length;
        if(current_compression <= -_compression_length) current_compression = -_compression_length;
        left_magnitude = _k * current_compression;
        a2de::Vector2D::Normalize(left_direction);
    }

    double right_magnitude = right_direction.GetLength();
    if(a2de::Math::IsEqual(std::abs(right_magnitude),_rest_length) == false) {
        double current_compression = right_magnitude - _rest_length;
        if(current_compression <= -_compression_length) current_compression = -_compression_length;
        right_magnitude = _k * current_compression;
        a2de::Vector2D::Normalize(right_direction);
    }

    //Apply Right Force to Left Object.
    first_body->ApplyImpulse(right_direction * right_magnitude);
    //Apply Left Force to Right Object.
    second_body->ApplyImpulse(left_direction * left_magnitude);

}

SpringForceGenerator::SpringForceGenerator() : ADTForceGenerator(), _k(0.0), _rest_length(0.0), _compression_length(0.0), _spring_ends(nullptr, nullptr) { /* DO NOTHING */ }

SpringForceGenerator::SpringForceGenerator(double k) : ADTForceGenerator(), _k(k), _rest_length(0.0), _compression_length(0.0), _spring_ends(nullptr, nullptr) { /* DO NOTHING */ }

SpringForceGenerator::SpringForceGenerator(double k, double rest_length) : ADTForceGenerator(), _k(k), _rest_length(rest_length), _compression_length(0.0), _spring_ends(nullptr, nullptr) { /* DO NOTHING */ }

SpringForceGenerator::SpringForceGenerator(double k, double rest_length, double compression_length) : ADTForceGenerator(), _k(k), _rest_length(rest_length), _compression_length(compression_length), _spring_ends(nullptr, nullptr) { /* DO NOTHING */ }

SpringForceGenerator::~SpringForceGenerator() {
    /* DO NOTHING */
}

void SpringForceGenerator::AttachFirstEndTo(a2de::Object* body) {
    if(body == nullptr) return;
    _spring_ends.first = body;
}

void SpringForceGenerator::AttachSecondEndTo(a2de::Object* body) {
    if(body == nullptr) return;
    _spring_ends.second = body;
}

void SpringForceGenerator::DetachFirstEnd() {
    _spring_ends.first = nullptr;
}

void SpringForceGenerator::DetachSecondEnd() {
    _spring_ends.second = nullptr;
}



A2DE_END