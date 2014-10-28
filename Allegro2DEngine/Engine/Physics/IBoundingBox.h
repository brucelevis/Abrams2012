/**************************************************************************************************
// file:	Engine\Physics\IBoundingBox.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the IBoundingBox interface
 **************************************************************************************************/
#ifndef A2DE_ADTBOUNDINGBOX_H
#define A2DE_ADTBOUNDINGBOX_H

#include "../a2de_vals.h"

#include <allegro5/bitmap.h>

A2DE_BEGIN

class Line;
class Vector2D;
class Transform2D;

class IBoundingBox {
public:

    /**************************************************************************************************
     * <summary>Gets the top.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The top.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetTop() const =0;

    /**************************************************************************************************
     * <summary>Gets the top.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The top.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetTop() =0;

    /**************************************************************************************************
     * <summary>Gets the bottom.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The bottom.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetBottom() const =0;

    /**************************************************************************************************
     * <summary>Gets the bottom.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The bottom.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetBottom() =0;

    /**************************************************************************************************
     * <summary>Gets the left.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The left.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetLeft() const =0;

    /**************************************************************************************************
     * <summary>Gets the left.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The left.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetLeft() =0;

    /**************************************************************************************************
     * <summary>Gets the right.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The right.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetRight() const =0;

    /**************************************************************************************************
     * <summary>Gets the right.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The right.</returns>
     **************************************************************************************************/
    virtual a2de::Line GetRight() =0;

    /**************************************************************************************************
     * <summary>Gets half extents.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The half extents.</returns>
     **************************************************************************************************/
    virtual const a2de::Vector2D& GetHalfExtents() const =0;

    /**************************************************************************************************
     * <summary>Gets half extents.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The half extents.</returns>
     **************************************************************************************************/
    virtual a2de::Vector2D& GetHalfExtents() =0;

    /**************************************************************************************************
     * <summary>Gets the transform.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The transform.</returns>
     **************************************************************************************************/
    virtual const a2de::Transform2D& GetTransform() const =0;

    /**************************************************************************************************
     * <summary>Gets the transform.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The transform.</returns>
     **************************************************************************************************/
    virtual a2de::Transform2D& GetTransform() =0;

    /**************************************************************************************************
     * <summary>Draws bounding box at the given destination.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="dest">[in,out] If non-null, destination to draw to.</param>
     **************************************************************************************************/
    virtual void Draw(ALLEGRO_BITMAP* dest)=0;

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~IBoundingBox() { /* DO NOTHING */ }
protected:
private:
};

A2DE_END

#endif