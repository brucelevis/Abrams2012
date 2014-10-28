#include "CTransform.h"

#include "CVector2D.h"
#include "CVector4D.h"

A2DE_BEGIN


Transform::Transform() : 
_position(),
_scale(1.0, 1.0),
_rotation(),
_curChildIndex(0),
_parent(nullptr),
_children()
{
    /* DO NOTHING */
}

Transform::Transform(Transform* parent) : 
_position(),
_scale(1.0, 1.0),
_rotation(),
_curChildIndex(0),
_parent(parent),
_children()
{
    /* DO NOTHING */
}

Transform::Transform(const Transform& other) :
_position(other._position),
_scale(other._scale),
_rotation(other._rotation),
_curChildIndex(0),
_parent(other._parent),
_children(other._children)
{
    /* DO NOTHING */
}

Transform& Transform::operator=(const Transform& rhs) {
    if(this == &rhs) return *this;

    this->_position = rhs._position;
    this->_scale = rhs._scale;
    this->_rotation = rhs._rotation;
    this->_curChildIndex = 0;
    this->_parent = rhs._parent;
    this->_children = rhs._children;

    return *this;
}

Transform::~Transform() {
    _children.clear();
    _parent = nullptr;
}

void Transform::SetParent(Transform* parent) {
    _parent = parent;
}

void Transform::AddChild(Transform* child) {
    if(child == nullptr) return;
    _children.push_back(child);
}

void Transform::RemoveChild(Transform* child) {
    if(child == nullptr) return;
    if(_children.empty()) return;
    _children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
}

Transform* Transform::FirstChild() {
    if(_children.empty()) return nullptr;
    _curChildIndex = 0;
    return *(_children.begin());
}

Transform* Transform::LastChild() {
    if(_children.empty()) return nullptr;
    _curChildIndex = _children.size();
    return *(_children.end());
}

Transform* Transform::NextChild() {
    if(_children.empty()) return nullptr;
    std::size_t s(_children.size());
    if(_curChildIndex >= s) {
        _curChildIndex = s;
        return nullptr;
    }
    return _children[_curChildIndex++];
}

Transform* Transform::PreviousChild() {
    if(_children.empty()) return nullptr;
    if(_curChildIndex == 0) {
        return nullptr;
    }
    return _children[_curChildIndex--];
}

Transform* Transform::GetChild(std::size_t index) {
    if(_children.empty()) return nullptr;
    if(index >= _children.size()) return nullptr;
    return _children[index];
}

std::size_t Transform::GetChildCount() const {
    if(_children.empty()) return 0;
    return _children.size();
}

std::size_t Transform::GetChildCount() {
    return static_cast<const Transform&>(*this).GetChildCount();
}

void Transform::SetPosition(const a2de::Vector3D& position) {
    _position = position;
}

const a2de::Vector3D& Transform::GetPosition() const {
    return _position;
}

a2de::Vector3D& Transform::GetPosition() {
    return const_cast<a2de::Vector3D&>(static_cast<const Transform&>(*this).GetPosition());
}

void Transform::SetRotation(const a2de::Vector3D& rotation) {
    double x = rotation.GetX();
    double y = rotation.GetY();
    double z = rotation.GetZ();
    double p2 = a2de::Math::A2DE_2PI;
    a2de::Vector3D rotation_clamped = a2de::Vector3D(a2de::Math::IsEqual(x, 0.0) ? 0.0 : std::fmod(x, p2), a2de::Math::IsEqual(y, 0.0) ? 0.0 : std::fmod(y, p2), a2de::Math::IsEqual(z, 0.0) ? 0.0 : std::fmod(z, p2));
    _rotation = rotation_clamped;
}

const a2de::Vector3D& Transform::GetRotation() const {
    return _rotation;
}

a2de::Vector3D& Transform::GetRotation() {
    return const_cast<a2de::Vector3D&>(static_cast<const Transform&>(*this).GetRotation());
}

void Transform::SetScale(const a2de::Vector3D& scale) {
    _scale = scale;
}

const a2de::Vector3D& Transform::GetScale() const {
    return _scale;
}

a2de::Vector3D& Transform::GetScale() {
    return const_cast<a2de::Vector3D&>(static_cast<const Transform&>(*this).GetScale());
}

a2de::Matrix4x4 Transform::GetLocalTransform() const {
    Matrix4x4 p((_parent ? _parent->GetLocalTransform() : a2de::Matrix4x4::GetIdentity()));
    Matrix4x4 t(a2de::Matrix4x4::GetTranslationMatrix(_position));
    Matrix4x4 r(a2de::Matrix4x4::GetRotationMatrix(_rotation));
    Matrix4x4 s(a2de::Matrix4x4::GetScaleMatrix(_scale));

    return (p * t * r * s);
}

a2de::Matrix4x4 Transform::GetLocalTransform() {
    return static_cast<const Transform&>(*this).GetLocalTransform();
}


A2DE_END