/**************************************************************************************************
// file:	Engine\Math\CSpline.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the spline class
 **************************************************************************************************/
#include "CSpline.h"

#include <algorithm>

#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CArc.h"
#include "CPolygon.h"
#include "CSector.h"

#include "CMiscMath.h"

A2DE_BEGIN

Spline::Spline()
      : Shape(),
        _control_points(4),
        _num_points(0),
        _result_points(_num_points)
      {
        _type = Shape::SHAPETYPE_SPLINE;
}
Spline::Spline(std::vector<Point> controlPoints, unsigned long numPoints, const ALLEGRO_COLOR& color)
      : Shape(0, 0, 0, 0, color),
        _control_points(controlPoints),
        _num_points(numPoints),
        _result_points(numPoints) {
            _type = Shape::SHAPETYPE_SPLINE;
            for(std::size_t i = 0; i < 4; ++i) {
                _control_points[i] = Point(controlPoints.at(i));
            }
        CalculateResultPoints();
}

Spline::Spline(const Spline& other)
      : Shape(other), _control_points(4), _num_points(other._num_points), _result_points(other._num_points) {
          _type = Shape::SHAPETYPE_SPLINE;
          for(std::size_t i = 0; i < 4; ++i) {
              _control_points[i] = Point(other._control_points.at(i));
          }
          CalculateResultPoints();
}

Spline::~Spline() {
    _result_points.clear();
    _control_points.clear();
}

const Point& Spline::GetControlPointOne() const {
    return _control_points.at(0);
}

Point& Spline::GetControlPointOne() {
    return const_cast<Point&>(static_cast<const Spline&>(*this).GetControlPointOne());
}

const Point& Spline::GetControlPointTwo() const {
    return _control_points.at(1);
}

Point& Spline::GetControlPointTwo() {
    return const_cast<Point&>(static_cast<const Spline&>(*this).GetControlPointTwo());
}

const Point& Spline::GetControlPointThree() const {
    return _control_points.at(2);
}

Point& Spline::GetControlPointThree() {
    return const_cast<Point&>(static_cast<const Spline&>(*this).GetControlPointThree());
}

const Point& Spline::GetControlPointFour() const {
    return _control_points.at(3);
}

Point& Spline::GetControlPointFour() {
    return const_cast<Point&>(static_cast<const Spline&>(*this).GetControlPointFour());
}

const std::vector<Point>& Spline::GetResultPoints() const {
    return _result_points;
}

std::vector<Point>& Spline::GetResultPoints() {
    return const_cast<std::vector<Point>&>(static_cast<const Spline&>(*this).GetResultPoints());
}

void Spline::AdjustControlPoint(unsigned int number, double x, double y) {
    number -= 1;
    if(number < 0) number = 0;
    if(number > 3) number = 3;
    _control_points[number].SetPosition(x, y);
    CalculateResultPoints();
}

void Spline::AdjustControlPoint(unsigned int number, const Point& value) {
    this->AdjustControlPoint(number, value.GetX(), value.GetY());
}

void Spline::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool /*filled*/) {
    if(dest == nullptr) return;

    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(dest);
    float points[8] = {
        a2de::Math::ToScreenScale(_control_points.at(0).GetX()), a2de::Math::ToScreenScale(_control_points.at(0).GetY()),
        a2de::Math::ToScreenScale(_control_points.at(1).GetX()), a2de::Math::ToScreenScale(_control_points.at(1).GetY()),
        a2de::Math::ToScreenScale(_control_points.at(2).GetX()), a2de::Math::ToScreenScale(_control_points.at(2).GetY()),
        a2de::Math::ToScreenScale(_control_points.at(3).GetX()), a2de::Math::ToScreenScale(_control_points.at(3).GetY()),
        };
    al_draw_spline(points, color, 0.0);
    al_set_target_bitmap(old_target);
}

bool Spline::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}
bool Spline::Intersects(const Point& point) const {
    return Intersects(point.GetPosition());
}

bool Spline::Intersects(const Line& line) const {
    
    //Perform fast searches first:
    Point point_one(line.GetPointOne());
    bool isOnPointOne = this->Intersects(point_one);
    if(isOnPointOne) return true;

    Point point_two(line.GetPointTwo());
    bool isOnPointTwo = this->Intersects(point_two);
    if(isOnPointTwo) return true;

    //Perform slow O(n) point search:
    for(std::size_t i = 0; i < _result_points.size(); ++i) {
        line.Contains(_result_points.at(i));
        if(_result_points.at(i).IsOnLine(line)) return true;
    }

    //Perform agonizingly slow O(n^2) line search.
    for(std::size_t i = 0; i < _result_points.size() - 1; ++i) {
        Line current_line(_result_points.at(i).GetPosition(), _result_points.at(i+1).GetPosition());
        if(current_line.Intersects(line)) return true;
    }
    return false;
}

bool Spline::Intersects(const Rectangle& rectangle) const {
    return IterateResultPoints<Rectangle>(rectangle);
}
bool Spline::Intersects(const Circle& circle) const {
    return IterateResultPoints<Circle>(circle);
}
bool Spline::Intersects(const Ellipse& ellipse) const {
    return IterateResultPoints<Ellipse>(ellipse);
}
bool Spline::Intersects(const Triangle& triangle) const {
    return IterateResultPoints<Triangle>(triangle);
}
bool Spline::Intersects(const Arc& arc) const {
    return IterateResultPoints<Arc>(arc);
}
bool Spline::Intersects(const Polygon& polygon) const {
    return IterateResultPoints<Polygon>(polygon);
}
bool Spline::Intersects(const Spline& spline) const {
    return IterateResultPoints<Spline>(spline);
}

bool Spline::Intersects(const Sector& sector) const {
    return IterateResultPoints<Sector>(sector);
}

bool Spline::Intersects(const Vector2D& position) const {
    std::vector<Point>::const_iterator b = _result_points.begin();
    std::vector<Point>::const_iterator e = _result_points.end();
    for(std::vector<Point>::const_iterator _iter = b; _iter != e; ++_iter) {
        if((*_iter).GetPosition() == position) return true;
    }
    return false;
}

void Spline::CalculateResultPoints() {

    float points[8] = { _control_points[0].GetX(), _control_points[0].GetY(),
        _control_points[1].GetX(), _control_points[1].GetY(),
        _control_points[2].GetX(), _control_points[2].GetY(),
        _control_points[3].GetX(), _control_points[3].GetY(),
    };
    std::vector<float> dest;
    dest.resize(_num_points / 2);

    al_calculate_spline(&dest[0], 0, points, 0.0, _num_points / 2);
    for(std::size_t i = 0; i < _num_points / 2 - 1; ++i) {
        _result_points[i] = Point(dest[i], dest[i+1]);
    }
}

Spline& Spline::operator=(const Spline& rhs) {
    if(this == &rhs) return *this;
    Shape::operator=(rhs);
    for(std::size_t i = 0; i < 4; ++i) {
        _control_points[i] = Point(rhs._control_points[i].GetX(), rhs._control_points[i].GetY());
    }
    this->_num_points = rhs._num_points;
    _result_points.clear();
    _result_points.resize(_num_points);
    CalculateResultPoints();
    return *this;
}

bool Spline::operator==(const Spline& rhs) {
    if(this == &rhs) return true;

    for(std::size_t i = 0; i < 4; ++i) {
        if(this->_control_points[i] != rhs._control_points[i]) return false;
    }
    return true;
}

bool Spline::operator!=(const Spline& rhs) {
    return !(*this == rhs);
}

void Spline::CalculateArea() { /* DO NOTHING */ }
void Spline::CalculateCenter() { /* DO NOTHING */ }
Point Spline::GetPosition() const { return Point(); }
Point Spline::GetPosition() { return Point(); }
Point Spline::GetCenter() const { return Point(); }
Point Spline::GetCenter() { return Point(); }
double Spline::GetArea() const { return 0.0; }
double Spline::GetArea() { return static_cast<const Spline&>(*this).GetArea(); }
bool Spline::IsFilled() const { return false; }
bool Spline::IsFilled() { return static_cast<const Spline&>(*this).IsFilled(); }
void Spline::SetFill(bool /*filled*/) { /* DO NOTHING*/ }
double Spline::GetX() const { return 0.0; }
double Spline::GetX() { return static_cast<const Spline&>(*this).GetX(); }
double Spline::GetY() const { return 0.0; }
double Spline::GetY() { return static_cast<const Spline&>(*this).GetY(); }
double Spline::GetHalfWidth() const { return 0; }
double Spline::GetHalfWidth() { return static_cast<const Spline&>(*this).GetHalfWidth(); }
double Spline::GetHalfHeight() const { return 0; }
double Spline::GetHalfHeight() { return static_cast<const Spline&>(*this).GetHalfHeight(); }

void Spline::SetX(double /*x*/) { /* DO NOTHING*/ }
void Spline::SetY(double /*y*/) { /* DO NOTHING*/ }
void Spline::SetPosition(double /*x*/, double /*y*/) { /* DO NOTHING*/ }
void Spline::SetPosition(const Vector2D& /*position*/) { /* DO NOTHING */ }

void Spline::SetHalfExtents(double /*width*/, double /*height*/) { /* DO NOTHING*/ }
void Spline::SetHalfExtents(const Vector2D& /*dimensions*/) { /* DO NOTHING*/ }

void Spline::SetHalfWidth(double /*width*/) { /* DO NOTHING*/ }
void Spline::SetHalfHeight(double /*height*/) { /* DO NOTHING*/ }

bool Spline::Contains(const Shape& shape) const {
    return this->Contains(shape);
}

bool Spline::Contains(const Point& /*point*/) const {
    return false;
}

bool Spline::Contains(const Line& /*line*/) const {
    return false;
}

bool Spline::Contains(const Rectangle& /*rectangle*/) const {
    return false;
}

bool Spline::Contains(const Circle& /*circle*/) const {
    return false;
}

bool Spline::Contains(const Ellipse& /*ellipse*/) const {
    return false;
}

bool Spline::Contains(const Triangle& /*triangle*/) const {
    return false;
}

bool Spline::Contains(const Arc& /*arc*/) const {
    return false;
}

bool Spline::Contains(const Polygon& /*polygon*/) const {
    return false;
}

bool Spline::Contains(const Spline& /*spline*/) const {
    return false;
}

bool Spline::Contains(const Sector& /*sector*/) const {
    return false;
}

A2DE_END