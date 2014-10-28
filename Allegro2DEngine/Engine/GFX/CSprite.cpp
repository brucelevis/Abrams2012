/**************************************************************************************************
// file:	Engine\GFX\CSprite.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the sprite class
 **************************************************************************************************/
#include "CSprite.h"

#include "../Math/MathConstants.h"
#include "../Math/CPoint.h"
#include "../Math/CRectangle.h"
#include "../Math/CMiscMath.h"
#include "../a2de_exceptions.h"
#include <fstream>
#include <string>
#include <allegro5/bitmap.h>
#include <allegro5/fshook.h>

#include "CBitmapCache.h"

A2DE_BEGIN

    Sprite* Sprite::CreateSprite(const std::string& name, ALLEGRO_BITMAP* file) {
        if(name.empty()) {
            throw Exception("Unnamed sprites not allowed.");
        }
        if(file == nullptr) {
            throw Exception("ALLEGRO_BITMAP pointer must point to valid ALLEGRO_BITMAP.");
        }
        return (new Sprite(name, file));
}

Sprite* Sprite::CreateSprite(const std::string& file) {
    if(file.empty() == false) {
        if(al_filename_exists(file.c_str()) == false) {
            throw FileNotFoundException(file);
        }
    } else {
        throw Exception("Use CreateSprite(std::string name, ALLEGRO_BITMAP* file) named constructor for creating Sprites from existing ALLEGRO_BITMAPs");
    }
    return (new Sprite(file));
}

Sprite* Sprite::CreateSprite(const Sprite& sprite) {
    return (new Sprite(sprite));
}

Sprite* Sprite::Clone() const {
    return CreateSprite(*this);
}

Sprite::Sprite(const std::string& name, ALLEGRO_BITMAP* file) throw(...)
    : _file(name),
    _dimensions(0.0, 0.0),
    _image(nullptr),
    _position(0.0, 0.0),
    _frameDimensions(_dimensions),
    _center(0.0, 0.0),
    _scaleDimensions(1.0, 1.0),
    _angle(0.0),
    _radius(0),
    _tint(al_map_rgba(255, 255, 255, 255)),
    _axis(a2de::SpriteHandler::AXIS_NONE) {
        BitmapCache::StoreBitmap(const_cast<std::string&>(name), file);
        _image = BitmapCache::RetrieveBitmap(const_cast<std::string&>(name));
        if(_image != nullptr) {
            _dimensions = Vector2D(al_get_bitmap_width(_image), al_get_bitmap_height(_image));
            _frameDimensions = _dimensions;
            _center = Vector2D(_dimensions.GetX() / 2, _dimensions.GetY() / 2);
        } else {
            throw BitmapCreationFailureException(name);
        }
}

Sprite::Sprite(const std::string& file)
    : _file(file),
    _dimensions(0.0, 0.0),
    _image(BitmapCache::GetBitmap(const_cast<std::string&>(file))),
    _position(0.0, 0.0),
    _frameDimensions(_dimensions),
    _center(0.0, 0.0),
    _scaleDimensions(1.0, 1.0),
    _angle(0.0),
    _radius(0),
    _tint(al_map_rgba(255, 255, 255, 255)),
    _axis(a2de::SpriteHandler::AXIS_NONE) {
        if(_image != nullptr) {
            _dimensions = Vector2D(al_get_bitmap_width(_image), al_get_bitmap_height(_image));
            _frameDimensions = _dimensions;
            _center = Vector2D(_dimensions.GetX() / 2, _dimensions.GetY() / 2);
        } else {
            throw BitmapLoadFailureException(file);
        }
}
Sprite::Sprite(const Sprite& sprite)
    : _file(sprite._file),
    _dimensions(sprite._dimensions),
    _image(BitmapCache::RetrieveBitmap(const_cast<std::string&>(sprite._file))),
    _position(sprite._position),
    _frameDimensions(sprite._dimensions),
    _center(sprite._center),
    _scaleDimensions(sprite._scaleDimensions),
    _angle(sprite._angle),
    _radius(sprite._radius),
    _tint(sprite._tint),
    _axis(sprite._axis) {
        if(_image != nullptr) {
            _dimensions = Vector2D(al_get_bitmap_width(_image), al_get_bitmap_height(_image));
            _frameDimensions = _dimensions;
            _center = Vector2D(_dimensions.GetX() / 2, _dimensions.GetY() / 2);
        }
}

Sprite::~Sprite() {
    if(_image) {
        BitmapCache::RemoveBitmap(_file);
        _image = nullptr;
    }
}

const std::string& Sprite::GetFilename() const {
    return _file;
}

std::string& Sprite::GetFilename() {
    return const_cast<std::string&>(static_cast<const Sprite&>(*this).GetFilename());
}

ALLEGRO_BITMAP* Sprite::GetImage() const {
    return _image;
}

ALLEGRO_BITMAP* Sprite::GetImage() {
    return static_cast<const Sprite&>(*this).GetImage();
}

double Sprite::GetX() const {
    return _position.GetX();
}
double Sprite::GetX() {
    return static_cast<const Sprite&>(*this).GetX();
}

double Sprite::GetY() const {
    return _position.GetY();
}
double Sprite::GetY() {
    return static_cast<const Sprite&>(*this).GetY();
}

Vector2D Sprite::GetPosition() const {
    return _position;
}
Vector2D Sprite::GetPosition() {
    return static_cast<const Sprite&>(*this).GetPosition();
}

int Sprite::GetWidth() const {
    return _dimensions.GetX();
}
int Sprite::GetWidth() {
    return static_cast<const Sprite&>(*this).GetWidth();
}

int Sprite::GetHeight() const {
    return _dimensions.GetY();
}
int Sprite::GetHeight() {
    return static_cast<const Sprite&>(*this).GetHeight();
}

void Sprite::SetTint(const ALLEGRO_COLOR& tint) {
    _tint = tint;
}
const ALLEGRO_COLOR& Sprite::GetTint() const {
    return _tint;
}
ALLEGRO_COLOR& Sprite::GetTint() {
    return const_cast<ALLEGRO_COLOR&>(static_cast<const Sprite&>(*this).GetTint());
}

int Sprite::GetCenterX() const {
    return _center.GetX();
}
int Sprite::GetCenterX() {
    return static_cast<const Sprite&>(*this).GetCenterX();
}

int Sprite::GetCenterY() const {
    return _center.GetY();
}
int Sprite::GetCenterY() {
    return static_cast<const Sprite&>(*this).GetCenterY();
}

double Sprite::GetAngle() const {
    return _angle;
}
double Sprite::GetAngle() {
    return static_cast<const Sprite&>(*this).GetAngle();
}

double Sprite::GetRotationRadius() const {
    return _radius;
}
double Sprite::GetRotationRadius() {
    return static_cast<const Sprite&>(*this).GetRotationRadius();
}

double Sprite::GetScaleX() const {
    return _scaleDimensions.GetX();
}
double Sprite::GetScaleX() {
    return static_cast<const Sprite&>(*this).GetScaleX();
}

double Sprite::GetScaleY() const {
    return _scaleDimensions.GetY();
}
double Sprite::GetScaleY() {
    return static_cast<const Sprite&>(*this).GetScaleY();
}

void Sprite::SetX(double x) {
    SetPosition(x, _position.GetY());
}
void Sprite::SetY(double y) {
    SetPosition(_position.GetX(), y);
}

unsigned char Sprite::GetAlpha() const {
    return _tint.a;
}
unsigned char Sprite::GetAlpha() {
    return static_cast<const Sprite&>(*this).GetAlpha();
}

void Sprite::SetAlpha(unsigned char alpha) {
    _tint.a = alpha;
}

void Sprite::SetPosition(double x, double y) {
    SetPosition(Vector2D(x, y));
}
void Sprite::SetPosition(const Vector2D& position) {
    _position = position;
}

void Sprite::SetAngle(double angle) {
    _angle = -angle;
}

void Sprite::SetRotationRadius(double radius) {
    _radius = radius;
}

void Sprite::SetCenterX(int x) {
    SetCenter(Vector2D(x, _center.GetY()));
}
void Sprite::SetCenterY(int y) {
    SetCenter(Vector2D(_center.GetX(), y));
}

void a2de::Sprite::SetCenter(const Vector2D& center) {
    int x = center.GetX();
    int y = center.GetY();
    if(x < 0) x = 0;
    if(x > _frameDimensions.GetX() * _scaleDimensions.GetX()) x = _frameDimensions.GetX() * _scaleDimensions.GetX();
    if(y < 0) y = 0;
    if(y > _frameDimensions.GetY() * _scaleDimensions.GetY()) y = _frameDimensions.GetY() * _scaleDimensions.GetY();
    _center = Vector2D(x, y);
}

void Sprite::SetScaleX(double x) {
    SetScale(Vector2D(x, _scaleDimensions.GetY()));
}
void Sprite::SetScaleY(double y) {
    SetScale(Vector2D(_scaleDimensions.GetX(), y));
}

void a2de::Sprite::SetScale(const Vector2D& scale) {
    double x = scale.GetX();
    double y = scale.GetY();
    if(x < 0.0) x = 0.0;
    if(y < 0.0) y = 0.0;
    _scaleDimensions = Vector2D(x, y);
    CalcCenterFrame();
}


void Sprite::CalcCenterFrame() {
    double x = (_frameDimensions.GetX() * _scaleDimensions.GetX()) / 2;
    double y = (_frameDimensions.GetY() * _scaleDimensions.GetY()) / 2;
    _center = Vector2D(x, y);
}

Sprite& Sprite::operator=(const Sprite& rhs) {
    if(this == &rhs) return *this;
    this->_file = rhs._file;

    this->_dimensions = rhs._dimensions;
    this->_image = BitmapCache::GetBitmap(const_cast<std::string&>(rhs._file));
    this->_dimensions = Vector2D(al_get_bitmap_width(this->_image), al_get_bitmap_height(this->_image));

    this->_position = rhs._position;
    this->_frameDimensions = rhs._frameDimensions;
    this->_scaleDimensions = rhs._scaleDimensions;
    CalcCenterFrame();
    this->_center = rhs._center;
    this->_angle = rhs._angle;
    this->_radius = rhs._radius;
    this->_tint = rhs._tint;
    this->_axis = rhs._axis;
    return *this;
}

void Sprite::SetFlipAxis(SpriteHandler::SPRITEAXIS axis) {
    _axis = axis;
}

SpriteHandler::SPRITEAXIS Sprite::GetFlipAxis() const {
    return _axis;
}

SpriteHandler::SPRITEAXIS Sprite::GetFlipAxis() {
    return static_cast<const Sprite&>(*this).GetFlipAxis();
}

void Sprite::Draw(ALLEGRO_BITMAP* dest) {
    bool hasRadius = a2de::Math::IsEqual(this->GetRotationRadius(), 0.0) == false;
    bool hasRotation = a2de::Math::IsEqual(this->GetAngle(), 0.0) == false;
    bool isFlipped = this->GetFlipAxis() != a2de::SpriteHandler::AXIS_NONE;
    bool isScaled = (a2de::Math::IsEqual(this->GetScaleX(), 1.0) || a2de::Math::IsEqual(this->GetScaleY(), 1.0)) == false;

    if(hasRadius) {
        if(isScaled && isFlipped) {
            a2de::SpriteHandler::DrawRotateWorldSpaceScaleFlip(dest, this, this->GetX(), this->GetY(), this->GetRotationRadius(), this->GetFlipAxis());
        } else if(isScaled) {
            a2de::SpriteHandler::DrawRotateWorldSpaceScale(dest, this, this->GetX(), this->GetY(), this->GetRotationRadius());
        } else if(isFlipped) {
            a2de::SpriteHandler::DrawRotateWorldSpaceFlip(dest, this, this->GetX(), this->GetY(), this->GetRotationRadius(), this->GetFlipAxis());
        } else {
            a2de::SpriteHandler::DrawRotateWorldSpace(dest, this, this->GetX(), this->GetY(), this->GetRotationRadius());
        }
    } else if(hasRotation) {
        if(isScaled && isFlipped) {
            a2de::SpriteHandler::DrawRotateScaleFlip(dest, this, this->GetFlipAxis());
        } else if(isFlipped) {
            a2de::SpriteHandler::DrawRotateFlip(dest, this, this->GetFlipAxis());
        } else if(isScaled) {
            a2de::SpriteHandler::DrawRotateScale(dest, this);
        } else {        
            a2de::SpriteHandler::DrawRotate(dest, this);
        }
    } else if(isScaled) {
        a2de::SpriteHandler::DrawScale(dest, this);
    } else if(isFlipped) {
        a2de::SpriteHandler::DrawFlip(dest, this, this->GetFlipAxis());
    } else {
        a2de::SpriteHandler::Draw(dest, this);
    }
}

/*****************************
*  ANIMATED SPRITE OVERRIDES *
*****************************/

void Sprite::SetCurFrame(int /*frame*/) {
    return;
}

void Sprite::Animate(std::string /*name*/, AnimationHandler::DIRECTION /*dir*/, double /*deltaTime*/) {
    return;
}

void Sprite::SetFrameRate(double /*deltaTime*/) {
    return;
}

double Sprite::GetFrameRate() const {
    return -1.0;
}

double Sprite::GetFrameRate() {
    return static_cast<const Sprite&>(*this).GetFrameRate();
}

AnimationHandler* Sprite::GetAnimationHandler() const {
    return nullptr;
}

AnimationHandler* Sprite::GetAnimationHandler() {
    return static_cast<const Sprite&>(*this).GetAnimationHandler();
}

ALLEGRO_BITMAP* Sprite::GetSheet() const {
    return Sprite::GetImage();
}
ALLEGRO_BITMAP* Sprite::GetSheet() {
    return static_cast<const Sprite&>(*this).GetSheet();
}

void Sprite::ResizeFrame(unsigned int /*width*/, unsigned int /*height*/) {
    /* DO NOTHING */
}


A2DE_END