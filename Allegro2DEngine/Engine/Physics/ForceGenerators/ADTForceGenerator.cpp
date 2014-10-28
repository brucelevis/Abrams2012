/**************************************************************************************************
// file:	Engine\Physics\ForceGenerators\ADTForceGenerator.cpp
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Implements the adt force generator class
 **************************************************************************************************/
#include "ADTForceGenerator.h"

#include "../../Objects/ADTObject.h"
#include <algorithm>

A2DE_BEGIN


    ADTForceGenerator::ADTForceGenerator() : _subscribers() { /* DO NOTHING */ }

ADTForceGenerator::ADTForceGenerator(const ADTForceGenerator& other) : _subscribers(other._subscribers) { /* DO NOTHING */ }

ADTForceGenerator& ADTForceGenerator::operator=(const ADTForceGenerator& rhs) {
    if(this == &rhs) return *this;

    this->_subscribers = rhs._subscribers;

    return *this;
}

ADTForceGenerator::~ADTForceGenerator() {
    _subscribers.erase(_subscribers.begin(), _subscribers.end());
}

bool ADTForceGenerator::RegisterBody(Object* body) {
    if(body == nullptr) return false;
    a2de::RigidBody* b = body->GetBody();
    if(b == nullptr) return false;

    std::list<Object*>::iterator _iter = std::find(_subscribers.begin(), _subscribers.end(), body);
    if(_iter != _subscribers.end()) return false;
    _subscribers.push_back(body);

    b->ClearForces();
    b->ClearImpulses();

    return true;
}


void ADTForceGenerator::UnregisterBody(Object* body) {
    if(body == nullptr) return;
    a2de::RigidBody* b = body->GetBody();
    if(b == nullptr) return;

    std::list<Object*>::iterator _iter = std::find(_subscribers.begin(), _subscribers.end(), body);
    if(_iter == _subscribers.end()) return;
    _subscribers.erase(_iter);

    b->ClearForces();
    b->ClearImpulses();

}

A2DE_END
