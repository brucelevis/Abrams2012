#include "CRodForceGenerator.h"

A2DE_BEGIN


RodForceGenerator::RodForceGenerator(double length) : ADTForceGenerator(), _length(length) { /* DO NOTHING */ }

RodForceGenerator::~RodForceGenerator() {
    DetachFirstEnd();
    DetachSecondEnd();
}

void RodForceGenerator::Update(double deltaTime) {
    if(a2de::Math::IsEqual(_length, 0.0)) return;
    if(_rod_ends.first == nullptr) return;
    if(_rod_ends.second == nullptr) return;

    a2de::RigidBody* fb = _rod_ends.first->GetBody();
    if(fb == nullptr) return;

    a2de::RigidBody* sb = _rod_ends.second->GetBody();
    if(sb == nullptr) return;

    a2de::Vector2D fbp = fb->GetPosition();
    a2de::Vector2D sbp = sb->GetPosition();

    double square_distance = (fbp - sbp).GetLengthSquared();
    double square_length = _length * _length;

    if(a2de::Math::IsEqual(square_length, square_distance)) return;

    double m1 = fb->GetMass();
    double m2 = sb->GetMass();

    a2de::Vector2D sb_to_center = (fbp - sbp).Normalize();
    a2de::Vector2D fb_to_center = (sbp - fbp).Normalize();

    //Update bodies to get up-to-date F=ma calculations for projection.
    fb->Update(deltaTime);
    sb->Update(deltaTime);

    a2de::Vector2D m1force = a2de::Vector2D::GetProjection(m1 * fb->GetAcceleration(), fb_to_center);
    a2de::Vector2D m2force = a2de::Vector2D::GetProjection(m2 * sb->GetAcceleration(), sb_to_center);

    double distance = std::sqrt(square_distance);
    double move_distance = distance - _length;

    fb->ApplyImpulse(m1force);
    sb->ApplyImpulse(m2force);

    double mass_sum = m1 + m2;
    double m1_ratio = m1 / mass_sum;
    double m2_ratio = m2 / mass_sum;    

    sb->SetPosition(sbp + ((sb_to_center * move_distance * m2_ratio)));
    fb->SetPosition(fbp + ((fb_to_center * move_distance * m1_ratio)));

}

void RodForceGenerator::AttachFirstEndTo(a2de::Object* body) {
    if(body == nullptr) return;
    this->_rod_ends.first = body;
}

void RodForceGenerator::AttachSecondEndTo(a2de::Object* body) {
    if(body == nullptr) return;
    this->_rod_ends.second = body;
}

void RodForceGenerator::DetachFirstEnd() {
    this->_rod_ends.first = nullptr;
}

void RodForceGenerator::DetachSecondEnd() {
    this->_rod_ends.second = nullptr;
}

A2DE_END