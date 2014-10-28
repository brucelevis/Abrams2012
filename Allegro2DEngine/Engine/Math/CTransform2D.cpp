#include "CTransform2D.h"

#include "CVector2D.h"
#include "CVector3D.h"

A2DE_BEGIN


Transform2D::Transform2D() : 
_position(),
_scale(1.0, 1.0),
_rotation(),
_curChildIndex(0),
_parent(nullptr),
_children()
{
    /* DO NOTHING */
}

Transform2D::Transform2D(Transform2D* parent) : 
_position(),
_scale(1.0, 1.0),
_rotation(),
_curChildIndex(0),
_parent(parent),
_children()
{
    /* DO NOTHING */
}

Transform2D::Transform2D(const Transform2D& other) :
_position(other._position),
_scale(other._scale),
_rotation(other._rotation),
_curChildIndex(other._curChildIndex),
_parent(other._parent),
_children(other._children)
{
    /* DO NOTHING */
}

Transform2D& Transform2D::operator=(const Transform2D& rhs) {
    if(this == &rhs) return *this;

    this->_position = rhs._position;
    this->_scale = rhs._scale;
    this->_rotation = rhs._rotation;
    this->_curChildIndex = rhs._curChildIndex;
    this->_parent = rhs._parent;
    this->_children = rhs._children;

    return *this;
}

Transform2D::~Transform2D() {
    _children.clear();
    _parent = nullptr;
}

void Transform2D::SetParent(Transform2D* parent) {
    _parent = parent;
}

void Transform2D::AddChild(Transform2D* child) {
    if(child == nullptr) return;
    _children.push_back(child);
}

void Transform2D::RemoveChild(Transform2D* child) {
    if(child == nullptr) return;
    if(_children.empty()) return;
    _children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
}

Transform2D* Transform2D::FirstChild() {
    if(_children.empty()) return nullptr;
    _curChildIndex = 0;
    return *(_children.begin());
}

Transform2D* Transform2D::LastChild() {
    if(_children.empty()) return nullptr;
    _curChildIndex = _children.size();
    return *(_children.end());
}

Transform2D* Transform2D::NextChild() {
    if(_children.empty()) return nullptr;
    std::size_t s(_children.size());
    if(_curChildIndex >= s) {
        _curChildIndex = s;
        return nullptr;
    }
    return _children[_curChildIndex++];
}

Transform2D* Transform2D::PreviousChild() {
    if(_children.empty()) return nullptr;
    if(_curChildIndex == 0) {
        return nullptr;
    }
    return _children[_curChildIndex--];
}

Transform2D* Transform2D::GetChild(std::size_t index) {
    if(_children.empty()) return nullptr;
    if(index >= _children.size()) return nullptr;
    return _children[index];
}

std::vector<Transform2D*>::size_type Transform2D::GetChildCount() const {
    return _children.size();
}

std::vector<Transform2D*>::size_type Transform2D::GetChildCount() {
    return static_cast<const Transform2D&>(*this).GetChildCount();
}

void Transform2D::SetPosition(const a2de::Vector2D& position) {
    _position = position;
}

const a2de::Vector2D& Transform2D::GetPosition() const {
    return _position;
}

a2de::Vector2D& Transform2D::GetPosition() {
    return const_cast<a2de::Vector2D&>(static_cast<const Transform2D&>(*this).GetPosition());
}

void Transform2D::SetRotation(double rotation) {
    _rotation = rotation;
}

double Transform2D::GetRotation() const {
    return _rotation;
}

double Transform2D::GetRotation() {
    return static_cast<const Transform2D&>(*this).GetRotation();
}

void Transform2D::SetScale(const a2de::Vector2D& scale) {
    _scale = scale;
}

const a2de::Vector2D& Transform2D::GetScale() const {
    return _scale;
}

a2de::Vector2D& Transform2D::GetScale() {
    return const_cast<a2de::Vector2D&>(static_cast<const Transform2D&>(*this).GetPosition());
}

a2de::Matrix3x3 Transform2D::GetLocalTransform() const {
    Matrix3x3 p((_parent ? _parent->GetLocalTransform() : a2de::Matrix3x3::GetIdentity()));
    Matrix3x3 t(a2de::Matrix3x3::GetTranslationMatrix(_position));
    Matrix3x3 r(a2de::Matrix3x3::GetRotationMatrix(_rotation));
    Matrix3x3 s(a2de::Matrix3x3::GetScaleMatrix(_scale));

    return (p * t * r * s);
}

a2de::Matrix3x3 Transform2D::GetLocalTransform() {
    return static_cast<const Transform2D&>(*this).GetLocalTransform();
}

a2de::Matrix3x3 Transform2D::RotateAround(const a2de::Vector2D& point) {

    Matrix3x3 p((_parent ? _parent->GetLocalTransform() : a2de::Matrix3x3::GetIdentity()));
    Matrix3x3 t(a2de::Matrix3x3::GetTranslationMatrix(point));
    Matrix3x3 t_inv(a2de::Matrix3x3::GetTranslationMatrix(-point));
    Matrix3x3 r(a2de::Matrix3x3::GetRotationMatrix(_rotation));
    Matrix3x3 s(a2de::Matrix3x3::GetScaleMatrix(_scale));

    return p * t * r * s * t_inv;
}


A2DE_END