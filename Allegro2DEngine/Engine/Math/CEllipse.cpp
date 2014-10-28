/**************************************************************************************************
// file:	Engine\Math\CEllipse.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the ellipse class
 **************************************************************************************************/
#include "CEllipse.h"

#include <cassert>
#include "MathConstants.h"
#include "CMiscMath.h"

#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CTriangle.h"
#include "CArc.h"
#include "CPolygon.h"
#include "CSpline.h"
#include "CSector.h"


A2DE_BEGIN

Ellipse::Ellipse(const Vector2D& center, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled)
: Shape(center, ((half_width < 0) ? 0 : half_width), ((half_height < 0) ? 0 : half_height), color, filled) {
    _type = Shape::SHAPETYPE_ELLIPSE;
    _radii = _half_extents;
    CalculateFoci();
    CalculateArea();
    CalculateCircumference();
}
Ellipse::Ellipse(const Vector2D& center, const Vector2D& half_extents, const ALLEGRO_COLOR& color, bool filled)
    : Shape(center, ((half_extents.GetX() < 0.0) ? 0.0 : half_extents.GetX()), ((half_extents.GetY() < 0.0) ? 0.0 : half_extents.GetY()), color, filled) {
        _type = Shape::SHAPETYPE_ELLIPSE;
        _radii = _half_extents;
        CalculateFoci();
        CalculateArea();
        CalculateCircumference();
}
Ellipse::Ellipse(int x, int y, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled)
: Shape(x, y, ((half_width < 0) ? 0 : half_width), ((half_height < 0) ? 0 : half_height), color, filled) {
    _type = Shape::SHAPETYPE_ELLIPSE;
    _radii = _half_extents;
    CalculateFoci();
    CalculateArea();
    CalculateCircumference();
}
Ellipse::Ellipse(const Ellipse& ellipse) : Shape(ellipse) {
    _type = Shape::SHAPETYPE_ELLIPSE;
    _radii = ellipse._half_extents;
    CalculateFoci();
    CalculateArea();
    CalculateCircumference();
}
Ellipse::~Ellipse() {

}

void Ellipse::SetHalfExtents(double half_width, double half_height) {
    SetHalfExtents(Vector2D(half_width, half_height));
}

void Ellipse::SetHalfExtents(const Vector2D& half_extents) {
    Shape::SetHalfExtents(half_extents);
    _radii = half_extents;
    CalculateFoci();
    CalculateArea();
    CalculateCircumference();
}

double Ellipse::GetCircumference() const {
    return _circumference;
}
void Ellipse::SetHalfWidth(double half_width) {
    SetHalfExtents(half_width, _half_extents.GetY());
}
void Ellipse::SetHalfHeight(double half_height) {
    SetHalfExtents(_half_extents.GetX(), half_height);
}
void Ellipse::SetX(double x) {
    SetPosition(x, GetY());
}
void Ellipse::SetY(double y) {
    SetPosition(GetX(), y);
}

void Ellipse::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}

void Ellipse::SetPosition(const Vector2D& position) {
    Shape::SetPosition(position);
}

bool Ellipse::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}

bool Ellipse::Intersects(const Triangle& /*triangle*/) const {
    return false;
    //Line tlAB(triangle.GetLineAB());
    //Line tlBC(triangle.GetLineBC());
    //Line tlCA(triangle.GetLineCA());
    //bool resultAB = tlAB.Intersects(*this);
    //bool resultBC = tlBC.Intersects(*this);
    //bool resultCA = tlCA.Intersects(*this);
    //bool isInside = Intersects(Point(triangle.GetCenter()));
    //return (isInside || resultAB || resultBC || resultCA);
}
bool Ellipse::Intersects(const Ellipse& ellipse) const {
    return a2de::Point::GetDistance(_position, ellipse.GetPosition()) <= this->_radii.GetX() + ellipse._radii.GetX() &&
           a2de::Point::GetDistance(_position, ellipse.GetPosition()) <= this->_radii.GetY() + ellipse._radii.GetY();
}
bool Ellipse::Intersects(const Circle& circle) const {
    return a2de::Point::GetDistance(_position, circle.GetPosition()) <= this->_radii.GetX() + circle.GetRadius() &&
           a2de::Point::GetDistance(_position, circle.GetPosition()) <= this->_radii.GetY() + circle.GetRadius();
}
bool Ellipse::Intersects(const Rectangle& rectangle) const {

    double distTop = a2de::Line::GetDistance(rectangle.GetTop(), _position);
    double distLeft = a2de::Line::GetDistance(rectangle.GetLeft(), _position);
    double distRight = a2de::Line::GetDistance(rectangle.GetRight(), _position);
    double distBottom = a2de::Line::GetDistance(rectangle.GetBottom(), _position);
    double radiusWidth = GetRadiusWidth();
    double radiusHeight = GetRadiusHeight();

    bool resultTop = (distTop < radiusWidth && distTop < radiusHeight);
    bool resultBottom = (distBottom < radiusWidth && distBottom < radiusHeight);
    bool resultLeft = (distLeft < radiusWidth && distLeft < radiusHeight);
    bool resultRight = (distRight < radiusWidth && distRight < radiusHeight);
    bool isInside = rectangle.Intersects(_position);
    return (isInside || resultTop || resultBottom || resultLeft || resultRight);
}
bool Ellipse::Intersects(const Point& point) const {
    return (a2de::Point::GetDistanceSquared(GetPosition(), point.GetPosition()) <= _radii.GetX() * _radii.GetX() &&
            a2de::Point::GetDistanceSquared(GetPosition(), point.GetPosition()) <= _radii.GetY() * _radii.GetY());
}
bool Ellipse::Intersects(const Line& line) const {
    return (a2de::Line::GetDistance(line, _position) < this->GetMinimumDistance()) || this->IsTangent(line);
}

bool Ellipse::Intersects(const Arc& /*arc*/) const {
    return false;
}

bool Ellipse::Intersects(const Polygon& /*polygon*/) const {
    return false;
}

bool Ellipse::Intersects(const Spline& /*spline*/) const {
    return false;
}

bool Ellipse::Intersects(const Sector& /*sector*/) const {
    return false;
}

bool Ellipse::Intersects(const Vector2D& position) const {

    double x = this->GetPosition().GetX();
    double y = this->GetPosition().GetY();
    double distance_squared = a2de::Point::GetDistanceSquared(x, y, position.GetX(), position.GetY());
    double rX_squared = _radii.GetX();
    rX_squared *= rX_squared;
    double rY_squared = _radii.GetY();
    rY_squared *= rY_squared;

    return (distance_squared <= rX_squared && distance_squared <= rY_squared);

}

double Ellipse::GetMinimumDistance() const {
    double a = _half_extents.GetX();
    double b = _half_extents.GetY();
    double distance_sq_cubed = (a * a + b * b) * (a * a + b * b) * (a * a + b * b);
    return (3.0 * std::sqrt(3.0) * a * a * b * b) / std::sqrt(distance_sq_cubed);
}

double Ellipse::GetMinimumDistance() {
    return static_cast<const Ellipse&>(*this).GetMinimumDistance();
}


bool Ellipse::IsTangent(const Line& line) const {
    return a2de::Math::IsEqual(a2de::Line::GetDistance(line, _position), GetMinimumDistance());
}

bool Ellipse::IsTangent(const Line& line) {
    return static_cast<const Ellipse&>(*this).IsTangent(line);
}

const Vector2D& Ellipse::GetFocusA() const {
    return _focusA;
}
Vector2D& Ellipse::GetFocusA() {
    return const_cast<Vector2D&>(static_cast<const Ellipse&>(*this).GetFocusA());
}

const Vector2D& Ellipse::GetFocusB() const {
    return _focusB;
}

Vector2D& Ellipse::GetFocusB() {
    return const_cast<Vector2D&>(static_cast<const Ellipse&>(*this).GetFocusB());
}

void Ellipse::CalculateArea() {
    _area = Math::A2DE_PI * _radii.GetX() * _radii.GetY();
}

void Ellipse::CalculateCircumference() {

    //C = 2 * pi * (sqrt(0.5 * (a^2 + b^2)) / 2.0 )
    double a = _half_extents.GetX();
    double b = _half_extents.GetY();
    _circumference = 2 * Math::A2DE_PI * (std::sqrt(0.5 * ((a * a) + (b * b))) / 2.0);

}

void Ellipse::CalculateFoci() {
    double x = _position.GetX();
    double y = _position.GetY();
    Vector2D half_radii = _radii / 2.0;
    double hrx = half_radii.GetX();
    double hry = half_radii.GetY();
    if(IsVertical()) {
        _focusA = Vector2D(x, y + hry);
        _focusB = Vector2D(x, y - hry);
    } else if(IsHorizontal()) {
        _focusA = Vector2D(x - hrx, y);
        _focusB = Vector2D(x + hrx, y);
    }
}

void Ellipse::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled) {

    if(dest == nullptr) return;

    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    filled ? al_draw_filled_ellipse(a2de::Math::ToScreenScale(GetX()), a2de::Math::ToScreenScale(GetY()), a2de::Math::ToScreenScale(GetHalfWidth()), a2de::Math::ToScreenScale(GetHalfHeight()), color) :
             al_draw_ellipse(a2de::Math::ToScreenScale(GetX()), a2de::Math::ToScreenScale(GetY()), a2de::Math::ToScreenScale(GetHalfWidth()), a2de::Math::ToScreenScale(GetHalfHeight()), color, 0.0);

    al_set_target_bitmap(old_target);

}

double Ellipse::GetRadiusWidth() const {
    return _radii.GetX();
}

double Ellipse::GetRadiusWidth() {
    return static_cast<const Ellipse&>(*this).GetRadiusWidth();
}

double Ellipse::GetRadiusHeight() const {
    return _radii.GetY();
}

double Ellipse::GetRadiusHeight() {
    return static_cast<const Ellipse&>(*this).GetRadiusHeight();
}

bool Ellipse::IsHorizontal() const {
    return (_radii.GetX() > _radii.GetY());
}

bool Ellipse::IsHorizontal() {
    return static_cast<const Ellipse&>(*this).IsHorizontal();
}

bool Ellipse::IsVertical() const {
    return (_radii.GetX() < _radii.GetY());
}

bool Ellipse::IsVertical() {
    return static_cast<const Ellipse&>(*this).IsVertical();
}

Ellipse& Ellipse::operator=(const Ellipse& rhs) {
    if(this == &rhs) return *this;
    Shape::operator=(rhs);
    this->_radii = Vector2D(rhs._half_extents.GetX() / 2, rhs._half_extents.GetY() / 2);
    this->_color = rhs._color;
    this->_filled = rhs._filled;
    CalculateFoci();
    CalculateArea();
    CalculateCircumference();
    return *this;
}


A2DE_END