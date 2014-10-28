/**************************************************************************************************
// file:	Engine\Math\CShape.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the shape class
 **************************************************************************************************/
#ifndef A2DE_CSHAPE_H
#define A2DE_CSHAPE_H

#include "../a2de_vals.h"

#include "CVector2D.h"

#include <tuple>
#include <utility>
#include <allegro5/allegro_primitives.h>
#include <allegro5/drawing.h>
#include <string>
#include "../GFX/IDrawable.h"

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
class Sector;

class Shape : public IDrawable {

public:
    enum SHAPE_TYPE {
        SHAPETYPE_SHAPE = -1,
        SHAPETYPE_POINT,
        SHAPETYPE_LINE,
        SHAPETYPE_RECTANGLE,
        SHAPETYPE_CIRCLE,
        SHAPETYPE_ELLIPSE,
        SHAPETYPE_TRIANGLE,
        SHAPETYPE_ARC,
        SHAPETYPE_POLYGON,
        SHAPETYPE_SPLINE,
        SHAPETYPE_SECTOR,
        SHAPETYPE_MAX,
    };

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    const Vector2D& GetPosition() const;

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    Vector2D& GetPosition();

    /**************************************************************************************************
     * <summary>Gets the area.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The area.</returns>
     **************************************************************************************************/
    double GetArea() const;

    /**************************************************************************************************
     * <summary>Gets the area.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The area.</returns>
     **************************************************************************************************/
    double GetArea();
    
    /**************************************************************************************************
     * <summary>Gets the color.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The color.</returns>
     **************************************************************************************************/
    const ALLEGRO_COLOR& GetColor() const;

    /**************************************************************************************************
     * <summary>Gets the color.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The color.</returns>
     **************************************************************************************************/
    ALLEGRO_COLOR& GetColor();

    /**************************************************************************************************
     * <summary>Query if this object is filled.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>true if filled, false if not.</returns>
     **************************************************************************************************/
    bool IsFilled() const;

    /**************************************************************************************************
     * <summary>Sets a color.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="color">The color.</param>
     **************************************************************************************************/
    void SetColor(const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Sets a fill.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="filled">true to filled.</param>
     **************************************************************************************************/
    void SetFill(bool filled);

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX() const;
    
    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX();
    
    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY();

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The width.</returns>
     **************************************************************************************************/
    double GetHalfWidth() const;

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The width.</returns>
     **************************************************************************************************/
    double GetHalfWidth();

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The height.</returns>
     **************************************************************************************************/
    double GetHalfHeight() const;

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The height.</returns>
     **************************************************************************************************/
    double GetHalfHeight();

    /**************************************************************************************************
     * <summary>Gets the dimensions.</summary>
     * <remarks>Casey Ugone, 5/3/2013.</remarks>
     * <returns>The dimensions.</returns>
     **************************************************************************************************/
    const Vector2D& GetHalfExtents() const;

    /**************************************************************************************************
     * <summary>Gets the dimensions.</summary>
     * <remarks>Casey Ugone, 5/3/2013.</remarks>
     * <returns>The dimensions.</returns>
     **************************************************************************************************/
    Vector2D& GetHalfExtents();

    /**************************************************************************************************
     * <summary>Sets an x coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    virtual void SetX(double x)=0;

    /**************************************************************************************************
     * <summary>Sets a y coordinate.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    virtual void SetY(double y)=0;

    /**************************************************************************************************
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    virtual void SetPosition(double x, double y)=0;

    /**************************************************************************************************
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    virtual void SetPosition(const Vector2D& position)=0;

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(double half_width, double half_height)=0;

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(const Vector2D& half_extents)=0;

    /**************************************************************************************************
     * <summary>Sets a width.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="width">The width.</param>
     **************************************************************************************************/
    virtual void SetHalfWidth(double half_width)=0;

    /**************************************************************************************************
     * <summary>Sets a height.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    virtual void SetHalfHeight(double half_height)=0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given position.</summary>
     * <remarks>Casey Ugone, 8/23/2013.</remarks>
     * <param name="position">The position.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const a2de::Vector2D& position) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given shape.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="shape">The shape.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Shape& shape) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given point.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="point">The point.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Point& point) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given line.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="line">The line.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Line& line) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given rectangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rectangle">The rectangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Rectangle& rectangle) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given circle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="circle">The circle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Circle& circle) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given ellipse.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="ellipse">The ellipse.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Ellipse& ellipse) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given triangle.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="triangle">The triangle.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Triangle& triangle) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given arc.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="arc">The arc.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Arc& arc) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given polygon.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="polygon">The polygon.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Polygon& polygon) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given spline.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="spline">The spline.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Spline& spline) const =0;

    /**************************************************************************************************
     * <summary>Query if this object intersects the given sector.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="sector">The sector.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    virtual bool Intersects(const Sector& sector) const =0;

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
     * <param name="dest">  [in,out] If non-null, destination for the shape.</param>
     * <param name="color"> The color.</param>
     * <param name="filled">true to filled.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest, const ALLEGRO_COLOR& color, bool filled)=0;

    /**************************************************************************************************
     * <summary>Draws.</summary>
     * <remarks>Casey Ugone, 1/19/2014.</remarks>
     * <param name="dest">[in,out] If non-null, destination for the shape.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest);

    /**************************************************************************************************
     * <summary>Gets the shape type.</summary>
     * <remarks>Casey Ugone, 3/28/2013.</remarks>
     * <returns>The shape type.</returns>
     **************************************************************************************************/
    virtual const Shape::SHAPE_TYPE& GetShapeType() const;

    /**************************************************************************************************
     * <summary>Gets the shape type.</summary>
     * <remarks>Casey Ugone, 3/28/2013.</remarks>
     * <returns>The shape type.</returns>
     **************************************************************************************************/
    virtual Shape::SHAPE_TYPE& GetShapeType();

    /**************************************************************************************************
     * <summary>Clones a shape.</summary>
     * <remarks>Casey Ugone, 12/15/2012.</remarks>
     * <param name="shape">[in,out] If non-null, the shape.</param>
     * <returns>null if it fails, else a copy of this object.</returns>
     **************************************************************************************************/
    static Shape* Clone(Shape* shape);
    
    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    Shape();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    Shape(double x, double y);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    Shape(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">     The x coordinate.</param>
     * <param name="y">     The y coordinate.</param>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    Shape(double x, double y, double half_width, double half_height);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     * <param name="width">   The width.</param>
     * <param name="height">  The height.</param>
     **************************************************************************************************/
    Shape(const Vector2D& position, double half_width, double half_height);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">         The x coordinate.</param>
     * <param name="y">         The y coordinate.</param>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    Shape(double x, double y, const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">  The position.</param>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    Shape(const Vector2D& position, const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">     The x coordinate.</param>
     * <param name="y">     The y coordinate.</param>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     * <param name="color"> The color.</param>
     **************************************************************************************************/
    Shape(double x, double y, double half_width, double half_height, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     * <param name="width">   The width.</param>
     * <param name="height">  The height.</param>
     * <param name="color">   The color.</param>
     **************************************************************************************************/
    Shape(const Vector2D& position, double half_width, double half_height, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">         The x coordinate.</param>
     * <param name="y">         The y coordinate.</param>
     * <param name="dimensions">The dimensions.</param>
     * <param name="color">     The color.</param>
     **************************************************************************************************/
    Shape(double x, double y, const Vector2D& half_extents, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">  The position.</param>
     * <param name="dimensions">The dimensions.</param>
     * <param name="color">     The color.</param>
     **************************************************************************************************/
    Shape(const Vector2D& position, const Vector2D& half_extents, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">     The x coordinate.</param>
     * <param name="y">     The y coordinate.</param>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     * <param name="color"> The color.</param>
     * <param name="filled">true to filled.</param>
     **************************************************************************************************/
    Shape(double x, double y, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">The position.</param>
     * <param name="width">   The width.</param>
     * <param name="height">  The height.</param>
     * <param name="color">   The color.</param>
     * <param name="filled">  true to filled.</param>
     **************************************************************************************************/
    Shape(const Vector2D& position, double half_width, double half_height, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="x">         The x coordinate.</param>
     * <param name="y">         The y coordinate.</param>
     * <param name="dimensions">The dimensions.</param>
     * <param name="color">     The color.</param>
     * <param name="filled">    true to filled.</param>
     **************************************************************************************************/
    Shape(double x, double y, const Vector2D& half_extents, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="position">  The position.</param>
     * <param name="dimensions">The dimensions.</param>
     * <param name="color">     The color.</param>
     * <param name="filled">    true to filled.</param>
     **************************************************************************************************/
    Shape(const Vector2D& position, const Vector2D& half_extents, const ALLEGRO_COLOR& color, bool filled);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="shape">The shape.</param>
     **************************************************************************************************/
    Shape(const Shape& shape);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Shape& operator=(const Shape& rhs);

    /**************************************************************************************************
     * <summary>Finaliser.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual ~Shape();

protected:

    /**************************************************************************************************
     * <summary>Calculates the area.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    virtual void CalculateArea()=0;

    /// <summary> The position </summary>
    Vector2D _position;
    /// <summary> The dimensions </summary>
    Vector2D _half_extents;
    /// <summary> The area </summary>
    double _area;
    /// <summary> The shape type </summary>
    Shape::SHAPE_TYPE _type;
    /// <summary> The color </summary>
    ALLEGRO_COLOR _color;
    /// <summary> true to filled </summary>
    bool _filled;

};

A2DE_END

#endif