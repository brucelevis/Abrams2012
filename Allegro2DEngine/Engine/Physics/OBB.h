/**************************************************************************************************
// file:	Engine\Physics\OBB.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the obb class
 **************************************************************************************************/
#ifndef A2DE_OBB_H
#define A2DE_OBB_H

#include "../Math/CVector2D.h"
#include "../Math/CLine.h"
#include "../Math/CTransform2D.h"
#include "IBoundingBox.h"

#include <allegro5/color.h>

#include <vector>

A2DE_BEGIN

class OBB : public IBoundingBox {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    OBB();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="transform_instance">The transform instance.</param>
     **************************************************************************************************/
    OBB(const Transform2D& transform_instance);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="transform_instance">The transform instance.</param>
     * <param name="half_extents">      The half extents.</param>
     **************************************************************************************************/
    OBB(const Transform2D& transform_instance, const a2de::Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="transform_instance">The transform instance.</param>
     * <param name="half_extents">      The half extents.</param>
     * <param name="color">             The color.</param>
     **************************************************************************************************/
    OBB(const Transform2D& transform_instance, const a2de::Vector2D& half_extents, const ALLEGRO_COLOR& color);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    OBB(const OBB& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    OBB& operator=(const OBB& rhs);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~OBB();

    /**************************************************************************************************
     * <summary>Sets half extents.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="half_extents">The half extents.</param>
     **************************************************************************************************/
    virtual void SetHalfExtents(const a2de::Vector2D& half_extents);

    /**************************************************************************************************
     * <summary>Gets half extents.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The half extents.</returns>
     **************************************************************************************************/
    virtual const a2de::Vector2D& GetHalfExtents() const;

    /**************************************************************************************************
     * <summary>Gets half extents.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The half extents.</returns>
     **************************************************************************************************/
    virtual a2de::Vector2D& GetHalfExtents();

    /**************************************************************************************************
     * <summary>Gets the right.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The right.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetRight() const;

    /**************************************************************************************************
     * <summary>Gets the right.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The right.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetRight();

    /**************************************************************************************************
     * <summary>Gets the top.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The top.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetTop() const;

    /**************************************************************************************************
     * <summary>Gets the top.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The top.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetTop();

    /**************************************************************************************************
     * <summary>Gets the left.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The left.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetLeft() const;

    /**************************************************************************************************
     * <summary>Gets the left.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The left.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetLeft();

    /**************************************************************************************************
     * <summary>Gets the bottom.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The bottom.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetBottom() const;

    /**************************************************************************************************
     * <summary>Gets the bottom.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The bottom.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetBottom();

    /**************************************************************************************************
     * <summary>Draws the bounding box at the given destination.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="dest">[in,out] If non-null, destination to draw to.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest);

    /**************************************************************************************************
     * <summary>Gets the transform.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The transform.</returns>
     **************************************************************************************************/
    virtual const a2de::Transform2D& GetTransform() const;

    /**************************************************************************************************
     * <summary>Gets the transform.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The transform.</returns>
     **************************************************************************************************/
    virtual a2de::Transform2D& GetTransform();

protected:
private:

    /**************************************************************************************************
     * <summary>Values that represent POINTS.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    enum POINTS {
        POINTS_TOP_LEFT,
        POINTS_TOP_RIGHT,
        POINTS_BOTTOM_LEFT,
        POINTS_BOTTOM_RIGHT,
    };

    /**************************************************************************************************
     * <summary>The transform instance.</summary>
     **************************************************************************************************/
    a2de::Transform2D _transform_instance;

    /**************************************************************************************************
     * <summary>Extents of the half.</summary>
     **************************************************************************************************/
    a2de::Vector2D _half_extents;

    /**************************************************************************************************
     * <summary>The points.</summary>
     **************************************************************************************************/
    std::vector<a2de::Vector2D> _points;

    /**************************************************************************************************
     * <summary>The color.</summary>
     **************************************************************************************************/
    ALLEGRO_COLOR _color;

};

A2DE_END

#endif
