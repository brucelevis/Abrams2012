/**************************************************************************************************
// file:	Engine\Exceptions\CTypeNotSupportedException.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the type not supported exception class
 **************************************************************************************************/
#include "CTypeNotSupportedException.h"
#include <algorithm>

A2DE_BEGIN

/// <summary> List of types of the type not supported exception supports </summary>
std::set<std::string> TypeNotSupportedException::_supportedTypes;

TypeNotSupportedException::TypeNotSupportedException(std::string name)
    : Exception("Type Not Supported"), _name(name) { }

TypeNotSupportedException::~TypeNotSupportedException() { }

std::string TypeNotSupportedException::Message() const {
    return Exception::Message().append(": ").append(_name);
}

bool TypeNotSupportedException::CheckFileType(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    return std::binary_search(_supportedTypes.begin(), _supportedTypes.end(), name);
}

bool TypeNotSupportedException::RegisterFileType(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    if(CheckFileType(name)) return false;
    _supportedTypes.insert(name);
    return true;

}

bool TypeNotSupportedException::UnregisterFileType(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    if(CheckFileType(name) == false) return false;
    _supportedTypes.erase(_supportedTypes.find(name));
    return true;
}

A2DE_END