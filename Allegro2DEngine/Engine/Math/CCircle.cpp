/**************************************************************************************************
// file:	Engine\Math\CCircle.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the circle class
 **************************************************************************************************/
#include "CCircle.h"

#include <cassert>
#include "MathConstants.h"
#include "CMiscMath.h"

#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CArc.h"
#include "CPolygon.h"
#include "CSpline.h"
#include "CSector.h"
#include "CVector2D.h"


A2DE_BEGIN

Circle::Circle(double x, double y, double radius, const ALLEGRO_COLOR& color, bool filled) : Shape(x, y, (radius < 0 ? 0 : radius), (radius < 0 ? 0 : radius), color, filled) {
    _type = Shape::SHAPETYPE_CIRCLE;
    _radius = radius;
    CalculateCenter();
    CalculateArea();
    CalculateCircumference();
}

Circle::Circle(const Vector2D& center, double radius, const ALLEGRO_COLOR& color, bool filled) : Shape(center, (radius < 0 ? 0 : radius), (radius < 0 ? 0 : radius), color, filled) {
    _type = Shape::SHAPETYPE_CIRCLE;
    _radius = radius;
    CalculateCenter();
    CalculateArea();
    CalculateCircumference();
}
Circle::Circle(const Circle& circle) : Shape(circle) {
    _type = Shape::SHAPETYPE_CIRCLE;
    _radius = circle._radius;
    CalculateCenter();
    CalculateArea();
    CalculateCircumference();
}
Circle::~Circle() {
    /* DO NOTHING. ALL DE-INITIALIZATION IS DONE IN BASE CLASS */
}
Circle& Circle::operator=(const Circle& rhs) {
    if(this == &rhs) return *this;

    Shape::operator=(rhs);
    this->_half_extents = rhs._half_extents;
    this->_radius = rhs._radius;
    CalculateCenter();
    CalculateCircumference();
    CalculateArea();

    return *this;
}

bool Circle::operator==(const Circle& rhs) const {
    if(this == &rhs) return true;
    return (this->_radius == rhs._radius);
}

bool Circle::operator!=(const Circle& rhs) const {
    return !(*this == rhs);
}

bool Circle::operator<(const Circle& rhs) const {
    if(this == &rhs) return false;
    return (this->_radius < rhs._radius);
}

bool Circle::operator>(const Circle& rhs) const {
    if(this == &rhs) return false;
    return (this->_radius > rhs._radius);
}

bool Circle::operator<=(const Circle& rhs) const {
    return (!(*this > rhs));
}

bool Circle::operator>=(const Circle& rhs) const {
    return (!(*this < rhs));
}

double Circle::GetRadius() const {
    return _radius;
}
double Circle::GetRadius() {
    return static_cast<const Circle&>(*this).GetRadius();
}

double Circle::GetDiameter() const {
    return _radius * 2;
}
double Circle::GetDiameter() {
    return static_cast<const Circle&>(*this).GetDiameter();
}

double Circle::GetCircumference() const {
    return _circumference;
}
double Circle::GetCircumference() {
    return static_cast<const Circle&>(*this).GetCircumference();
}


void Circle::SetX(double x) {
    SetPosition(x, GetY());
}
void Circle::SetY(double y) {
    SetPosition(GetX(), y);
}
void Circle::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}

void Circle::SetPosition(const Vector2D& position) {
    Shape::SetPosition(position);
}

void Circle::SetHalfExtents(double half_width, double half_height) {
    SetHalfExtents(Vector2D(half_width, half_height));
}

void Circle::SetHalfExtents(const Vector2D& half_extents) {
    Shape::SetHalfExtents(half_extents);
    SetHalfWidth(half_extents.GetX());
    SetHalfHeight(half_extents.GetY());
}

void Circle::SetHalfWidth(double half_width) {
    _half_extents = Vector2D(half_width, half_width);
    SetRadius(half_width);
}
void Circle::SetHalfHeight(double half_height) {
    _half_extents = Vector2D(half_height, half_height);
    SetRadius(half_height);
}
void Circle::SetRadius(double radius) {
    _radius = radius;
    CalculateArea();
    CalculateCircumference();
}

bool Circle::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}

bool Circle::Intersects(const Rectangle& rectangle) const {
    bool resultTop = (Point(GetPosition()).GetDistance(rectangle.GetTop()) <= _radius);
    bool resultLeft = (Point(GetPosition()).GetDistance(rectangle.GetLeft()) <= _radius);
    bool resultRight = (Point(GetPosition()).GetDistance(rectangle.GetRight()) <= _radius);
    bool resultBottom = (Point(GetPosition()).GetDistance(rectangle.GetBottom()) <= _radius);
    bool isInside = Point(GetPosition()).Intersects(rectangle);
    return (isInside || resultTop || resultLeft || resultRight || resultBottom);
}
bool Circle::Intersects(const Ellipse& ellipse) const {
    bool resultX = (Point(GetPosition()).GetDistance(ellipse.GetPosition()) <= ellipse.GetRadiusWidth() + GetRadius());
    bool resultY = (Point(GetPosition()).GetDistance(ellipse.GetPosition()) <= ellipse.GetRadiusHeight() + GetRadius());
    return (resultX && resultY);
}
bool Circle::Intersects(const Triangle& triangle) const {
    bool resultTop = (Point(GetPosition()).GetDistance(triangle.GetLineAB()) <= _radius);
    bool resultLeft = (Point(GetPosition()).GetDistance(triangle.GetLineBC()) <= _radius);
    bool resultRight = (Point(GetPosition()).GetDistance(triangle.GetLineCA()) <= _radius);
    bool isInside = Point(GetPosition()).Intersects(triangle);
    return (isInside || resultTop || resultLeft || resultRight);
}
bool Circle::Intersects(const Circle& circle) const {
    return (Point(GetPosition()).GetDistance(circle.GetPosition()) <= this->GetRadius() + circle.GetRadius());
}
bool Circle::Intersects(const Point& point) const {
    return Intersects(point.GetPosition());
}
bool Circle::Intersects(const Line& line) const {
    return line.Intersects(*this);
}

bool Circle::Intersects(const Arc& /*arc*/) const {
    return false;
}

bool Circle::Intersects(const Polygon& /*polygon*/) const {
    return false;
}

bool Circle::Intersects(const Spline& /*spline*/) const {
    return false;
}

bool Circle::Intersects(const Sector& /*sector*/) const {
    return false;
}

bool Circle::Intersects(const Vector2D& position) const {
    return (a2de::Point::GetDistanceSquared(this->GetX(), this->GetY(), position.GetX(), position.GetY()) <= (_radius * _radius));
}

bool Circle::IsTangent(const Line& line) {
    return (Point(GetPosition()).GetDistance(line) == _radius);
}

void Circle::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled) {

    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    filled ? al_draw_filled_circle(a2de::Math::ToScreenScale(GetX()), a2de::Math::ToScreenScale(GetY()), a2de::Math::ToScreenScale(_radius), color) :
             al_draw_circle(a2de::Math::ToScreenScale(GetX()), a2de::Math::ToScreenScale(GetY()), a2de::Math::ToScreenScale(_radius), color, 0.0);

    al_set_target_bitmap(old_target);

}

void Circle::CalculateArea() {
    _area = (Math::A2DE_PI * _radius * _radius);
}
void Circle::CalculateCenter() { /* DO NOTHING: CENTER DEFAULTS TO ZERO OFFSET */ }
void Circle::CalculateCircumference() {
    _circumference = 2 * Math::A2DE_PI * _radius;
}

bool Circle::Contains(const Circle& circle) const {
    if(((this->GetPosition().GetX() == circle.GetPosition().GetX()) && (this->GetPosition().GetY() == circle.GetPosition().GetY())) && circle.GetRadius() <= this->GetRadius()) return true;
    return this->Intersects(Point(circle.GetPosition())) && circle.GetDiameter() <= this->GetRadius();
}


A2DE_END