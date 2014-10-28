/**************************************************************************************************
// file:	Engine\Physics\CRigidBody.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the rigid body class
 **************************************************************************************************/
#include "CRigidBody.h"

#include <cmath>
#include <numeric>
#include "../Math/CPoint.h"
#include "../Math/CRectangle.h"
#include "../Time/CStopwatch.h"
#include "../Math/CMiscMath.h"

A2DE_BEGIN

double RigidBody::MASS_EQUIVALENCY_TOLERANCE = 0.0001;

RigidBody::RigidBody(double mass, double gravModX, double gravModY, double restitution, double static_friction, double kinetic_friction)
 : _curState(mass, Vector2D(gravModX, gravModY), Vector2D(0.0, 0.0), Vector2D(0.0, 0.0), restitution, static_friction, kinetic_friction) { }

RigidBody::RigidBody(double mass, const Vector2D& gravMod, const PhysicsMaterial& material)
 : _curState(mass, gravMod, Vector2D(0.0, 0.0), Vector2D(0.0, 0.0), material.GetRestitution(), material.GetStaticFriction(), material.GetKineticFriction()) { }

RigidBody::RigidBody(double mass, double gravModX, double gravModY, const PhysicsMaterial& material)
 : _curState(mass, Vector2D(gravModX, gravModY), Vector2D(0.0, 0.0), Vector2D(0.0, 0.0), material.GetRestitution(), material.GetStaticFriction(), material.GetKineticFriction()) { }

RigidBody::RigidBody(const State& state) 
 : _curState(state) { }

RigidBody::RigidBody(const RigidBody& other)
 : _curState(other._curState) { }

RigidBody::RigidBody(const RigidBodyDef& body_definition)
: _curState(body_definition.mass,
  Vector2D(body_definition.gravity_mod_x, body_definition.gravity_mod_y),
  Vector2D(body_definition.position_x, body_definition.position_y),
  Vector2D(body_definition.velocity_x, body_definition.velocity_y),
  body_definition.restitution,
  body_definition.static_friction,
  body_definition.kinetic_friction) {
    /* DO NOTHING */
}

RigidBody::~RigidBody() {
    /* DO NOTHING */
}

RigidBody& RigidBody::operator=(const RigidBody& rhs) {
    if(this == &rhs) return *this;
    this->_curState = rhs._curState;
    return *this;
}

void RigidBody::SetMassEquivalencyTolerance(double value) {
    if(value < 0.0) value = 0.0;
    MASS_EQUIVALENCY_TOLERANCE = value;
}

double RigidBody::GetMass() const {
    return _curState.GetMass();
}
double RigidBody::GetMass() {
    return static_cast<const RigidBody&>(*this).GetMass();
}
void RigidBody::SetMass(double mass) {
    _curState.SetMass(mass);
}

double RigidBody::GetXPosition() const {
    return _curState.GetXPosition();
}

double RigidBody::GetXPosition() {
    return static_cast<const RigidBody&>(*this).GetXPosition();
}
void RigidBody::SetXPosition(double x) {
    SetPosition(x, GetYPosition());
}

double RigidBody::GetYPosition() const {
    return _curState.GetYPosition();
}
double RigidBody::GetYPosition() {
    return static_cast<const RigidBody&>(*this).GetYPosition();
}
void RigidBody::SetYPosition(double y) {
    SetPosition(GetXPosition(), y);
}

double RigidBody::GetXVelocity() const {
    return _curState.GetXVelocity();
}
double RigidBody::GetXVelocity() {
    return static_cast<const RigidBody&>(*this).GetXVelocity();
}
void RigidBody::SetXVelocity(double x) {
    SetVelocity(x, GetYVelocity());
}

double RigidBody::GetYVelocity() const {
    return _curState.GetYVelocity();
}
double RigidBody::GetYVelocity() {
    return static_cast<const RigidBody&>(*this).GetYVelocity();
}
void RigidBody::SetYVelocity(double y) {
    SetVelocity(GetXVelocity(), y);
}

void RigidBody::SetVelocity(double x, double y) {
    this->SetVelocity(Vector2D(x, y));
}

void RigidBody::SetVelocity(const Vector2D& velocity) {
    _curState.SetVelocity(velocity);
}

double RigidBody::GetXGravityModifier() const {
    return _curState.GetXGravityModifier();
}
double RigidBody::GetXGravityModifier() {
    return static_cast<const RigidBody&>(*this).GetXGravityModifier();
}
void RigidBody::SetXGravityModifier(double xModifier) {
    SetGravityModifier(xModifier, GetYGravityModifier());
}

double RigidBody::GetYGravityModifier() const {
    return _curState.GetYGravityModifier();
}
double RigidBody::GetYGravityModifier() {
    return static_cast<const RigidBody&>(*this).GetYGravityModifier();
}
void RigidBody::SetYGravityModifier(double y) {
    SetGravityModifier(GetXGravityModifier(), y);
}

void RigidBody::SetGravityModifier(double x, double y) {
    _curState.SetGravityModifier(x, y);
}

bool RigidBody::operator<(const RigidBody& rhs) const {
    return (this->_curState.GetMass() < rhs._curState.GetMass());
}
bool RigidBody::operator>(const RigidBody& rhs) const {
    return (this->_curState.GetMass() > rhs._curState.GetMass());
}
bool RigidBody::operator==(const RigidBody& rhs) const {
    return (Math::IsEqual(this->_curState.GetMass() - rhs._curState.GetMass(), RigidBody::MASS_EQUIVALENCY_TOLERANCE));
}

bool RigidBody::operator<=(const RigidBody& rhs) const {
    return !(*this > rhs);
}
bool RigidBody::operator>=(const RigidBody& rhs) const {
    return !(*this < rhs);
}
bool RigidBody::operator!=(const RigidBody& rhs) const {
    return !(*this == rhs);
}

double RigidBody::GetXAcceleration() const {
    return _curState.GetXAcceleration();
}
double RigidBody::GetXAcceleration() {
    return static_cast<const RigidBody&>(*this).GetXAcceleration();
}

double RigidBody::GetYAcceleration() const {
    return _curState.GetYAcceleration();
}
double RigidBody::GetYAcceleration() {
    return static_cast<const RigidBody&>(*this).GetYAcceleration();
}

void RigidBody::Update(double deltaTime) {
    _curState.Update(deltaTime);    
}

const Vector2D& RigidBody::GetPosition() const {
    return this->_curState.GetPosition();
}

Vector2D& RigidBody::GetPosition() {
    return const_cast<a2de::Vector2D&>(static_cast<const RigidBody&>(*this).GetPosition());
}

void a2de::RigidBody::SetPosition(const Vector2D& position) {
    _curState.SetPosition(position);
}

void RigidBody::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}

Vector2D RigidBody::GetVelocity() const {
    return _curState.GetVelocity();
}

Vector2D RigidBody::GetVelocity() {
    return static_cast<const RigidBody&>(*this).GetVelocity();
}

Vector2D RigidBody::GetAcceleration() const {
    return _curState.GetAcceleration();
}

Vector2D RigidBody::GetAcceleration() {
    return static_cast<const RigidBody&>(*this).GetAcceleration();
}

void RigidBody::SetAcceleration(const Vector2D& acceleration) {
    _curState.SetAcceleration(acceleration);
}
void RigidBody::SetAcceleration(double x, double y) {
    SetAcceleration(Vector2D(x, y));
}
void RigidBody::SetXAcceleration(double x) {
    SetAcceleration(x, GetYAcceleration());
}
void RigidBody::SetYAcceleration(double y) {
    SetAcceleration(GetXAcceleration(), y);
}

Vector2D RigidBody::GetGravityModifier() const {
    return _curState.GetGravityModifier();
}

Vector2D RigidBody::GetGravityModifier() {
    return static_cast<const RigidBody&>(*this).GetGravityModifier();
}

void RigidBody::ApplyForce(const Vector2D& force, double duration) {
    _curState.ApplyForce(force, duration);
}
void RigidBody::ApplyForce(double x, double y, double duration) { ApplyForce(Vector2D(x, y), duration); }
void RigidBody::ApplyXForce(double x, double duration) { ApplyForce(x, 0.0, duration); }
void RigidBody::ApplyYForce(double y, double duration) { ApplyForce(0.0, y, duration); }

void RigidBody::ApplyImpulse(const Vector2D& impulse) {
    _curState.ApplyImpulse(impulse);
}
void RigidBody::ApplyImpulse(double x, double y) { ApplyImpulse(Vector2D(x, y)); }
void RigidBody::ApplyXImpulse(double x) { ApplyImpulse(x, 0.0); }
void RigidBody::ApplyYImpulse(double y) { ApplyImpulse(0.0, y); }

void RigidBody::ClearForces() {
    _curState.ClearForces();
}

void RigidBody::ClearImpulses() {
    _curState.ClearImpulses();
}

double RigidBody::GetRestitution() const {
    return _curState.GetRestitution();
}

double RigidBody::GetRestitution(){
    return static_cast<const RigidBody&>(*this).GetRestitution();
}

void RigidBody::SetRestitution(double restitution) {
    _curState.SetRestitution(restitution);
}

double RigidBody::GetStaticFriction() const{
    return _curState.GetStaticFriction();
}

double RigidBody::GetStaticFriction() {
    return static_cast<const RigidBody&>(*this).GetStaticFriction();
}

void RigidBody::SetStaticFriction(double friction) {
    _curState.SetStaticFriction(friction);
}

double RigidBody::GetKineticFriction() const {
    return _curState.GetKineticFriction();
}

double RigidBody::GetKineticFriction() {
    return static_cast<const RigidBody&>(*this).GetKineticFriction();
}

void RigidBody::SetKineticFriction(double friction) {
    _curState.SetKineticFriction(friction);
}

void RigidBody::SetMaterial(const PhysicsMaterial& material) {
    _curState.SetMaterial(material);
}

const IBoundingBox* RigidBody::GetBoundingRectangle() const {
    return _curState.GetBoundingRectangle();
}

IBoundingBox* RigidBody::GetBoundingRectangle(){
    return const_cast<IBoundingBox*>(static_cast<const RigidBody&>(*this).GetBoundingRectangle());
}

void RigidBody::SetBoundingRectangle(IBoundingBox* bounding_rectangle) {
    _curState.SetBoundingRectangle(bounding_rectangle);
}

Shape* RigidBody::GetCollisionShape() {
    return const_cast<Shape*>(static_cast<const RigidBody&>(*this).GetCollisionShape());
}

const Shape* RigidBody::GetCollisionShape() const {
    return _curState.GetCollisionShape();
}

void RigidBody::SetCollisionShape(Shape* shape) {
    _curState.SetCollisionShape(shape);
    _curState._density = _curState.CalculateDensity();
}

void RigidBody::SetDamper(double value) {
    _curState.SetDamper(value);
}

double RigidBody::GetDamper() const {
    return _curState.GetDamper();
}

double RigidBody::GetDamper() {
    return static_cast<const RigidBody&>(*this).GetDamper();
}

void RigidBody::Wake() {
    _curState.Wake();
}

void RigidBody::Sleep() {
    _curState.Sleep();
}

bool RigidBody::IsActive() const {
    return _curState.IsActive();
}

bool RigidBody::IsActive() {
    return static_cast<const RigidBody&>(*this).IsActive();
}


A2DE_END