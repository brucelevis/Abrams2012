/**************************************************************************************************
// file:	Engine\Objects\ADTObject.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the adt object class
 **************************************************************************************************/
#include "ADTObject.h"

A2DE_BEGIN

Object::Object() { /* DO NOTHING */ }
Object::Object(const Object& /*other*/) { /* DO NOTHING */ }
Object& Object::operator=(const Object& /*rhs*/) { return *this; }


void Object::Update(double /*deltaTime*/) { /* DO NOTHING */ }

void Object::Draw(ALLEGRO_BITMAP* /*dest*/) { /* DO NOTHING */ }

Object::~Object() { /* DO NOTHING */ }


void Object::SetBody(const a2de::RigidBodyDef& /*body*/) { /* DO NOTHING */ }
const a2de::RigidBody* Object::GetBody() const { return nullptr; }
a2de::RigidBody* Object::GetBody() { return const_cast<a2de::RigidBody*>(static_cast<const Object&>(*this).GetBody()); }


A2DE_END