/**************************************************************************************************
// file:	Engine\GFX\CAnimatedSprite.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the animated sprite class
 **************************************************************************************************/
#include "CAnimatedSprite.h"

#include <allegro5/drawing.h>
#include <allegro5/color.h>
#include <allegro5/bitmap.h>
#include <allegro5/fshook.h>
#include <allegro5/display.h>

#include "../a2de_exceptions.h"
#include <string>

#include "CAnimationHandler.h"

A2DE_BEGIN

AnimatedSprite* AnimatedSprite::CreateAnimatedSprite(const std::string& name, ALLEGRO_BITMAP* file, double frameRate) {
    if(file == nullptr) {
        throw InvalidArgumentException("Null BITMAPs not allowed.");
    }
    if(name.empty()) {
        throw InvalidArgumentException("Name cannot be empty.");
    }
    return (new AnimatedSprite(name, file, frameRate));
}

AnimatedSprite* AnimatedSprite::CreateAnimatedSprite(const std::string& file, double frameRate) {
    if(file.empty() == false) {
        if(al_filename_exists(file.c_str()) == false) {
            throw FileNotFoundException(file);
        }
    } else {
        throw InvalidArgumentException("File cannot be empty.");
    }
    return (new AnimatedSprite(file, frameRate));
}

AnimatedSprite* AnimatedSprite::CreateAnimatedSprite(const AnimatedSprite& animatedSprite) {
    return (new AnimatedSprite(animatedSprite));
}

AnimatedSprite::AnimatedSprite(const std::string& name, ALLEGRO_BITMAP* file, double frameRate)
    : Sprite(name, file), _frameImage(nullptr), _frameRate(frameRate), _animation(nullptr), _accumulator(0.0) {
        if(_frameRate < 0.0) _frameRate = 0.0;
        _frameDimensions = Vector2D(0.0, 0.0);
        _animation = new AnimationHandler(*this);
}

AnimatedSprite::AnimatedSprite(const std::string& file, double frameRate)
    : Sprite(file), _frameImage(nullptr), _frameRate(frameRate), _animation(nullptr), _accumulator(0.0) {
        if(_frameRate < 0.0) _frameRate = 0.0;
        _frameDimensions = Vector2D(0.0, 0.0);
        _animation = new AnimationHandler(*this);
}

AnimatedSprite::AnimatedSprite(const AnimatedSprite& animatedSprite)
 : Sprite(animatedSprite), _frameImage(nullptr), _frameRate(animatedSprite._frameRate), _animation(nullptr), _accumulator(0.0) {
    this->_frameImage = al_create_bitmap(al_get_bitmap_width(animatedSprite._frameImage), al_get_bitmap_height(animatedSprite._frameImage));
    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(this->_frameImage);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_target_bitmap(old_target);
    this->_frameDimensions = animatedSprite._frameDimensions;
    if(animatedSprite._animation != nullptr) {
        delete this->_animation;
        this->_animation = new AnimationHandler(*animatedSprite._animation);
    } else {
        delete this->_animation;
        this->_animation = nullptr;
    }
}

AnimatedSprite::~AnimatedSprite() {
    al_destroy_bitmap(_frameImage);
    _frameImage = nullptr;
    delete _animation;
    _animation = nullptr;
}

ALLEGRO_BITMAP* AnimatedSprite::GetImage() const {
    return _frameImage;
}
ALLEGRO_BITMAP* AnimatedSprite::GetImage() {
    return static_cast<const AnimatedSprite&>(*this).GetImage();
}

ALLEGRO_BITMAP* AnimatedSprite::GetSheet() const {
    return Sprite::GetSheet();
}
ALLEGRO_BITMAP* AnimatedSprite::GetSheet() {
    return static_cast<const AnimatedSprite&>(*this).GetSheet();
}

void AnimatedSprite::Animate(const std::string& name, AnimationHandler::DIRECTION dir, double deltaTime) {

    _accumulator += deltaTime;
    if(_accumulator < _frameRate) return;
    
    typedef  void (AnimationHandler::*func_ptr)(const std::string& name, bool rewind);
    #define CALL_MEMBER_FUNCTION(object, ptrToMember)  ((object).*(ptrToMember)) 

    func_ptr play = &AnimationHandler::Play;
    func_ptr reverse = &AnimationHandler::Reverse;

    while(_accumulator >= _frameRate) {

        //Defaults to DIR_FORWARD_LOOPING
        func_ptr func = play;
        bool rewindOnCompletion = true;

        if(dir == AnimationHandler::DIR_FORWARD_NONLOOPING) {
            rewindOnCompletion = false;
        } else if(dir == AnimationHandler::DIR_REVERSE_LOOPING || dir == AnimationHandler::DIR_REVERSE_NONLOOPING) {
            func = reverse;
            if(dir == AnimationHandler::DIR_REVERSE_NONLOOPING) {
                rewindOnCompletion = false;
            }
        } else {
            /* default case handled */
        }

        CALL_MEMBER_FUNCTION(*_animation, func)(name, rewindOnCompletion);
        if(_frameRate == 0.0) {
            _accumulator = 0.0;
            break;
        }
        _accumulator -= _frameRate;
    }
}

void AnimatedSprite::SetFrameRate(double deltaTime) {
    if(deltaTime <= 0.001) deltaTime = 0.0;
    _frameRate = deltaTime;
}

double AnimatedSprite::GetFrameRate() const {
    return _frameRate;
}

double AnimatedSprite::GetFrameRate() {
    return static_cast<const AnimatedSprite&>(*this).GetFrameRate();
}

AnimationHandler* AnimatedSprite::GetAnimationHandler() const {
    return _animation;
}

AnimationHandler* AnimatedSprite::GetAnimationHandler() {
    return static_cast<const AnimatedSprite&>(*this).GetAnimationHandler();
}

void AnimatedSprite::ResizeFrame(unsigned int width, unsigned int height) {

    //Frame Image hasn't been created yet, create and re-call method.
    if(_frameImage == nullptr) {
        this->_frameDimensions = Vector2D(width, height);
        CalcCenterFrame();
        _frameImage = al_create_bitmap(width, height);
        ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
        al_set_target_bitmap(_frameImage);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_set_target_bitmap(old_target);
        ResizeFrame(width, height);
        return;
    }

    double fdX = this->_frameDimensions.GetX();
    double fdY = this->_frameDimensions.GetY();
    if(static_cast<unsigned int>(fdX) == width && static_cast<unsigned int>(fdY) == height) return;

    this->_frameDimensions = Vector2D(width, height);
    CalcCenterFrame();
    al_destroy_bitmap(this->_frameImage);
    this->_frameImage = al_create_bitmap(width, height);
    ALLEGRO_BITMAP* old_target = al_get_target_bitmap();
    al_set_target_bitmap(_frameImage);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_target_bitmap(old_target);

}

int AnimatedSprite::GetWidth() const {
    return _frameDimensions.GetX();
}

int AnimatedSprite::GetWidth() {
    return static_cast<const AnimatedSprite&>(*this).GetWidth();
}

int AnimatedSprite::GetHeight() const {
    return _frameDimensions.GetY();
}

int AnimatedSprite::GetHeight() {
    return static_cast<const AnimatedSprite&>(*this).GetHeight();
}

A2DE_END