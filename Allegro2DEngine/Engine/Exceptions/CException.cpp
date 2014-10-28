/**************************************************************************************************
// file:	Engine\Exceptions\CException.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the exception class
 **************************************************************************************************/
#include "CException.h"

A2DE_BEGIN

Exception::Exception(std::string message)
 : std::exception(message.c_str()), _message(message) { }


Exception::~Exception() { }

std::string Exception::Message() const {	return _message; }

const char* Exception::what() const { return (std::exception::what()); }

A2DE_END