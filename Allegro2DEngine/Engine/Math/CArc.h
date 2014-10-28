/**************************************************************************************************
// file:	Engine\Math\CArc.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the arc class
 **************************************************************************************************/
#ifndef A2DE_CARC_H
#define A2DE_CARC_H

#include "../a2de_vals.h"
#include "CShape.h"

struct ALLEGRO_BITMAP;

A2DE_BEGIN

class Point;
class Line;
class Rectangle;
class Circle;
class Ellipse;
class Triangle;
class Polygon;
class Spline;
class Sector;

class Arc : public Shape {

public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">  The position.</param>
     * <param name="startAngle">The start angle.</param>
     * <param name="endAngle">  The end angle.</param>
     * <param name="radius">    The radius.</param>
     * <param name="color">     The color.</param>
     * <param name="filled">    true to filled.</param>
     **************************************************************************************************/
    Arc(const Vector2D& position, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">         The x coordinate.</param>
     * <param name="y">         The y coordinate.</param>
     * <param name="startAngle">The start angle.</param>
     * <param name="endAngle">  The end angle.</param>
     * <param name="radius">    The radius.</param>
     * <param name="color">     The color.</param>
     * <param name="filled">    true to filled.</param>
     **************************************************************************************************/
    Arc(double x, double y, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="arc">The arc.</param>
     **************************************************************************************************/
    Arc(const Arc& arc);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual ~Arc();
    
    /**************************************************************************************************
     * <summary>Gets the theta.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The theta.</returns>
     **************************************************************************************************/
    double GetTheta() const;

    /**************************************************************************************************
     * <summary>Gets the theta.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The theta.</returns>
     **************************************************************************************************/
    double GetTheta();
    
    /**************************************************************************************************
     * <summary>Gets the length.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length.</returns>
     **************************************************************************************************/
    double GetLength() const;

    /**************************************************************************************************
     * <summary>Gets the length.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The length.</returns>
     **************************************************************************************************/
    double GetLength();
    
    /**************************************************************************************************
     * <summary>Gets the radius.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The radius.</returns>
     **************************************************************************************************/
    double GetRadius() const;

    /**************************************************************************************************
     * <summary>Gets the radius.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The radius.</returns>
     **************************************************************************************************/
    double GetRadius();

    /**************************************************************************************************
     * <summary>Sets the radius.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="radius">The radius.</param>
     **************************************************************************************************/
    void SetRadius(double radius);

    /**************************************************************************************************
     * <summary>Sets an x coordinate.</summary>
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
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    virtual void SetPosition(double x, double y);

    /**************************************************************************************************
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    virtual void SetPosition(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Query if this object intersects the given position.</summary>
     * <remarks>Casey Ugone, 8/24/2013.</remarks>
     * <param name="position">The position.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Vector2D& position) const;

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
     * <summary>Query if this object fully contains the given shape.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="shape">The shape.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Shape& shape) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="point">The point.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Point& point) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given line.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="line">The line.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Line& line) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given rectangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rectangle">The rectangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Rectangle& rectangle) const;

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
     * <summary>Query if this object fully contains the given triangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="triangle">The triangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Triangle& triangle) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given arc.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="arc">The arc.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Arc& arc) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given polygon.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="polygon">The polygon.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Polygon& polygon) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given spline.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="spline">The spline.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Spline& spline) const;

    /**************************************************************************************************
     * <summary>Query if this object fully contains the given sector.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="sector">The sector.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Contains(const Sector& sector) const;

    /**************************************************************************************************
     * <summary>Draws.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, destination for the.</param>
     * <param name="color"> The color.</param>
     * <param name="filled">true to filled.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Sets the angles in degrees.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="startAngle">The start angle.</param>
     * <param name="endAngle">  The end angle.</param>
     **************************************************************************************************/
    void SetAnglesDegrees(double startAngle, double endAngle);

    /**************************************************************************************************
     * <summary>Sets the angles.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="startAngle">The start angle.</param>
     * <param name="endAngle">  The end angle.</param>
     **************************************************************************************************/
    void SetAngles(double startAngle, double endAngle);

    /**************************************************************************************************
     * <summary>Gets the start angle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The start angle.</returns>
     **************************************************************************************************/
    double GetStartAngle() const;

    /**************************************************************************************************
     * <summary>Gets the start angle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The start angle.</returns>
     **************************************************************************************************/
    double GetStartAngle();
    
    /**************************************************************************************************
     * <summary>Gets the end angle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end angle.</returns>
     **************************************************************************************************/
    double GetEndAngle() const;

    /**************************************************************************************************
     * <summary>Gets the end angle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end angle.</returns>
     **************************************************************************************************/
    double GetEndAngle();

    /**************************************************************************************************
     * <summary>Gets the start point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The start point.</returns>
     **************************************************************************************************/
    Vector2D GetStartPoint() const;

    /**************************************************************************************************
     * <summary>Gets the end point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end point.</returns>
     **************************************************************************************************/
    Vector2D GetEndPoint() const;

    /**************************************************************************************************
     * <summary>Gets the center point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The center point.</returns>
     **************************************************************************************************/
    Vector2D GetCenterPoint() const;

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Arc& operator=(const Arc& rhs);

protected:

    /**************************************************************************************************
     * <summary>Sets a width.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="width">The width.</param>
     **************************************************************************************************/
    virtual void SetHalfWidth(double half_width);

    /**************************************************************************************************
     * <summary>Sets a height.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfHeight(double half_height);

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(double half_width, double half_height);

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Calculates the area.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateArea();

    /**************************************************************************************************
     * <summary>Calculates the length.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateLength();

    /// <summary> The start angle </summary>
    double _startAngle;
    /// <summary> The end angle </summary>
    double _endAngle;
    /// <summary> The radius </summary>
    double _radius;
    /// <summary> The theta </summary>
    double _theta;
    /// <summary> The length </summary>
    double _length;

    /// <summary> The sector </summary>
    friend Sector;
};

A2DE_END

#endif