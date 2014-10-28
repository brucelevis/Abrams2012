/**************************************************************************************************
// file:	Engine\GFX\CAnimationFrame.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the animation frame class
 **************************************************************************************************/
#include "CAnimationFrame.h"

#include <iostream>
#include <fstream>

A2DE_BEGIN

AnimationFrame::AnimationFrame() : _position(0, 0), _dimensions(1, 1) { }

AnimationFrame::AnimationFrame(int xOffset, int yOffset, int width, int height)
              : _position(xOffset,yOffset), _dimensions(width,height) { }

AnimationFrame::AnimationFrame(const AnimationFrame& other)
              : _position(other._position), _dimensions(other._dimensions) { }

AnimationFrame::~AnimationFrame() {
    /* DO NOTHING */
}

AnimationFrame& AnimationFrame::operator=(const AnimationFrame& rhs) {
    if(this == &rhs) return *this;
    this->_position = std::make_pair(rhs._position.first, rhs._position.second);
    this->_dimensions = std::make_pair(rhs._dimensions.first, rhs._dimensions.second);
    return *this;
}

bool AnimationFrame::operator==(const AnimationFrame& rhs) {
    return (this->_position == rhs._position && this->_dimensions == rhs._dimensions);
}

bool AnimationFrame::operator!=(const AnimationFrame& rhs) {
    return !(*this == rhs);
}

int AnimationFrame::GetWidth() const {
    return this->_dimensions.first;
}

int AnimationFrame::GetWidth() {
    return static_cast<const AnimationFrame&>(*this).GetWidth();
}

int AnimationFrame::GetHeight() const {
    return this->_dimensions.second;
}

int AnimationFrame::GetHeight() {
    return static_cast<const AnimationFrame&>(*this).GetHeight();
}

int AnimationFrame::GetX() const {
    return this->_position.first;
}

int AnimationFrame::GetX() {
    return static_cast<const AnimationFrame&>(*this).GetX();
}

int AnimationFrame::GetY() const {
    return this->_position.second;
}

int AnimationFrame::GetY() {
    return static_cast<const AnimationFrame&>(*this).GetY();
}

A2DE_END