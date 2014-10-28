/**************************************************************************************************
// file:	Engine\Math\CVector2D.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the vector 2 d class
 **************************************************************************************************/
#include "CVector2D.h"

#include <cassert>
#include <cmath>
#include "../a2de_exceptions.h"

#include "CVector3D.h"

A2DE_BEGIN


Vector2D::Vector2D() : _x(0.0), _y(0.0), _angle(std::atan2(_y, _x)) { /* DO NOTHING */ }
Vector2D::Vector2D(double x, double y) : _x(x), _y(y), _angle(std::atan2(_y, _x)) { /* DO NOTHING */ }
Vector2D::Vector2D(const Vector2D& vector) : _x(vector.GetX()), _y(vector.GetY()), _angle(std::atan2(_y, _x)) { /* DO NOTHING */ }
Vector2D::Vector2D(const Vector3D& v3d) : _x(v3d.GetX()), _y(v3d.GetY()), _angle(std::atan2(_y, _x))  { /* DO NOTHING */ }

Vector2D::Vector2D(const a2de::Math::PolarCoordinate& magnitude_and_angle) : _x(0.0), _y(0.0), _angle(0.0) {
    a2de::Math::CartesianCoordinate xy(a2de::Math::PolarToCartesian(magnitude_and_angle));
    _x = xy.first;
    _y = xy.second;
    _angle = magnitude_and_angle.second;
}

Vector2D::~Vector2D() { }

double Vector2D::GetX() const {
    return _x;
}
double Vector2D::GetX() {
    return static_cast<const Vector2D&>(*this).GetX();
}

double Vector2D::GetY() const {
    return _y;
}
double Vector2D::GetY() {
    return static_cast<const Vector2D&>(*this).GetY();
}

double Vector2D::GetLength() const {
    return std::sqrt(GetLengthSquared());
}
double Vector2D::GetLength() {
    return static_cast<const Vector2D&>(*this).GetLength();
}

double Vector2D::GetLengthSquared() const {
    double a1 = GetX();
    double a2 = GetY();
    if(Math::IsEqual(a1, 0.0) && Math::IsEqual(a2, 0.0)) return 0.0;
    return (a1 * a1 + a2 * a2);
}
double Vector2D::GetLengthSquared() {
    return static_cast<const Vector2D&>(*this).GetLengthSquared();
}

Vector2D& Vector2D::operator=(const Vector2D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(rhs.GetX(), rhs.GetY());
    return *this;
}

bool Vector2D::operator==(const Vector2D& rhs) {
    return static_cast<const Vector2D&>(*this).operator==(rhs);
}

bool Vector2D::operator==(const Vector2D& rhs) const {
    return ( (Math::IsEqual(this->GetX(), rhs.GetX())) && (Math::IsEqual(this->GetY(), rhs.GetY())) );
}

bool Vector2D::operator!=(const Vector2D& rhs) {
    return static_cast<const Vector2D&>(*this).operator!=(rhs);
}

bool Vector2D::operator!=(const Vector2D& rhs) const {
    return !(*this == rhs);
}

Vector2D& Vector2D::operator+=(double scalar) {
    SetTerminal(GetX() + scalar, GetY() + scalar);
    return *this;
}
Vector2D& Vector2D::operator-=(double scalar) {
    SetTerminal(GetX() - scalar, GetY() - scalar);
    return *this;
}
Vector2D& Vector2D::operator/=(double scalar) {
    assert(Math::IsEqual(scalar, 0.0) == false);
    SetTerminal(GetX() / scalar, GetY() / scalar);
    return *this;
}
Vector2D& Vector2D::operator*=(double scalar) {
    SetTerminal(GetX() * scalar, GetY() * scalar);
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& rhs) const {
    return Vector2D(this->GetX() + rhs.GetX(), this->GetY() + rhs.GetY());
}
Vector2D Vector2D::operator+(const Vector2D& rhs) {
    return static_cast<const Vector2D&>(*this).operator+(rhs);
}

Vector2D operator+(double scalar_lhs, const Vector2D& v_rhs) {
    return v_rhs + scalar_lhs;
}

Vector2D operator+(const Vector2D& v_lhs, double scalar_rhs) {
    return Vector2D(v_lhs.GetX() + scalar_rhs, v_lhs.GetY() + scalar_rhs);
    
}

Vector2D Vector2D::operator-(const Vector2D& rhs) const {
    return Vector2D(this->GetX() - rhs.GetX(), this->GetY() - rhs.GetY());
}
Vector2D Vector2D::operator-(const Vector2D& rhs) {
    return static_cast<const Vector2D&>(*this).operator-(rhs);
}

Vector2D operator-(const Vector2D& v_lhs, double scalar_rhs) {
    return Vector2D(v_lhs.GetX() - scalar_rhs, v_lhs.GetY() - scalar_rhs);
}

Vector2D operator-(double scalar_lhs, const Vector2D& v_rhs) {
    return v_rhs - scalar_lhs;
}

Vector2D Vector2D::operator-() const {
    return Vector2D(-GetX(), -GetY());
}

Vector2D Vector2D::operator-() {
    return static_cast<const Vector2D&>(*this).operator-();
}

Vector2D Vector2D::operator*(const Vector2D& rhs) const {
    return Vector2D(this->GetX() * rhs.GetX(), this->GetY() * rhs.GetY());
}
Vector2D Vector2D::operator*(const Vector2D& rhs) {
    return static_cast<const Vector2D&>(*this).operator*(rhs);
}

Vector2D operator*(const Vector2D& v_lhs, double scalar_rhs) {
    return Vector2D(v_lhs.GetX() * scalar_rhs, v_lhs.GetY() * scalar_rhs);
}

Vector2D operator*(double scalar_lhs, const Vector2D& v_rhs) {
    return v_rhs * scalar_lhs;
}

a2de::Vector2D Vector2D::operator/(const Vector2D& rhs) const {
    assert(Math::IsEqual(rhs.GetX(), 0.0) == false && Math::IsEqual(rhs.GetY(), 0.0) == false);
    return Vector2D(this->GetX() / rhs.GetX(), this->GetY() / rhs.GetY());
}
a2de::Vector2D Vector2D::operator/(const Vector2D& rhs) {
    return static_cast<const Vector2D&>(*this).operator/(rhs);
}

Vector2D operator/(const Vector2D& v_lhs, double scalar_rhs) {
    assert(Math::IsEqual(scalar_rhs, 0.0) == false);
    return Vector2D(v_lhs.GetX() / scalar_rhs, v_lhs.GetY() / scalar_rhs);
}

Vector2D operator/(double scalar_lhs, const Vector2D& v_rhs) {
    return v_rhs / scalar_lhs;
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() + rhs.GetX(), this->GetY() + rhs.GetY());
    return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() - rhs.GetX(), this->GetY() - rhs.GetY());
    return *this;
}

Vector2D& Vector2D::operator*=(const Vector2D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() + rhs.GetX(), this->GetY() + rhs.GetY());
    return *this;
}
Vector2D& Vector2D::operator/=(const Vector2D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() - rhs.GetX(), this->GetY() - rhs.GetY());
    return *this;
}

Vector2D::operator Vector3D() {
    return Vector3D(*this);
}

void Vector2D::SetX(double x) {
    SetTerminal(x, GetY());
}
void Vector2D::SetY(double y) {
    SetTerminal(GetX(), y);
}

void Vector2D::SetTerminal(double x, double y) {
    _x = x;
    _y = y;
    _angle = std::atan2(_y, _x);
}

double Vector2D::DotProduct(const Vector2D& rhs) const {
    return DotProduct(*this, rhs);
}

double Vector2D::DotProduct(const Vector2D& a, const Vector2D& b) {
    double a1 = a.GetX();
    double a2 = a.GetY();

    double b1 = b.GetX();
    double b2 = b.GetY();

    return a1 * b1 + a2 * b2;
}

Vector2D Vector2D::Normalize() const {
    double a1 = GetX();
    double a2 = GetY();
    double length = GetLength();
    if(Math::IsEqual(length, 0.0)) {
        return Vector2D(0.0, 0.0);
    }
    return Vector2D(a1 / length, a2 / length);
}

void Vector2D::Normalize(Vector2D& v) {
    double a1 = v.GetX();
    double a2 = v.GetY();
    double length = v.GetLength();
    if(Math::IsEqual(length, 0.0)) {
        return;
    }
    v.SetTerminal(a1 / length, a2 / length);
}

Vector2D Vector2D::GetNormal() const {
    return GetLeftNormal();
}

Vector2D Vector2D::GetNormal() {
    return static_cast<const Vector2D&>(*this).GetNormal();
}

a2de::Vector2D Vector2D::GetLeftNormal() const {
    return Vector2D(-_y, _x);
}

a2de::Vector2D Vector2D::GetLeftNormal() {
    return static_cast<const Vector2D&>(*this).GetLeftNormal();
}

a2de::Vector2D Vector2D::GetRightNormal() const {
    return Vector2D(_y, -_x);
}

a2de::Vector2D Vector2D::GetRightNormal() {
    return static_cast<const Vector2D&>(*this).GetRightNormal();
}

a2de::Vector2D Vector2D::GetProjection(const Vector2D& b) {
    return GetProjection(*this, b);
}

a2de::Vector2D Vector2D::GetProjection(const Vector2D& a, const Vector2D& b) {

    //See http://www.metanetsoftware.com/technique/tutorialA.html#appendixA
    //--= projection =--
    //
    // The formula for projecting vector a onto vector b is:
    //
    // proj.x = ( dp / (b.x*b.x + b.y*b.y) ) * b.x;
    // proj.y = ( dp / (b.x*b.x + b.y*b.y) ) * b.y;
    //
    // where dp is the dotprod of a and b: dp = (a.x*b.x + a.y*b.y)
    //
    // Note that the result is a vector; also, (b.x*b.x + b.y*b.y) is simply the length of b squared.
    //
    // If b is a unit vector, (b.x*b.x + b.y*b.y) = 1, and thus a projected onto b reduces to:
    //
    // proj.x = dp*b.x;
    // proj.y = dp*b.y;

    double dp = Vector2D::DotProduct(a, b);
    double b_length_squared = b.GetLengthSquared();
    double b_x = b.GetX();
    double b_y = b.GetY();
    double dp_over_b_length_squared = dp / b_length_squared;

    double x = dp_over_b_length_squared * b_x;
    double y = dp_over_b_length_squared * b_y;

    if(a2de::Math::IsEqual(x, 0.0)) x = 0.0;
    if(a2de::Math::IsEqual(y, 0.0)) y = 0.0;

    return Vector2D(x, y);
}

a2de::Vector2D Vector2D::GetProjectionOnXAxis() {
    return GetProjection(Vector2D(1.0, 0.0));
}

a2de::Vector2D Vector2D::GetProjectionOnYAxis() {
    return GetProjection(Vector2D(0.0, 1.0));
}

double Vector2D::GetAngle() const {
    return _angle;
}
double Vector2D::GetAngle(){
    return static_cast<const Vector2D&>(*this).GetAngle();
}

double Vector2D::GetAngle(const Vector2D& v) {
    return std::atan2(v.GetY(), v.GetX());
}

double Vector2D::GetAngleFrom(const Vector2D& b) {
    return GetAngleFrom(b, *this);
}

double Vector2D::GetAngleFrom(const Vector2D& b, const Vector2D& a) {
    double b_length = b.GetLengthSquared();
    double a_length = a.GetLengthSquared();
    assert(Math::IsEqual(a_length, 0.0) == false && Math::IsEqual(b_length, 0.0) == false);
    if(Math::IsEqual(a_length, 0.0) || Math::IsEqual(b_length, 0.0)) {
        throw Exception("Can not get the angle of a Null Vector.");
    }
    b_length = std::sqrt(b_length);
    a_length = std::sqrt(a_length);
    double dot_product = DotProduct(b, a);
    double length_product = a_length * b_length;
    double dot_product_over_length_product = dot_product / length_product;
    double arc_cosine = std::acos(dot_product_over_length_product);

    return arc_cosine;
}


double Vector2D::GetFacingAngle(const Vector2D& target, const Vector2D& source) {
    return GetFacingVector(target, source).GetAngle();
}

a2de::Vector2D Vector2D::GetFacingVector(const Vector2D& target, const Vector2D& source) {
    a2de::Vector2D facingVec(target - source);
    return facingVec;
}

a2de::Vector3D Vector2D::GetHomogeneous() const {
    double x = GetX();
    double y = GetY();
    return Vector3D(x, y, 1);
}

a2de::Vector3D Vector2D::GetHomogeneous() {
    return static_cast<const Vector2D&>(*this).GetHomogeneous();
}


A2DE_END