/**************************************************************************************************
// file:	Engine\GFX\CSprite.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the sprite class
 **************************************************************************************************/
#ifndef A2DE_CSPRITE_H
#define A2DE_CSPRITE_H

#include "../a2de_vals.h"
#include <allegro5/drawing.h>
#include <allegro5/color.h>
#include <iostream>
#include <string>
#include <vector>

#include "../Math/CVector2D.h"
#include "../Math/CVector3D.h"
#include "CAnimationHandler.h"
#include "CSpriteHandler.h"

struct ALLEGRO_BITMAP;

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Sprite.</summary>
 * <remarks>Casey Ugone, 8/1/2011.</remarks>
 **************************************************************************************************/
class Sprite {

public:

    /**************************************************************************************************
     * <summary>Creates a named sprite from a previously allocated ALLEGRO_BITMAP.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="name">The name of the sprite.</param>
     * <param name="file">The ALLEGRO_BITMAP to use to create the Sprite.</param>
     * <returns>null if it fails, else a new Sprite object.</returns>
     * <exception cref="Exception">Thrown when file is null.</exception>
     **************************************************************************************************/
    static Sprite* CreateSprite(const std::string& name, ALLEGRO_BITMAP* file);

    /**************************************************************************************************
     * <summary>Creates a sprite from a file on disk.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="file">The filename and path.</param>
     * <returns>null if it fails, else a new Sprite object.</returns>
     * <exception cref="FileNotFoundException">Thrown when the requested file is not present.</exception>
     * <exception cref="Exception">            Thrown when file is a PACKFILE.</exception>
     **************************************************************************************************/
    static Sprite* CreateSprite(const std::string& file);

    /**************************************************************************************************
     * <summary>Makes a deep copy of the passed in sprite.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="sprite">The sprite to copy.</param>
     * <returns>A copy of the sprite object.</returns>
     **************************************************************************************************/
    static Sprite* CreateSprite(const Sprite& sprite);

    /**************************************************************************************************
     * <summary>Destructor</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     **************************************************************************************************/
    virtual ~Sprite();

    /**************************************************************************************************
     * <summary>Gets the filename or name.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The filename or Name associated with this sprite object.</returns>
     **************************************************************************************************/
    const std::string& GetFilename() const;

    /**************************************************************************************************
     * <summary>Gets the filename or name.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The filename or Name associated with this sprite object.</returns>
     **************************************************************************************************/
    std::string& GetFilename();

    /**************************************************************************************************
     * <summary>Gets the image.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>null if it fails, else returns a pointer to the underlying ALLEGRO_BITMAP structure of the Sprite object.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetImage() const;

    /**************************************************************************************************
     * <summary>Gets the image.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>null if it fails, else returns a pointer to the underlying ALLEGRO_BITMAP structure of the Sprite object.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetImage();

    /**************************************************************************************************
     * <summary>Gets the entire ALLEGRO_BITMAP sprite sheet.</summary>
     * <remarks>Casey Ugone, 10/31/2011.</remarks>
     * <returns>null if it fails, else the sheet.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetSheet() const;

    /**************************************************************************************************
     * <summary>Gets the entire ALLEGRO_BITMAP sprite sheet.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>null if it fails, else the sheet.</returns>
     **************************************************************************************************/
    virtual ALLEGRO_BITMAP* GetSheet();

    /**************************************************************************************************
     * <summary>Gets x coordinate.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX() const;

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX();

    /**************************************************************************************************
     * <summary>Gets y coordinate.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY();

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>Returns a Vector2D object describing the XY location of the sprite.</returns>
     **************************************************************************************************/
    Vector2D GetPosition() const;

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    Vector2D GetPosition();

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The width.</returns>
     **************************************************************************************************/
    virtual int GetWidth() const;

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The width.</returns>
     **************************************************************************************************/
    virtual int GetWidth();

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The height.</returns>
     **************************************************************************************************/
    virtual int GetHeight() const;

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The height.</returns>
     **************************************************************************************************/
    virtual int GetHeight();

    /**************************************************************************************************
     * <summary>Gets the center x coordinate.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The center x coordinate.</returns>
     **************************************************************************************************/
    int GetCenterX() const;

    /**************************************************************************************************
     * <summary>Gets the center x coordinate.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The center x coordinate.</returns>
     **************************************************************************************************/
    int GetCenterX();

    /**************************************************************************************************
     * <summary>Gets the center y coordinate.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The center y coordinate.</returns>
     **************************************************************************************************/
    int GetCenterY() const;

    /**************************************************************************************************
     * <summary>Gets the center y coordinate.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The center y coordinate.</returns>
     **************************************************************************************************/
    int GetCenterY();

    /**************************************************************************************************
     * <summary>Gets the angle of the sprite in radians.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Positive angles are counter-clockwise.</remarks>
     * <returns>The rotation in radians.</returns>
     **************************************************************************************************/
    double GetAngle() const;

    /**************************************************************************************************
     * <summary>Gets the rotation amount in radians.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The rotation.</returns>
     **************************************************************************************************/
    double GetAngle();

    /**************************************************************************************************
     * <summary>Gets the scale in the x direction.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The scale.</returns>
     **************************************************************************************************/
    double GetScaleX() const;

    /**************************************************************************************************
     * <summary>Gets the scale in the x direction.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The scale.</returns>
     **************************************************************************************************/
    double GetScaleX();

    /**************************************************************************************************
     * <summary>Gets the scale in the y direction.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The scale.</returns>
     **************************************************************************************************/
    double GetScaleY() const;

    /**************************************************************************************************
     * <summary>Gets the scale in the y direction.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The scale y coordinate.</returns>
     **************************************************************************************************/
    double GetScaleY();

    /**************************************************************************************************
     * <summary>Gets the tint color of the sprite.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The tint as an ALLEGRO_COLOR color.</returns>
     **************************************************************************************************/
    const ALLEGRO_COLOR& GetTint() const;

    /**************************************************************************************************
     * <summary>Gets the tint color of the sprite.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The tint as a ALLEGRO_COLOR color.</returns>
     **************************************************************************************************/
    ALLEGRO_COLOR& GetTint();

    /**************************************************************************************************
     * <summary>Gets the alpha value of the tint color.</summary>
     * <remarks>Casey Ugone, 10/5/2014.</remarks>
     * <returns>The alpha value of the tint color</returns>
     **************************************************************************************************/
    unsigned char GetAlpha() const;

    /**************************************************************************************************
     * <summary>Gets the alpha value of the tint color</summary>
     * <remarks>Casey Ugone, 10/5/2014.</remarks>
     * <returns>The alpha value of the tint color</returns>
     **************************************************************************************************/
    unsigned char GetAlpha();

    /**************************************************************************************************
     * <summary>Sets the alpha value of the tint color</summary>
     * <remarks>Casey Ugone, 10/5/2014.</remarks>
     * <param name="alpha">Sets the alpha value of the tint color</param>
     **************************************************************************************************/
    void SetAlpha(const unsigned char alpha);

    /**************************************************************************************************
     * <summary>Gets the rotation radius.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The distance from the rotation point in meters that the sprite rotates.</returns>
     **************************************************************************************************/
    double GetRotationRadius() const;

    /**************************************************************************************************
     * <summary>Gets the rotation radius.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The distance from the rotation point in meters that the sprite rotates.</returns>
     **************************************************************************************************/
    double GetRotationRadius();

    /**************************************************************************************************
     * <summary>Sets the x coordinate of the sprite's upper left corner.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets the y coordinate of the sprite's upper left corner.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetY(double y);

    /**************************************************************************************************
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetPosition(double x, double y);

    /**************************************************************************************************
     * <summary>Sets a position.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPosition(const Vector2D& position);

    /**************************************************************************************************
     * <summary>Sets the center x coordinate.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="x">The x coordinate where { x | 0 &lt;= x &lt;= GetFrameWidth() }</param>
     **************************************************************************************************/
    void SetCenterX(int x);

    /**************************************************************************************************
     * <summary>Sets a center y coordinate.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetCenterY(int y);

    /**************************************************************************************************
     * <summary>Sets the center point.</summary>
     * <remarks>Casey Ugone, 3/11/2012.</remarks>
     * <param name="center">The center.</param>
     **************************************************************************************************/
    void SetCenter(const Vector2D& center);

    /**************************************************************************************************
     * <summary>Sets the scale in the x direction.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Recalculates the center of the frame.</remarks>
     * <param name="x">The scale to set.</param>
     **************************************************************************************************/
    void SetScaleX(double x);

    /**************************************************************************************************
     * <summary>Sets a scale y coordinate.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Recalculates the center of the frame.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetScaleY(double y);

    /**************************************************************************************************
     * <summary>Sets the scale modifier.</summary>
     * <remarks>Casey Ugone, 3/11/2012.</remarks>
     * <param name="scale">The scale.</param>
     **************************************************************************************************/
    void SetScale(const Vector2D& scale);

    /**************************************************************************************************
     * <summary>Sets the rotation angle amount when drawing the sprite as a rotation.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="angle">The angle in radians.</param>
     **************************************************************************************************/
    void SetAngle(double angle);

    /**************************************************************************************************
     * <summary>Sets the tint of the sprite.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="tint">The tint where { tint | 0x000000 &lt;= tint &lt;= 0xFFFFFF }</param>
     **************************************************************************************************/
    void SetTint(const ALLEGRO_COLOR& tint);

    /**************************************************************************************************
     * <summary>Sets the distance, in meters, in which to rotate around when rotating in World Space.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="radius">The radius where { radius | DBL_MIN &lt;= radius &lt;= DBL_MAX }</param>
     **************************************************************************************************/
    void SetRotationRadius(double radius);

    /**************************************************************************************************
     * <summary>Makes a deep copy of this object.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <param name="sprite">The sprite.</param>
     * <returns>A copy of this object.</returns>
     **************************************************************************************************/
    virtual Sprite* Clone() const;
    
    /////////////////////////////////////////////////////////////////
    // FOLLOWING METHODS ARE USED IN DERIVED ANIMATED SPRITE CLASS //
    /////////////////////////////////////////////////////////////////

    /**************************************************************************************************
     * <summary>Animates an animated sprite based on the name of the sprite passed in. Animated it in the direction indicated.</summary>
     * <remarks>Casey Ugone, 11/8/2011.</remarks>
     * <remarks>Does nothing when called on Sprite objects.</remarks>
     * <param name="name">     The name of the animation to animate.</param>
     * <param name="dir">      The direction of the animation to play.</param>
     * <param name="deltaTime">The current time between frames in seconds.</param>
     **************************************************************************************************/
    virtual void Animate(std::string name, AnimationHandler::DIRECTION dir, double deltaTime);

    /**************************************************************************************************
     * <summary>Sets the frame rate of the animated sprite.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Does nothing when called on Sprite objects.</remarks>
     * <param name="deltaTime">The time between each frame in seconds.</param>
     **************************************************************************************************/
    virtual void SetFrameRate(double deltaTime);

    /**************************************************************************************************
     * <summary>Gets the frame rate of the animated sprite.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <returns>The frame rate. Returns -1.0 for Sprite objects.</returns>
     **************************************************************************************************/
    virtual double GetFrameRate() const;

    /**************************************************************************************************
     * <summary>Gets the frame rate of the animated sprite.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>The frame rate. Returns -1.0 for Sprite objects.</returns>
     **************************************************************************************************/
    virtual double GetFrameRate();

    /**************************************************************************************************
     * <summary>Gets the animation handler.</summary>
     * <remarks>Casey Ugone, 10/27/2011.</remarks>
     * <returns>null if it fails, else the animation handler. Returns NULL when called on a Sprite object.</returns>
     **************************************************************************************************/
    virtual AnimationHandler* GetAnimationHandler() const;

    /**************************************************************************************************
     * <summary>Gets the animation handler.</summary>
     * <remarks>Casey Ugone, 6/30/2012.</remarks>
     * <returns>null if it fails, else the animation handler. Returns NULL when called on a Sprite object.</returns>
     **************************************************************************************************/
    virtual AnimationHandler* GetAnimationHandler();

    /**************************************************************************************************
     * <summary>Sets the flip axis.</summary>
     * <remarks>Casey Ugone, 12/21/2013.</remarks>
     * <param name="axis">The axis.</param>
     **************************************************************************************************/
    virtual void SetFlipAxis(SpriteHandler::SPRITEAXIS axis);

    /**************************************************************************************************
     * <summary>Gets the flip axis.</summary>
     * <remarks>Casey Ugone, 12/21/2013.</remarks>
     * <returns>The flip axis.</returns>
     **************************************************************************************************/
    virtual SpriteHandler::SPRITEAXIS GetFlipAxis() const;

    /**************************************************************************************************
     * <summary>Gets the flip axis.</summary>
     * <remarks>Casey Ugone, 12/21/2013.</remarks>
     * <returns>The flip axis.</returns>
     **************************************************************************************************/
    virtual SpriteHandler::SPRITEAXIS GetFlipAxis();

    virtual void Draw(ALLEGRO_BITMAP* dest);

protected:

    /// <summary> The file path and name</summary>
    std::string _file;
    /// <summary> The sheet dimensions </summary>
    Vector2D _dimensions;
    /// <summary> The allocated image </summary>
    ALLEGRO_BITMAP* _image;

    /// <summary> The position </summary>
    Vector2D _position;
    /// <summary> The frame dimensions </summary>
    Vector2D _frameDimensions;
    /// <summary> The center (offset) </summary>
    Vector2D _center;
    /// <summary> The scale dimensions </summary>
    Vector2D _scaleDimensions;
    /// <summary> The rotation angle </summary>
    double _angle;
    /// <summary> The rotation radius </summary>
    double _radius;
    /// <summary> The tint color</summary>
    ALLEGRO_COLOR _tint;
    /// <summary> The flip axis </summary>
    SpriteHandler::SPRITEAXIS _axis;

    /**************************************************************************************************
     * <summary>Calculates the center of the frame.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     **************************************************************************************************/
    void CalcCenterFrame();

    /**************************************************************************************************
     * <summary>Sets the current frame.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Does nothing when called on a Sprite object.</remarks>
     * <param name="frame">The frame where { frame | 0 &lt;= frame &lt; GetNumFrames() }</param>
     **************************************************************************************************/
    virtual void SetCurFrame(int frame);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the Sprite class.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Must use named constructors above.</remarks>
     * <param name="name">The name of the sprite.</param>
     * <param name="file">[in,out] If non-null, the file.</param>
     **************************************************************************************************/
    Sprite(const std::string& name, ALLEGRO_BITMAP* file);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the Sprite class.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Must use named constructors above.</remarks>
     * <param name="file">The file.</param>
     **************************************************************************************************/
    Sprite(const std::string& file);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the Sprite class.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Must use named constructors above.</remarks>
     * <param name="sprite">The sprite.</param>
     **************************************************************************************************/
    Sprite(const Sprite& sprite);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 8/1/2011.</remarks>
     * <remarks>Must use named constructors above.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A deep copy of this object.</returns>
     **************************************************************************************************/
    Sprite& operator=(const Sprite& rhs);

    /**************************************************************************************************
     * <summary>Resize the frame.</summary>
     * <remarks>Casey Ugone, 3/11/2012.</remarks>
     * <remarks>Does nothing if width and height are unchanged from previous width and height.</remarks>
     * <remarks>Does nothing if called on a Sprite object.</remarks>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    virtual void ResizeFrame(unsigned int width, unsigned int height);

private:

    friend AnimationHandler;

};

A2DE_END

#endif
