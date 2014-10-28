/**************************************************************************************************
// file:	Engine\GFX\CSpriteHandler.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the sprite handler class
 **************************************************************************************************/
#ifndef A2DE_CSPRITEHANDLER_H
#define A2DE_CSPRITEHANDLER_H

#include "../a2de_vals.h"
#include <list>
#include <vector>
#include <allegro5/color.h>

//Forward declarations for cohesive pointer types.
struct ALLEGRO_BITMAP;

A2DE_BEGIN

class Sprite;
class AnimatedSprite;
class Shape;
class GameWindow;

class SpriteHandler {

public:

    /**************************************************************************************************
     * <summary>The axis to flip a sprite or bitmap.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     **************************************************************************************************/
    enum SPRITEAXIS {
        /// <summary>No flipping necessary.</summary>
        AXIS_NONE = 0,
        /// <summary>Flips the image over the y-axis, appearing as a mirror image.</summary>
        AXIS_HORIZONTAL = 1,
        /// <summary>Flips the image over the x-axis, appearing upside-down.</summary>
        AXIS_VERTICAL = 2,
        /// <summary>Flips the image over both the x- and y-axis, appearing as an upside-down mirror image.</summary>
        AXIS_BOTH = 3,
    };

    /**************************************************************************************************
     * <summary>Draws a BITMAP onto another BITMAP.</summary>
     * <remarks>Casey Ugone, 11/23/2013.</remarks>
     * <param name="dest">               [in,out] If non-null, destination for the.</param>
     * <param name="source">             [in,out] If non-null, source for the.</param>
     * <param name="x">                  The x coordinate.</param>
     * <param name="y">                  The y coordinate.</param>
     * <param name="tintColor">          The tint color.</param>
     **************************************************************************************************/
    static void Draw(ALLEGRO_BITMAP* dest, ALLEGRO_BITMAP* source, double x, double y, ALLEGRO_COLOR tintColor);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap using the sprite's stored tintColor, tintIntensity and alpha values.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     **************************************************************************************************/
	static void Draw(ALLEGRO_BITMAP* dest, Sprite* sprite);
    
    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap flipped over a specific axis.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the sprite.</param>
     * <param name="axis">  A valid SpriteHandler::SPRITEAXIS value in which to flip the sprite over.</param>
     **************************************************************************************************/
    static void DrawFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, SpriteHandler::SPRITEAXIS axis);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap using the sprite's stored scale values.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     **************************************************************************************************/
	static void DrawScale(ALLEGRO_BITMAP* dest, Sprite* sprite);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value and at a distance of radius away from its
     * center.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     * <param name="x">     The x coordinate of the center point in which the sprite rotates around.</param>
     * <param name="y">     The y coordinate of the center point in which the sprite rotates around.</param>
     * <param name="radius">The distance (in meters) to draw the sprite away from the (x, y) point to its center.</param>
     **************************************************************************************************/
    static void DrawRotateWorldSpace(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double radius);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value and at a distance of radius away from its
     * center and scaled with its stored scale value.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     * <param name="x">     The x coordinate of the center point in which the sprite rotates around.</param>
     * <param name="y">     The y coordinate of the center point in which the sprite rotates around.</param>
     * <param name="radius">The distance (in meters) to draw the sprite away from the (x, y) point to its center.</param>
     **************************************************************************************************/
    static void DrawRotateWorldSpaceScale(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double radius);
    
    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value and flipped around the axis argument.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     * <param name="x">     The x coordinate of the center point in which the sprite rotates around.</param>
     * <param name="y">     The y coordinate of the center point in which the sprite rotates around.</param>
     * <param name="radius">The distance (in meters) to draw the sprite away from the (x, y) point to its center.</param>
     * <param name="axis">  The axis in which to flip the sprite where axis equals one of the defined SpriteHandler::SPRITEAXIS values: HORIZONTAL, VERTICAL or BOTH.</param>
     **************************************************************************************************/
    static void DrawRotateWorldSpaceFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double radius, SpriteHandler::SPRITEAXIS axis);
    
    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value, scaled with its stored scale value and flipped
     * around the axis argument.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     * <param name="x">     The x coordinate of the center point in which the sprite rotates around.</param>
     * <param name="y">     The y coordinate of the center point in which the sprite rotates around.</param>
     * <param name="radius">The distance (in meters) to draw the sprite away from the (x, y) point to its center.</param>
     * <param name="axis">  The axis in which to flip the sprite where axis equals one of the defined SpriteHandler::SPRITEAXIS values: HORIZONTAL, VERTICAL or
     * BOTH.</param>
     **************************************************************************************************/
    static void DrawRotateWorldSpaceScaleFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, double x, double y, double radius, SpriteHandler::SPRITEAXIS axis);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     **************************************************************************************************/
	static void DrawRotate(ALLEGRO_BITMAP* dest, Sprite* sprite);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value and scaled with its stored scale value.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     **************************************************************************************************/
	static void DrawRotateScale(ALLEGRO_BITMAP* dest, Sprite* sprite);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value and flipped around the axis argument.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     * <param name="axis">  The axis in which to flip the sprite where axis equals one of the defined SpriteHandler::SPRITEAXIS values: HORIZONTAL, VERTICAL or
     * BOTH.</param>
     **************************************************************************************************/
    static void DrawRotateFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, SpriteHandler::SPRITEAXIS axis);

    /**************************************************************************************************
     * <summary>Draws a Sprite object on to another bitmap at point (x, y) rotated with its stored rotation value, scaled with its stored scale value and flipped
     * around the axis argument.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="sprite">[in,out] If non-null, the source sprite.</param>
     * <param name="axis">  The axis in which to flip the sprite where axis equals one of the defined SpriteHandler::SPRITEAXIS values: HORIZONTAL, VERTICAL or
     * BOTH.</param>
     **************************************************************************************************/
    static void DrawRotateScaleFlip(ALLEGRO_BITMAP* dest, Sprite* sprite, SpriteHandler::SPRITEAXIS axis);

    /**************************************************************************************************
     * <summary>Draws a Shape object on to another bitmap using the shape's stored color, position, and fill values.</summary>
     * <remarks>Casey Ugone, 4/8/2012.</remarks>
     * <param name="dest">  [in,out] If non-null, the destination bitmap.</param>
     * <param name="object">[in,out] If non-null, the source shape.</param>
     **************************************************************************************************/
    static void Draw(ALLEGRO_BITMAP* dest, Shape* object);

private:
    //Creation of object of type SpriteHandler is illegal,
    //all methods are static anyway.
    //Use of these methods will result in a linker error.
    SpriteHandler();
    SpriteHandler(const SpriteHandler&);
    //Creation of object of type SpriteHandler is illegal,
    //all methods are static anyway.
    //Use of these methods will result in a linker error.
    //NO COPYING ALLOWED!
    SpriteHandler& operator=(const SpriteHandler&);
    ~SpriteHandler();
    
};

A2DE_END

#endif