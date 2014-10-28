/**************************************************************************************************
// file:	Engine\Exceptions\CBitmapCreationFailureException.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the bitmap creation failure exception class
 **************************************************************************************************/
#include "CBitmapCreationFailureException.h"

A2DE_BEGIN

BitmapCreationFailureException::BitmapCreationFailureException(std::string name)
 : Exception("Bitmap \'"), _name(name) { }

BitmapCreationFailureException::~BitmapCreationFailureException() { }

std::string BitmapCreationFailureException::Message() const {
    return Exception::Message().append(_name).append("\' creation failed.");
}

A2DE_END