#ifndef A2DE_CMATRIX4X4_H
#define A2DE_CMATRIX4X4_H

#include "../a2de_vals.h"
#include <array>

A2DE_BEGIN

class Vector3D;
class Vector4D;

/**************************************************************************************************
 * <summary>A 4x4 matrix.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
class Matrix4x4 {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    Matrix4x4();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="m00">First row, first column.</param>
     * <param name="m01">First row, second column.</param>
     * <param name="m02">First row, third column.</param>
     * <param name="m03">First row, fourth column.</param>
     * <param name="m10">Second row, first column.</param>
     * <param name="m11">Second row, second column.</param>
     * <param name="m12">Second row, third column.</param>
     * <param name="m13">Second row, fourth column.</param>
     * <param name="m20">Third row, first column.</param>
     * <param name="m21">Third row, second column.</param>
     * <param name="m22">Third row, third column.</param>
     * <param name="m23">Third row, fourth column.</param>
     * <param name="m30">Fourth row, first column.</param>
     * <param name="m31">Fourth row, second column.</param>
     * <param name="m32">Fourth row, third column.</param>
     * <param name="m33">Fourth row, fourth column.</param>
     **************************************************************************************************/
    Matrix4x4(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23, double m30, double m31, double m32, double m33);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row_one">  The row one.</param>
     * <param name="row_two">  The row two.</param>
     * <param name="row_three">The row three.</param>
     * <param name="row_four"> The row four.</param>
     **************************************************************************************************/
    Matrix4x4(const Vector4D& row_one, const Vector4D& row_two, const Vector4D& row_three, const Vector4D& row_four);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Matrix4x4(const Matrix4x4& other);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    ~Matrix4x4();

    /**************************************************************************************************
     * <summary>Gets the identity.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The identity.</returns>
     **************************************************************************************************/
    static Matrix4x4 GetIdentity();

    /**************************************************************************************************
     * <summary>Gets translation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="position">The position.</param>
     * <returns>The translation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 GetTranslationMatrix(const a2de::Vector3D& position);

    /**************************************************************************************************
     * <summary>Gets translation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <param name="z">The z coordinate.</param>
     * <returns>The translation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 GetTranslationMatrix(double x, double y, double z);

    /**************************************************************************************************
     * <summary>Gets rotation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rotations">The rotations.</param>
     * <returns>The rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 GetRotationMatrix(const a2de::Vector3D& rotations);

    /**************************************************************************************************
     * <summary>Gets the 2D rotation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="angle">The angle.</param>
     * <returns>The 2D rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 Get2DRotationMatrix(double angle);

    /**************************************************************************************************
     * <summary>Gets 3D rotation matrix around the X axis.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="angle">The angle.</param>
     * <returns>The 3D rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 Get3DXRotationMatrix(double angle);

    /**************************************************************************************************
     * <summary>Gets 3D rotation matrix around the Y axis.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="angle">The angle to rotate.</param>
     * <returns>The 3D rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 Get3DYRotationMatrix(double angle);

    /**************************************************************************************************
     * <summary>Gets 3D rotation matrix around the Z axis.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="angle">The angle to rotate.</param>
     * <returns>The 3D rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 Get3DZRotationMatrix(double angle);

    /**************************************************************************************************
     * <summary>Gets a rotation matrix .</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="Xangle">The angle around the x axis to rotate.</param>
     * <param name="Yangle">The angle around the y axis to rotate.</param>
     * <param name="Zangle">The angle around the z axis to rotate.</param>
     * <returns>The rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 GetRotationMatrix(double Xangle, double Yangle, double Zangle);

    /**************************************************************************************************
     * <summary>Gets scale matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scale">The scale.</param>
     * <returns>The scale matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 GetScaleMatrix(const a2de::Vector3D& scale);

    /**************************************************************************************************
     * <summary>Gets scale matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scale_x">The scale x coordinate.</param>
     * <param name="scale_y">The scale y coordinate.</param>
     * <param name="scale_z">The scale z coordinate.</param>
     * <returns>The scale matrix.</returns>
     **************************************************************************************************/
    static Matrix4x4 GetScaleMatrix(double scale_x, double scale_y, double scale_z);

    /**************************************************************************************************
     * <summary>Sets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowOne(const Vector4D& row);

    /**************************************************************************************************
     * <summary>Sets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowTwo(const Vector4D& row);

    /**************************************************************************************************
     * <summary>Sets row three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowThree(const Vector4D& row);

    /**************************************************************************************************
     * <summary>Sets row four.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowFour(const Vector4D& row);

    /**************************************************************************************************
     * <summary>Gets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row one.</returns>
     **************************************************************************************************/
    Vector4D GetRowOne() const;

    /**************************************************************************************************
     * <summary>Gets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row one.</returns>
     **************************************************************************************************/
    Vector4D GetRowOne();

    /**************************************************************************************************
     * <summary>Gets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row two.</returns>
     **************************************************************************************************/
    Vector4D GetRowTwo() const;

    /**************************************************************************************************
     * <summary>Gets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row two.</returns>
     **************************************************************************************************/
    Vector4D GetRowTwo();

    /**************************************************************************************************
     * <summary>Gets row three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row three.</returns>
     **************************************************************************************************/
    Vector4D GetRowThree() const;

    /**************************************************************************************************
     * <summary>Gets row three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row three.</returns>
     **************************************************************************************************/
    Vector4D GetRowThree();

    /**************************************************************************************************
     * <summary>Gets row four.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row four.</returns>
     **************************************************************************************************/
    Vector4D GetRowFour() const;

    /**************************************************************************************************
     * <summary>Gets row four.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row four.</returns>
     **************************************************************************************************/
    Vector4D GetRowFour();

    /**************************************************************************************************
     * <summary>Gets column one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column one.</returns>
     **************************************************************************************************/
    Vector4D GetColumnOne() const;

    /**************************************************************************************************
     * <summary>Gets column one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column one.</returns>
     **************************************************************************************************/
    Vector4D GetColumnOne();

    /**************************************************************************************************
     * <summary>Gets column two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column two.</returns>
     **************************************************************************************************/
    Vector4D GetColumnTwo() const;

    /**************************************************************************************************
     * <summary>Gets column two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column two.</returns>
     **************************************************************************************************/
    Vector4D GetColumnTwo();

    /**************************************************************************************************
     * <summary>Gets column three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column three.</returns>
     **************************************************************************************************/
    Vector4D GetColumnThree() const;

    /**************************************************************************************************
     * <summary>Gets column three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column three.</returns>
     **************************************************************************************************/
    Vector4D GetColumnThree();

    /**************************************************************************************************
     * <summary>Gets column four.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column four.</returns>
     **************************************************************************************************/
    Vector4D GetColumnFour() const;

    /**************************************************************************************************
     * <summary>Gets column four.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column four.</returns>
     **************************************************************************************************/
    Vector4D GetColumnFour();

    /**************************************************************************************************
     * <summary>Sets the value at the given index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the element to set.</param>
     * <param name="value">The value to set it to.</param>
     **************************************************************************************************/
    void SetIndex(unsigned int index, double value);

    /**************************************************************************************************
     * <summary>Gets the element at the given index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the element.</param>
     * <returns>The value of the element.</returns>
     **************************************************************************************************/
    double GetIndex(unsigned int index) const;

    /**************************************************************************************************
     * <summary>Gets the element at the given index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the element.</param>
     * <returns>The value of the element.</returns>
     **************************************************************************************************/
    double GetIndex(unsigned int index);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Matrix4x4& operator=(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Transposes this object.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Transpose();

    /**************************************************************************************************
     * <summary>Inverses this object.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Inverse();

    /**************************************************************************************************
     * <summary>Calculates the determinant.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="mat">The matrix.</param>
     * <returns>The calculated determinant.</returns>
     **************************************************************************************************/
    static double CalculateDeterminant(const Matrix4x4& mat);

    /**************************************************************************************************
     * <summary>Calculates the determinant.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The calculated determinant.</returns>
     **************************************************************************************************/
    double CalculateDeterminant() const;

    /**************************************************************************************************
     * <summary>Calculates the determinant.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The calculated determinant.</returns>
     **************************************************************************************************/
    double CalculateDeterminant();

    /**************************************************************************************************
     * <summary>Calculates the trace.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The calculated trace.</returns>
     **************************************************************************************************/
    double CalculateTrace() const;

    /**************************************************************************************************
     * <summary>Calculates the trace.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The calculated trace.</returns>
     **************************************************************************************************/
    double CalculateTrace();

    /**************************************************************************************************
     * <summary>Transposes the given matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="mat">The matrix.</param>
     * <returns>A Matrix4x4.</returns>
     **************************************************************************************************/
    static Matrix4x4 Transpose(const Matrix4x4& mat);

    /**************************************************************************************************
     * <summary>Inverses the given matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="mat">The matrix.</param>
     * <returns>A Matrix4x4.</returns>
     **************************************************************************************************/
    static Matrix4x4 Inverse(const Matrix4x4& mat);

    /**************************************************************************************************
     * <summary>Indirection operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    const double * const operator*() const;

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Matrix4x4& rhs) const;

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Matrix4x4& rhs) const;

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4 operator*(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4 operator*(double scalar);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector4D operator*(const Vector4D& rhs);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4& operator*=(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4& operator*=(double scalar);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4 operator+(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Addition assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4& operator+=(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4 operator-(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Subtraction assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4& operator-=(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4 operator/(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Division assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4& operator/=(const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix4x4 operator-();

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The first value to multiply.</param>
     * <param name="rhs">   The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Matrix4x4 operator*(double scalar, const Matrix4x4& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="lhs">The first value to multiply.</param>
     * <param name="rhs">The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector4D operator*(const Matrix4x4& lhs, const Vector4D& rhs);

protected:
private:
    //[00 01 02 03]
    //[10 11 12 13]
    //[20 21 22 23]
    //[30 31 32 33]

    /**************************************************************************************************
     * <summary>The indicies.</summary>
     **************************************************************************************************/
    std::array<double, 16> _indicies;

/**************************************************************************************************
 * <summary>Gets or sets the. </summary>
 * <value>.</value>
 **************************************************************************************************/
};

A2DE_END

#endif