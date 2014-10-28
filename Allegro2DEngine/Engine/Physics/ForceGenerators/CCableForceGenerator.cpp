#include "CCableForceGenerator.h"

A2DE_BEGIN

void CableForceGenerator::Update(double /*deltaTime*/) {
    if(a2de::Math::IsEqual(_length, 0.0)) return;
    if(_cable_ends.first == nullptr) return;
    if(_cable_ends.second == nullptr) return;

    a2de::RigidBody* fb = _cable_ends.first->GetBody();
    if(fb == nullptr) return;

    a2de::RigidBody* sb = _cable_ends.second->GetBody();
    if(sb == nullptr) return;

    double square_distance = (fb->GetPosition() - sb->GetPosition()).GetLengthSquared();
    double square_length = _length * _length;

    if(square_distance < square_length || a2de::Math::IsEqual(square_length, square_distance)) return;

    a2de::Vector2D direction_away_from_sb = (fb->GetPosition() - sb->GetPosition()).Normalize();
    a2de::Vector2D direction_away_from_fb = (sb->GetPosition() - fb->GetPosition()).Normalize();

    double m1 = fb->GetMass();
    double m2 = sb->GetMass();
    double mass_sum = m1 + m2;

    double m1_ratio = m1 / mass_sum;
    double m2_ratio = m2 / mass_sum;
    
    
    a2de::Vector2D m1force;
    a2de::Vector2D m2force;
    if(square_length < square_distance) {
        double distance = std::sqrt(square_distance);
        //double move_distance = distance - _length;
        double distance_ratio = distance / _length;
        fb->ApplyForce(direction_away_from_fb * distance_ratio * m1_ratio, 0.0);
        sb->ApplyForce(direction_away_from_sb * distance_ratio * m2_ratio, 0.0);
    }

}

CableForceGenerator::CableForceGenerator(double length) :
_length(length)
{ /* DO NOTHING */ }

CableForceGenerator::~CableForceGenerator() { /* DO NOTHING */ }

void CableForceGenerator::AttachFirstEndTo(a2de::Object* body) {
    _cable_ends.first = body;
}

void CableForceGenerator::AttachSecondEndTo(a2de::Object* body) {
    _cable_ends.second = body;
}

void CableForceGenerator::DetachFirstEnd() {
    _cable_ends.first = nullptr;
}

void CableForceGenerator::DetachSecondEnd() {
    _cable_ends.second = nullptr;
}

A2DE_END