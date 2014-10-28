#ifndef A2DE_CTRANSFORM2D_H
#define A2DE_CTRANSFORM2D_H

#include "../a2de_vals.h"
#include "CMatrix3x3.h"
#include "CVector2D.h"

#include <vector>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>A transform 2 d.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
class Transform2D {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    Transform2D();

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="parent">[in,out] If non-null, the parent.</param>
     **************************************************************************************************/
    Transform2D(Transform2D* parent);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Transform2D(const Transform2D& other);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Transform2D& operator=(const Transform2D& rhs);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    virtual ~Transform2D();

    /**************************************************************************************************
     * <summary>Sets the parent transform.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="parent">[in,out] If non-null, the parent.</param>
     **************************************************************************************************/
    void SetParent(Transform2D* parent);

    /**************************************************************************************************
     * <summary>Adds a child transform.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="child">[in,out] If non-null, the child.</param>
     **************************************************************************************************/
    void AddChild(Transform2D* child);

    /**************************************************************************************************
     * <summary>Removes the child transform described by child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="child">[in,out] If non-null, the child.</param>
     **************************************************************************************************/
    void RemoveChild(Transform2D* child);

    /**************************************************************************************************
     * <summary>First child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform2D*.</returns>
     **************************************************************************************************/
    Transform2D* FirstChild();

    /**************************************************************************************************
     * <summary>Last child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform2D*.</returns>
     **************************************************************************************************/
    Transform2D* LastChild();

    /**************************************************************************************************
     * <summary>Next child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform2D*.</returns>
     **************************************************************************************************/
    Transform2D* NextChild();

    /**************************************************************************************************
     * <summary>Previous child.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else a Transform2D*.</returns>
     **************************************************************************************************/
    Transform2D* PreviousChild();

    /**************************************************************************************************
     * <summary>Gets a child transform at index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the child.</param>
     * <returns>null if it fails, else the child.</returns>
     **************************************************************************************************/
    Transform2D* GetChild(std::size_t index);

    /**************************************************************************************************
     * <summary>Gets the number of child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the child count.</returns>
     **************************************************************************************************/
    std::vector<Transform2D*>::size_type GetChildCount() const;

    /**************************************************************************************************
     * <summary>Gets the number of child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>null if it fails, else the child count.</returns>
     **************************************************************************************************/
    std::vector<Transform2D*>::size_type GetChildCount();

    /**************************************************************************************************
     * <summary>Sets the position elements.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="position">The position.</param>
     **************************************************************************************************/
    void SetPosition(const a2de::Vector2D& position);

    /**************************************************************************************************
     * <summary>Gets the position elements.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    const a2de::Vector2D& GetPosition() const;

    /**************************************************************************************************
     * <summary>Gets the position elements.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The position.</returns>
     **************************************************************************************************/
    a2de::Vector2D& GetPosition();

    /**************************************************************************************************
     * <summary>Sets the rotation elements based on the rotation argument.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rotation">The rotation in radians.</param>
     **************************************************************************************************/
    void SetRotation(double rotation);

    /**************************************************************************************************
     * <summary>Gets the rotation in radians.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The rotation.</returns>
     **************************************************************************************************/
    double GetRotation() const;

    /**************************************************************************************************
     * <summary>Gets the rotation in radians.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The rotation.</returns>
     **************************************************************************************************/
    double GetRotation();

    /**************************************************************************************************
     * <summary>Sets the scale elements.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scale">The scale.</param>
     **************************************************************************************************/
    void SetScale(const a2de::Vector2D& scale);

    /**************************************************************************************************
     * <summary>Gets the scale.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The scale.</returns>
     **************************************************************************************************/
    const a2de::Vector2D& GetScale() const;

    /**************************************************************************************************
     * <summary>Gets the scale.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The scale.</returns>
     **************************************************************************************************/
    a2de::Vector2D& GetScale();

    /**************************************************************************************************
     * <summary>Builds a 3x3 Matrix from the Position, Scale, Rotation, parent and child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The local transform.</returns>
     **************************************************************************************************/
    a2de::Matrix3x3 GetLocalTransform() const;

    /**************************************************************************************************
     * <summary>Builds a 3x3 Matrix from the Position, Scale, Rotation, parent and child transforms.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The local transform.</returns>
     **************************************************************************************************/
    a2de::Matrix3x3 GetLocalTransform();

    /**************************************************************************************************
     * <summary>Builds a 3x3 Matrix that represents a rotation around the given point.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="point">The point to rotate around.</param>
     * <returns>An a2de::Matrix3x3.</returns>
     **************************************************************************************************/
    a2de::Matrix3x3 RotateAround(const a2de::Vector2D& point);
protected:

private:

    /**************************************************************************************************
     * <summary>The position.</summary>
     **************************************************************************************************/
    a2de::Vector2D _position;

    /**************************************************************************************************
     * <summary>The scale.</summary>
     **************************************************************************************************/
    a2de::Vector2D _scale;

    /**************************************************************************************************
     * <summary>The rotation.</summary>
     **************************************************************************************************/
    double _rotation;

    /**************************************************************************************************
     * <summary>The current child index.</summary>
     **************************************************************************************************/
    std::size_t _curChildIndex;

    /**************************************************************************************************
     * <summary>The parent.</summary>
     **************************************************************************************************/
    Transform2D* _parent;

    /**************************************************************************************************
     * <summary>The children.</summary>
     **************************************************************************************************/
    std::vector<Transform2D*> _children;

};

A2DE_END

#endif