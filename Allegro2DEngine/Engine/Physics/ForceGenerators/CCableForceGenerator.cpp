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

    a2de::Vector2D fbp = fb->GetPosition();
    a2de::Vector2D sbp = sb->GetPosition();

    double square_distance = (fbp - sbp).GetLengthSquared();
    double square_length = _length * _length;

    if(square_distance < square_length || a2de::Math::IsEqual(square_length, square_distance)) return;

    if(square_length < square_distance) {

        a2de::Vector2D sb_to_center = (fbp - sbp).Normalize();
        a2de::Vector2D fb_to_center = (sbp - fbp).Normalize();

        double m1 = fb->GetMass();
        double m2 = sb->GetMass();
        double mass_sum = m1 + m2;

        double m1_ratio = m1 / mass_sum;
        double m2_ratio = m2 / mass_sum;    
        
        a2de::Vector2D m1force = a2de::Vector2D::GetProjection(m1 * fb->GetAcceleration(), fb_to_center);
        a2de::Vector2D m2force = a2de::Vector2D::GetProjection(m2 * sb->GetAcceleration(), sb_to_center);

        double distance = std::sqrt(square_distance);
        double move_distance = distance - _length;

        fb->ApplyImpulse(m1force);
        sb->ApplyImpulse(m2force);
        sb->SetPosition(sbp + ((sb_to_center * move_distance * m2_ratio)));
        fb->SetPosition(fbp + ((fb_to_center * move_distance * m1_ratio)));
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