/**************************************************************************************************
// file:	Engine\Input\CMouse.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the mouse class
 **************************************************************************************************/
#ifndef A2DE_CMOUSE_H
#define A2DE_CMOUSE_H

#include "../a2de_vals.h"
#include <allegro5/mouse.h>
#include <allegro5/mouse_cursor.h>
#include <bitset>
#include <utility>
#include <tuple>
#include "../Math/CPoint.h"
#include "../Math/CVector2D.h"
#include "../Math/CVector3D.h"
#include "../Math/CVector4D.h"

struct ALLEGRO_BITMAP;

A2DE_BEGIN

class Sprite;
class GameWindow;

/**************************************************************************************************
 * <summary>Mouse.</summary>
 * <remarks>Casey Ugone, 7/28/2011.</remarks>
 **************************************************************************************************/
class Mouse {

public:
    
    /**************************************************************************************************
     * <summary>Creates the mouse with a default arrow pointer.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>null if it fails, else a pointer to a Mouse.</returns>
     **************************************************************************************************/
	static Mouse* CreateMouse(ALLEGRO_DISPLAY* parent_display);

    /**************************************************************************************************
     * <summary>Creates a mouse with a custom pointer.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="image"> [in] If non-null, the image.</param>
     * <param name="focusX">The focus x coordinate.</param>
     * <param name="focusY">The focus y coordinate.</param>
     * <returns>null if it fails, else a pointer to a Mouse.</returns>
     **************************************************************************************************/
    static Mouse* CreateMouse(ALLEGRO_DISPLAY* parent_display, Sprite* image, int focusX, int focusY);

    /**************************************************************************************************
     * <summary>Creates a mouse.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <param name="image"> [in,out] If non-null, the image.</param>
     * <param name="focus_coordinates">The focus coordinates.</param>
     * <returns>null if it fails, else a pointer to a Mouse.</returns>
     **************************************************************************************************/
    static Mouse* CreateMouse(ALLEGRO_DISPLAY* parent_display, Sprite* image, const a2de::Vector2D& focus_coordinates);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     **************************************************************************************************/
    ~Mouse();

    /**************************************************************************************************
     * <summary>Gets the sprite of the mouse image.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>null if it fails, else the sprite.</returns>
     **************************************************************************************************/
    Sprite* GetSprite() const;

    /**************************************************************************************************
     * <summary>Gets position as a 4D Vector.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    const Vector4D& GetPosition4d() const;

    /**************************************************************************************************
     * <summary>Gets position as a 4D Vector.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    Vector4D& GetPosition4d();

    /**************************************************************************************************
     * <summary>Gets the position as a Vector3D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The position 3d.</returns>
     **************************************************************************************************/
    Vector3D GetPosition3d() const;

    /**************************************************************************************************
     * <summary>Gets the position as a Vector3D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The position 3d.</returns>
     **************************************************************************************************/
    Vector3D GetPosition3d();

    /**************************************************************************************************
     * <summary>Gets the position as a Vector2D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The position 2d.</returns>
     **************************************************************************************************/
    Vector2D GetPosition2d() const;

    /**************************************************************************************************
     * <summary>Gets the position as a Vector2D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The position 2d.</returns>
     **************************************************************************************************/
    Vector2D GetPosition2d();

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    int GetX() const;

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    int GetX();

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    int GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    int GetY();

    /**************************************************************************************************
     * <summary>Get the mouse wheel's vertical wheel value.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mouse wheel value..</returns>
     **************************************************************************************************/
    int GetZ() const;

    /**************************************************************************************************
     * <summary>Get the mouse wheel's vertical wheel value.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mouse wheel value..</returns>
     **************************************************************************************************/
    int GetZ();

    /**************************************************************************************************
     * <summary>Get the mouse wheel's horizontal value.</summary>
     * <remarks>Casey Ugone, 10/12/2014.</remarks>
     * <returns>The w.</returns>
     **************************************************************************************************/
    int GetW() const;

    /**************************************************************************************************
     * <summary>Get the mouse wheel's horizontal value.</summary>
     * <remarks>Casey Ugone, 10/12/2014.</remarks>
     * <returns>The w.</returns>
     **************************************************************************************************/
    int GetW();

    /**************************************************************************************************
     * <summary>Gets mickeys as a 4D Vector.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The mickeys.</returns>
     **************************************************************************************************/
    const Vector4D& GetMickeys4d() const;

    /**************************************************************************************************
     * <summary>Gets mickeys as a 4D Vector.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The mickeys.</returns>
     **************************************************************************************************/
    Vector4D& GetMickeys4d();

    /**************************************************************************************************
     * <summary>Gets the mickeys as a Vector3D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The mickeys.</returns>
     **************************************************************************************************/
    Vector3D GetMickeys3d() const;

    /**************************************************************************************************
     * <summary>Gets the mickeys as a Vector3D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The mickeys.</returns>
     **************************************************************************************************/
    Vector3D GetMickeys3d();

    /**************************************************************************************************
     * <summary>Gets mickeys 2d.</summary>
     * <remarks>Casey Ugone, 10/11/2014.</remarks>
     * <returns>The mickeys 2d.</returns>
     **************************************************************************************************/
    Vector2D GetMickeys2d() const;

    /**************************************************************************************************
     * <summary>Gets mickeys 2d.</summary>
     * <remarks>Casey Ugone, 10/11/2014.</remarks>
     * <returns>The mickeys 2d.</returns>
     **************************************************************************************************/
    Vector2D GetMickeys2d();

    /**************************************************************************************************
     * <summary>Gets the change in x coordinates between Updates.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey x coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyX() const;

    /**************************************************************************************************
     * <summary>Gets the change in x coordinates between Updates.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey x coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyX();

    /**************************************************************************************************
     * <summary>Gets the change in y coordinates between Updates..</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey y coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyY() const;

    /**************************************************************************************************
     * <summary>Gets the change in y coordinates between Updates..</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey y coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyY();

    /**************************************************************************************************
     * <summary>Gets the vertical change in mouse wheel position between Updates.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey z coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyZ() const;

    /**************************************************************************************************
     * <summary>Gets the vertical change in mouse wheel position between Updates.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey z coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyZ();

    /**************************************************************************************************
     * <summary>Gets the horizontal change in mouse wheel position between Updates.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey w coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyW() const;

    /**************************************************************************************************
     * <summary>Gets the horizontal change in mouse wheel position between Updates.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The mickey w coordinate.</returns>
     **************************************************************************************************/
    int GetMickeyW();

    /**************************************************************************************************
     * <summary>Gets the focus as a Vector2D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The focus.</returns>
     **************************************************************************************************/
    const Vector2D& GetFocus() const;

    /**************************************************************************************************
     * <summary>Gets the focus as a Vector2D object.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <returns>The focus.</returns>
     **************************************************************************************************/
    Vector2D& GetFocus();

    /**************************************************************************************************
     * <summary>Gets the focus x coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The focus x coordinate.</returns>
     **************************************************************************************************/
	int GetFocusX() const;

    /**************************************************************************************************
     * <summary>Gets the focus x coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The focus x coordinate.</returns>
     **************************************************************************************************/
    int GetFocusX();

    /**************************************************************************************************
     * <summary>Gets the focus y coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The focus y coordinate.</returns>
     **************************************************************************************************/
	int GetFocusY() const;

    /**************************************************************************************************
     * <summary>Gets the focus y coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The focus y coordinate.</returns>
     **************************************************************************************************/
    int GetFocusY();

    /**************************************************************************************************
     * <summary>Gets the number of buttons.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The number of buttons.</returns>
     **************************************************************************************************/
	int GetNumButtons() const;

    /**************************************************************************************************
     * <summary>Gets the number of buttons.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>The number of buttons.</returns>
     **************************************************************************************************/
    int GetNumButtons();

    /**************************************************************************************************
     * <summary>Sets the x coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets the y coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetY(double y);

    /**************************************************************************************************
     * <summary>Sets the z coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="z">The z coordinate.</param>
     **************************************************************************************************/
    void SetZ(double z);

    /**************************************************************************************************
     * <summary>Sets the w coordinate.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="w">The w coordinate.</param>
     **************************************************************************************************/
    void SetW(double w);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetPosition(double x, double y);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <param name="z">The z coordinate.</param>
     **************************************************************************************************/
    void SetPosition(double x, double y, double z);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 10/11/2014.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <param name="z">The horizontal coordinate of the mouse wheel.</param>
     * <param name="w">The vertical coordinate of the mouse wheel.</param>
     **************************************************************************************************/
    void SetPosition(double x, double y, double z, double w);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <param name="pos">The position as a Vector2D object.</param>
     **************************************************************************************************/
    void SetPosition(const a2de::Vector2D& pos);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 1/2/2013.</remarks>
     * <param name="pos">The position as a Vector3D object.</param>
     **************************************************************************************************/
    void SetPosition(const a2de::Vector3D& pos);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 10/11/2014.</remarks>
     * <param name="pos">The position as a Vector4D object.</param>
     **************************************************************************************************/
    void SetPosition(const a2de::Vector4D& pos);

    /**************************************************************************************************
     * <summary>Sets the focus point.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
	void SetFocus(int x, int y);

    /**************************************************************************************************
     * <summary>Updates the mouse parameters.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     **************************************************************************************************/
    void Update();
    
    /**************************************************************************************************
     * <summary>Sets the image.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="image"> [in] If non-null, the image, else clears the image.</param>
     * <param name="focusX">The focus x coordinate.</param>
     * <param name="focusY">The focus y coordinate.</param>
     **************************************************************************************************/
	void SetImage(Sprite* image, int focusX, int focusY);

    /**************************************************************************************************
     * <summary>Query if this object is visible.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <returns>true if visible, false if not.</returns>
     **************************************************************************************************/
	bool IsVisible();

    /**************************************************************************************************
     * <summary>Sets the mouse's visible state.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="visible">true to show, false to hide.</param>
     **************************************************************************************************/
	void SetVisible(bool visible);

    /**************************************************************************************************
     * <summary>Shows the mouse on the specified BITMAP.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <remarks>Synonoumus with Show(dest, 0, 0, dest->w, dest->h)</remarks>
     * <param name="dest">[in] If non-null, destination for the Bitmap, else hides the mouse pointer.</param>
     **************************************************************************************************/
    void Show();
    
    /**************************************************************************************************
     * <summary>Hides the mouse pointer.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     **************************************************************************************************/
	void Hide();

    /**************************************************************************************************
     * <summary>Sets the image to the default system cursor.</summary>
     * <remarks>Casey Ugone, 12/11/2012.</remarks>
     **************************************************************************************************/
    void SetImageToDefault();

    /**************************************************************************************************
     * <summary>Sets image to a system default.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="cursor">The cursor to set to.</param>
     **************************************************************************************************/
    void SetImageToDefault(ALLEGRO_SYSTEM_MOUSE_CURSOR cursor);

    /**************************************************************************************************
     * <summary>Determines if the display lost focus of the mouse.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>true if it did, false if it did not.</returns>
     **************************************************************************************************/
    bool MouseLostFocus() const;

    /**************************************************************************************************
     * <summary>Determines if the display lost focus of the mouse.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>true if it did, false if it did not.</returns>
     **************************************************************************************************/
    bool MouseLostFocus();

    /**************************************************************************************************
     * <summary>Sets the parent display.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="display">[in,out] If non-null, the display.</param>
     **************************************************************************************************/
    void SetParentDisplay(ALLEGRO_DISPLAY* display);

private:

    /// <summary> The position </summary>
    Vector4D _position;
    /// <summary> The mickeys </summary>
    Vector4D _mickeys;

    /// <summary>The focus location.</summary>
    Vector2D _focus;
    /// <summary> The image </summary>
    a2de::Sprite* _image;
    
    /// <summary> true to show, false to hide the image</summary>
    bool _isVisible;

    /// <summary> Number of buttons </summary>
    unsigned int _numButtons;

    /**************************************************************************************************
     * <summary>the previous state.</summary>
     **************************************************************************************************/
    ALLEGRO_MOUSE_STATE _prevState;

    /**************************************************************************************************
     * <summary>The current state.</summary>
     **************************************************************************************************/
    ALLEGRO_MOUSE_STATE _curState;

    /**************************************************************************************************
     * <summary>The cursor currently in use.</summary>
     **************************************************************************************************/
    ALLEGRO_MOUSE_CURSOR* _cursor;

    /**************************************************************************************************
     * <summary>The parent display.</summary>
     **************************************************************************************************/
    ALLEGRO_DISPLAY* _parent_display;

    /**************************************************************************************************
     * <summary>Identifier for the cursor.</summary>
     **************************************************************************************************/
    ALLEGRO_SYSTEM_MOUSE_CURSOR _cursor_id;

    /// <summary> The instance </summary>
    static Mouse* _instance;

    /**************************************************************************************************
     * <summary>Configs this object.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    static bool Config();

    /**************************************************************************************************
     * <summary>Initializes this object.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Init();

    /**************************************************************************************************
     * <summary>Deinitializes this object.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Deinit();

    /**************************************************************************************************
     * <summary>Initializes a new instance of the Mouse class.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     **************************************************************************************************/
    Mouse(ALLEGRO_DISPLAY* parent_display);

    /**************************************************************************************************
     * <summary>Initializes a new instance of the Mouse class.</summary>
     * <remarks>Casey Ugone, 7/28/2011.</remarks>
     * <param name="image"> [in] If non-null, the image.</param>
     * <param name="focusX">The focus x coordinate.</param>
     * <param name="focusY">The focus y coordinate.</param>
     **************************************************************************************************/
    Mouse(ALLEGRO_DISPLAY* parent_display, Sprite* image, int focusX, int focusY);
    
    friend class MouseInputHandler;
};

A2DE_END

#endif