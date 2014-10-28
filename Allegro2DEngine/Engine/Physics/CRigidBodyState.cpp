/**************************************************************************************************
// file:	Engine\Physics\CRigidBodyState.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the rigid body state class
 **************************************************************************************************/
#include "CRigidBodyState.h"

#include "../Math/CMiscMath.h"
#include <numeric>
#include <algorithm>
#include "../Math/CShape.h"
#include <string>
#include <cassert>

#include "../a2de_exceptions.h"

#include "../Math/CArc.h"
#include "../Math/CCircle.h"
#include "../Math/CEllipse.h"
#include "../Math/CLine.h"
#include "../Math/CPoint.h"
#include "../Math/CPolygon.h"
#include "../Math/CRectangle.h"
#include "../Math/CSector.h"
#include "../Math/CSpline.h"
#include "../Math/CTriangle.h"
#include "../Math/CShape.h"

#include "IBoundingBox.h"
#include "AABB.h"
#include "OBB.h"

A2DE_BEGIN

const double State::DEFAULT_DAMPER_VALUE = 0.9999;

State::State(double mass, const Vector2D& gravMod, const Vector2D& position, const Vector2D& velocity, double restitution, double static_friction, double kinetic_friction)
     : _mass(mass), _gravMod(gravMod), _position(position), _velocity(velocity), _acceleration(0.0, 0.0), _forces(), _impulses(), _active(false), _mat(restitution, static_friction, kinetic_friction), _bounding_rectangle(nullptr), _collision_shape(nullptr), _density(), _damper(DEFAULT_DAMPER_VALUE) {
    SetBoundingRectangle(_bounding_rectangle);
    SetCollisionShape(_collision_shape);
    _density = CalculateDensity();
}

State::State(const State& other)
     : _mass(other._mass), _gravMod(other._gravMod), _position(other._position), _velocity(other._velocity), _acceleration(other._acceleration), _forces(other._forces), _impulses(other._impulses), _active(other._active), _mat(other._mat), _bounding_rectangle(nullptr), _collision_shape(nullptr), _density(), _damper(DEFAULT_DAMPER_VALUE) {
    SetBoundingRectangle(other._bounding_rectangle);
    SetCollisionShape(other._collision_shape);
    _density = CalculateDensity();
}

State& State::operator=(const State& rhs) {
    if(this == &rhs) return *this;

    this->_mass = rhs._mass;
    this->_gravMod = rhs._gravMod;
    this->_position = rhs._position;
    this->_velocity = rhs._velocity;
    this->_acceleration = rhs._acceleration;
    this->_forces = rhs._forces;
    this->_impulses = rhs._impulses;
    this->_active = rhs._active;
    this->_mat = rhs._mat;
    SetBoundingRectangle(rhs._bounding_rectangle);
    SetCollisionShape(rhs._collision_shape);
    this->_density = CalculateDensity();
    this->_damper = rhs._damper;
    return *this;
}

double State::GetMass() const { return _mass; }
double State::GetMass() { return static_cast<const State&>(*this).GetMass(); }

void State::SetMass(double mass) {
    this->_mass = mass;
    this->_density = CalculateDensity();
}

Vector2D State::GetGravityModifier() const { return _gravMod; }
Vector2D State::GetGravityModifier() { return static_cast<const State&>(*this).GetGravityModifier(); }

double State::GetXGravityModifier() const { return _gravMod.GetX(); }
double State::GetXGravityModifier() { return static_cast<const State&>(*this).GetXGravityModifier(); }

double State::GetYGravityModifier() const { return _gravMod.GetY(); }
double State::GetYGravityModifier() { return static_cast<const State&>(*this).GetYGravityModifier(); }

void State::SetGravityModifier(const Vector2D& gravity_modifier) { _gravMod = gravity_modifier; }
void State::SetGravityModifier(double x, double y) { SetGravityModifier(Vector2D(x, y)); }

const Vector2D& State::GetPosition() const { return _position; }
Vector2D& State::GetPosition() { return const_cast<a2de::Vector2D&>(static_cast<const State&>(*this).GetPosition()); }

double State::GetXPosition() const { return _position.GetX(); }
double State::GetXPosition() { return static_cast<const State&>(*this).GetXPosition(); }
void State::SetXPosition(double x) { SetPosition(x, GetYPosition()); }

double State::GetYPosition() const { return _position.GetY(); }
double State::GetYPosition() { return static_cast<const State&>(*this).GetYPosition(); }
void State::SetYPosition(double y) { SetPosition(GetXPosition(), y); }

void State::SetPosition( double x, double y ) { SetPosition(Vector2D(x, y)); }
void a2de::State::SetPosition(const Vector2D& position) {
    this->_position = position;
    if(_bounding_rectangle) _bounding_rectangle->GetTransform().SetPosition(_position);
    if(_collision_shape) _collision_shape->SetPosition(position);
}

Vector2D State::GetVelocity() const { return _velocity; }
Vector2D State::GetVelocity() { return static_cast<const State&>(*this).GetVelocity(); }

double State::GetXVelocity() const { return _velocity.GetX(); }
double State::GetXVelocity() { return static_cast<const State&>(*this).GetXVelocity(); }
void State::SetXVelocity( double x ) { SetVelocity(x, GetYVelocity()); }

double State::GetYVelocity() const { return _velocity.GetY(); }
double State::GetYVelocity() { return static_cast<const State&>(*this).GetYVelocity(); }
void State::SetYVelocity(double y) { SetVelocity(GetXVelocity(), y); }

void State::SetVelocity(double x, double y) { SetVelocity(Vector2D(x, y)); }
void State::SetVelocity(const Vector2D& velocity) { _velocity = velocity; }

a2de::Vector2D State::GetAcceleration() const { return _acceleration; }
a2de::Vector2D State::GetAcceleration() { return static_cast<const State&>(*this).GetAcceleration(); }

double State::GetXAcceleration() const { return _acceleration.GetX(); }
double State::GetXAcceleration() { return static_cast<const State&>(*this).GetXAcceleration(); }
void State::SetXAcceleration(double x) { SetAcceleration(x, _acceleration.GetY()); }

double State::GetYAcceleration() const { return _acceleration.GetY(); }
double State::GetYAcceleration() { return static_cast<const State&>(*this).GetYAcceleration(); }
void State::SetYAcceleration(double y) { SetAcceleration(_acceleration.GetX(), y); }

void State::SetAcceleration(const Vector2D& acceleration) { _acceleration = acceleration; }
void State::SetAcceleration(double x, double y) { SetAcceleration(Vector2D(x, y)); }

void State::ApplyForce(const Vector2D& force, double duration) {
    if(duration < 0.0) return;
    _forces.push_back(std::make_pair(force, duration));
}
void State::ApplyForce(double x, double y, double duration) { ApplyForce(Vector2D(x, y), duration); }
void State::ApplyXForce(double x, double duration) { ApplyForce(x, 0.0, duration); }
void State::ApplyYForce(double y, double duration) { ApplyForce(0.0, y, duration); }

void State::ApplyImpulse(const Vector2D& impulse) {
    _impulses.push_back(impulse);
}
void State::ApplyImpulse(double x, double y) { ApplyImpulse(Vector2D(x, y)); }
void State::ApplyXImpulse(double x) { ApplyImpulse(x, 0.0); }
void State::ApplyYImpulse(double y) { ApplyImpulse(0.0, y); }

void State::ClearForces() {
    _forces.clear();
}

void State::ClearImpulses() {
    _impulses.clear();
}

bool State::IsActive() const {
    return _active;
}

bool State::IsActive() {
    return static_cast<const State&>(*this).IsActive();
}

void State::SetActive(bool active) {
    _active = active;
}

void State::Update(double deltaTime) {

    Vector2D total_forces =
        std::accumulate(_forces.begin(), _forces.end(), a2de::Vector2D(),
            [&](a2de::Vector2D& result, a2de::State::ForceContainer::value_type& intermediate)->a2de::Vector2D {
                if(intermediate.second < 0.0) return Vector2D();
                return result += intermediate.first;
            }
        )
    ;
    Vector2D total_impulses = std::accumulate(_impulses.begin(), _impulses.end(), Vector2D());
    Vector2D F(total_forces + total_impulses);
    ClearImpulses();
    double mass = GetMass();

    //If static body, do nothing.
    if(Math::IsEqual(mass, 0.0) == false) {

        //Integrate from constant acceleration.
        //a = F / m
        //v = at + v;
        //p = (1/2)at^2 + vt + p

        SetAcceleration(F / mass);

        a2de::Vector2D a = GetAcceleration();
        a2de::Vector2D v = GetVelocity();
        SetVelocity(a * deltaTime + v);

        a2de::Vector2D p = GetPosition();
        SetPosition(((0.5 * a) * deltaTime * deltaTime) + (v * deltaTime) + p);
    }
    
    _forces.remove_if([&deltaTime](a2de::State::ForceContainer::value_type& current_force)->bool {
        current_force.second -= deltaTime;
        return (current_force.second < 0.0);
    });

}

void State::Sleep() {
    SetActive(false);
}

void State::Wake() {
    SetActive(true);
}

double State::GetRestitution() const {
    return _mat.GetRestitution();
}

double State::GetRestitution() {
    return static_cast<const State&>(*this).GetRestitution();
}

void State::SetRestitution(double restitution) {
    _mat.SetRestitution(restitution);
}

double State::GetStaticFriction() const {
    return _mat.GetStaticFriction();
}

double State::GetStaticFriction() {
    return static_cast<const State&>(*this).GetStaticFriction();
}

void State::SetStaticFriction(double friction) {
    _mat.SetStaticFriction(friction);
}

double State::GetKineticFriction() const {
    return _mat.GetKineticFriction();
}

double State::GetKineticFriction() {
    return static_cast<const State&>(*this).GetKineticFriction();
}

void State::SetKineticFriction(double friction) {
    _mat.SetKineticFriction(friction);
}

void State::SetMaterial(const PhysicsMaterial& material) {
    _mat = material;
}

void State::SetBoundingRectangle(IBoundingBox* rectangle) {
    delete _bounding_rectangle;
    _bounding_rectangle = rectangle;
    CalculateDensity();
}

const IBoundingBox* State::GetBoundingRectangle() const {
    return _bounding_rectangle;
}

IBoundingBox* State::GetBoundingRectangle() {
    return const_cast<IBoundingBox*>(static_cast<const State&>(*this).GetBoundingRectangle());
}

Shape* State::GetCollisionShape() {
    return const_cast<Shape*>(static_cast<const State&>(*this).GetCollisionShape());
}

const Shape* State::GetCollisionShape() const {
    return _collision_shape;
}

void State::SetCollisionShape(Shape* shape) {
    delete _collision_shape;
    _collision_shape = shape;
}

State::~State() {
    delete _collision_shape;
    delete _bounding_rectangle;
}

double State::GetDamper() const {
    return _damper;
}

double State::GetDamper() {
    return static_cast<const State&>(*this).GetDamper();
}

void State::SetDamper(double value) {
    _damper = value;
}

double State::GetDensity() const {
    return _density;
}

double State::GetDensity() {
    return static_cast<const State&>(*this).GetDensity();
}

double State::CalculateDensity() {
    if(_bounding_rectangle == nullptr) return 0.0;
    a2de::Vector2D dimensions = (_bounding_rectangle->GetHalfExtents() * 2.0);
    double area = dimensions.GetX() * dimensions.GetY();
    if(a2de::Math::IsEqual(area, 0.0)) return a2de::Math::A2DE_INFINITY;
    return (_mass / area);
}

PhysicsMaterial::PhysicsMaterial(double restitution, double static_friction, double kinetic_friction) : _restitution(restitution), _static_friction(static_friction), _kinetic_friction(kinetic_friction) { }

PhysicsMaterial::PhysicsMaterial(const PhysicsMaterial& other) : _restitution(other._restitution), _static_friction(other._static_friction), _kinetic_friction(other._kinetic_friction) { }

PhysicsMaterial& PhysicsMaterial::operator=(const PhysicsMaterial& rhs) {
    if(this == &rhs) return *this;

    this->_restitution = rhs._restitution;
    this->_static_friction = rhs._static_friction;
    this->_kinetic_friction = rhs._kinetic_friction;

    return *this;
}

double PhysicsMaterial::GetRestitution() const {
    return _restitution;
}

double PhysicsMaterial::GetRestitution() {
    return static_cast<const PhysicsMaterial&>(*this).GetRestitution();
}

void PhysicsMaterial::SetRestitution(double restitution) {
    if(restitution < 0.0) restitution = 0.0;
    if(restitution > 1.0) restitution = 1.0;
    _restitution = restitution;
}

double PhysicsMaterial::GetKineticFriction() const {
    return _kinetic_friction;
}

double PhysicsMaterial::GetKineticFriction() {
    return static_cast<const PhysicsMaterial&>(*this).GetKineticFriction();
}

void PhysicsMaterial::SetKineticFriction(double friction) {
    _kinetic_friction = friction;
}

double PhysicsMaterial::GetStaticFriction() const {
    return _static_friction;
}

double PhysicsMaterial::GetStaticFriction() {
    return static_cast<const PhysicsMaterial&>(*this).GetStaticFriction();
}

void PhysicsMaterial::SetStaticFriction(double friction) {
    _static_friction = friction;
}



A2DE_END