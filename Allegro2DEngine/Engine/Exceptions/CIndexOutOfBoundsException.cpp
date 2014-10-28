/**************************************************************************************************
// file:	Engine\Exceptions\CIndexOutOfBoundsException.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the index out of bounds exception class
 **************************************************************************************************/
#include "CIndexOutOfBoundsException.h"

A2DE_BEGIN

IndexOutOfBoundsException::IndexOutOfBoundsException(std::string argument, std::string lowerBound, std::string upperBound)
 : Exception("Index out of bounds"), _lower(lowerBound), _upper(upperBound), _argument(argument) { }

IndexOutOfBoundsException::~IndexOutOfBoundsException() { }

std::string IndexOutOfBoundsException::Message() const {
    return Exception::Message().append(":\nArgument: ").append(_argument).append("\nLower: ").append(_lower).append("\nUpper: ").append(_upper);
}

A2DE_END