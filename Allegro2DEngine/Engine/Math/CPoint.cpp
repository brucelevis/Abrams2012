/**************************************************************************************************
// file:	Engine\Math\CPoint.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the point class
 **************************************************************************************************/
#include "CPoint.h"

#include <cassert>
#include <cmath>
#include "CMiscMath.h"

#include "CLine.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CArc.h"
#include "CPolygon.h"
#include "CSpline.h"
#include "CSector.h"
#include "CVector2D.h"

#include "../a2de_exceptions.h"

A2DE_BEGIN

Point::Point() : Shape(0.0, 0.0) {
    _type = Shape::SHAPETYPE_POINT;
    CalculateArea();
    CalculateCenter();
}

Point::Point(double x, double y) : Shape(x, y) {
    _type = Shape::SHAPETYPE_POINT;
    CalculateArea();
    CalculateCenter();
}

Point::Point(double x, double y, const ALLEGRO_COLOR& color) : Shape(x, y, 0, 0, color, false) {
    _type = Shape::SHAPETYPE_POINT;
    CalculateArea();
    CalculateCenter();
}

Point::Point(const Point& point) : Shape(point) {
    _type = Shape::SHAPETYPE_POINT;
    CalculateArea();
    CalculateCenter();
}

Point::Point(const Vector2D& position, const ALLEGRO_COLOR& color) : Shape(position, 0, 0, color, false) {
    _type = Shape::SHAPETYPE_POINT;
    CalculateArea();
    CalculateCenter();
}

Point::Point(const Vector2D& position) : Shape(position) {
    _type = Shape::SHAPETYPE_POINT;
    CalculateArea();
    CalculateCenter();
}

Point::~Point() { }


void Point::SetX(double x) {
    SetPosition(x, GetY());
}

void Point::SetY(double y) {
    SetPosition(GetX(), y);
}

void Point::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}

void Point::SetPosition(const Vector2D& position) {
    Shape::SetPosition(position);
}

double Point::GetDistance(const Line& line) const {
    return line.GetDistance(*this);
}

double Point::GetDistance(const Point& point) const {
    return GetDistance(*this, point);
}

double Point::GetDistance(const Point& one, const Point& two) {
    return GetDistance(one.GetX(), one.GetY(), two.GetX(), two.GetY());
}

double Point::GetDistance(const Vector2D& one, const Vector2D& two) {
    return std::sqrt(Point::GetDistanceSquared(one, two));
}

double Point::GetDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(GetDistanceSquared(x1, y1, x2, y2));
}
double Point::GetDistanceSquared(const Point& point) {
    return GetDistanceSquared(*this, point);
}

double Point::GetDistanceSquared(double x1, double y1, double x2, double y2) {
    double xDiff = x2 - x1;
    double yDiff = y2 - y1;
    return (xDiff * xDiff + yDiff * yDiff);
}

double Point::GetDistanceSquared(const Vector2D& one, const Vector2D& two) {
    return (two - one).GetLengthSquared();
}


double Point::GetDistanceSquared(const Point& one, const Point& two) {
    return Point::GetDistanceSquared(one.GetPosition(), two.GetPosition());
}
bool Point::IsOnLine(const Line& line) const {
    return (GetDistance(line) <= 0.0001);
}

Point& Point::operator=(const Point& rhs) {
    if(this == &rhs) return *this;
    Shape::operator=(rhs);
    return *this;
}

bool Point::operator==(const Point& rhs) const {
    return (Math::IsEqual(this->GetX(), rhs.GetX()) && Math::IsEqual(this->GetY(), rhs.GetY()));
}

bool Point::operator!=(const Point& rhs) const {
    return !(*this == rhs);
}

Point Point::operator+(const Point& rhs) {
    double xP = this->GetX();
    double yP = this->GetY();
    double xR = rhs.GetX();
    double yR = rhs.GetY();

    return Point(xP + xR, yP + yR);
}
Point Point::operator-(const Point& rhs) {
    double xP = this->GetX();
    double yP = this->GetY();
    double xR = rhs.GetX();
    double yR = rhs.GetY();

    return Point(xP - xR, yP - yR);
}
Point Point::operator*(const Point& rhs) {
    double xP = this->GetX();
    double yP = this->GetY();
    double xR = rhs.GetX();
    double yR = rhs.GetY();

    return Point(xP * xR, yP * yR);
}
Point Point::operator/(const Point& rhs) {
    double xP = this->GetX();
    double yP = this->GetY();
    double xR = rhs.GetX();
    double yR = rhs.GetY();

    assert(xR != 0 || yR != 0);
    return Point(xP / xR, yP / yR);
}
Point Point::operator+(double scalar) {
    double xP = this->GetX();
    double yP = this->GetY();

    return Point(xP + scalar, yP + scalar);
}
Point Point::operator-(double scalar) {
    double xP = this->GetX();
    double yP = this->GetY();

    return Point(xP - scalar, yP - scalar);
}
Point Point::operator*(double scalar) {
    double xP = this->GetX();
    double yP = this->GetY();

    return Point(xP * scalar, yP * scalar);
}
Point Point::operator/(double scalar) {
    assert(scalar != 0);

    double xP = this->GetX();
    double yP = this->GetY();

    return Point(xP / scalar, yP / scalar);
}

Point& Point::operator+=(const Point& rhs) {    
    double x = this->GetX() + rhs.GetX();
    double y = this->GetY() + rhs.GetY();

    this->SetPosition(x, y);

    return *this;
}
Point& Point::operator-=(const Point& rhs) {
    double x = this->GetX() - rhs.GetX();
    double y = this->GetY() - rhs.GetY();

    this->SetPosition(x, y);

    return *this;
}
Point& Point::operator*=(const Point& rhs) {
    double x = this->GetX() * rhs.GetX();
    double y = this->GetY() * rhs.GetY();

    this->SetPosition(x, y);

    return *this;
}
Point& Point::operator/=(const Point& rhs) {
    double xR = rhs.GetX();
    double yR = rhs.GetY();

    assert(xR != 0 || yR != 0);

    double xP = this->GetX();
    double yP = this->GetY();
    
    double x = xP / xR;
    double y = yP / yR;

    this->SetPosition(x, y);
    return *this;
}

Point& Point::operator+=(double scalar) {
    double xP = this->GetX();
    double yP = this->GetY();

    double x = xP + scalar;
    double y = yP + scalar;

    this->SetPosition(x, y);
    return *this;
}
Point& Point::operator-=(double scalar) {
    double xP = this->GetX();
    double yP = this->GetY();

    double x = xP - scalar;
    double y = yP - scalar;

    this->SetPosition(x, y);
    return *this;
}
Point& Point::operator*=(double scalar) {
    double xP = this->GetX();
    double yP = this->GetY();

    double x = xP * scalar;
    double y = yP * scalar;

    this->SetPosition(x, y);
    return *this;
}
Point& Point::operator/=(double scalar) {
    assert(scalar != 0);

    double xP = this->GetX();
    double yP = this->GetY();

    double x = xP / scalar;
    double y = yP / scalar;

    this->SetPosition(x, y);
    return *this;
}

void Point::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool /*filled*/) {
    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(dest);
    al_draw_pixel(a2de::Math::ToScreenScale(this->GetX()), a2de::Math::ToScreenScale(this->GetY()), color);
    al_set_target_bitmap(old_target);
}

void Point::CalculateArea() { /* DO NOTHING */ }
void Point::CalculateCenter() { /* DO NOTHING */ }
void Point::SetHalfExtents(double /*half_width*/, double /*half_height*/) { /* DO NOTHING */ }
void Point::SetHalfExtents(const Vector2D& /*half_extents*/) { /* DO NOTHING */ }
void Point::SetHalfWidth(double /*half_width*/) { /* DO NOTHING */ }
void Point::SetHalfHeight(double /*half_height*/) { /* DO NOTHING */ }

bool Point::Intersects(const Vector2D& position) const {
    return (this->GetPosition() == position);
}

bool Point::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}

bool Point::Intersects(const Point& point) const {
    return Intersects(point.GetPosition());
}

bool Point::Intersects(const Line& line) const {
    return line.Intersects(*this);
}

bool Point::Intersects(const Rectangle& rectangle) const {

    double rLeft = rectangle.GetX();
    double pWidth = this->GetHalfWidth();
    double pRight = this->GetX() + pWidth;
    if(rLeft > pRight) return false;

    double rWidth = rectangle.GetHalfWidth();
    double rRight = rLeft + rWidth;
    double pLeft = pRight - pWidth;
    if(rRight < pLeft) return false;

    double rTop = rectangle.GetY();
    double pHeight = this->GetHalfHeight();
    double pBottom = this->GetY() + pHeight;
    if(rTop > pBottom) return false;

    double rHeight = rectangle.GetHalfHeight();
    double rBottom = rTop + rHeight;
    double pTop = pBottom - pHeight;
    if(rBottom < pTop) return false;

    return true;
}
bool Point::Intersects(const Circle& circle) const {
    return (GetDistance(GetX(), GetY(), circle.GetX(), circle.GetY()) <= circle.GetRadius());
}
bool Point::Intersects(const Ellipse& ellipse) const {
    bool resultX = (GetDistance(Point(ellipse.GetX(), ellipse.GetY())) <= ellipse.GetRadiusWidth());
    bool resultY = (GetDistance(Point(ellipse.GetX(), ellipse.GetY())) <= ellipse.GetRadiusHeight());
    return (resultX && resultY);
}
bool Point::Intersects(const Triangle& triangle) const {

    //Distance: this from center
    Point tCenter(triangle.GetX(), triangle.GetY());
    double distCtoP = GetDistance(tCenter);

    //Distance: center to sides
    double distCtoAB = tCenter.GetDistance(triangle.GetLineAB());
    double distCtoBC = tCenter.GetDistance(triangle.GetLineBC());
    double distCtoCA = tCenter.GetDistance(triangle.GetLineCA());

    //Distance: this from points
    double distPtoA = GetDistance(triangle.GetPointA());
    double distPtoB = GetDistance(triangle.GetPointB());
    double distPtoC = GetDistance(triangle.GetPointC());

    bool resultAB = (distCtoP <= distCtoAB);
    bool resultBC = (distCtoP <= distCtoBC);
    bool resultCA = (distCtoP <= distCtoCA);
    bool resultA = (distPtoA <= distCtoP);
    bool resultB = (distPtoB <= distCtoP);
    bool resultC = (distPtoC <= distCtoP);

    return (resultAB && resultBC && resultCA && resultA && resultB && resultC);
}

bool Point::Intersects(const Arc& /*arc*/) const {
    return false;
}
bool Point::Intersects(const Polygon& /*polygon*/) const {
    return false;
}
bool Point::Intersects(const Spline& /*spline*/) const {
    return false;
}

bool Point::Intersects(const Sector& sector) const {
    return sector.Intersects(*this);
}


bool Point::Contains(const Shape& shape) const {
    return this->Contains(shape);
}

bool Point::Contains(const Point& point) const {
    return (*this) == point;
}

bool Point::Contains(const Line& /*line*/) const {
    return false;
}

bool Point::Contains(const Rectangle& /*rectangle*/) const {
    return false;
}

bool Point::Contains(const Circle& /*circle*/) const {
    return false;
}

bool Point::Contains(const Ellipse& /*ellipse*/) const {
    return false;
}

bool Point::Contains(const Triangle& /*triangle*/) const {
    return false;
}

bool Point::Contains(const Arc& /*arc*/) const {
    return false;
}

bool Point::Contains(const Polygon& /*polygon*/) const {
    return false;
}

bool Point::Contains(const Spline& /*spline*/) const {
    return false;
}

bool Point::Contains(const Sector& /*sector*/) const {
    return false;
}


A2DE_END