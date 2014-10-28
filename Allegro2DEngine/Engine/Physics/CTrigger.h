/**************************************************************************************************
// file:	Engine\Physics\CTrigger.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the trigger class
 **************************************************************************************************/
#ifndef A2DE_CTRIGGER_H
#define A2DE_CTRIGGER_H

#include "../a2de_vals.h"
#include "../Math/CRectangle.h"
#include "../Math/CVector2D.h"

#include "../Objects/ADTObject.h"
#include "CRigidBody.h"
#include "IUpdatable.h"

#include <list>
#include <algorithm>
#include <iterator>

A2DE_BEGIN

template<class T>
class Trigger : public Object {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    Trigger();

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Trigger(const Trigger& other);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    virtual ~Trigger()=0;

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Trigger<T>& operator=(const Trigger<T>& rhs);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPosition(const a2de::Vector2D& position);

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetPosition(double x, double y);

    /**************************************************************************************************
     * <summary>Sets the x coordinate.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="x">The x coordinate.</param>
     **************************************************************************************************/
    void SetX(double x);

    /**************************************************************************************************
     * <summary>Sets the y coordinate.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="y">The y coordinate.</param>
     **************************************************************************************************/
    void SetY(double y);

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    a2de::Vector2D GetPosition() const;

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    Vector2D GetPosition();

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX() const;

    /**************************************************************************************************
     * <summary>Get x coordinate.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The x coordinate.</returns>
     **************************************************************************************************/
    double GetX();

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY() const;

    /**************************************************************************************************
     * <summary>Get y coordinate.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The y coordinate.</returns>
     **************************************************************************************************/
    double GetY();

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="dimensions">The dimensions.</param>
     **************************************************************************************************/
    void SetDimensions(const a2de::Vector2D& dimensions);

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    void SetDimensions(double width, double height);

    /**************************************************************************************************
     * <summary>Gets the dimensions.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The dimensions.</returns>
     **************************************************************************************************/
    const Vector2D& GetDimensions() const;

    /**************************************************************************************************
     * <summary>Gets the dimensions.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The dimensions.</returns>
     **************************************************************************************************/
    a2de::Vector2D& GetDimensions();

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The width.</returns>
     **************************************************************************************************/
    double GetWidth() const;

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The width.</returns>
     **************************************************************************************************/
    double GetWidth();

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The height.</returns>
     **************************************************************************************************/
    double GetHeight() const;

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>The height.</returns>
     **************************************************************************************************/
    double GetHeight();

    /**************************************************************************************************
     * <summary>Updates the trigger and all objects.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Executes the enter action.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="entered_object">The entered object.</param>
     **************************************************************************************************/
    virtual void OnEnter(T entered_object)=0;

    /**************************************************************************************************
     * <summary>Executes the exit action.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="exited_object">The exited object.</param>
     **************************************************************************************************/
    virtual void OnExit(T exited_object)=0;

    /**************************************************************************************************
     * <summary>Executes the tick action.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="object">The object.</param>
     **************************************************************************************************/
    virtual void OnTick(T object)=0;

    /**************************************************************************************************
     * <summary>Registers the object described by object.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="object">The object.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RegisterObject(T object);

    /**************************************************************************************************
     * <summary>Unregisters the object described by object.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="object">The object.</param>
     **************************************************************************************************/
    void UnregisterObject(T object);

    /**************************************************************************************************
     * <summary>Gets the body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the body.</returns>
     **************************************************************************************************/
    const a2de::RigidBody* GetBody() const;

    /**************************************************************************************************
     * <summary>Gets the body.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>null if it fails, else the body.</returns>
     **************************************************************************************************/
    a2de::RigidBody* GetBody();

protected:
    /// <summary> The area </summary>
    a2de::RigidBody* _area;
    /// <summary> The previous objects </summary>
    std::list<T> _previous_objects;
    /// <summary> The current objects </summary>
    std::list<T> _current_objects;
    /// <summary> The temp objects </summary>
    std::list<T> _temp_objects;
private:

};

template<class T>
Trigger<T>::Trigger() : _area(nullptr), _previous_objects(), _current_objects(), _temp_objects() {
    _area = new a2de::RigidBody(0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    _area->SetBoundingRectangle(new a2de::AABB(a2de::Transform2D(), a2de::Vector2D(), al_map_rgb(255, 255, 0)));
}

template<class T>
Trigger<T>::Trigger(const Trigger& other) : _area(nullptr), _previous_objects(other._previous_objects), _current_objects(other._current_objects), _temp_objects(other._temp_objects)  {
    
    this->_area = new a2de::RigidBody(other.GetBody()->GetMass(), other.GetBody()->GetGravityModifier(), a2de::PhysicsMaterial(other.GetBody()->GetRestitution(), other.GetBody()->GetStaticFriction(), other.GetBody()->GetKineticFriction()));
    this->_area->SetPosition(other.GetPosition());
    this->_area->SetBoundingRectangle(new AABB(other.GetPosition(), other.GetDimensions(), a2de::Color::YELLOW()));


}

template<class T>
Trigger<T>::~Trigger() {
    delete _area;
    _previous_objects.clear();
    _current_objects.clear();
    _temp_objects.clear();
}

template<class T>
Trigger<T>& Trigger<T>::operator=(const Trigger<T>& rhs) {
    if(this == &rhs) return *this;

    delete _area;
    _area = nullptr;
    this->_area = new a2de::RigidBody(rhs.GetBody()->GetMass(), rhs.GetBody()->GetGravityModifier(), a2de::PhysicsMaterial(rhs.GetBody()->GetRestitution(), rhs.GetBody()->GetStaticFriction()), a2de::Shape::Clone(rhs.GetBody()->GetBoundingRectangle()));
    this->_previous_objects = rhs._previous_objects;
    this->_current_objects = rhs._current_objects;
    this->_temp_objects = rhs._temp_objects;

    this->GetBody()->SetBoundingRectangle(rhs.GetBody()->GetBoundingRectangle());

    return *this;
}

template<class T>
void Trigger<T>::Update(double /*deltaTime*/) {

    _previous_objects = _current_objects;

    _temp_objects.sort();
    _current_objects.sort();

    std::set_difference(_temp_objects.begin(), _temp_objects.end(), _current_objects.begin(), _current_objects.end(), std::back_inserter(_current_objects));
    _temp_objects.clear();

    _previous_objects.sort();
    _current_objects.sort();

    std::list<T> just_entered;
    std::set_difference(_current_objects.begin(), _current_objects.end(), _previous_objects.begin(), _previous_objects.end(), std::back_inserter(just_entered));

    std::list<T> still_in;
    std::set_intersection(_previous_objects.begin(), _previous_objects.end(), _current_objects.begin(), _current_objects.end(), std::back_inserter(still_in));

    std::list<T> just_exited;
    std::set_difference(_previous_objects.begin(), _previous_objects.end(), _current_objects.begin(), _current_objects.end(), std::back_inserter(just_exited));

    std::for_each(just_entered.begin(), just_entered.end(), [&](T elem) {
        this->OnEnter(elem);
    });

    std::for_each(still_in.begin(), still_in.end(), [&](T elem) {
        this->OnTick(elem);
    });

    std::for_each(just_exited.begin(), just_exited.end(), [&](T elem) {
        this->OnExit(elem);
    });

}

template<class T>
void Trigger<T>::SetPosition(const a2de::Vector2D& position) {
    _area->SetPosition(position);
}

template<class T>
void Trigger<T>::SetPosition(double x, double y) {
    this->SetPosition(a2de::Vector2D(x, y));
}

template<class T>
void Trigger<T>::SetX(double x) {
    this->SetPosition(a2de::Vector2D(x, this->GetY()));
}

template<class T>
void Trigger<T>::SetY(double y) {
    this->SetPosition(a2de::Vector2D(this->GetX(), y));
}

template<class T>
Vector2D Trigger<T>::GetPosition() const {
    return _area->GetPosition();
}

template<class T>
a2de::Vector2D Trigger<T>::GetPosition() {
    return static_cast<const Trigger<T>&>(*this).GetPosition();
}

template<class T>
double Trigger<T>::GetX() const {
    return this->GetPosition().GetX();
}

template<class T>
double Trigger<T>::GetX() {
    return static_cast<const Trigger<T>&>(*this).GetX();
}

template<class T>
double Trigger<T>::GetY() const {
    return this->GetPosition().GetY();
}

template<class T>
double Trigger<T>::GetY() {
    return static_cast<const Trigger<T>&>(*this).GetY();
}

template<class T>
void Trigger<T>::SetDimensions(const a2de::Vector2D& dimensions) {
    _area->SetBoundingRectangle(new a2de::AABB(this->GetPosition(), dimensions / 2.0, a2de::Color::YELLOW()));
}

template<class T>
void Trigger<T>::SetDimensions(double width, double height) {
    this->SetDimensions(a2de::Vector2D(width, height));
}

template<class T>
const a2de::Vector2D& Trigger<T>::GetDimensions() const {
    return _area->GetBoundingRectangle()->GetHalfExtents() * 2.0;
}

template<class T>
a2de::Vector2D& Trigger<T>::GetDimensions() {
    return const_cast<Vector2D&>(static_cast<const Trigger<T>&>(*this).GetDimensions());
}

template<class T>
double Trigger<T>::GetWidth() const {
    return this->GetDimensions().GetX();
}

template<class T>
double Trigger<T>::GetWidth() {
    return static_cast<const Trigger<T>&>(*this).GetWidth();
}

template<class T>
double Trigger<T>::GetHeight() const {
    return this->GetDimensions().GetY();
}

template<class T>
double Trigger<T>::GetHeight() {
    return static_cast<const Trigger<T>&>(*this).GetHeight();
}

template<class T>
void Trigger<T>::OnEnter(T /*entered_object*/) {
    /* DO NOTHING */
}

template<class T>
void Trigger<T>::OnExit(T /*exited_object*/) {
    /* DO NOTHING */
}

template<class T>
void Trigger<T>::OnTick(T /*object*/) {
    /* DO NOTHING */
}

template<class T>
bool Trigger<T>::RegisterObject(T object) {
    std::list<T>::iterator _iter = std::find(_temp_objects.begin(), _temp_objects.end(), object);
    if(_iter != _temp_objects.end()) return false;
    _temp_objects.push_back(object);
    return true;
}

template<class T>
void Trigger<T>::UnregisterObject(T object) {
    std::list<T>::iterator _iter = std::find(_temp_objects.begin(), _temp_objects.end(), object);
    if(_iter == _temp_objects.end()) return;
    _temp_objects.erase(_iter);
}

template<class T>
const a2de::RigidBody* Trigger<T>::GetBody() const {
    return _area;
}

template<class T>
a2de::RigidBody* Trigger<T>::GetBody() {
    return const_cast<a2de::RigidBody*>(static_cast<const Trigger<T>&>(*this).GetBody());
}


A2DE_END

#endif // CTRIGGER_H