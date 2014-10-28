/**************************************************************************************************
// file:	Engine\Physics\CCamera.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the camera class
 **************************************************************************************************/
#ifndef A2DE_CCAMERA_H
#define A2DE_CCAMERA_H

#include "../a2de_vals.h"
#include "../Math/CVector2D.h"
#include "../Math/CRectangle.h"
#include <iostream>
#include <string>

struct ALLEGRO_BITMAP;

A2DE_BEGIN

class World;
class Rectangle;
class Shape;
class Sprite;
class Color;

/**************************************************************************************************
 * <summary>Camera. </summary>
 * <remarks>Casey Ugone, 6/29/2012.</remarks>
 **************************************************************************************************/
class Camera {

public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="position">  The position.</param>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    Camera(const Vector2D& position, const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="parent">    The parent.</param>
     * <param name="position">  The position.</param>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    Camera(const World& parent, const Vector2D& position, const Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Camera(const Camera& other);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     **************************************************************************************************/
    ~Camera();

    /**************************************************************************************************
     * <summary>Gets the parent of this item.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The parent.</returns>
     **************************************************************************************************/
    const World* const GetParent() const;

    /**************************************************************************************************
     * <summary>Gets the parent of this item.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>null if it fails, else the parent.</returns>
     **************************************************************************************************/
    const World* GetParent();

    /**************************************************************************************************
     * <summary>Sets a parent.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="parent">The parent.</param>
     **************************************************************************************************/
    void SetParent(const World& parent);

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX() const;

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX();

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY();

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    const Vector2D& GetPosition() const;

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    Vector2D& GetPosition();

    /**************************************************************************************************
     * <summary>Sets an x coordinate.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets a y coordinate.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetY(double y);

    /**************************************************************************************************
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPosition(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Gets the dimensions.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The dimensions.</returns>
     **************************************************************************************************/
    const Vector2D& GetHalfExtents() const;

    /**************************************************************************************************
     * <summary>Gets the dimensions.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The dimensions.</returns>
     **************************************************************************************************/
    Vector2D& GetHalfExtents();

    /**************************************************************************************************
     * <summary>Sets screen position.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     * <param name="screen_position">The screen position.</param>
     **************************************************************************************************/
    void SetScreenPosition(const Vector2D& screen_position);

    /**************************************************************************************************
     * <summary>Sets screen position.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetScreenPosition(double x, double y);

    /**************************************************************************************************
     * <summary>Sets screen x coordinate position.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetScreenXPosition(double x);

    /**************************************************************************************************
     * <summary>Sets screen y coordinate position.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetScreenYPosition(double y);

    /**************************************************************************************************
     * <summary>Gets screen position.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     * <returns>The screen position.</returns>
     **************************************************************************************************/
    const Vector2D& GetScreenPosition() const;

    /**************************************************************************************************
     * <summary>Gets screen position.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     * <returns>The screen position.</returns>
     **************************************************************************************************/
    Vector2D& GetScreenPosition();

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Camera& operator=(const Camera& rhs);

    /**************************************************************************************************
     * <summary>Camera to world position.</summary>
     * <remarks>Casey Ugone, 7/28/2012.</remarks>
     * <param name="cam">            The camera.</param>
     * <param name="screen_position">The screen position.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    static Vector2D CameraToWorldPosition(const Camera& cam, const Vector2D& screen_position);

    /**************************************************************************************************
     * <summary>World to camera position.</summary>
     * <remarks>Casey Ugone, 7/28/2012.</remarks>
     * <param name="cam">           The camera.</param>
     * <param name="world_position">The world position.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    static Vector2D WorldToCameraPosition(const Camera& cam, const Vector2D& world_position);

    /**************************************************************************************************
     * <summary>Gets the area the camera represents.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     * <returns>The area.</returns>
     **************************************************************************************************/
    const a2de::Rectangle& GetArea() const;

protected:
private:
    /// <summary> The parent </summary>
    const World* _parent;

    /// <summary> The defined area of the camera view </summary>
    a2de::Rectangle _world_area;

    /// <summary> The position to draw to on the screen. </summary>
    a2de::Vector2D _screen_position;
};

A2DE_END

#endif