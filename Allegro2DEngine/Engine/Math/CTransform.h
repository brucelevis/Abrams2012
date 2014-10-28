#ifndef A2DE_CTRANSFORM_H
#define A2DE_CTRANSFORM_H

#include "../a2de_vals.h"
#include "CMatrix4x4.h"
#include "CVector3D.h"

#include <vector>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>A 3D Transform.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
class Transform {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    Transform();

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="parent">[in,out] If non-null, the parent.</param>
     **************************************************************************************************/
    Transform(Transform* parent);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Transform(const Transform& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Transform& operator=(const Transform& rhs);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~Transform();

    /**************************************************************************************************
     * <summary>Sets a parent.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="parent">[in,out] If non-null, the parent.</param>
     **************************************************************************************************/
    void SetParent(Transform* parent);

    /**************************************************************************************************
     * <summary>Adds a child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="child">[in,out] If non-null, the child.</param>
     **************************************************************************************************/
    void AddChild(Transform* child);

    /**************************************************************************************************
     * <summary>Removes the child described by child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="child">[in,out] If non-null, the child.</param>
     **************************************************************************************************/
    void RemoveChild(Transform* child);

    /**************************************************************************************************
     * <summary>First child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform*.</returns>
     **************************************************************************************************/
    Transform* FirstChild();

    /**************************************************************************************************
     * <summary>Last child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform*.</returns>
     **************************************************************************************************/
    Transform* LastChild();

    /**************************************************************************************************
     * <summary>Next child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform*.</returns>
     **************************************************************************************************/
    Transform* NextChild();

    /**************************************************************************************************
     * <summary>Previous child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform*.</returns>
     **************************************************************************************************/
    Transform* PreviousChild();

    /**************************************************************************************************
     * <summary>Gets child transform at the given index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the child.</param>
     * <returns>null if it fails, else the child.</returns>
     **************************************************************************************************/
    Transform* GetChild(std::size_t index);

    /**************************************************************************************************
     * <summary>Gets number of child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The child count.</returns>
     **************************************************************************************************/
    std::size_t GetChildCount() const;

    /**************************************************************************************************
     * <summary>Gets the number of child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The child count.</returns>
     **************************************************************************************************/
    std::size_t GetChildCount();

    /**************************************************************************************************
     * <summary>Sets the position.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPosition(const a2de::Vector3D& position);

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    const a2de::Vector3D& GetPosition() const;

    /**************************************************************************************************
     * <summary>Gets the position.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    a2de::Vector3D& GetPosition();

    /**************************************************************************************************
     * <summary>Sets the rotation.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rotation">The rotation.</param>
     **************************************************************************************************/
    void SetRotation(const a2de::Vector3D& rotation);

    /**************************************************************************************************
     * <summary>Gets the rotation.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The rotation.</returns>
     **************************************************************************************************/
    const a2de::Vector3D& GetRotation() const;

    /**************************************************************************************************
     * <summary>Gets the rotation.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The rotation.</returns>
     **************************************************************************************************/
    a2de::Vector3D& GetRotation();

    /**************************************************************************************************
     * <summary>Sets a scale.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scale">The scale.</param>
     **************************************************************************************************/
    void SetScale(const a2de::Vector3D& scale);

    /**************************************************************************************************
     * <summary>Gets the scale.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The scale.</returns>
     **************************************************************************************************/
    const a2de::Vector3D& GetScale() const;

    /**************************************************************************************************
     * <summary>Gets the scale.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The scale.</returns>
     **************************************************************************************************/
    a2de::Vector3D& GetScale();

    /**************************************************************************************************
     * <summary>Builds a 3D transform from the positoin, scale, rotation, parent, and child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The local transform.</returns>
     **************************************************************************************************/
    a2de::Matrix4x4 GetLocalTransform() const;

    /**************************************************************************************************
     * <summary>Builds a 3D transform from the positoin, scale, rotation, parent, and child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The local transform.</returns>
     **************************************************************************************************/
    a2de::Matrix4x4 GetLocalTransform();

protected:

private:

    /**************************************************************************************************
     * <summary>The position.</summary>
     **************************************************************************************************/
    a2de::Vector3D _position;

    /**************************************************************************************************
     * <summary>The scale.</summary>
     **************************************************************************************************/
    a2de::Vector3D _scale;

    /**************************************************************************************************
     * <summary>The rotation.</summary>
     **************************************************************************************************/
    a2de::Vector3D _rotation;

    /**************************************************************************************************
     * <summary>The current child index.</summary>
     **************************************************************************************************/
    std::size_t _curChildIndex;

    /**************************************************************************************************
     * <summary>The parent.</summary>
     **************************************************************************************************/
    Transform* _parent;

    /**************************************************************************************************
     * <summary>The children.</summary>
     **************************************************************************************************/
    std::vector<Transform*> _children;    
};

A2DE_END

#endif