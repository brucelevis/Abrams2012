/**************************************************************************************************
// file:	Engine\GFX\CAnimationFrame.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the animation frame class
 **************************************************************************************************/
#ifndef A2DE_CANIMATIONFRAME_H
#define A2DE_CANIMATIONFRAME_H

#include "../a2de_vals.h"
#include <utility>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Animation frame. </summary>
 * <remarks>Casey Ugone, 6/29/2012.</remarks>
 **************************************************************************************************/
class AnimationFrame {

public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     **************************************************************************************************/
    AnimationFrame();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="x">     The x coordinate of the frame.</param>
     * <param name="y">     The y coordinate of the frame.</param>
     * <param name="width"> The width of the frame.</param>
     * <param name="height">The height of the frame.</param>
     **************************************************************************************************/
    AnimationFrame(int x, int y, int width, int height);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="other">The other AnimationFrame to copy.</param>
     **************************************************************************************************/
    AnimationFrame(const AnimationFrame& other);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     **************************************************************************************************/
    ~AnimationFrame();

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    AnimationFrame& operator=(const AnimationFrame& rhs);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const AnimationFrame& rhs);

    /**************************************************************************************************
     * <summary>InEquality operator.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const AnimationFrame& rhs);

    /**************************************************************************************************
     * <summary>Get width of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The width in pixels.</returns>
     **************************************************************************************************/
    int GetWidth() const;

    /**************************************************************************************************
     * <summary>Get width of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The width in pixels.</returns>
     **************************************************************************************************/
    int GetWidth();

    /**************************************************************************************************
     * <summary>Get height of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The height in pixels.</returns>
     **************************************************************************************************/
    int GetHeight() const;

    /**************************************************************************************************
     * <summary>Get height of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The height in pixels.</returns>
     **************************************************************************************************/
    int GetHeight();

    /**************************************************************************************************
     * <summary>Get x coordinate of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The x coordinate in pixels.</returns>
     **************************************************************************************************/
    int GetX() const;

    /**************************************************************************************************
     * <summary>Get x coordinate of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The x coordinate in pixels.</returns>
     **************************************************************************************************/
    int GetX();

    /**************************************************************************************************
     * <summary>Get y coordinate of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The y coordinate in pixels.</returns>
     **************************************************************************************************/
    int GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate of the frame.</summary>
     * <remarks>Casey Ugone, 6/29/2012.</remarks>
     * <returns>The y coordinate in pixels.</returns>
     **************************************************************************************************/
    int GetY();

protected:

private:
    /// <summary> The position of the frame in the source sprite.</summary>
    std::pair<int, int> _position;
    /// <summary> The dimensions of the frame.</summary>
    std::pair<int, int> _dimensions;
};

A2DE_END

#endif