/**************************************************************************************************
// file:	Engine\Physics\CCamera.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the camera class
 **************************************************************************************************/
#include "CCamera.h"

#include <allegro5/display.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/bitmap_draw.h>

#include "../a2de_math.h"
#include "../a2de_graphics.h"
#include "CWorld.h"

A2DE_BEGIN

Camera::Camera(const Vector2D& position, const Vector2D& half_extents)
    : _parent(nullptr), _world_area(position, half_extents) { }

Camera::Camera(const World& parent, const Vector2D& position, const Vector2D& half_extents)
            : _parent(&parent), _world_area(position, half_extents) { }

Camera::Camera(const Camera& other)
            : _parent(other._parent), _world_area(other._world_area) { }

Camera::~Camera() {
    _parent = nullptr;
}

Camera& Camera::operator=(const Camera& rhs) {
    if(this == &rhs) return *this;

    this->_parent = rhs._parent;
    this->_world_area = rhs._world_area;
    this->_screen_position = rhs._screen_position;

    return *this;
}

const Vector2D& Camera::GetPosition() const {
    return _world_area.GetPosition();
}

Vector2D& Camera::GetPosition() {
    return const_cast<Vector2D&>(static_cast<const Camera&>(*this).GetPosition());
}

void Camera::SetPosition(const Vector2D& position) {
    double x = position.GetX();
    double y = position.GetY();
    double hew = _world_area.GetHalfWidth();
    double heh = _world_area.GetHalfHeight();
    double min_x = hew;
    double min_y = heh;

    if(x < min_x) x = min_x;
    if(y < min_y) y = min_y;

    double p_width = _parent->GetWidth();
    double p_height = _parent->GetHeight();
    double max_x = p_width - hew;
    double max_y = p_height - heh;
    if(x > max_x) x = max_x;
    if(y > max_y) y = max_y;

    _world_area.SetPosition(x, y);
}

const Vector2D& Camera::GetHalfExtents() const {
    return _world_area.GetHalfExtents();
}

Vector2D& Camera::GetHalfExtents() {
    return const_cast<Vector2D&>(static_cast<const Camera&>(*this).GetHalfExtents());
}

double Camera::GetX() const {
    return _world_area.GetX();
}

double Camera::GetX() {
    return static_cast<const Camera&>(*this).GetX();
}

double Camera::GetY() const {
    return _world_area.GetY();
}

double Camera::GetY() {
    return static_cast<const Camera&>(*this).GetY();
}

void Camera::SetX(double x) {
    SetPosition(Vector2D(x, GetY()));
}

void Camera::SetY(double y) {
    SetPosition(Vector2D(GetX(), y));
}

const World* const Camera::GetParent() const {
    return _parent;
}

const World* Camera::GetParent() {
    return static_cast<const Camera&>(*this).GetParent();
}

void Camera::SetParent(const World& parent) {
    _parent = &parent;
}

a2de::Vector2D Camera::CameraToWorldPosition(const Camera& cam, const Vector2D& screen_position) {
    Vector2D world_pos(cam.GetPosition());
    world_pos += a2de::Vector2D(a2de::Math::ToWorldScale(screen_position.GetX()), a2de::Math::ToWorldScale(screen_position.GetY()));
    world_pos = a2de::Vector2D(world_pos.GetX(), world_pos.GetY());
    return world_pos;
}

a2de::Vector2D Camera::WorldToCameraPosition(const Camera& cam, const Vector2D& world_position) {
    Vector2D screen_pos(a2de::Math::ToScreenScale(world_position.GetX()), a2de::Math::ToScreenScale(world_position.GetY()));
    screen_pos -= a2de::Vector2D(a2de::Math::ToScreenScale(cam.GetPosition().GetX()), a2de::Math::ToScreenScale(cam.GetPosition().GetY()));
    screen_pos = a2de::Vector2D(screen_pos.GetX(), screen_pos.GetY());
    return screen_pos;
}

void Camera::SetScreenPosition(const Vector2D& screen_position) {
    _screen_position = screen_position;
}

void Camera::SetScreenPosition(double x, double y) {
    SetScreenPosition(Vector2D(x, y));
}

void Camera::SetScreenXPosition(double x) {
    SetScreenPosition(x, _screen_position.GetY());
}

void Camera::SetScreenYPosition(double y) {
    SetScreenPosition(_screen_position.GetX(), y);
}

const Vector2D& Camera::GetScreenPosition() const {
    return _screen_position;
}

Vector2D& Camera::GetScreenPosition() {
    return const_cast<Vector2D&>(static_cast<const Camera&>(*this).GetScreenPosition());
}

const a2de::Rectangle& Camera::GetArea() const {
    return _world_area;
}

A2DE_END