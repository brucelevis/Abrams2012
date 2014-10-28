/**************************************************************************************************
// file:	Engine\Math\CTriangle.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the triangle class
 **************************************************************************************************/
#ifndef A2DE_CTRIANGLE_H
#define A2DE_CTRIANGLE_H

#include "../a2de_vals.h"

#include "CShape.h"

#include <tuple>

#include "CPoint.h"
#include "CLine.h"

A2DE_BEGIN


class Rectangle;
class Circle;
class Ellipse;
class Arc;
class Polygon;
class Spline;
class Sector;

class Triangle : public Shape {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x1">    The first point's x value.</param>
     * <param name="y1">    The first point's y value.</param>
     * <param name="x2">    The second point's x value.</param>
     * <param name="y2">    The second point's y value.</param>
     * <param name="x3">    The third point's x value.</param>
     * <param name="y3">    The third point's y value.</param>
     * <param name="color"> The color.</param>
     * <param name="filled">true to filled.</param>
     **************************************************************************************************/
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="pointOne">  The point one.</param>
     * <param name="pointTwo">  The point two.</param>
     * <param name="pointThree">The point three.</param>
     * <param name="color">     The color.</param>
     * <param name="filled">    true to filled.</param>
     **************************************************************************************************/
    Triangle(const Vector2D& pointOne, const Vector2D& pointTwo, const Vector2D& pointThree, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="triangle">The triangle.</param>
     **************************************************************************************************/
    Triangle(const Triangle& triangle);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual ~Triangle();
    
    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    virtual double GetX() const;

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    virtual double GetX();
    
    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    virtual double GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    virtual double GetY();

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_width"> The width.</param>
     * <param name="half_height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(double half_width, double half_height);

    /**************************************************************************************************
     * <summary>Sets the half extents.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_extents">The dimensions.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Sets the half width.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_width">The width.</param>
     **************************************************************************************************/
    virtual void SetHalfWidth(double half_width);

    /**************************************************************************************************
     * <summary>Sets the half height.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfHeight(double half_height);

    /**************************************************************************************************
     * <summary>Sets the x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    virtual void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets a y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    virtual void SetY(double y);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    virtual void SetPosition(double x, double y);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    virtual void SetPosition(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Query if this object intersects the given position.</summary>
     * <remarks>Casey Ugone, 8/23/2013.</remarks>
     * <param name="position">The position.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const a2de::Vector2D& position) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given shape.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="shape">The shape.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Shape& shape) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="point">The point.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Point& point) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given line.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="line">The line.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Line& line) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given rectangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rectangle">The rectangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Rectangle& rectangle) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given circle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="circle">The circle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Circle& circle) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given ellipse.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="ellipse">The ellipse.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Ellipse& ellipse) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given triangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="triangle">The triangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Triangle& triangle) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given arc.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="arc">The arc.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Arc& arc) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given polygon.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="polygon">The polygon.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Polygon& polygon) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given spline.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="spline">The spline.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Spline& spline) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given sector.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="sector">The sector.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Sector& sector) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given circle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="circle">The circle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Circle& circle) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given ellipse.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="ellipse">The ellipse.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Ellipse& ellipse) const;

    /**************************************************************************************************
     * <summary>Draws the triangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, destination BITMAP.</param>
     * <param name="color"> The color.</param>
     * <param name="filled">true to filled.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Gets the first point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The point a.</returns>
     **************************************************************************************************/
    const Vector2D& GetPointA() const;

    /**************************************************************************************************
     * <summary>Gets the first point.</summary>
     * <remarks>Casey Ugone, 5/3/2013.</remarks>
     * <returns>The point a.</returns>
     **************************************************************************************************/
    Vector2D& GetPointA();

    /**************************************************************************************************
     * <summary>Gets the second point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The point b.</returns>
     **************************************************************************************************/
    const Vector2D& GetPointB() const;

    /**************************************************************************************************
     * <summary>Gets the second point.</summary>
     * <remarks>Casey Ugone, 5/3/2013.</remarks>
     * <returns>The point b.</returns>
     **************************************************************************************************/
    Vector2D& GetPointB();

    /**************************************************************************************************
     * <summary>Gets the third point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The point c.</returns>
     **************************************************************************************************/
    const Vector2D& GetPointC() const;

    /**************************************************************************************************
     * <summary>Gets the third point.</summary>
     * <remarks>Casey Ugone, 5/3/2013.</remarks>
     * <returns>The point c.</returns>
     **************************************************************************************************/
    Vector2D& GetPointC();

    /**************************************************************************************************
     * <summary>Gets line AB.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The line a b.</returns>
     **************************************************************************************************/
    Vector2D GetLineAB() const;

    /**************************************************************************************************
     * <summary>Gets line BC.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The line bc.</returns>
     **************************************************************************************************/
    Vector2D GetLineBC() const;

    /**************************************************************************************************
     * <summary>Gets line CA.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The line ca.</returns>
     **************************************************************************************************/
    Vector2D GetLineCA() const;

    /**************************************************************************************************
     * <summary>Gets the length of side BC.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length of side BC.</returns>
     **************************************************************************************************/
    double GetSideA() const;

    /**************************************************************************************************
     * <summary>Gets the length of side CA.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length of side CA.</returns>
     **************************************************************************************************/
    double GetSideB() const;

    /**************************************************************************************************
     * <summary>Gets the length of side AB.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length of side AB.</returns>
     **************************************************************************************************/
    double GetSideC() const;

    /**************************************************************************************************
     * <summary>Gets length of angle A.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length of angle A.</returns>
     **************************************************************************************************/
    double GetAngleA() const;

    /**************************************************************************************************
     * <summary>Gets the length of angle B.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length of angle B.</returns>
     **************************************************************************************************/
    double GetAngleB() const;

    /**************************************************************************************************
     * <summary>Gets the length of angle C.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length of angle C.</returns>
     **************************************************************************************************/
    double GetAngleC() const;

    /**************************************************************************************************
     * <summary>Query if this object is right triangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>true if right triangle, false if not.</returns>
     **************************************************************************************************/
    bool IsRightTriangle() const;

    /**************************************************************************************************
     * <summary>Sets the position of point A.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPointA(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Sets the position of point B.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPointB(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Sets the position of point C.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPointC(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Sets the position of point A.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="A">Point A.</param>
     **************************************************************************************************/
    void SetPointA(const Point& A);

    /**************************************************************************************************
     * <summary>Sets the position of point B.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="B">Point B.</param>
     **************************************************************************************************/
    void SetPointB(const Point& B);

    /**************************************************************************************************
     * <summary>Sets the position of point C.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="C">Point C.</param>
     **************************************************************************************************/
    void SetPointC(const Point& C);

    /**************************************************************************************************
     * <summary>Sets the position of point A.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetPointA(double x, double y);

    /**************************************************************************************************
     * <summary>Sets the position of point B.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetPointB(double x, double y);

    /**************************************************************************************************
     * <summary>Sets the position of point C.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetPointC(double x, double y);

    /**************************************************************************************************
     * <summary>Sets the position of all three points.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="xA">The x coordinate of point A.</param>
     * <param name="yA">The y coordinate of point A.</param>
     * <param name="xB">The x coordinate of point B.</param>
     * <param name="yB">The y coordinate of point B.</param>
     * <param name="xC">The x coordinate of point C.</param>
     * <param name="yC">The y coordinate of point C.</param>
     **************************************************************************************************/
    void SetPoints(double xA, double yA, double xB, double yB, double xC, double yC);

    /**************************************************************************************************
     * <summary>Sets the position of all three points.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="pointA">Point A.</param>
     * <param name="pointB">Point B.</param>
     * <param name="pointC">Point C.</param>
     **************************************************************************************************/
    void SetPoints(const Vector2D& pointA, const Vector2D& pointB, const Vector2D& pointC);

    /**************************************************************************************************
     * <summary>Sets the position of all three points.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="A">Point A.</param>
     * <param name="B">Point B.</param>
     * <param name="C">Point C.</param>
     **************************************************************************************************/
    void SetPoints(const Point& A, const Point& B, const Point& C);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/8/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    Triangle& operator=(const Triangle& rhs);

protected:

    /**************************************************************************************************
     * <summary>Calculates the area.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateArea();

    /**************************************************************************************************
     * <summary>Calculates the lines.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="pointOne">  The point one.</param>
     * <param name="pointTwo">  The point two.</param>
     * <param name="pointThree">The point three.</param>
     **************************************************************************************************/
    void CalculateLines(const Point& pointOne, const Point& pointTwo, const Point& pointThree);

    /**************************************************************************************************
     * <summary>Calculates the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    void CalculateDimensions();

    /// <summary> The points </summary>
    Vector2D _pointA;
    Vector2D _pointB;
    Vector2D _pointC;

};

A2DE_END

#endif