/**************************************************************************************************
// file:	Engine\Math\CSector.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the sector class
 **************************************************************************************************/
#include "CSector.h"

#include "CPoint.h"
#include "CLine.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CArc.h"
#include "CPolygon.h"
#include "CSpline.h"

#include "MathConstants.h"
#include "CMiscMath.h"
#include "../a2de_exceptions.h"

A2DE_BEGIN


Sector::Sector(double x, double y, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled) : Shape(x, y, (radius < 0.0 ? 0.0 : radius * 2), (radius < 0.0 ? 0.0 : radius * 2), color, filled), _arc(x, y, startAngle, endAngle, (radius < 0.0 ? 0.0 : radius), color, filled) {
    _type = Shape::SHAPETYPE_SECTOR;
    SetAngles(_arc.GetStartAngle(), _arc.GetEndAngle());
    CalculateArea();
}
Sector::Sector(const Vector2D& position, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled) : Shape(position, (radius < 0.0 ? 0.0 : radius * 2), (radius < 0.0 ? 0.0 : radius * 2), color, filled), _arc(position, startAngle, endAngle, (radius < 0.0 ? 0.0 : radius), color, filled) {
    _type = Shape::SHAPETYPE_SECTOR;
    SetAngles(_arc.GetStartAngle(), _arc.GetEndAngle());
    CalculateArea();
}

Sector::Sector(const Sector& sector) : Shape(sector), _arc(sector._arc) {
    _type = Shape::SHAPETYPE_SECTOR;
    SetAngles(sector._arc.GetStartAngle(), sector._arc.GetEndAngle());
    CalculateArea();
}

Sector::~Sector() {
    /* DO NOTHING. ALL DE-INITIALIZATION DONE IN BASE CLASS */
}


void Sector::SetX(double x) {
    SetPosition(x, GetY());
}
void Sector::SetY(double y) {
    SetPosition(GetX(), y);
}
void Sector::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}
void Sector::SetPosition(const Vector2D& position) {
    _arc.SetPosition(position);
    _position = position;
}

void Sector::SetHalfWidth(double width) {
    SetHalfExtents(width, GetHalfHeight());
}
void Sector::SetHalfHeight(double height) {
    SetHalfExtents(GetHalfWidth(), height);
}
void Sector::SetHalfExtents(double width, double height) {
    SetHalfExtents(Vector2D(width, height));
}
void Sector::SetHalfExtents(const Vector2D& dimensions) {
    _half_extents = Vector2D((dimensions.GetX() < 0.0 ? 0.0 : dimensions.GetX()), (dimensions.GetY() < 0.0 ? 0.0 : dimensions.GetY()));
    _arc.SetHalfExtents(_half_extents);
}

void Sector::SetRadius(double radius) {
    if(radius < 0.0) radius = 0.0;
    SetHalfExtents(Vector2D(radius * 2.0, radius * 2.0));
}

void Sector::SetAngles(double startAngle, double endAngle) {
    _arc.SetAngles(startAngle, endAngle);
    CalculateArea();
}

double Sector::GetLength() const {
    return _arc.GetLength();
}
double Sector::GetLength(){
    return static_cast<const Sector&>(*this).GetLength();
}

double Sector::GetRadius() const {
    return _arc.GetRadius();
}
double Sector::GetRadius(){
    return static_cast<const Sector&>(*this).GetRadius();
}

double Sector::GetTheta() const {
    return _arc.GetTheta();
}
double Sector::GetTheta(){
    return static_cast<const Sector&>(*this).GetTheta();
}

double Sector::GetStartAngle() const {
    return _arc.GetStartAngle();
}
double Sector::GetStartAngle() {
    return static_cast<const Sector&>(*this).GetStartAngle();
}

double Sector::GetEndAngle() const {
    return _arc.GetEndAngle();
}
double Sector::GetEndAngle() {
    return static_cast<const Sector&>(*this).GetEndAngle();
}

Point Sector::GetStartPoint() const {
    return _arc.GetStartPoint();
}
Point Sector::GetEndPoint() const {
    return _arc.GetEndPoint();
}

Point Sector::GetCenterPoint() const {
    return _position;
}

const a2de::Vector2D& Sector::GetArcCenter() const {
    return _arc.GetPosition();
}

a2de::Vector2D& Sector::GetArcCenter() {
    return const_cast<Vector2D&>(static_cast<const Sector&>(*this).GetArcCenter());
}

Point Sector::GetArcCenterPoint() const {
    return _arc.GetCenterPoint();
}


void Sector::Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled) {

    Line initial(GetPosition(), GetStartPoint().GetPosition(), color);
    Line terminal(GetPosition(), GetEndPoint().GetPosition(), color);

    initial.Draw(dest, initial.GetColor(), false);
    terminal.Draw(dest, terminal.GetColor(), false);

    _arc.Draw(dest, color, filled);

    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();

    filled ? al_draw_filled_pieslice(a2de::Math::ToScreenScale(GetX()), a2de::Math::ToScreenScale(GetY()), a2de::Math::ToScreenScale(GetRadius()), GetStartAngle(), GetEndAngle() - GetStartAngle(), color) :
             al_draw_pieslice(a2de::Math::ToScreenScale(GetX()), a2de::Math::ToScreenScale(GetY()), a2de::Math::ToScreenScale(GetRadius()), GetStartAngle(), GetEndAngle() - GetStartAngle(), color, 0.0);

    al_set_target_bitmap(old_target);

}

void Sector::CalculateArea() {
    _area = 0.5 * (GetRadius() * GetRadius() * GetTheta());
}

bool Sector::Intersects(const Shape& shape) const {
    return shape.Intersects(*this);
}

bool Sector::Intersects(const Point& point) const {
    return Intersects(point.GetPosition());
}

bool Sector::Intersects(const Line& line) const {
    if(this->Intersects(Point(line.GetPointOne()))) return true;
    if(this->Intersects(Point(line.GetPointTwo()))) return true;

    Line initial(GetPosition(), GetStartPoint().GetPosition());
    Line terminal(GetPosition(), GetEndPoint().GetPosition());

    if(initial.Intersects(line)) return true;
    if(terminal.Intersects(line)) return true;

    return false;
}

bool Sector::Intersects(const Rectangle& rectangle) const {

    Circle s(this->GetPosition(), this->GetRadius(), this->GetColor(), this->IsFilled());

    if(rectangle.Intersects(s) == false) return false;
    if(rectangle.Intersects(Point(this->GetPosition()))) return true;

    if(this->Intersects(rectangle.GetTopLeft())) return true;
    if(this->Intersects(rectangle.GetTopRight())) return true;
    if(this->Intersects(rectangle.GetBottomLeft())) return true;
    if(this->Intersects(rectangle.GetBottomRight())) return true;

    if(this->Intersects(rectangle.GetTop())) return true;
    if(this->Intersects(rectangle.GetLeft())) return true;
    if(this->Intersects(rectangle.GetBottom())) return true;
    if(this->Intersects(rectangle.GetRight())) return true;

    return false;
}

bool Sector::Intersects(const Circle& circle) const {

    //Intersections performed fast to slow.
    //FAST:
    //If bounding circle and argument circle do not intersect: no.
    //If initial point intersects circle: yes.
    //If terminal point intersects circle: yes.
    //If central point intersects circle: yes.
    //SLOW:
    //If the angle between the circle and the sector is in-between the start and end angles (mapped to [0, 2pi]): yes.
    //If the circle intersects the initial line: yes.
    //If the circle intersects the terminal line: yes.
    //Otherwise: no.

    double my_x = this->GetX();
    double my_y = this->GetY();
    double your_x = circle.GetX();
    double your_y = circle.GetY();
    double radius_sum = this->GetRadius() + circle.GetRadius();
    if(a2de::Point::GetDistance(my_x, my_y, your_x, your_y) > radius_sum) return false;

    if(this->GetStartPoint().Intersects(circle)) return true;
    if(this->GetEndPoint().Intersects(circle)) return true;
    if(Point(this->GetPosition()).Intersects(circle)) return true;
    
    double angle = Vector2D::GetFacingAngle(circle.GetPosition(), this->GetPosition());

    //Map return values to [0, 360]
    double sA = this->GetStartAngle();
    if(sA > Math::A2DE_PI) {
        sA -= Math::A2DE_2PI;
    }
    double eA = this->GetEndAngle();
    if(eA > Math::A2DE_PI) {
        eA -= Math::A2DE_2PI;
    }
    bool within_sector = (sA <= angle && angle <= eA);
    if(within_sector) return true;

    Line sl(this->GetPosition(), this->GetStartPoint().GetPosition());
    Line tl(this->GetPosition(), this->GetEndPoint().GetPosition());

    if(sl.Intersects(circle)) return true;
    if(tl.Intersects(circle)) return true;

    return false;
}

bool Sector::Intersects(const Ellipse& /*ellipse*/) const {
    return false;
}

bool Sector::Intersects(const Triangle& triangle) const {

    Line il(this->GetPosition(), this->GetStartPoint().GetPosition());
    Line tl(this->GetPosition(), this->GetEndPoint().GetPosition());
    Circle s(this->GetPosition(), this->GetRadius(), this->GetColor(), this->IsFilled());

    bool circle_intersect = triangle.Intersects(s);
    if(circle_intersect == false) return false;

    bool il_intersect = triangle.Intersects(il);
    if(il_intersect) return true;

    bool tl_intersect = triangle.Intersects(tl);
    if(tl_intersect) return true;

    bool c_intersect = triangle.Intersects(Point(this->GetPosition()));
    if(c_intersect) return true;

    return false;
}

bool Sector::Intersects(const Arc& /*arc*/) const {
    return false;
}

bool Sector::Intersects(const Polygon& /*polygon*/) const {
    return false;
}

bool Sector::Intersects(const Spline& /*spline*/) const {
    return false;
}

bool Sector::Intersects(const Sector& /*sector*/) const {
    return false;
}

bool Sector::Intersects(const Vector2D& position) const {
    Vector2D l(this->GetPosition() - position);
    if(l.GetLength() > GetRadius()) return false;
    if(Math::IsEqual(l.GetLength(), 0.0)) return true;

    Vector2D sF = Vector2D::GetFacingVector(this->GetArcCenter(), this->GetPosition());
    Vector2D sF_n(sF.Normalize());
    Vector2D P_to_S(l.Normalize());

    double angle = std::acos(Vector2D::DotProduct(sF_n, P_to_S));

    return (angle <= GetTheta() / 2.0);
}

void Sector::SetAnglesDegrees(double startAngle, double endAngle) {
    SetAngles(a2de::Math::DegreeToRadian(startAngle), a2de::Math::DegreeToRadian(endAngle));
}

Sector& Sector::operator=(const Sector& rhs) {
    if(this == &rhs) return *this;

    Shape::operator=(rhs);
    SetAngles(rhs._arc.GetStartAngle(), rhs._arc.GetEndAngle());
    CalculateArea();

    return *this;
}


A2DE_END