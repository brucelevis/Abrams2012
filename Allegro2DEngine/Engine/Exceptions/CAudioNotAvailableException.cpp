/**************************************************************************************************
// file:	Engine\Exceptions\CAudioNotAvailableException.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the audio not available exception class
 **************************************************************************************************/
#include "CAudioNotAvailableException.h"

A2DE_BEGIN
AudioNotAvailableException::AudioNotAvailableException() : Exception("Audio Not Available") { }

AudioNotAvailableException::~AudioNotAvailableException() { }

std::string AudioNotAvailableException::Message() const {
    return Exception::Message();
}

A2DE_END