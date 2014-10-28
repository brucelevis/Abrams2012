/**************************************************************************************************
// file:	Engine\GFX\CBitmapCache.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the bitmap cache class
 **************************************************************************************************/
#include "CBitmapCache.h"

#include <algorithm>
#include <map>

#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/allegro_image.h>
#include <allegro5/fshook.h>

A2DE_BEGIN

//filename or name of bitmap, reference count, memory location...
typedef std::map<std::string, std::pair<long, ALLEGRO_BITMAP*> > MapStrBmp;
typedef MapStrBmp::iterator MapStrBmpIter;

MapStrBmp BitmapCache::_cache;

ALLEGRO_BITMAP* BitmapCache::GetBitmap(const std::string& filename) {
    //Return NULL if a bad filename was passed.
    if(filename.empty()) return nullptr;
    if(al_filename_exists(filename.c_str()) == false) return nullptr;

    //Clean the cache if it's dirty.
    CleanCache();

    //Search for requested BITMAP.
    MapStrBmpIter _iter = _cache.find(filename);

    //If found, return it.
    if(_iter != _cache.end()) {
        _iter->second.first++;
        return _iter->second.second;
    }

    //Otherwise, create it, store it, then return it.
    ALLEGRO_BITMAP* result = al_load_bitmap(filename.c_str());
    if(result == nullptr) return nullptr;
    _cache.insert(std::make_pair(filename, std::make_pair(static_cast<long>(1), result)));
    return result;
}

void BitmapCache::StoreBitmap(const std::string& name, ALLEGRO_BITMAP* bmp) {
    if(name.empty() || bmp == nullptr) return;

    CleanCache();

    MapStrBmpIter _iter = _cache.find(name);
    //Bitmap already exists in cache, do not store it.
    if(_iter != _cache.end()) {
        return;
    }
    _cache.insert(std::make_pair(name, std::make_pair(static_cast<long>(0), bmp)));
}

ALLEGRO_BITMAP* BitmapCache::RetrieveBitmap(const std::string& name) {
    if(name.empty()) return nullptr;

    MapStrBmpIter _iter = _cache.find(name);
    if(_iter != _cache.end()) {
        _iter->second.first++;
        return _iter->second.second;
    }
    return nullptr;
}

void BitmapCache::RemoveBitmap(const std::string& name) {
    if(name.empty()) return;

    MapStrBmpIter _iter = _cache.find(name);

    if(_iter != _cache.end()) {
        _iter->second.first--;
        CleanCache();
    }
}

void BitmapCache::CleanCache() {

    //Clean the cache of any bitmaps that are no longer referenced.
    for(MapStrBmpIter _iter = _cache.begin(); _iter != _cache.end(); /* DO NOTHING */ ) {
        if(_iter->second.first > 0) {
            ++_iter;
            continue;
        }
        al_destroy_bitmap(_iter->second.second);
        _iter->second.second = nullptr;
        _cache.erase(_iter++);
    }
}

A2DE_END