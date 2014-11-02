/**************************************************************************************************
// file:	Engine\Math\CPolygon.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the polygon class
 **************************************************************************************************/
#include "CPolygon.h"


#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CArc.h"
#include "CSpline.h"
#include "CSector.h"


#include "MathConstants.h"
#include "CMiscMath.h"
#include <algorithm>
#include <cfloat>
#include "../a2de_exceptions.h"

#include <iostream>

A2DE_BEGIN

Polygon::Polygon(const std::vector<Point>& points, const ALLEGRO_COLOR& color, bool filled) : Shape() {
    if(points.size() < 3) throw Exception("A polygon must have at least 3 vertices.");
    _type = Shape::SHAPETYPE_POLYGON;
    _color = color;
    _filled = filled;

    for(size_t i = 0; i < points.size(); ++i) {
        _points.push_back(points[i]);
    }
    double width = 0.0;
    double height = 0.0;
    double smallestX = DBL_MAX;
    double largestX = DBL_MIN;
    double smallestY = DBL_MAX;
    double largestY = DBL_MIN;
    GetLargestCoordinates(largestX, largestY);
    GetSmallestCoordinates(smallestX, smallestY);
    width = largestX - smallestX;
    height = largestY - smallestY;
    _half_extents = Vector2D(width, height);
    CalculateArea();
    CalculateCenter();
}
Polygon::Polygon(const Polygon& polygon) : Shape(polygon) {
    if(polygon._points.size() < 3) throw Exception("A polygon must have at least 3 vertices.");
    _type = Shape::SHAPETYPE_POLYGON;
    for(size_t i = 0; i < polygon._points.size(); ++i) {
        this->_points.push_back(polygon._points[i]);
    }
    CalculateArea();
    CalculateCenter();
}
Polygon::~Polygon() {

}

void Polygon::SetX(double x) {
    SetPosition(x, GetY());
}
void Polygon::SetY(double y) {
    SetPosition(GetX(), y);
}
void Polygon::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}
void Polygon::SetPosition(const Vector2D& position) {
    double deltaX = position.GetX() - GetX();
    double deltaY = position.GetY() - GetY();
    Shape::SetPosition(position);
    CalculateCenter();
    CalculatePoints(deltaX, deltaY);
}
void Polygon::SetVertexPosition(unsigned int vertexNum, double x, double y) {
    _points[vertexNum].SetPosition(x, y);
    CalculateArea();
    CalculateCenter();
}

bool Polygon::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}

bool Polygon::Intersects(const Point& point) const {
    return (GetBoundingBox().Intersects(point.GetPosition()));
}
bool Polygon::Intersects(const Line& line) const {
    return line.Intersects(*this);
}
bool Polygon::Intersects(const Rectangle& rectangle) const {
    if(rectangle.Intersects(GetBoundingBox()) == false) return false;
    for(size_t i = 0; i < _points.size(); ++i) {
        if(_points[i].Intersects(rectangle) == true) {
            return true;
        }
    }
    return false;
}
bool Polygon::Intersects(const Circle& circle) const {
    if(circle.Intersects(GetBoundingBox()) == false) return false;
    for(size_t i = 0; i < _points.size(); ++i) {
        if(_points[i].Intersects(circle) == true) {
            return true;
        }
    }
    return false;
}
bool Polygon::Intersects(const Ellipse& ellipse) const {
    if(ellipse.Intersects(GetBoundingBox()) == false) return false;
    for(size_t i = 0; i < _points.size(); ++i) {
        if(_points[i].Intersects(ellipse) == true) {
            return true;
        }
    }
    return false;
}
bool Polygon::Intersects(const Triangle& triangle) const {
    if(triangle.Intersects(GetBoundingBox()) == false) return false;
    for(size_t i = 0; i < _points.size(); ++i) {
        if(_points[i].Intersects(triangle) == true) {
            return true;
        }
    }
    return false;
}
bool Polygon::Intersects(const Polygon& polygon) const {
    if(polygon.Intersects(this->GetBoundingBox()) == false) return false;
    std::vector<Line> mySides(0);
    std::vector<Line> yourSides(0);
    this->GetSides(mySides);
    polygon.GetSides(yourSides);
    for(size_t i = 0; i < mySides.size(); ++i) {
        for(size_t j = 0; j < yourSides.size(); ++j) {
            if(mySides[i].Intersects(yourSides[j]) == true) {
                return true;
            }
        }
    }
    return false;
}
void Polygon::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& /*color*/, bool /*filled*/) {
    if(dest == nullptr) return;

    std::cout << "Polygon drawing not supported in Allegro 5.0.10" << std::endl;

}

bool Polygon::Intersects(const Arc& /*arc*/) const {
    return false;
}

bool Polygon::Intersects(const Spline& /*spline*/) const {
    return false;
}

bool Polygon::Intersects(const Sector& /*sector*/) const {
    return false;
}

bool Polygon::Intersects(const Vector2D& position) const {
    return (GetBoundingBox().Intersects(position));
}

int Polygon::GetNumSides() const {
    return (_points.size());
}

int Polygon::GetNumSides() {
    return static_cast<const Polygon&>(*this).GetNumSides();
}

int Polygon::GetNumVertices() const {
    return (_points.size());
}

int Polygon::GetNumVertices() {
    return static_cast<const Polygon&>(*this).GetNumVertices();
}

void Polygon::GetSides(std::vector<Line>& sides) const {
    sides.clear();
    for(size_t i = 0; i < _points.size(); ++i) {
        size_t x = i+1;
        if(x == _points.size()) x = 0;
        sides.push_back(Line(_points[i].GetPosition(), _points[x].GetPosition()));
    }
}

void Polygon::GetSides(std::vector<Line>& sides) {
    return static_cast<const Polygon&>(*this).GetSides(sides);
}

std::vector<Point>& Polygon::GetVertices() {
    return const_cast<std::vector<Point>&>(static_cast<const Polygon&>(*this).GetVertices());
}

const std::vector<Point>& Polygon::GetVertices() const {
    return _points;
}

int* Polygon::CreateVerticesArray() {
    int* points = new int[GetNumVertices() * 2];
    for(size_t i = 0; i < _points.size(); ++i) {
        int x = i * 2;
        points[x] = a2de::Math::ToScreenScale(_points[i].GetX());
        points[x+1] = a2de::Math::ToScreenScale(_points[i].GetY());
    }
    return points;
}
void Polygon::ReleaseVerticesArray(int* points) {
    delete[] points;
    points = nullptr;
}
void Polygon::CalculateArea() {
    double area = 0.0;
    //A = 1/2(sum of ((X[i] * Y[i+1]) - (X[i+1] * Y[i])) where i = 0 to n - 1
    if(_points.size() < 3) _area = area;
    for(size_t i = 0; i < _points.size() - 1; ++i) {
        double Xi = _points[i].GetX();
        double Yi = _points[i].GetY();
        double Xi1 = _points[i+1].GetX();
        double Yi1 = _points[i+1].GetY();
        area += ((Xi * Yi1) - (Xi1 * Yi));
    }
    area = (0.5) * area;
    _area = area;
}
void Polygon::CalculateCenter() {
    if(_area == 0.0) {
        _position = Vector2D(0.0, 0.0);
        return;
    }
    //Cx = (1/6A)(sum of(X[i] + X[i+1])((X[i] * Y[i+1]) - (X[i+1] * Y[i]))) where A = Area, i = 0 to n - 1
    double Cx = 0.0;
    for(size_t i = 0; i < _points.size() - 1; ++i) {
        double Xi = _points[i].GetX();
        double Yi = _points[i].GetY();
        double Xi1 = _points[i+1].GetX();
        double Yi1 = _points[i+1].GetY();
        Cx += ((Xi + Xi1) * ((Xi * Yi1) - (Xi1 * Yi)));
    }
    double A = _area;
    Cx = ((1.0 / 6.0) * A) * Cx;

    //Cy = (1/6A)(sum of(Y[i] + Y[i+1])((X[i] * Y[i+1]) - (X[i+1] * Y[i]))) where A = Area, i = 0 to n - 1
    double Cy = 0.0;
    for(size_t i = 0; i < _points.size() - 1; ++i) {
        double Xi = _points[i].GetX();
        double Yi = _points[i].GetY();
        double Xi1 = _points[i+1].GetX();
        double Yi1 = _points[i+1].GetY();
        Cy += ((Yi + Yi1) * ((Xi * Yi1) - (Xi1 * Yi)));
    }
    Cy = ((1.0 / 6.0) * A) * Cy;
    _position = Vector2D(Cx, Cy);
}

void Polygon::CalculatePoints(double deltaX, double deltaY) {
    for(size_t i = 0; i <_points.size(); ++i) {
        _points[i].SetPosition(_points[i].GetX() + deltaX, _points[i].GetY() + deltaY);
    }
}
double Polygon::GetSmallestX() const {
    return GetSmallestCoordinates().GetX();
}

double Polygon::GetSmallestX() {
    return static_cast<const Polygon&>(*this).GetSmallestX();
}

double Polygon::GetSmallestY() const {
    return GetSmallestCoordinates().GetY();
}

double Polygon::GetSmallestY() {
    return static_cast<const Polygon&>(*this).GetSmallestY();
}

double Polygon::GetLargestX() const {
    return GetLargestCoordinates().GetX();
}

double Polygon::GetLargestX() {
    return static_cast<const Polygon&>(*this).GetLargestX();
}

double Polygon::GetLargestY() const {
    return GetLargestCoordinates().GetY();
}

double Polygon::GetLargestY() {
    return static_cast<const Polygon&>(*this).GetLargestY();
}

void Polygon::GetSmallestCoordinates(double& x, double& y) const {
    double smallestX = DBL_MAX;
    double largestX = DBL_MIN;
    double smallestY = DBL_MAX;
    double largestY = DBL_MIN;
    for(size_t i = 0; i < _points.size(); ++i) {
        if(_points[i].GetX() < smallestX) {
            smallestX = _points[i].GetX();
        }
        if(_points[i].GetX() > largestX) {
            largestX = _points[i].GetX();
        }
        if(_points[i].GetY() < smallestY) {
            smallestY = _points[i].GetY();
        }
        if(_points[i].GetY() > largestY) {
            largestY = _points[i].GetY();
        }
    }
    x = smallestX;
    y = smallestY;
}

Vector2D Polygon::GetSmallestCoordinates() const {
    double x;
    double y;
    GetSmallestCoordinates(x, y);
    return Vector2D(x, y);
}

Vector2D Polygon::GetSmallestCoordinates() {
    return static_cast<const Polygon&>(*this).GetSmallestCoordinates();
}

void Polygon::GetLargestCoordinates(double& x, double& y) const {
    double smallestX = DBL_MAX;
    double largestX = DBL_MIN;
    double smallestY = DBL_MAX;
    double largestY = DBL_MIN;
    for(size_t i = 0; i < _points.size(); ++i) {
        if(_points[i].GetX() < smallestX) {
            smallestX = _points[i].GetX();
        }
        if(_points[i].GetX() > largestX) {
            largestX = _points[i].GetX();
        }
        if(_points[i].GetY() < smallestY) {
            smallestY = _points[i].GetY();
        }
        if(_points[i].GetY() > largestY) {
            largestY = _points[i].GetY();
        }
    }
    x = largestX;
    y = largestY;
}

Vector2D Polygon::GetLargestCoordinates() const {
    double x;
    double y;
    GetLargestCoordinates(x, y);
    return Vector2D(x, y);
}

Vector2D Polygon::GetLargestCoordinates() {
    return static_cast<const Polygon&>(*this).GetLargestCoordinates();
}

Rectangle Polygon::GetBoundingBox() const {
    double smallX;
    double smallY;
    double largeX;
    double largeY;
    GetSmallestCoordinates(smallX, smallY);
    GetLargestCoordinates(largeX, largeY);

    Rectangle bb(smallX, smallY, largeX - smallX, largeY - smallY);
    return bb;
}

void Polygon::SetHalfExtents(double /*width*/, double /*height*/) { /* DO NOTHING */ }
void Polygon::SetHalfExtents(const Vector2D& /*dimensions*/) { /* DO NOTHING */ }
void Polygon::SetHalfWidth(double /*width*/) { /* DO NOTHING */ }
void Polygon::SetHalfHeight(double /*height*/) { /* DO NOTHING */ }

Polygon& Polygon::operator=(const Polygon& rhs) {
    if(this == &rhs) return *this;

    Shape::operator=(rhs);
    if(rhs._points.size() < 3) throw Exception("A polygon must have at least 3 vertices.");
    _type = Shape::SHAPETYPE_POLYGON;
    for(size_t i = 0; i < rhs._points.size(); ++i) {
        this->_points.push_back(rhs._points[i]);
    }
    CalculateArea();
    CalculateCenter();

    return *this;
}


A2DE_END