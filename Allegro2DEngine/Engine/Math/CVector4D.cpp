/**************************************************************************************************
// file:	Engine\Math\CVector3D.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the vector 3 d class
 **************************************************************************************************/
#include "CVector4D.h"

#include <cassert>
#include <cmath>

#include "../a2de_exceptions.h"
#include "CMiscMath.h"

#include "CVector2D.h"
#include "CVector3D.h"

A2DE_BEGIN

Vector4D::Vector4D() : _x(0.0), _y(0.0), _z(0.0), _w(0.0) { /* DO NOTHING */ }

Vector4D::Vector4D(double x, double y) : _x(x), _y(y), _z(0.0), _w(0.0) { /* DO NOTHING */ }

Vector4D::Vector4D(double x, double y, double z) : _x(x), _y(y), _z(z), _w(0.0) { /* DO NOTHING */ }

Vector4D::Vector4D(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w) { /* DO NOTHING */ }

Vector4D::Vector4D(const Vector3D& v3d) : _x(v3d.GetX()), _y(v3d.GetY()), _z(v3d.GetZ()), _w(0.0) { /* DO NOTHING */ }

Vector4D::Vector4D(const Vector2D& v2d) : _x(v2d.GetX()), _y(v2d.GetY()), _z(0.0), _w(0.0) { /* DO NOTHING */ }

Vector4D::Vector4D(const Vector4D& other) : _x(other.GetX()), _y(other.GetY()), _z(other.GetZ()), _w(other.GetW()) { /* DO NOTHING */ }

Vector4D::~Vector4D() {
    /* DO NOTHING */
}

double Vector4D::GetX() const {
    return _x;
}

double Vector4D::GetY() const {
    return _y;
}

double Vector4D::GetZ() const {
    return _z;
}

double Vector4D::GetW() const {
    return _w;
}

double Vector4D::GetX() {
    return static_cast<const Vector4D&>(*this).GetX();
}

double Vector4D::GetY() {
    return static_cast<const Vector4D&>(*this).GetY();
}

double Vector4D::GetZ() {
    return static_cast<const Vector4D&>(*this).GetZ();
}

double Vector4D::GetW() {
    return static_cast<const Vector4D&>(*this).GetW();
}


double Vector4D::GetLength() const {
    double length_sq = GetLengthSquared();
    if(Math::IsEqual(length_sq, 0.0)) return 0.0;
    return std::sqrt(length_sq);
}

double Vector4D::GetLength() {
    return static_cast<const Vector4D&>(*this).GetLength();
}

double Vector4D::GetLengthSquared() const {
    double a1 = GetX();
    double a2 = GetY();
    double a3 = GetZ();
    double a4 = GetW();
    if(Math::IsEqual(a1, 0.0) && Math::IsEqual(a2, 0.0) && Math::IsEqual(a3, 0.0) && Math::IsEqual(a4, 0.0)) return 0.0;
    return (a1 * a1 + a2 * a2 + a3 * a3 + a4 * a4);
}

double Vector4D::GetLengthSquared() {
    return static_cast<const Vector4D&>(*this).GetLengthSquared();
}

Vector4D Vector4D::Normalize() const {
    double a1 = GetX();
    double a2 = GetY();
    double a3 = GetZ();
    double a4 = GetW();
    double length = GetLength();
    if(Math::IsEqual(length, 0.0)) {
        return Vector4D(0.0, 0.0, 0.0, 0.0);
    }
    return Vector4D(a1 / length, a2 / length, a3 / length, a4 / length);
}

void Vector4D::Normalize(Vector4D& v) {
    double a1 = v.GetX();
    double a2 = v.GetY();
    double a3 = v.GetZ();
    double a4 = v.GetW();
    double length = v.GetLength();
    if(Math::IsEqual(length, 0.0)) {
        return;
    }
    v.SetTerminal(a1 / length, a2 / length, a3 / length, a4 / length);
}
double Vector4D::DotProduct(const Vector4D& b) {
    return DotProduct(*this, b);
}

double Vector4D::DotProduct(const Vector4D& a, const Vector4D& b) {
    double a1 = a.GetX();
    double a2 = a.GetY();
    double a3 = a.GetZ();
    double a4 = a.GetW();

    double b1 = b.GetX();
    double b2 = b.GetY();
    double b3 = b.GetZ();
    double b4 = b.GetW();

    return a1 * b1 + a2 * b2 + a3 * b3 + a4 * b4;
}

Vector4D& Vector4D::operator=(const Vector4D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(rhs.GetX(), rhs.GetY(), rhs.GetZ(), rhs.GetW());
    return *this;
}

Vector4D& Vector4D::operator=(const Vector3D& rhs) {
    this->SetTerminal(rhs.GetX(), rhs.GetY(), rhs.GetZ(),0.0);
    return *this;
}

Vector4D& Vector4D::operator=(const Vector2D& rhs) {
    this->SetTerminal(rhs.GetX(), rhs.GetY(), 0.0, 0.0);
    return *this;
}

bool Vector4D::operator==(const Vector4D& rhs) {
    return ( (Math::IsEqual(this->GetX(), rhs.GetX())) && (Math::IsEqual(this->GetY(), rhs.GetY())) && (Math::IsEqual(this->GetZ(), rhs.GetZ()))  && (Math::IsEqual(this->GetW(), rhs.GetW())) );
}

bool Vector4D::operator!=(const Vector4D& rhs) {
    return !(*this == rhs);
}

Vector4D operator+(double scalar_lhs, const Vector4D& v_rhs) {
    return (v_rhs + scalar_lhs);
}
Vector4D operator+(const Vector4D& v_lhs, double scalar_rhs) {
    return Vector4D(v_lhs.GetX() + scalar_rhs, v_lhs.GetY() + scalar_rhs, v_lhs.GetZ() + scalar_rhs, v_lhs.GetW() + scalar_rhs);
}

Vector4D operator-(double scalar_lhs, const Vector4D& v_rhs) {
    return v_rhs + scalar_lhs;
}
Vector4D operator-(const Vector4D& v_lhs, double scalar_rhs) {
    return Vector4D(v_lhs.GetX() - scalar_rhs, v_lhs.GetY() + scalar_rhs, v_lhs.GetZ() - scalar_rhs, v_lhs.GetW() - scalar_rhs);
}

Vector4D operator-(const Vector4D& lhs) {
    return Vector4D(-lhs.GetX(), -lhs.GetY(), -lhs.GetZ(), -lhs.GetW());
}

Vector4D operator*(const Vector4D& v_lhs, double scalar_rhs) {
    return Vector4D(v_lhs.GetX() * scalar_rhs, v_lhs.GetY() * scalar_rhs, v_lhs.GetZ() * scalar_rhs, v_lhs.GetW() * scalar_rhs);
}
Vector4D operator*(double scalar_lhs, const Vector4D& v_rhs) {
    return v_rhs + scalar_lhs;
}

Vector4D operator/(const Vector4D& v_lhs, double scalar_rhs) {
    assert(Math::IsEqual(scalar_rhs, 0.0) == false);
    return Vector4D(v_lhs.GetX() / scalar_rhs, v_lhs.GetY() / scalar_rhs, v_lhs.GetZ() / scalar_rhs, v_lhs.GetW() / scalar_rhs);
}
Vector4D operator/(double scalar_lhs, const Vector4D& v_rhs) {
    return v_rhs / scalar_lhs;
}

Vector4D& Vector4D::operator+=(double scalar) {
    SetTerminal(GetX() + scalar, GetY() + scalar, GetZ() + scalar, GetW() + scalar);
    return *this;
}
Vector4D& Vector4D::operator-=(double scalar) {
    SetTerminal(GetX() - scalar, GetY() - scalar, GetZ() - scalar, GetW() - scalar);
    return *this;
}
Vector4D& Vector4D::operator*=(double scalar) {
    SetTerminal(GetX() * scalar, GetY() * scalar, GetZ() * scalar, GetW() * scalar);
    return *this;
}
Vector4D& Vector4D::operator/=(double scalar) {
    assert(Math::IsEqual(scalar, 0.0) == false);
    SetTerminal(GetX() / scalar, GetY() / scalar, GetZ() / scalar, GetW() / scalar);
    return *this;
}

Vector4D Vector4D::operator+(const Vector4D& rhs) const {
    return Vector4D(this->GetX() + rhs.GetX(), this->GetY() + rhs.GetY(), this->GetZ() + rhs.GetZ(), this->GetW() + rhs.GetW());
}
Vector4D Vector4D::operator+(const Vector4D& rhs) {
    return static_cast<const Vector4D&>(*this).operator+(rhs);
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const {
    return Vector4D(this->GetX() - rhs.GetX(), this->GetY() - rhs.GetY(), this->GetZ() - rhs.GetZ(), this->GetW() - rhs.GetW());
}
Vector4D Vector4D::operator-(const Vector4D& rhs) {
    return static_cast<const Vector4D&>(*this).operator-(rhs);
}

Vector4D Vector4D::operator-() const {
    return Vector4D(-GetX(), -GetY(), -GetZ(), -GetW());
}

Vector4D Vector4D::operator-() {
    return static_cast<const Vector4D&>(*this).operator-();
}

Vector4D Vector4D::operator*(const Vector4D& rhs) const {
    return Vector4D(this->GetX() * rhs.GetX(), this->GetY() * rhs.GetY(), this->GetZ() * rhs.GetZ(), this->GetW() * rhs.GetW());
}
Vector4D Vector4D::operator*(const Vector4D& rhs) {
    return static_cast<const Vector4D&>(*this).operator*(rhs);
}

Vector4D Vector4D::operator/(const Vector4D& rhs) const {
    return Vector4D(this->GetX() / rhs.GetX(), this->GetY() / rhs.GetY(), this->GetZ() / rhs.GetZ(), this->GetW() / rhs.GetW());
}
Vector4D Vector4D::operator/(const Vector4D& rhs) {
    return static_cast<const Vector4D&>(*this).operator/(rhs);
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() + rhs.GetX(), this->GetY() + rhs.GetY(), this->GetZ() + rhs.GetZ(), this->GetW() + rhs.GetW());
    return *this;
}
Vector4D& Vector4D::operator-=(const Vector4D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() - rhs.GetX(), this->GetY() - rhs.GetY(), this->GetZ() - rhs.GetZ(), this->GetW() - rhs.GetW());
    return *this;
}
Vector4D& Vector4D::operator*=(const Vector4D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() * rhs.GetX(), this->GetY() * rhs.GetY(), this->GetZ() * rhs.GetZ(), this->GetW() * rhs.GetW());
    return *this;
}
Vector4D& Vector4D::operator/=(const Vector4D& rhs) {
    if(this == &rhs) return *this;
    this->SetTerminal(this->GetX() / rhs.GetX(), this->GetY() / rhs.GetY(), this->GetZ() / rhs.GetZ(), this->GetW() / rhs.GetW());
    return *this;
}


/************************************************************************/
/*  PROTECTED                                                           */
/************************************************************************/


void Vector4D::SetX(double x) {
    SetTerminal(x, GetY(), GetZ(), GetW());
}

void Vector4D::SetY(double y) {
    SetTerminal(GetX(), y, GetZ(), GetW());
}

void Vector4D::SetZ(double z) {
    SetTerminal(GetX(), GetY(), z, GetW());
}

void Vector4D::SetW(double w) {
    SetTerminal(GetX(), GetY(), GetZ(), w);
}

void Vector4D::SetTerminal(double x, double y, double z, double w) {
    _x = x;
    _y = y;
    _z = z;
    _w = w;
}

void Vector4D::GetHomogeneous(a2de::Vector4D& v) {
    double x = v.GetX();
    double y = v.GetY();
    double z = v.GetZ();
    double w = v.GetW();
    if(a2de::Math::IsEqual(w, 0.0)) return;
    v.SetTerminal(x / w, y / w, z / w, 1.0);
}

a2de::Vector4D Vector4D::GetHomogeneous() const {
    double x = GetX();
    double y = GetY();
    double z = GetZ();
    double w = GetW();
    if(a2de::Math::IsEqual(w, 0.0)) return a2de::Vector4D(x, y, z, w);
    return a2de::Vector4D(x / w, y / w, z / w, 1.0);
}

Vector4D Vector4D::GetHomogeneous() {
    return static_cast<const a2de::Vector4D&>(*this).GetHomogeneous();
}


A2DE_END