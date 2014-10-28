/**************************************************************************************************
// file:	Engine\GFX\CTileSet.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the tile set class
 **************************************************************************************************/
#ifndef A2DE_CTILESET_H
#define A2DE_CTILESET_H

#include "../a2de_vals.h"

#include <vector>
#include <string>

struct ALLEGRO_BITMAP;

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Tile set. </summary>
 * <remarks>Casey Ugone, 7/6/2012.</remarks>
 **************************************************************************************************/
class TileSet {

public:

    /**************************************************************************************************
     * <summary>Creates a tile set.</summary>
     * <remarks>Casey Ugone, 4/2/2012.</remarks>
     * <param name="file">       The image file containing the tiles.</param>
     * <param name="tile_width"> Width of all tiles in pixels.</param>
     * <param name="tile_height">Height of all tiles in pixels</param>
     * <returns>null if it fails, else a created TileSet object.</returns>
     **************************************************************************************************/
    static TileSet* CreateTileSet(const std::string& file, int tile_width, int tile_height);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 4/2/2012.</remarks>
     **************************************************************************************************/
    ~TileSet();

    /**************************************************************************************************
     * <summary>Draw tiles to an ALLEGRO_BITMAP.</summary>
     * <remarks>Casey Ugone, 4/2/2012.</remarks>
     * <param name="dest">  If non-null, destination ALLEGRO_BITMAP for the tile to draw to.</param>
     * <param name="column">Zero-based index of the column of the tile.</param>
     * <param name="row">   Zero-based index of the row of the tile.</param>
     * <param name="dest_x">Destination x coordinate in pixels.</param>
     * <param name="dest_y">Destination y coordinate in pixels.</param>
     **************************************************************************************************/
    void DrawTile(ALLEGRO_BITMAP* dest, unsigned int column, unsigned int row, int dest_x, int dest_y);

    /**************************************************************************************************
     * <summary>Draw tiles to an ALLEGRO_BITMAP.</summary>
     * <remarks>Casey Ugone, 4/2/2012.</remarks>
     * <param name="dest">  If non-null, destination ALLEGRO_BITMAP for the tile to draw to.</param>
     * <param name="index"> Zero-based index of the tile.</param>
     * <param name="dest_x">Destination x coordinate in pixels.</param>
     * <param name="dest_y">Destination y coordinate in pixels.</param>
     **************************************************************************************************/
    void DrawTile(ALLEGRO_BITMAP* dest, unsigned int index, int dest_x, int dest_y);

    /**************************************************************************************************
     * <summary>Gets the tile width in pixels.</summary>
     * <remarks>Casey Ugone, 4/3/2012.</remarks>
     * <returns>The tile width in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetTileWidth() const;

    /**************************************************************************************************
     * <summary>Gets the tile width in pixels.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <returns>The tile width in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetTileWidth();

    /**************************************************************************************************
     * <summary>Gets the tile height in pixels.</summary>
     * <remarks>Casey Ugone, 4/3/2012.</remarks>
     * <returns>The tile height in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetTileHeight() const;

    /**************************************************************************************************
     * <summary>Gets the tile height in pixels.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <returns>The tile height in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetTileHeight();

    /**************************************************************************************************
     * <summary>Gets the tile sheet width in pixels.</summary>
     * <remarks>Casey Ugone, 4/3/2012.</remarks>
     * <returns>The sheet width in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetSheetWidth() const;

    /**************************************************************************************************
     * <summary>Gets the sheet width in pixels.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <returns>The sheet width in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetSheetWidth();

    /**************************************************************************************************
     * <summary>Gets the tile sheet height in pixels.</summary>
     * <remarks>Casey Ugone, 4/3/2012.</remarks>
     * <returns>The sheet height in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetSheetHeight() const;

    /**************************************************************************************************
     * <summary>Gets the sheet height in pixels.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <returns>The sheet height in pixels.</returns>
     **************************************************************************************************/
    unsigned int GetSheetHeight();

protected:
private:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 4/2/2012.</remarks>
     * <param name="file">       The path to the image file.</param>
     * <param name="tile_width"> Width of the tiles.</param>
     * <param name="tile_height">Height of the tiles.</param>
     **************************************************************************************************/
    TileSet(const std::string& file, int tile_width, int tile_height);   

    /// <summary> The file </summary>
    std::string _file;
    /// <summary> Width of a tile </summary>
    int _tileWidth;
    /// <summary> Height of a tile </summary>
    int _tileHeight;
    /// <summary> Width of the sheet </summary>
    unsigned int _sheetWidth;
    /// <summary> Height of the sheet </summary>
    unsigned int _sheetHeight;
    /// <summary> The maximum rows </summary>
    unsigned int _max_rows;
    /// <summary> The maximum columns </summary>
    unsigned int _max_columns;
    /// <summary> The maximum tiles </summary>
    unsigned int _max_tiles;
    /// <summary> The tile sheet </summary>
    ALLEGRO_BITMAP* _tileSheet;

};

A2DE_END

#endif