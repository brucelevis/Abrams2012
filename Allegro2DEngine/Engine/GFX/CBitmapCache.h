/**************************************************************************************************
// file:	Engine\GFX\CBitmapCache.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the bitmap cache class
 **************************************************************************************************/
#ifndef A2DE_CBITMAPCACHE_H
#define A2DE_CBITMAPCACHE_H

#include "../a2de_vals.h"

#include <map>
#include <utility>
#include <string>

struct ALLEGRO_BITMAP;

A2DE_BEGIN

/**************************************************************************************************
 * <summary>Bitmap pool.</summary>
 * <remarks>Casey Ugone, 8/2/2011.</remarks>
 **************************************************************************************************/
class BitmapCache {

    /**************************************************************************************************
     * <summary>Pulls the requested bitmap from the cache if it has already been loaded, else it loads and stores it first.</summary>
     * <remarks>Casey Ugone, 8/2/2011.</remarks>
     * <remarks>The caller is responsible for destroying the ALLEGRO_BITMAP.</remarks>
     * <param name="filename">Path and Filename of the file.</param>
     * <returns>null if it fails, else the ALLEGRO_BITMAP.</returns>
     **************************************************************************************************/
    static ALLEGRO_BITMAP* GetBitmap(const std::string& filename);

    /**************************************************************************************************
     * <summary>Stores a bitmap into the cache.</summary>
     * <remarks>Casey Ugone, 12/30/2011.</remarks>
     * <param name="name">The name of the bitmap to store.</param>
     * <param name="bmp"> The ALLEGRO_BITMAP to store.</param>
     **************************************************************************************************/
    static void StoreBitmap(const std::string& name, ALLEGRO_BITMAP* bmp);

    /**************************************************************************************************
     * <summary>Retrieves a bitmap with the specified name.</summary>
     * <remarks>Casey Ugone, 12/30/2011.</remarks>
     * <param name="name">The specified name or filename of the ALLEGRO_BITMAP to retrieve.</param>
     * <returns>null if it fails, else the ALLEGRO_BITMAP.</returns>
     **************************************************************************************************/
    static ALLEGRO_BITMAP* RetrieveBitmap(const std::string& name);

    /**************************************************************************************************
     * <summary>Removes the bitmap described by name.</summary>
     * <remarks>Casey Ugone, 4/4/2012.</remarks>
     * <param name="name">The name of the BITMAP to remove.</param>
     **************************************************************************************************/
    static void RemoveBitmap(const std::string& name);

    /// <summary> The BITMAP cache:
    ///           std::string: The name or filepath of the ALLEGRO_BITMAP.
    ///           long: The total number of references of the name.
    ///           ALLEGRO_BITMAP*: The stored pixel data.</summary>
    static std::map<std::string, std::pair<long, ALLEGRO_BITMAP*> > _cache;

    /**************************************************************************************************
     * <summary>Cleans the cache of any unreferenced keys.</summary>
     * <remarks>Casey Ugone, 8/2/2011.</remarks>
     **************************************************************************************************/
    static void CleanCache();

    friend class Sprite;
    friend class TileSet;
};

A2DE_END

#endif