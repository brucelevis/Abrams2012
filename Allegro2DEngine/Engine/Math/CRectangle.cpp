/**************************************************************************************************
// file:	Engine\Math\CRectangle.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the rectangle class
 **************************************************************************************************/
#define NOMINMAX

#include "CRectangle.h"

#include <utility>
#include <algorithm>

#include "CPoint.h"
#include "CLine.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CArc.h"
#include "CPolygon.h"
#include "CSpline.h"
#include "CSector.h"
#include "CVector2D.h"

#include "CMiscMath.h"
#include "../a2de_exceptions.h"

A2DE_BEGIN

Rectangle::Rectangle() : Shape(0.0, 0.0) {
    _type = Shape::SHAPETYPE_RECTANGLE;
    CalculateCenter();
    CalculateArea();

}

Rectangle::Rectangle(double x, double y, double half_width, double half_height)
    : Shape(x, y, half_width, half_height) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(const Vector2D& position, double half_width, double half_height)
    : Shape(position, half_width, half_height) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(double x, double y, const Vector2D& half_extents)
    : Shape(x, y, half_extents) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(const Vector2D& position, const Vector2D& half_extents)
    : Shape(position, half_extents) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}

Rectangle::Rectangle(double x, double y, double half_width, double half_height, const ALLEGRO_COLOR& color)
    : Shape(x, y, half_width, half_height, color) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(const Vector2D& position, double half_width, double half_height, const ALLEGRO_COLOR& color)
    : Shape(position, half_width, half_height, color) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(double x, double y, const Vector2D& half_extents, const ALLEGRO_COLOR& color)
    : Shape(x, y, half_extents, color) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(const Vector2D& position, const Vector2D& half_extents, const ALLEGRO_COLOR& color)
    : Shape(position, half_extents, color) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}

Rectangle::Rectangle(double x, double y, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled)
    : Shape(x, y, half_width, half_height, color, filled) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(const Vector2D& position, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled)
    : Shape(position, half_width, half_height, color, filled) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(double x, double y, const Vector2D& half_extents, const ALLEGRO_COLOR& color, bool filled)
    : Shape(x, y, half_extents, color, filled) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}
Rectangle::Rectangle(const Vector2D& position, const Vector2D& half_extents, const ALLEGRO_COLOR& color, bool filled)
    : Shape(position, half_extents, color, filled) {
        _type = Shape::SHAPETYPE_RECTANGLE;
        CalculateCenter();
        CalculateArea();
}

Rectangle::Rectangle(const Rectangle& rect) : Shape(rect) {
    _type = Shape::SHAPETYPE_RECTANGLE;
    CalculateCenter();
    CalculateArea();
}

Rectangle::~Rectangle() {

}
Line Rectangle::GetTop() const {
    return Line(GetX() - GetHalfWidth(), GetY() - GetHalfHeight(), GetX() + GetHalfWidth(), GetY() + GetHalfHeight());
}
Line Rectangle::GetLeft() const {
    return Line(GetX() - GetHalfWidth(), GetY() + GetHalfHeight(), GetX() - GetHalfWidth(), GetY() - GetHalfHeight());
}
Line Rectangle::GetBottom() const {
    return Line(GetX() - GetHalfWidth(), GetY() + GetHalfHeight(), GetX() + GetHalfWidth(), GetY() + GetHalfHeight());
}
Line Rectangle::GetRight() const {
    return Line(GetX() + GetHalfWidth(), GetY() - GetHalfHeight(), GetX() + GetHalfWidth(), GetY() + GetHalfHeight());
}
Point Rectangle::GetTopLeft() const {
    return Point(GetX() - GetHalfWidth(), GetY() - GetHalfHeight());
}
Point Rectangle::GetTopRight() const {
    return Point(GetX() + GetHalfWidth(), GetY() - GetHalfHeight());
}
Point Rectangle::GetBottomLeft() const {
    return Point(GetX() - GetHalfWidth(), GetY() + GetHalfHeight());
}
Point Rectangle::GetBottomRight() const {
    return Point(GetX() + GetHalfWidth(), GetY() + GetHalfHeight());
}

void Rectangle::SetX(double x) {
    SetPosition(x, GetY());
}

void Rectangle::SetY(double y) {
    SetPosition(GetX(), y);
}

void Rectangle::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}

void Rectangle::SetPosition(const Vector2D& position) {
    Shape::SetPosition(position);
    CalculateCenter();
}

void Rectangle::SetHalfExtents(double half_width, double half_height) {
    if(half_width < 0.0) half_width = 0.0;
    if(half_height < 0.0) half_height = 0.0;
    SetHalfExtents(Vector2D(half_width, half_height));
}

void Rectangle::SetHalfExtents(const Vector2D& half_extents) {
    Shape::SetHalfExtents(half_extents);
    CalculateCenter();
    CalculateArea();
}

void Rectangle::SetHalfWidth(double half_width) {
    SetHalfExtents(half_width, GetHalfHeight());
}

void Rectangle::SetHalfHeight(double half_height) {
    SetHalfExtents(GetHalfWidth(), half_height);
}

void Rectangle::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled) {
    double x1 = a2de::Math::ToScreenScale(GetX() - GetHalfWidth());
    double y1 = a2de::Math::ToScreenScale(GetY() - GetHalfHeight());
    double x2 = a2de::Math::ToScreenScale(GetX() + GetHalfWidth());
    double y2 = a2de::Math::ToScreenScale(GetY() + GetHalfHeight());

    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(dest);

    filled ? al_draw_filled_rectangle(x1, y1, x2, y2, color) : al_draw_rectangle(x1, y1, x2, y2, color, 0.0);

    al_set_target_bitmap(old_target);

}

bool Rectangle::Intersects(const Polygon& polygon) const {
    return polygon.Intersects(*this);
}
bool Rectangle::Intersects(const Rectangle& rectangle) const {
    
    double myX = this->GetX();
    double myY = this->GetY();
    double myWidth = this->GetHalfWidth();
    double myHeight = this->GetHalfHeight();
    
    double myTop = myY - myHeight;
    double myLeft = myX - myWidth;
    double myRight = myX + myWidth;
    double myBottom = myY + myHeight;

    double rX = rectangle.GetX();
    double rY = rectangle.GetY();
    double rWidth = rectangle.GetHalfWidth();
    double rHeight = rectangle.GetHalfHeight();

    double rTop = rY - rHeight;
    double rLeft = rX - rWidth;
    double rRight = rX + rWidth;
    double rBottom = rY + rHeight;

    if(myTop > rBottom) return false;
    if(myBottom < rTop) return false;
    if(myLeft > rRight) return false;
    if(myRight < rLeft) return false;

    return true;
}
bool Rectangle::Intersects(const Triangle& /*triangle*/) const {
    return false;
    //bool resultTop = GetTop().Intersects(triangle.GetLineAB()) ||
    //    GetTop().Intersects(triangle.GetLineBC()) ||
    //    GetTop().Intersects(triangle.GetLineCA());
    //bool resultLeft = GetLeft().Intersects(triangle.GetLineAB()) ||
    //    GetLeft().Intersects(triangle.GetLineBC()) ||
    //    GetLeft().Intersects(triangle.GetLineCA());
    //bool resultRight = GetRight().Intersects(triangle.GetLineAB()) ||
    //    GetRight().Intersects(triangle.GetLineBC()) ||
    //    GetRight().Intersects(triangle.GetLineCA());
    //bool resultBottom = GetBottom().Intersects(triangle.GetLineAB()) ||
    //    GetBottom().Intersects(triangle.GetLineBC()) ||
    //    GetBottom().Intersects(triangle.GetLineCA());
    //bool isInside = Intersects(Point(triangle.GetCenter(), triangle.GetColor()));
    //return (isInside || resultTop || resultLeft || resultRight || resultBottom);
}
bool Rectangle::Intersects(const Ellipse& ellipse) const {

    double ellipseResultWidth = ellipse.GetRadiusWidth();
    double ellipseResultHeight = ellipse.GetRadiusHeight();

    double distTop = Point(ellipse.GetPosition()).GetDistance(GetTop());
    double distLeft = Point(ellipse.GetPosition()).GetDistance(GetLeft());
    double distRight = Point(ellipse.GetPosition()).GetDistance(GetRight());
    double distBottom = Point(ellipse.GetPosition()).GetDistance(GetBottom());

    bool resultTop = (distTop <= ellipseResultWidth) || (distTop <= ellipseResultHeight);
    bool resultLeft = (distLeft <= ellipseResultWidth) || (distLeft <= ellipseResultHeight);
    bool resultRight = (distRight <= ellipseResultWidth) || (distRight <= ellipseResultHeight);
    bool resultBottom = (distBottom <= ellipseResultWidth) || (distBottom <= ellipseResultHeight);

    return (resultTop || resultLeft || resultRight || resultBottom);
}
bool Rectangle::Intersects(const Circle& circle) const {

    double radius = circle.GetRadius();

    double distTop = Point(circle.GetPosition()).GetDistance(GetTop());
    double distLeft = Point(circle.GetPosition()).GetDistance(GetLeft());
    double distRight = Point(circle.GetPosition()).GetDistance(GetRight());
    double distBottom = Point(circle.GetPosition()).GetDistance(GetBottom());

    bool resultTop = distTop <= radius;
    bool resultLeft = distLeft <= radius;
    bool resultRight = distRight <= radius;
    bool resultBottom = distBottom <= radius;
    bool isInside = Intersects(Point(circle.GetPosition()));
    return (isInside || resultTop || resultLeft || resultRight || resultBottom);
}

bool Rectangle::Intersects(const Line& line) const {
    return line.Intersects(*this);
}

bool Rectangle::Intersects(const Point& point) const {
    return Intersects(point.GetPosition());
}

bool Rectangle::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}

bool Rectangle::Intersects(const Arc& /*arc*/) const {
    return false;
}

bool Rectangle::Intersects(const Spline& /*spline*/) const {
    return false;
}

bool Rectangle::Intersects(const Sector& /*sector*/) const {
    return false;
}

bool Rectangle::Intersects(const Vector2D& position) const {

    double rX = this->GetX();
    double rHalfWidth = this->GetHalfWidth();
    double rLeft = rX - rHalfWidth;
    double rRight = rX + rHalfWidth;

    double rY = this->GetY();
    double rHalfHeight = this->GetHalfHeight();
    double rTop = rY - rHalfHeight;
    double rBottom = rY + rHalfHeight;

    double pX = position.GetX();
    double pY = position.GetY();

    if(rLeft > pX) return false;
    if(rRight < pX) return false;
    if(rTop > pY) return false;
    if(rBottom < pY) return false;

    return true;
}

void Rectangle::Overlap(const Rectangle& rectIN, Rectangle& rectOUT, bool& result) {
    if(this->Intersects(rectIN) == false) {
        result = false;
        return;
    }

    a2de::Vector2D my_TL(this->_position - this->_half_extents);
    a2de::Vector2D my_BR(this->_position + this->_half_extents);

    a2de::Vector2D your_TL(rectIN._position - rectIN._half_extents);
    a2de::Vector2D your_BR(rectIN._position + rectIN._half_extents);

    a2de::Vector2D topLeft(std::max(my_TL.GetX(), your_TL.GetX()), std::max(my_TL.GetY(), your_TL.GetY()));
    a2de::Vector2D bottomRight(std::min(my_BR.GetX(), your_BR.GetX()), std::min(my_BR.GetY(), your_BR.GetY()));

    rectOUT = Rectangle(topLeft, bottomRight);
    result = true;
}

Rectangle& Rectangle::operator=(const Rectangle& rhs) {
    if(this == &rhs) return *this;

    Shape::operator=(rhs);
    CalculateCenter();
    CalculateArea();

    return *this;
}

bool Rectangle::operator==(const Rectangle& rhs) {
    if(this == &rhs) return true;
    return (this->GetArea() == rhs.GetArea());
}
bool operator==(const Rectangle& lhs, const Rectangle& rhs) {
    if(&lhs == &rhs) return true;
    return (lhs.GetArea() == rhs.GetArea());
}
bool Rectangle::operator!=(const Rectangle& rhs) {
    return !(*this == rhs);
}
bool operator!=(const Rectangle& lhs, const Rectangle& rhs) {
    if(&lhs == &rhs) return false;
    return (lhs.GetArea() != rhs.GetArea());
}
bool Rectangle::operator<(const Rectangle& rhs) {
    if(this == &rhs) return false;
    return (this->GetArea() < rhs.GetArea());
}
bool operator<(const Rectangle& lhs, const Rectangle& rhs) {
    if(&lhs == &rhs) return false;
    return (lhs.GetArea() < rhs.GetArea());
}
bool Rectangle::operator>(const Rectangle& rhs) {
    if(this == &rhs) return false;
    return (this->GetArea() > rhs.GetArea());
}
bool operator>(const Rectangle& lhs, const Rectangle& rhs) {
    if(&lhs == &rhs) return false;
    return (lhs.GetArea() > rhs.GetArea());
}
bool Rectangle::operator<=(const Rectangle& rhs) {
    return !(*this > rhs);
}
bool operator<=(const Rectangle& lhs, const Rectangle& rhs) {
    return !(lhs.GetArea() < rhs.GetArea());
}

bool Rectangle::operator>=(const Rectangle& rhs) {
    return !(*this < rhs);
}
bool operator>=(const Rectangle& lhs, const Rectangle& rhs) {
    return !(lhs.GetArea() > rhs.GetArea());
}

void Rectangle::CalculateCenter() {
    /* DO NOTHING */
}

void Rectangle::CalculateArea() {
    _area = (4.0) * (_half_extents.GetX() * _half_extents.GetY());
}

A2DE_END