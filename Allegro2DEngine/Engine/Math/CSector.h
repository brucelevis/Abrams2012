/**************************************************************************************************
// file:	Engine\Math\CSector.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the sector class
 **************************************************************************************************/
#ifndef A2DE_CSECTOR_H
#define A2DE_CSECTOR_H

#include "../a2de_vals.h"
#include "CArc.h"

struct ALLEGRO_BITMAP;

A2DE_BEGIN

class Point;
class Line;
class Rectangle;
class Circle;
class Ellipse;
class Triangle;
class Arc;
class Polygon;
class Spline;
class Vector2D;

class Sector : public Shape {

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
    Sector(const Vector2D& position, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled);

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
    Sector(double x, double y, double startAngle, double endAngle, double radius, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="sector">The sector.</param>
     **************************************************************************************************/
    Sector(const Sector& sector);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual ~Sector();

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
    Point GetStartPoint() const;

    /**************************************************************************************************
     * <summary>Gets the end point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The end point.</returns>
     **************************************************************************************************/
    Point GetEndPoint() const;

    /**************************************************************************************************
     * <summary>Gets the center point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The center point.</returns>
     **************************************************************************************************/
    Point GetCenterPoint() const;

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
     * <summary>Query if this object intersects the given position.</summary>
     * <remarks>Casey Ugone, 8/23/2013.</remarks>
     * <param name="position">The position.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Vector2D& position) const;

    /**************************************************************************************************
     * <summary>Gets the arc center.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The arc center.</returns>
     **************************************************************************************************/
    const Vector2D& GetArcCenter() const;

    /**************************************************************************************************
     * <summary>Gets the arc center.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The arc center.</returns>
     **************************************************************************************************/
    Vector2D& GetArcCenter();

    /**************************************************************************************************
     * <summary>Gets the arc center point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The arc center point.</returns>
     **************************************************************************************************/
    Point GetArcCenterPoint() const;

    /**************************************************************************************************
     * <summary>Sets the angles degrees.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="startAngle">The start angle.</param>
     * <param name="endAngle">  The end angle.</param>
     **************************************************************************************************/
    virtual void SetAnglesDegrees(double startAngle, double endAngle);

    /**************************************************************************************************
     * <summary>Sets the angles.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="startAngle">The start angle.</param>
     * <param name="endAngle">  The end angle.</param>
     **************************************************************************************************/
    virtual void SetAngles(double startAngle, double endAngle);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    Sector& operator=(const Sector& rhs);

protected:

    /**************************************************************************************************
     * <summary>Sets a width.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="width">The width.</param>
     **************************************************************************************************/
    virtual void SetHalfWidth(double width);

    /**************************************************************************************************
     * <summary>Sets a height.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfHeight(double height);

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(double width, double height);

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(const Vector2D& dimensions);

    /**************************************************************************************************
     * <summary>Calculates the area.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateArea();


private:
    /// <summary> The arc </summary>
    Arc _arc;

};

A2DE_END

#endif