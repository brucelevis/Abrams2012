/**************************************************************************************************
// file:	Engine\GFX\CAnimationHandler.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the animation handler class
 **************************************************************************************************/
#include "CAnimationHandler.h"

#include "CAnimationFrameSet.h"
#include "CSprite.h"
#include "CAnimatedSprite.h"

#include "../a2de_exceptions.h"

#include <allegro5/display.h>
#include <allegro5/bitmap_draw.h>

A2DE_BEGIN

typedef std::map<std::string, AnimationFrameSet> AnimMap;
typedef AnimMap::iterator AnimMapIter;
typedef AnimMap::const_iterator AnimMapConstIter;

AnimationHandler::AnimationHandler(const Sprite& source) : _animations(AnimMap()), _curSet(AnimMapIter()), _observed(const_cast<Sprite*>(&source)), _curName("") { }

AnimationHandler::AnimationHandler(const AnimationHandler& other) : _animations(other._animations), _curSet(other._curSet), _observed(other._observed), _curName("") { }

AnimationHandler::~AnimationHandler() {
    _animations.clear();
}

bool AnimationHandler::AddAnimation(const std::string& name) {
    return AddAnimation(name, AnimationFrameSet());
}

bool AnimationHandler::AddAnimation(const std::string& name, const AnimationFrameSet& frames) {
    AnimMapIter _iter = _animations.find(name);
    if(_iter != _animations.end()) return false;
    
    bool was_empty = this->IsEmpty();
    _animations.insert(std::make_pair(name, frames));
    if(was_empty) {
        AnimMapIter first_animation = _animations.begin();
        first_animation->second.First();
        CopyCurrentFrameToImageFrame(first_animation);
    }
    return true;
}

bool AnimationHandler::RemoveAnimation(const std::string& name) {
    AnimMapIter _iter = _animations.find(name);
    if(_iter == _animations.end()) return false;
    _animations.erase(_iter);
    return true;
}

const a2de::AnimationFrameSet& AnimationHandler::GetFrameSetByName(const std::string& name) const {
    AnimMapConstIter _iter = _animations.find(name);
    if(_iter == _animations.end()) {
        throw a2de::InvalidArgumentException(std::string("Frame set by name: ").append(name).append(" does not exist."));
    }
    return _iter->second;
}

a2de::AnimationFrameSet& AnimationHandler::GetFrameSetByName(const std::string& name) {
    return const_cast<a2de::AnimationFrameSet&>(static_cast<const AnimationHandler&>(*this).GetFrameSetByName(name));
}

std::size_t AnimationHandler::Size(const std::string& name) const {
    AnimMapConstIter _iter = _animations.find(name);
    if(_iter == _animations.end()) return 0;
    return _iter->second.Size();
}

std::size_t AnimationHandler::Size(const std::string& name) {
    return static_cast<const AnimationHandler&>(*this).Size(name);
}

std::size_t AnimationHandler::Size() const {
    return _animations.size();
}

std::size_t AnimationHandler::Size() {
    return static_cast<const AnimationHandler&>(*this).Size();
}

bool AnimationHandler::IsEmpty() const {
    return _animations.empty();
}

bool AnimationHandler::IsEmpty() {
    return static_cast<const AnimationHandler&>(*this).IsEmpty();
}

void AnimationHandler::Animate(const std::string& name, AnimationHandler::DIRECTION dir) {
    AnimMapIter _iter;
    _iter = _animations.find(name);
    if(_iter == _animations.end()) return;

    if(_curName != name) {
        _curName = name;

        switch(dir) {
        case DIR_FORWARD_LOOPING: /* Fall through to DIR_FORWARD_NONLOOPING */
        case DIR_FORWARD_NONLOOPING:
            _iter->second.First();
            break;
        case DIR_REVERSE_LOOPING: /* Fall through to DIR_REVERSE_NONLOOPING */
        case DIR_REVERSE_NONLOOPING:
            _iter->second.Last();
            break;
        }
    } else {

        switch(dir) {
        case DIR_FORWARD_LOOPING:
            _iter->second.Next();
            if(_iter->second.IsAtEnd()) _iter->second.First();
            break;
        case DIR_FORWARD_NONLOOPING:
            _iter->second.Next();
            if(_iter->second.IsAtEnd()) _iter->second.Last();
            break;
        case DIR_REVERSE_LOOPING:
            _iter->second.Previous();
            if(_iter->second.IsAtFront()) _iter->second.Last();
            break;
        case DIR_REVERSE_NONLOOPING:
            _iter->second.Previous();
            if(_iter->second.IsAtFront()) _iter->second.First();
            break;
        }
    }

    CopyCurrentFrameToImageFrame(_iter);
}

void AnimationHandler::Play(const std::string& name, bool rewindOnCompletion) {
    if(rewindOnCompletion) {
        this->Animate(name, AnimationHandler::DIR_FORWARD_LOOPING);
    } else {
        this->Animate(name, AnimationHandler::DIR_FORWARD_NONLOOPING);
    }
}

void AnimationHandler::Reverse(const std::string& name, bool rewindOnCompletion) {
    if(rewindOnCompletion) {
        this->Animate(name, AnimationHandler::DIR_REVERSE_LOOPING);
    } else {
        this->Animate(name, AnimationHandler::DIR_REVERSE_NONLOOPING);
    }
}

AnimationHandler& AnimationHandler::operator=(const AnimationHandler& rhs) {
    if(this == &rhs) return *this;
    this->_observed = rhs._observed;
    this->_curSet = rhs._curSet;
    this->_animations = rhs._animations;
    return *this;
}

a2de::AnimMapIter AnimationHandler::Begin() {
    return _animations.begin();
}

a2de::AnimMapIter AnimationHandler::End() {
    return _animations.end();
}

void AnimationHandler::CopyCurrentFrameToImageFrame(AnimMapIter _iter) {
    a2de::AnimationFrame curFrame = _iter->second.GetCurFrame();
    double curFrameWidth = curFrame.GetWidth();
    double curFrameHeight = curFrame.GetHeight();
    double curFrameX = curFrame.GetX();
    double curFrameY = curFrame.GetY();

    _observed->ResizeFrame(curFrameWidth, curFrameHeight);
    
    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(_observed->GetImage());

    al_draw_bitmap_region(_observed->GetSheet(), curFrameX, curFrameY, curFrameWidth, curFrameHeight, 0, 0, 0);

    al_set_target_bitmap(old_target);
}


A2DE_END