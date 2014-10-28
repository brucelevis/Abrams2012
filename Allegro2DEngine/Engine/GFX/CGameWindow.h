/**************************************************************************************************
// file:	Engine\GFX\CGameWindow.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the game Windows Form
 **************************************************************************************************/
#ifndef A2DE_CGAMEWINDOW_H
#define A2DE_CGAMEWINDOW_H

#include "../a2de_vals.h"
#include <utility>
#include <string>

//Forward declarations for cohesive pointer types.
struct ALLEGRO_BITMAP;
struct ALLEGRO_DISPLAY;

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Window for viewing the game. </summary>
 * <remarks>Casey Ugone, 9/3/2012.</remarks>
 **************************************************************************************************/
class GameWindow {

public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     **************************************************************************************************/
    GameWindow();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     * <param name="display_flags">bitwise or'd Allegro display flags</param>
     **************************************************************************************************/
    GameWindow(int display_flags);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     * <param name="display_flags">bitwise or'd Allegro display flags</param>
     * <param name="width">        The width of the window; it does not include the window title bar and edges if set to windowed mode!.</param>
     * <param name="height">       The height of the window; it does not include the window title bar and edges if set to windowed mode!.</param>
     **************************************************************************************************/
    GameWindow(int display_flags, int width, int height); /* throws Exception */

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     * <param name="display_flags">bitwise or'd ALlegro display flags</param>
     * <param name="width">        The width of the window; it does not include the window title bar and edges if set to windowed mode!.</param>
     * <param name="height">       The height of the window; it does not include the window title bar and edges if set to windowed mode!.</param>
     * <param name="title">        The text to display as the program title.</param>
     **************************************************************************************************/
	GameWindow(int display_flags, int width, int height, const std::string& title); /* throws Exception */

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     **************************************************************************************************/
    ~GameWindow();

    /**************************************************************************************************
     * <summary>Query if the window is set to windowed mode.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     * <returns>true if windowed, false if not.</returns>
     **************************************************************************************************/
    bool IsWindowed() const;

    /**************************************************************************************************
     * <summary>Gets the width of the window.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     * <returns>The width of the window not including the title bar or edges.</returns>
     **************************************************************************************************/
    int GetWidth() const;

    /**************************************************************************************************
     * <summary>Gets the height of the window.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     * <returns>The height of the window not including the title bar or edges.</returns>
     **************************************************************************************************/
    int GetHeight() const;

    /**************************************************************************************************
     * <summary>Displays the window to the screen.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     **************************************************************************************************/
    void ShowWindow();

    /**************************************************************************************************
     * <summary>Starts a render operation.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     **************************************************************************************************/
    void StartRender();

    /**************************************************************************************************
     * <summary>Ends a render operation.</summary>
     * <remarks>Casey Ugone, 7/26/2011.</remarks>
     * <remarks>This method assumes the offset coordinate is at (0,0).</remarks>
     **************************************************************************************************/
    void EndRender();

    /**************************************************************************************************
     * <summary>Gets the display.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>A pointer to the ALLEGRO_DISPLAY.</returns>
     **************************************************************************************************/
    ALLEGRO_DISPLAY* const GetDisplay() const;

    /**************************************************************************************************
     * <summary>Gets the display.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>A pointer to the ALLEGRO_DISPLAY.</returns>
     **************************************************************************************************/
    ALLEGRO_DISPLAY* const GetDisplay();

private:
	/// <summary> The display flags </summary>
	int _display_flags;
	/// <summary> screen dimensions </summary>
	std::pair<int, int> _dimensions;
	/// <summary> The title </summary>
	std::string _title;
    /// <summary>The display.</summary>
    ALLEGRO_DISPLAY* _display;

};

A2DE_END

#endif
