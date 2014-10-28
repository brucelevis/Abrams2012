/**************************************************************************************************
// file:	Engine\Physics\CWorld.h
// A2DE
// Copyright (c) 2013 Blisspoint Softworks and Casey Ugone. All rights reserved.
// Contact cugone@gmail.com for questions or support.
// summary:	Declares the world class
 **************************************************************************************************/
#ifndef A2DE_CWORLD_H
#define A2DE_CWORLD_H

#include "../a2de_vals.h"
#include <list>
#include <map>
#include <vector>
#include <iterator>
#include <set>
#include <thread>

#include "a2de_force_generators.h"
#include "CCamera.h"

#include "IUpdatable.h"
#include "../Math/CRectangle.h"
#include "CQuadTree.h"
#include "CContactData.h"

A2DE_BEGIN

class Object;
class RigidBody;
class Sprite;
class Shape;
class ContactPair;
class IBoundingBox;
class RenderManager;

/**************************************************************************************************
* <summary>World definition. </summary>
* <remarks>Casey Ugone, 8/15/2013.</remarks>
**************************************************************************************************/
struct WorldDef {

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    WorldDef() {
        width = 1.0;
        height = 1.0;
        gravity_x = 0.0;
        gravity_y = a2de::GravityForceGenerator::DEFAULT_GRAVITY_VALUE;
        drag_k1 = 0.0;
        drag_k2 = 0.0;
        scale = 0.01;
    }
    /// <summary> The width of the world in meters.</summary>
    double width;
    /// <summary> The height of the world in meters.</summary>
    double height;
    /// <summary> The force of gravity in Newtons in the x-direction.</summary>
    double gravity_x;
    /// <summary> The force of gravity in Newtons in the y-direction.</summary>
    double gravity_y;
    /// <summary> The first drag coefficient. </summary>
    double drag_k1;
    /// <summary> The second drag coefficient. </summary>
    double drag_k2;
    /// <summary> The meters-to-pixels ratio for world scale.</summary>
    double scale;
};


class World : public IUpdatable {

public:


    /**************************************************************************************************
     * <summary>Defines an alias representing the map cams. .</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef std::map<unsigned char, Camera> MapCams;

    /**************************************************************************************************
     * <summary>Defines an alias representing the map cams iterator. .</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef MapCams::iterator MapCamsIter;

    /**************************************************************************************************
     * <summary>Defines an alias representing the map cams constant iterator. .</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef MapCams::const_iterator MapCamsConstIter;

    /**************************************************************************************************
     * <summary>Defines an alias representing the list objects. .</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef std::list<Object*> Objects;

    /**************************************************************************************************
     * <summary>Defines an alias representing the list objects iterator. .</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     **************************************************************************************************/
    typedef Objects::iterator ObjectsIter;

    /**************************************************************************************************
     * <summary>Defines an alias representing the contact pairs. .</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    typedef std::set<ContactPair> ContactPairs;

    /**************************************************************************************************
     * <summary>Defines an alias representing the contact pairs iterator. .</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    typedef ContactPairs::iterator ContactPairsIter;

    /**************************************************************************************************
     * <summary>Defines an alias representing the contact pairs constant iterator. .</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    typedef ContactPairs::const_iterator ContactPairsConstIter;

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 8/15/2013.</remarks>
     * <param name="world_definition">The world definition.</param>
     **************************************************************************************************/
    World(const a2de::WorldDef& world_definition);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     **************************************************************************************************/
    virtual ~World();

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <returns>The width in pixels.</returns>
     **************************************************************************************************/
    double GetWidth() const;

    /**************************************************************************************************
     * <summary>Gets the width.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <returns>The width in pixels.</returns>
     **************************************************************************************************/
    double GetWidth();

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <returns>The height in pixels.</returns>
     **************************************************************************************************/
    double GetHeight() const;

    /**************************************************************************************************
     * <summary>Gets the height.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <returns>The height in pixels.</returns>
     **************************************************************************************************/
    double GetHeight();

    /**************************************************************************************************
     * <summary>Gets the dimensions of the world.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <returns>The dimensions as a Vector2D.</returns>
     **************************************************************************************************/
    Vector2D GetDimensions() const;

    /**************************************************************************************************
     * <summary>Gets the dimensions.</summary>
     * <remarks>Casey Ugone, 7/6/2012.</remarks>
     * <returns>The dimensions as a Vector2D.</returns>
     **************************************************************************************************/
    Vector2D GetDimensions();

    /**************************************************************************************************
     * <summary>Sets the dimensions.</summary>
     * <remarks>Casey Ugone, 4/27/2012.</remarks>
     * <param name="width"> The width.</param>
     * <param name="height">The height.</param>
     **************************************************************************************************/
    void SetDimensions(double width, double height);

    /**************************************************************************************************
     * <summary>Renders the world.</summary>
     * <remarks>Casey Ugone, 10/10/2014.</remarks>
     **************************************************************************************************/
    void Render();

    /**************************************************************************************************
     * <summary>Adds a camera.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="camera">The camera to add.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddCamera(const Camera& camera);

    /**************************************************************************************************
     * <summary>Removes the camera described by camera_index.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="camera_index">Zero-based index of the camera.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RemoveCamera(const unsigned char camera_index);

    /**************************************************************************************************
     * <summary>Removes the camera described by camera.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="camera">[in,out] The camera.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RemoveCamera(const Camera& camera);

    /**************************************************************************************************
     * <summary>Gets a camera.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="index">Zero-based index of the camera.</param>
     * <returns>An iterator describing the location of the camera if it succeeds or map.end() if it fails.</returns>
     **************************************************************************************************/
    MapCamsIter GetCamera(unsigned char index);

    /**************************************************************************************************
     * <summary>Gets the cameras.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The cameras.</returns>
     **************************************************************************************************/
    MapCams GetCameras() const;

    /**************************************************************************************************
     * <summary>Gets the cameras.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The cameras.</returns>
     **************************************************************************************************/
    MapCams GetCameras();

    /**************************************************************************************************
     * <summary>Gets the camera count.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The camera count.</returns>
     **************************************************************************************************/
    unsigned char GetCameraCount() const;

    /**************************************************************************************************
     * <summary>Gets the camera count.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The camera count.</returns>
     **************************************************************************************************/
    unsigned char GetCameraCount();

    /**************************************************************************************************
     * <summary>Adds an object. </summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="obj">[in,out] If non-null, the object.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool AddObject(Object* obj);

    /**************************************************************************************************
     * <summary>Removes the object described by obj.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="obj">[in,out] If non-null, the object.</param>
     * <returns>true if it succeeds, false if it fails.</returns>
     **************************************************************************************************/
    bool RemoveObject(Object* obj);

    /**************************************************************************************************
     * <summary>Gets the objects.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The objects.</returns>
     **************************************************************************************************/
    const Objects& GetObjects() const;

    /**************************************************************************************************
     * <summary>Gets the objects.</summary>
     * <remarks>Casey Ugone, 9/3/2012.</remarks>
     * <returns>The objects.</returns>
     **************************************************************************************************/
    Objects& GetObjects();

    /**************************************************************************************************
     * <summary>Moves a Camera's view to center it on an object's location.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="cam">[in,out] The camera.</param>
     * <param name="obj">The object.</param>
     **************************************************************************************************/
    void CameraToObject(Camera& cam, const Object& obj);

    /**************************************************************************************************
     * <summary>Moves an Object's location to the center of a camera's view.</summary>
     * <remarks>Casey Ugone, 3/16/2012.</remarks>
     * <param name="obj">[in,out] The object.</param>
     * <param name="cam">The camera.</param>
     **************************************************************************************************/
    void ObjectToCamera(Object& obj, const Camera& cam);

    /**************************************************************************************************
     * <summary>Camera to world position.</summary>
     * <remarks>Casey Ugone, 7/28/2012.</remarks>
     * <param name="cam">            The camera.</param>
     * <param name="screen_position">The screen position.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    static Vector2D CameraToWorldPosition(const Camera& cam, const Vector2D& screen_position);

    /**************************************************************************************************
     * <summary>World to camera position.</summary>
     * <remarks>Casey Ugone, 7/28/2012.</remarks>
     * <param name="cam">           The camera.</param>
     * <param name="world_position">The world position.</param>
     * <returns>.</returns>
     **************************************************************************************************/
    static Vector2D WorldToCameraPosition(const Camera& cam, const Vector2D& world_position);

    /**************************************************************************************************
     * <summary>Sets the gravity.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="gravity">The gravity.</param>
     **************************************************************************************************/
    void SetGravity(const Vector2D& gravity);

    /**************************************************************************************************
     * <summary>Gets the gravity handler.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <returns>The gravity handler.</returns>
     **************************************************************************************************/
    const GravityForceGenerator* GetGravityHandler() const;

    /**************************************************************************************************
     * <summary>Sets the drag coefficients.</summary>
     * <remarks>Casey Ugone, 5/4/2013.</remarks>
     * <param name="k1k2">k1 and k2 values.</param>
     **************************************************************************************************/
    void SetDragCoefficients(const Vector2D& k1k2);

    /**************************************************************************************************
     * <summary>Gets the drag handler.</summary>
     * <remarks>Casey Ugone, 5/4/2013.</remarks>
     * <returns>null if it fails, else the drag handler.</returns>
     **************************************************************************************************/
    const DragForceGenerator* GetDragHandler() const;

    /**************************************************************************************************
     * <summary>Updates the world.</summary>
     * <remarks>Casey Ugone, 8/29/2012.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    void Update(double deltaTime);

    /**************************************************************************************************
     * <summary>Resolve collisions.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    void ResolveCollisions(double deltaTime);

    /**************************************************************************************************
     * <summary>Gets the spatial partition grid.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the grid.</returns>
     **************************************************************************************************/
    const a2de::QuadTree<a2de::Vector2D>* GetGrid() const;

    /**************************************************************************************************
     * <summary>Gets the spatial partition grid.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the grid.</returns>
     **************************************************************************************************/
    a2de::QuadTree<a2de::Vector2D>* GetGrid();

protected:
private:

    /**************************************************************************************************
     * <summary>Deallocates the world.</summary>
     * <remarks>Casey Ugone, 8/15/2013.</remarks>
     **************************************************************************************************/
    void DeallocateWorld();

    /**************************************************************************************************
     * <summary>Updates the objects in world described by deltaTime.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="deltaTime">Time since the last frame.</param>
     **************************************************************************************************/
    void UpdateObjectsInWorld(double deltaTime);

    /**************************************************************************************************
     * <summary>Updates the grid.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     **************************************************************************************************/
    void UpdateGrid();

    /**************************************************************************************************
     * <summary>Calculates the Narrow phase collision.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="contact_pairs">[in,out] The contact pairs.</param>
     * <param name="deltaTime">    Time since the last frame.</param>
     **************************************************************************************************/
    void NarrowPhaseCollision(a2de::World::ContactPairs& contact_pairs, double deltaTime);

    /**************************************************************************************************
     * <summary>Interpenetration solver.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="first_body"> [in,out] If non-null, the first body.</param>
     * <param name="second_body">[in,out] If non-null, the second body.</param>
     * <param name="deltaTime">  Time since the last frame.</param>
     **************************************************************************************************/
    void PositionSolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body, double deltaTime);

    /**************************************************************************************************
     * <summary>Velocity solver.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="first_body"> [in,out] If non-null, the first body.</param>
     * <param name="second_body">[in,out] If non-null, the second body.</param>
     **************************************************************************************************/
    void VelocitySolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body);

    /**************************************************************************************************
     * <summary>Calculates the broad phase collision.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <returns>.</returns>
     **************************************************************************************************/
    a2de::World::ContactPairs BroadPhaseCollision();

    /**************************************************************************************************
     * <summary>Generates contact pairs.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="queried_boxes">[in,out] [in,out] If non-null, the queried boxes.</param>
     * <returns>The contact pairs.</returns>
     **************************************************************************************************/
    a2de::World::ContactPairs GenerateContactPairs(std::vector<a2de::Vector2D>& queried_elems);

    /**************************************************************************************************
     * <summary>Queries all cameras.</summary>
     * <remarks>Casey Ugone, 5/20/2013.</remarks>
     * <param name="queried_boxes">[in,out] [in,out] If non-null, the queried boxes.</param>
     **************************************************************************************************/
    void QueryAllCameras(std::vector<a2de::Vector2D>& queried_elems);

    /**************************************************************************************************
     * <summary>Shape collision solver.</summary>
     * <remarks>Casey Ugone, 5/21/2013.</remarks>
     * <param name="first_collision_shape"> [in,out] If non-null, the first collision shape.</param>
     * <param name="second_collision_shape">[in,out] If non-null, the second collision shape.</param>
     **************************************************************************************************/
    std::vector<ContactData> ShapeCollisionSolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body);

    /**************************************************************************************************
     * <summary>Circle-Circle collision solver.</summary>
     * <remarks>Casey Ugone, 5/21/2013.</remarks>
     * <param name="first_collision_shape"> [in,out] If non-null, the first collision shape.</param>
     * <param name="second_collision_shape">[in,out] If non-null, the second collision shape.</param>
     **************************************************************************************************/
    std::vector<ContactData> CircleCircleCollisionSolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body);

    /**************************************************************************************************
     * <summary>Circle-Line collision solver.</summary>
     * <remarks>Casey Ugone, 5/21/2013.</remarks>
     * <param name="first_collision_shape"> [in,out] If non-null, the first collision shape.</param>
     * <param name="second_collision_shape">[in,out] If non-null, the second collision shape.</param>
     **************************************************************************************************/
    std::vector<ContactData> CircleLineCollisionSolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body);

    /**************************************************************************************************
     * <summary>Circle-Rectangle collision solver.</summary>
     * <remarks>Casey Ugone, 5/21/2013.</remarks>
     * <param name="first_collision_shape"> [in,out] If non-null, the first collision shape.</param>
     * <param name="second_collision_shape">[in,out] If non-null, the second collision shape.</param>
     **************************************************************************************************/
    std::vector<ContactData> CircleRectangleCollisionSolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body);

    /**************************************************************************************************
     * <summary>Rectangle-Line collision solver.</summary>
     * <remarks>Casey Ugone, 5/21/2013.</remarks>
     * <param name="first_collision_shape"> [in,out] If non-null, the first collision shape.</param>
     * <param name="second_collision_shape">[in,out] If non-null, the second collision shape.</param>
     **************************************************************************************************/
    std::vector<ContactData> RectangleLineCollisionSolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body);

    /**************************************************************************************************
     * <summary>Rectangle-Rectangle collision solver.</summary>
     * <remarks>Casey Ugone, 5/21/2013.</remarks>
     * <param name="first_collision_shape"> [in,out] If non-null, the first collision shape.</param>
     * <param name="second_collision_shape">[in,out] If non-null, the second collision shape.</param>
     **************************************************************************************************/
    std::vector<ContactData> RectangleRectangleCollisionSolver(a2de::RigidBody* first_body, a2de::RigidBody* second_body);

    /**************************************************************************************************
     * <summary>Method for threading the physics calculations.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="deltaTime">The delta time.</param>
     **************************************************************************************************/
    void UpdateImpl(double deltaTime);

    /// <summary> The dimensions </summary>
    Vector2D _dimensions;
    /// <summary> The cameras </summary>
    std::map<unsigned char, Camera> _cameras;
    /// <summary> The objects </summary>
    std::list<Object*> _objects;

    /// <summary> The gravity handler </summary>
    GravityForceGenerator* _gh;
    /// <summary> The drag handler </summary>
    DragForceGenerator* _dh;

    /// <summary> The render manager.</summary>
   a2de::RenderManager* _render_context;
   /// <summary> The update thread. </summary>
   std::thread _update_thread;

   /// <summary> The spatial partition grid </summary>
   a2de::QuadTree<a2de::Vector2D>* _grid;

};

A2DE_END

#endif