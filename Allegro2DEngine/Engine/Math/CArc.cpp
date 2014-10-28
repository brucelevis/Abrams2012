/**************************************************************************************************
// file:	Engine\Math\CArc.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the arc class
 **************************************************************************************************/
#include "CArc.h"


#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CPolygon.h"
#include "CSpline.h"
#include "CSector.h"



#include "MathConstants.h"
#include "CMiscMath.h"
#include "../a2de_exceptions.h"

A2DE_BEGIN

Arc::Arc(double x, double y, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled) : Shape(x, y, (radius < 0 ? 0 : radius), (radius < 0 ? 0 : radius), color, filled), _startAngle(0.0), _endAngle(0.0), _theta(0.0), _radius((radius < 0.0 ? 0.0 : radius)) {
    _type = Shape::SHAPETYPE_ARC;
    _radius = radius;
    SetAngles(startAngle, endAngle);
    CalculateLength();
    CalculateArea();
}

Arc::Arc(const Vector2D& position, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled) : Shape(position, (radius < 0 ? 0 : radius), (radius < 0 ? 0 : radius), color, filled), _startAngle(0.0), _endAngle(0.0), _theta(0.0), _radius((radius < 0.0 ? 0.0 : radius)) {
    _type = Shape::SHAPETYPE_ARC;
    _radius = radius;
    SetAngles(startAngle, endAngle);
    CalculateLength();
    CalculateArea();
}

Arc::Arc(const Arc& arc) : Shape(arc), _startAngle(arc._startAngle), _endAngle(arc._endAngle), _theta(arc._theta), _radius(arc._radius) {
    _type = Shape::SHAPETYPE_ARC;
    SetAngles(_startAngle, _endAngle);
    CalculateLength();
    CalculateArea();
}

Arc::~Arc() {
    /* DO NOTHING. ALL DE-INITIALIZATION DONE IN BASE CLASS */
}

double Arc::GetRadius() const {
    return _radius;
}

void Arc::SetRadius(double radius) {
    if(radius < 0.0) radius = 0.0;
    SetHalfExtents(Vector2D(radius, radius));
}

void Arc::SetHalfExtents(double half_width, double half_height) {
    if(Math::IsEqual(half_width, half_height) == false) return;
    SetHalfExtents(Vector2D(half_width, half_height));
}

void Arc::SetHalfExtents(const Vector2D& half_extents) {
    if(Math::IsEqual(half_extents.GetX(), half_extents.GetY()) == false) return;
    _half_extents = Vector2D((half_extents.GetX() < 0.0 ? 0.0 : half_extents.GetX()), (half_extents.GetY() < 0.0 ? 0.0 : half_extents.GetY()));
    _radius = half_extents.GetX();
    CalculateLength();
    CalculateArea();
}

void Arc::SetHalfWidth(double half_width) {
    SetHalfExtents(half_width, half_width);
}

void Arc::SetHalfHeight(double half_height) {
    SetHalfExtents(half_height, half_height);
}

double Arc::GetLength() const {
    return _length;
}

double Arc::GetLength() {
    return static_cast<const Arc&>(*this).GetLength();
}

void Arc::SetX(double x) {
    SetPosition(x, GetY());
}

void Arc::SetY(double y) {
    SetPosition(GetX(), y);
}

void Arc::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}

void Arc::SetPosition(const Vector2D& position) {
    Shape::SetPosition(position);
}

bool Arc::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}

bool Arc::Intersects(const Point& /*point*/) const {
    return false;
}

bool Arc::Intersects(const Line& line) const {
    return line.Intersects(*this);
}

bool Arc::Intersects(const Rectangle& rectangle) const {
    bool resultCTop = Point(GetPosition().GetX(), GetPosition().GetY()).GetDistance(rectangle.GetTop()) <= GetRadius();
    bool resultCLeft = Point(GetPosition().GetX(), GetPosition().GetY()).GetDistance(rectangle.GetLeft()) <= GetRadius();
    bool resultCRight = Point(GetPosition().GetX(), GetPosition().GetY()).GetDistance(rectangle.GetRight()) <= GetRadius();
    bool resultCBottom = Point(GetPosition().GetX(), GetPosition().GetY()).GetDistance(rectangle.GetBottom()) <= GetRadius();
    bool CisInside = Point(GetPosition().GetX(), GetPosition().GetY()).Intersects(rectangle);
    bool resultC = (CisInside || resultCTop || resultCLeft || resultCRight || resultCBottom);

    bool resultS = rectangle.Intersects(GetStartPoint());
    bool resultE = rectangle.Intersects(GetEndPoint());

    return (resultC || resultS || resultE);
}

bool Arc::Intersects(const Circle& circle) const {
    double cr = circle.GetRadius();
    bool resultC = a2de::Point::GetDistanceSquared(GetPosition(), circle.GetPosition()) <= cr * cr;
    bool resultS = circle.Intersects(GetStartPoint());
    bool resultE = circle.Intersects(GetEndPoint());
    return (resultC || resultS || resultE);
}
bool Arc::Intersects(const Ellipse& ellipse) const {
    double dist = Point(GetPosition().GetX(), GetPosition().GetY()).GetDistance(ellipse.GetPosition());
    bool resultC = dist <= ellipse.GetRadiusWidth() || dist <= ellipse.GetRadiusHeight();
    bool resultS = ellipse.Intersects(GetStartPoint());
    bool resultE = ellipse.Intersects(GetEndPoint());

    return (resultC || resultS || resultE);
}
bool Arc::Intersects(const Triangle& triangle) const {
    bool resultC = triangle.Intersects(GetPosition());
    bool resultS = triangle.Intersects(GetPosition());
    bool resultE = triangle.Intersects(GetPosition());
    return (resultC || resultS || resultE);
}

bool Arc::Intersects(const Arc& arc) const {
    Vector2D myCenter(this->GetPosition().GetX(), this->GetPosition().GetY());
    Vector2D yourCenter(arc.GetPosition().GetX(), arc.GetPosition().GetY());
    double distance_between_centers = a2de::Point::GetDistance(myCenter.GetX(), myCenter.GetY(), yourCenter.GetX(), yourCenter.GetY());

    return ((myCenter == yourCenter) && distance_between_centers == arc.GetRadius() || distance_between_centers == this->GetRadius());
}

bool Arc::Intersects(const Polygon& polygon) const {
    return polygon.Intersects(this->GetStartPoint()) || polygon.Intersects(this->GetEndPoint());
}

bool Arc::Intersects(const Spline& /*spline*/) const {
    return false;
}

bool Arc::Intersects(const Sector& /*sector*/) const {
    return false;
}

bool Arc::Intersects(const Vector2D& /*position*/) const {
    return false;
}

void Arc::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool /*filled*/) {
    if(dest == nullptr) return;

    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();

    al_set_target_bitmap(dest);
    al_draw_arc(a2de::Math::ToScreenScale(GetX()), a2de::Math::ToScreenScale(GetY()), _startAngle, _endAngle - _startAngle, _radius, color, 0.0);

    al_set_target_bitmap(old_target);

}

void Arc::CalculateArea() {
    _area = 0.5 * _radius * _radius * _theta;
}

void Arc::CalculateLength() {
    _length = _theta * _radius;
}
void Arc::SetAnglesDegrees(double startAngle, double endAngle) {
    SetAngles(Math::DegreeToRadian(startAngle), Math::DegreeToRadian(endAngle));
}

void Arc::SetAngles(double startAngle, double endAngle) {
    while(startAngle < 0.0) {
        startAngle += Math::A2DE_2PI;
    }
    while(endAngle < 0.0) {
        endAngle += Math::A2DE_2PI;
    }
    _startAngle = std::fmod(startAngle, Math::A2DE_2PI);
    _endAngle = std::fmod(endAngle, Math::A2DE_2PI);
    double eA = _endAngle;
    double sA = _startAngle;
    if(eA < sA) {
        eA = _endAngle + Math::A2DE_2PI;
    }
    _theta = std::fabs(eA - sA);
    CalculateLength();
    CalculateArea();
}

double Arc::GetStartAngle() const {
    return _startAngle;
}

double Arc::GetStartAngle() {
    return static_cast<const Arc&>(*this).GetStartAngle();
}

double Arc::GetEndAngle() const {
    return _endAngle;
}
double Arc::GetEndAngle() {
    return static_cast<const Arc&>(*this).GetEndAngle();
}

Vector2D Arc::GetStartPoint() const {
    return _position + _radius * Vector2D(std::cos(_startAngle), -std::sin(_startAngle));
}
Vector2D Arc::GetEndPoint() const {
    return _position + _radius * Vector2D(std::cos(_endAngle), -std::sin(_endAngle));
}

Vector2D Arc::GetCenterPoint() const {
    Vector2D s(GetStartPoint());
    Vector2D e(GetEndPoint());
    return s + (e - s) * 0.5;
}

double Arc::GetTheta() const {
    return _theta;
}

double Arc::GetTheta() {
    return static_cast<const Arc&>(*this).GetTheta();
}

bool Arc::Contains(const Shape& shape) const {
    return this->Contains(shape);
}

bool Arc::Contains(const Point& /*point*/) const {
    return false;
}

bool Arc::Contains(const Line& /*line*/) const {
    return false;
}

bool Arc::Contains(const Rectangle& /*rectangle*/) const {
    return false;
}

bool Arc::Contains(const Circle& /*circle*/) const {
    return false;
}

bool Arc::Contains(const Ellipse& /*ellipse*/) const {
    return false;
}

bool Arc::Contains(const Triangle& /*triangle*/) const {
    return false;
}

bool Arc::Contains(const Arc& /*arc*/) const {
    return false;
}

bool Arc::Contains(const Polygon& /*polygon*/) const {
    return false;
}

bool Arc::Contains(const Spline& /*spline*/) const {
    return false;
}

bool Arc::Contains(const Sector& /*sector*/) const {
    return false;
}

Arc& Arc::operator=(const Arc& rhs) {
    if(this == &rhs) return *this;

    Shape::operator=(rhs);
    this->_startAngle = rhs._startAngle;
    this->_endAngle = rhs._endAngle;
    this->_radius = rhs._radius;
    this->_theta = rhs._theta;
    this->_length = rhs._length;
    SetAngles(_startAngle, _endAngle);
    CalculateLength();
    CalculateArea();

    return *this;
}


A2DE_END