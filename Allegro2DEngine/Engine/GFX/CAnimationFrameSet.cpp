/**************************************************************************************************
// file:	Engine\GFX\CAnimationFrameSet.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the animation frame set class
 **************************************************************************************************/
#include "CAnimationFrameSet.h"

#include "CSprite.h"
#include <algorithm>

A2DE_BEGIN

typedef std::vector<AnimationFrame> frameList;
typedef std::vector<AnimationFrame>::iterator frameIter;
typedef std::vector<AnimationFrame>::const_iterator constFrameIter;
typedef std::vector<AnimationFrame>::reverse_iterator frameRevIter;


AnimationFrameSet::AnimationFrameSet()
                 : _frameStrip(frameList()), _curPos(0) { }

AnimationFrameSet::AnimationFrameSet(const AnimationFrameSet& other)
                 : _frameStrip(frameList(other._frameStrip)), _curPos(0) { }

AnimationFrameSet::~AnimationFrameSet() {
    _frameStrip.clear();
}

AnimationFrameSet& AnimationFrameSet::operator=(const AnimationFrameSet& rhs) {
    if(this == &rhs) return *this;

    this->_frameStrip.resize(rhs._frameStrip.size());
    std::copy(rhs._frameStrip.begin(), rhs._frameStrip.end(), this->_frameStrip.begin());

    return *this;
}

bool AnimationFrameSet::operator==(const AnimationFrameSet& rhs) {
    if(this == &rhs) return true;
    if(this->_frameStrip.size() != rhs._frameStrip.size()) return false;

    constFrameIter _rhsIter = rhs._frameStrip.begin();
    frameIter _thisIter = this->_frameStrip.begin();
    frameIter _myEnd = _frameStrip.end();
    while(_thisIter != _myEnd) {
        if((*_thisIter) != (*_rhsIter)) return false;
        _rhsIter++;
        _thisIter++;
    }
    return true;
}


bool AnimationFrameSet::operator!=(const AnimationFrameSet& rhs) {
    return !(*this == rhs);
}

void AnimationFrameSet::AddFrame(const AnimationFrame& frame) {
    _frameStrip.push_back(frame);
    _curPos = 0;
}

void AnimationFrameSet::First() {
    _curPos = 0;
}

void AnimationFrameSet::Last() {
    _curPos = _frameStrip.size() - 1;
}

void AnimationFrameSet::Next() {
    std::size_t s = _frameStrip.size();
    if(s == 0 || _curPos == s) return;
    ++_curPos;
}

void AnimationFrameSet::Previous() {
    std::size_t s = _frameStrip.size();
    if(s == 0 || _curPos < 0) return;
    --_curPos;
}

std::size_t AnimationFrameSet::Size() const {
    return _frameStrip.size();
}

std::size_t AnimationFrameSet::Size() {
    return static_cast<const AnimationFrameSet&>(*this).Size();
}

bool AnimationFrameSet::IsAtFirst() const {
    return _curPos == 0;
}

bool AnimationFrameSet::IsAtFirst() {
    return static_cast<const AnimationFrameSet&>(*this).IsAtFirst();
}

bool a2de::AnimationFrameSet::IsAtLast() const {
    return _curPos == _frameStrip.size() - 1;
}

bool a2de::AnimationFrameSet::IsAtLast() {
    return static_cast<const AnimationFrameSet&>(*this).IsAtLast();
}

bool AnimationFrameSet::IsAtEnd() const {
    return IsComplete();
}

bool AnimationFrameSet::IsAtEnd() {
    return static_cast<const AnimationFrameSet&>(*this).IsAtEnd();
}

bool AnimationFrameSet::IsAt(std::size_t position) const {
    return _curPos == position;
}

bool AnimationFrameSet::IsAt(std::size_t position) {
    return static_cast<const AnimationFrameSet&>(*this).IsAt(position);
}

bool a2de::AnimationFrameSet::IsAtFront() const {
    return _curPos == -1;
}

bool a2de::AnimationFrameSet::IsAtFront() {
    return static_cast<const AnimationFrameSet&>(*this).IsAtFront();
}

bool AnimationFrameSet::IsComplete() const {
    return _curPos == _frameStrip.size();
}

bool AnimationFrameSet::IsComplete() {
    return static_cast<const AnimationFrameSet&>(*this).IsComplete();
}

const AnimationFrame& AnimationFrameSet::GetCurFrame() const {
    return GetFrameAt(_curPos);
}

AnimationFrame& AnimationFrameSet::GetCurFrame() {
    return const_cast<AnimationFrame&>(static_cast<const AnimationFrameSet&>(*this).GetCurFrame());
}

const AnimationFrame& AnimationFrameSet::GetFrameAt(std::size_t position) const {
    if(position < 0) position = 0;
    if(position >= _frameStrip.size()) position = _frameStrip.size() - 1;
    return this->_frameStrip[position];
}

AnimationFrame& AnimationFrameSet::GetFrameAt(std::size_t position) {
    return const_cast<AnimationFrame&>(static_cast<const AnimationFrameSet&>(*this).GetFrameAt(position));
}

A2DE_END