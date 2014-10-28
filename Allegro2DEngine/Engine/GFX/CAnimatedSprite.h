/**************************************************************************************************
// file:	Engine\GFX\CAnimatedSprite.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the animated sprite class
 **************************************************************************************************/
#ifndef A2DE_CANIMATEDSPRITE_H
#define A2DE_CANIMATEDSPRITE_H

#include "../a2de_vals.h"
#include "CSprite.h"
#include <vector>
#include <iostream>

struct ALLEGRO_BITMAP;

A2DE_BEGIN

class AnimationHandler;

/**************************************************************************************************
 * <summary>Animated sprite.</summary>
 * <remarks>Casey Ugone, 8/1/2011.</remarks>
 * <seealso cref="Sprite"/>
 **************************************************************************************************/
class AnimatedSprite : public Sprite {
public:

    /**************************************************************************************************
     * <summary>Creates an animated sprite.</summary>
     * <remarks>Casey Ugone, 11/22/2011.</remarks>
     * <param name="name">     The name of the sprite.</param>
     * <param name="file">     A previously created pointer to a BITMAP structure.</param>
     * <param name="frameRate">Length of time per frame in seconds.</param>
     * <returns>null if it fails, else.</returns>
     **************************************************************************************************/
    static AnimatedSprite* CreateAnimatedSprite(const std::string& name, ALLEGRO_BITMAP* file, double frameRate);

    /**************************************************************************************************
     * <summary>Creates an animated sprite.</summary>
     * <remarks>Casey Ugone, 11/22/2011.</remarks>
     * <param name="file">     The file path and name.</param>
     * <param name="frameRate">Length of time per frame in seconds.</param>
     * <returns>null if it fails, else.</returns>
     **************************************************************************************************/
    static AnimatedSprite* CreateAnimatedSprite(const std::string& file, double frameRate);

    /**************************************************************************************************
     * <summary>Creates an animated sprite.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="animatedSprite">The animated sprite to copy.</param>
     * <returns>null if it fails, else a copy of the animatedSprite passed in..</returns>
     **************************************************************************************************/
    static AnimatedSprite* CreateAnimatedSprite(const AnimatedSprite& animatedSprite);

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     **************************************************************************************************/
    virtual ~AnimatedSprite();

    /**************************************************************************************************
     * <summary>Gets the current frame.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>null if it fails, else the current frame.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetImage() const;

    /**************************************************************************************************
     * <summary>Gets the current frame.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>null if it fails, else the image.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetImage();

    /**************************************************************************************************
     * <summary>Gets the entire BITMAP sheet.</summary>
     * <remarks>Casey Ugone, 10/31/2011.</remarks>
     * <returns>null if it fails, else the sheet.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetSheet() const;

    /**************************************************************************************************
     * <summary>Gets the entire BITMAP sheet.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>null if it fails, else the sheet.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetSheet();

    /**************************************************************************************************
     * <summary>Animates an animated sprite.</summary>
     * <remarks>Casey Ugone, 11/8/2011.</remarks>
     * <param name="name">     The name of the animation.</param>
     * <param name="dir">      The direction to animate.</param>
     * <param name="deltaTime">The current time between frames.</param>
     **************************************************************************************************/
    virtual void Animate(const std::string& name, AnimationHandler::DIRECTION dir, double deltaTime);

    /**************************************************************************************************
     * <summary>Sets the frame rate of the animated sprite.</summary>
     * <remarks>Casey Ugone, 8/2/2011.</remarks>
     * <remarks>If deltaTime is zero or less, the animation plays as fast as possible.</remarks>
     * <param name="deltaTime">The time between each frame in seconds.</param>
     **************************************************************************************************/
    virtual void SetFrameRate(double deltaTime);

    /**************************************************************************************************
     * <summary>Gets the width of the frame.</summary>
     * <remarks>Casey Ugone, 7/4/2012.</remarks>
     * <returns>The width of the frame in pixels.</returns>
     **************************************************************************************************/
    virtual int GetWidth() const;

    /**************************************************************************************************
     * <summary>Gets the width of the frame.</summary>
     * <remarks>Casey Ugone, 7/4/2012.</remarks>
     * <returns>The width of the frame in pixels.</returns>
     **************************************************************************************************/
    virtual int GetWidth();

    /**************************************************************************************************
     * <summary>Gets the height of the frame.</summary>
     * <remarks>Casey Ugone, 7/4/2012.</remarks>
     * <returns>The height of the frame in pixels.</returns>
     **************************************************************************************************/
    virtual int GetHeight() const;

    /**************************************************************************************************
     * <summary>Gets the height of the frame.</summary>
     * <remarks>Casey Ugone, 7/4/2012.</remarks>
     * <returns>The height of the frame in pixels.</returns>
     **************************************************************************************************/
    virtual int GetHeight();

    /**************************************************************************************************
     * <summary>Gets the frame rate.</summary>
     * <remarks>Casey Ugone, 8/2/2011.</remarks>
     * <returns>The frame rate in seconds.</returns>
     **************************************************************************************************/
    virtual double GetFrameRate() const;

    /**************************************************************************************************
     * <summary>Gets the frame rate.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The frame rate.</returns>
     **************************************************************************************************/
    virtual double GetFrameRate();

    /**************************************************************************************************
     * <summary>Gets the animation handler.</summary>
     * <remarks>Casey Ugone, 12/3/2011.</remarks>
     * <returns>null if it fails, else the animation handler.</returns>
     **************************************************************************************************/
    virtual AnimationHandler* GetAnimationHandler() const;

    /**************************************************************************************************
     * <summary>Gets the animation handler.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>null if it fails, else the animation handler.</returns>
     **************************************************************************************************/
    virtual AnimationHandler* GetAnimationHandler();

protected:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 11/22/2011.</remarks>
     * <param name="name">     The name.</param>
     * <param name="file">     [in,out] If non-null, the file.</param>
     * <param name="frameRate">The frame rate.</param>
     **************************************************************************************************/
    AnimatedSprite(const std::string& name, ALLEGRO_BITMAP* file, double frameRate);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 11/22/2011.</remarks>
     * <param name="file">     The file.</param>
     * <param name="frameRate">The frame rate.</param>
     **************************************************************************************************/
    AnimatedSprite(const std::string& file, double frameRate);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the AnimatedSprite class.</summary>
     * <remarks>Casey Ugone, 8/2/2011.</remarks>
     * <param name="animSprite">The animated sprite.</param>
     **************************************************************************************************/
    AnimatedSprite(const AnimatedSprite& animSprite);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 8/2/2011.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    AnimatedSprite& operator=(const AnimatedSprite& rhs);

    /**************************************************************************************************
     * <summary>Resize frame image.</summary>
     * <remarks>Casey Ugone, 12/3/2011.</remarks>
     * <remarks>Does nothing if width and height are unchanged from previous width and height.</remarks>
     * <remarks>Does nothing if called on a Sprite object.</remarks>
     * <param name="width"> The new width.</param>
     * <param name="height">The new height.</param>
     **************************************************************************************************/
    virtual void ResizeFrame(unsigned int width, unsigned int height);

private:
    /// <summary> The current frame image </summary>
    ALLEGRO_BITMAP* _frameImage;
    /// <summary> The frame rate </summary>
    double _frameRate;
    /// <summary> The animation handler.</summary>
    AnimationHandler* _animation;
    /// <summary> The framerate accumulator to determine if a frame should advance.</summary>
    double _accumulator;

    friend AnimationHandler;
};

A2DE_END

#endif