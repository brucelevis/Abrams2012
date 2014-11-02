/**************************************************************************************************
// file:	Engine\Math\CRectangle.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the rectangle class
 **************************************************************************************************/
#ifndef A2DE_CRECTANGLE_H
#define A2DE_CRECTANGLE_H

#include "../a2de_vals.h"
#include "CShape.h"
#include "CPoint.h"
#include "CLine.h"

struct ALLEGRO_BITMAP;

A2DE_BEGIN

class Circle;
class Ellipse;
class Triangle;
class Arc;
class Polygon;
class Spline;
class Sector;
class Vector2D;


class Rectangle : public Shape {

public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    Rectangle();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">          The x coordinate.</param>
     * <param name="y">          The y coordinate.</param>
     * <param name="half_width"> The half width.</param>
     * <param name="half_height">The half height.</param>
     **************************************************************************************************/
    Rectangle(double x, double y, double half_width, double half_height);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">   The position.</param>
     * <param name="half_width"> The half width.</param>
     * <param name="half_height">The half height.</param>
     **************************************************************************************************/
    Rectangle(const Vector2D& position, double half_width, double half_height);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">           The x coordinate.</param>
     * <param name="y">           The y coordinate.</param>
     * <param name="half_extents">The half extents.</param>
     **************************************************************************************************/
    Rectangle(double x, double y, const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">    The position.</param>
     * <param name="half_extents">The half extents.</param>
     **************************************************************************************************/
    Rectangle(const Vector2D& position, const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">          The x coordinate.</param>
     * <param name="y">          The y coordinate.</param>
     * <param name="half_width"> The half width.</param>
     * <param name="half_height">The half height.</param>
     * <param name="color">      The color.</param>
     **************************************************************************************************/
    Rectangle(double x, double y, double half_width, double half_height, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">   The position.</param>
     * <param name="half_width"> The half width.</param>
     * <param name="half_height">The half height.</param>
     * <param name="color">      The color.</param>
     **************************************************************************************************/
    Rectangle(const Vector2D& position, double half_width, double half_height, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">         The x coordinate.</param>
     * <param name="y">         The y coordinate.</param>
     * <param name="dimensions">The dimensions.</param>
     * <param name="color">     The color.</param>
     **************************************************************************************************/
    Rectangle(double x, double y, const Vector2D& half_extents, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">    The position.</param>
     * <param name="half_extents">The half extents.</param>
     * <param name="color">       The color.</param>
     **************************************************************************************************/
    Rectangle(const Vector2D& position, const Vector2D& half_extents, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">          The x coordinate.</param>
     * <param name="y">          The y coordinate.</param>
     * <param name="half_width"> The half width.</param>
     * <param name="half_height">The half height.</param>
     * <param name="color">      The color.</param>
     * <param name="filled">     true to filled.</param>
     **************************************************************************************************/
    Rectangle(double x, double y, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">   The position.</param>
     * <param name="half_width"> The half width.</param>
     * <param name="half_height">The half height.</param>
     * <param name="color">      The color.</param>
     * <param name="filled">     true to filled.</param>
     **************************************************************************************************/
    Rectangle(const Vector2D& position, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">           The x coordinate.</param>
     * <param name="y">           The y coordinate.</param>
     * <param name="half_extents">The half extents.</param>
     * <param name="color">       The color.</param>
     * <param name="filled">      true to filled.</param>
     **************************************************************************************************/
    Rectangle(double x, double y, const Vector2D& half_extents, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">    The position.</param>
     * <param name="half_extents">The half extents.</param>
     * <param name="color">       The color.</param>
     * <param name="filled">      true to filled.</param>
     **************************************************************************************************/
    Rectangle(const Vector2D& position, const Vector2D& half_extents, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rect">The rectangle.</param>
     **************************************************************************************************/
    Rectangle(const Rectangle& rect);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual ~Rectangle();

    /**************************************************************************************************
     * <summary>Sets the x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    virtual void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets the y coordinate.</summary>
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
     * <summary>Sets the half extents.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_width"> The width.</param>
     * <param name="half_height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(double half_width, double half_height);

    /**************************************************************************************************
     * <summary>Sets the half extents.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_extents">The half extents.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Sets the half width.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_width">The half width.</param>
     **************************************************************************************************/
    virtual void SetHalfWidth(double half_width);

    /**************************************************************************************************
     * <summary>Sets the half height.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="half_height">The half height.</param>
     **************************************************************************************************/
    virtual void SetHalfHeight(double half_height);

    /**************************************************************************************************
     * <summary>Gets the top.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The top.</returns>
     **************************************************************************************************/
    Line GetTop() const;

    /**************************************************************************************************
     * <summary>Gets the left.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The left.</returns>
     **************************************************************************************************/
    Line GetLeft() const;

    /**************************************************************************************************
     * <summary>Gets the bottom.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The bottom.</returns>
     **************************************************************************************************/
    Line GetBottom() const;

    /**************************************************************************************************
     * <summary>Gets the right.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The right.</returns>
     **************************************************************************************************/
    Line GetRight() const;

    /**************************************************************************************************
     * <summary>Gets the top left.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The top left.</returns>
     **************************************************************************************************/
    Point GetTopLeft() const;

    /**************************************************************************************************
     * <summary>Gets the top right.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The top right.</returns>
     **************************************************************************************************/
    Point GetTopRight() const;

    /**************************************************************************************************
     * <summary>Gets the bottom left.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The bottom left.</returns>
     **************************************************************************************************/
    Point GetBottomLeft() const;

    /**************************************************************************************************
     * <summary>Gets the bottom right.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The bottom right.</returns>
     **************************************************************************************************/
    Point GetBottomRight() const;

    /**************************************************************************************************
     * <summary>Draws.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, destination for the.</param>
     * <param name="color"> The color.</param>
     * <param name="filled">true to filled.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Query if this object intersects the given shape.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="shape">The shape.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Shape& shape) const;

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
     * <summary>Query if this object intersects the given rectangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rectangle">The rectangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Rectangle& rectangle) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given triangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="triangle">The triangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Triangle& triangle) const;

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
     * <summary>Query if this object intersects the given line.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="line">The line.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Line& line) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="point">The point.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Point& point) const;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given position.</summary>
     * <remarks>Casey Ugone, 8/23/2013.</remarks>
     * <param name="position">The position.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Vector2D& position) const;

    /**************************************************************************************************
     * <summary>Gets a rectangle that defines the overlap of this rectangle and another.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rectIN"> The other rectangle.</param>
     * <param name="rectOUT">The resultant rectangle.</param>
     * <param name="result"> If the resultant rectangle is valid.</param>
     **************************************************************************************************/
    void Overlap(const Rectangle& rectIN, Rectangle& rectOUT, bool& result);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Rectangle& operator=(const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="lhs">The first instance to compare.</param>
     * <param name="rhs">The second instance to compare.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    friend bool operator==(const Rectangle& lhs, const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     **************************************************************************************************/
    bool operator!=(const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="lhs">The first instance to compare.</param>
     * <param name="rhs">The second instance to compare.</param>
     **************************************************************************************************/
    friend bool operator!=(const Rectangle& lhs, const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Less-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    bool operator<(const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Less-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="lhs">The first instance to compare.</param>
     * <param name="rhs">The second instance to compare.</param>
     * <returns>true if the first parameter is less than the second.</returns>
     **************************************************************************************************/
    friend bool operator<(const Rectangle& lhs, const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Greater-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than to the second.</returns>
     **************************************************************************************************/
    bool operator>(const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Greater-than comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="lhs">The first instance to compare.</param>
     * <param name="rhs">The second instance to compare.</param>
     * <returns>true if the first parameter is greater than to the second.</returns>
     **************************************************************************************************/
    friend bool operator>(const Rectangle& lhs, const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Less-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is less than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator<=(const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Less-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="lhs">The first instance to compare.</param>
     * <param name="rhs">The second instance to compare.</param>
     * <returns>true if the first parameter is less than or equal to the second.</returns>
     **************************************************************************************************/
    friend bool operator<=(const Rectangle& lhs, const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Greater-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the first parameter is greater than or equal to the second.</returns>
     **************************************************************************************************/
    bool operator>=(const Rectangle& rhs);

    /**************************************************************************************************
     * <summary>Greater-than-or-equal comparison operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="lhs">The first instance to compare.</param>
     * <param name="rhs">The second instance to compare.</param>
     * <returns>true if the first parameter is greater than or equal to the second.</returns>
     **************************************************************************************************/
    friend bool operator>=(const Rectangle& lhs, const Rectangle& rhs);

private:

    /**************************************************************************************************
     * <summary>Calculates the center.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateCenter();

    /**************************************************************************************************
     * <summary>Calculates the area.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateArea();

};

A2DE_END

#endif