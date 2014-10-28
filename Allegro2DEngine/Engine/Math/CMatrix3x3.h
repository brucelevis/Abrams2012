#ifndef A2DE_CMATRIX3X3_H
#define A2DE_CMATRIX3X3_H

#include "../a2de_vals.h"
#include "CVector3D.h"
#include <array>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>A 3x3 matrix.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
class Matrix3x3 {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    Matrix3x3();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="m00">First row, first column.</param>
     * <param name="m01">First row, second column.</param>
     * <param name="m02">First row, third column.</param>
     * <param name="m10">Second row, first column.</param>
     * <param name="m11">Second row, second column.</param>
     * <param name="m12">Second row, third column.</param>
     * <param name="m20">Third row, first column.</param>
     * <param name="m21">Third row, second column.</param>
     * <param name="m22">Third row, third column.</param>
     **************************************************************************************************/
    Matrix3x3(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row_one">  The row one.</param>
     * <param name="row_two">  The row two.</param>
     * <param name="row_three">The row three.</param>
     **************************************************************************************************/
    Matrix3x3(const Vector3D& row_one, const Vector3D& row_two, const Vector3D& row_three);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other 3x3 matrix.</param>
     **************************************************************************************************/
    Matrix3x3(const Matrix3x3& other);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    ~Matrix3x3();

    /**************************************************************************************************
     * <summary>Gets the identity matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The identity marix.</returns>
     **************************************************************************************************/
    static Matrix3x3 GetIdentity();

    /**************************************************************************************************
     * <summary>Gets translation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <returns>The translation matrix.</returns>
     **************************************************************************************************/
    static Matrix3x3 GetTranslationMatrix(double x, double y);

    /**************************************************************************************************
     * <summary>Gets translation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="pos">The position.</param>
     * <returns>The translation matrix.</returns>
     **************************************************************************************************/
    static Matrix3x3 GetTranslationMatrix(const a2de::Vector2D& pos);

    /**************************************************************************************************
     * <summary>Gets rotation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="angle">The angle.</param>
     * <returns>The rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix3x3 GetRotationMatrix(double angle);

    /**************************************************************************************************
     * <summary>Gets scale matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scale_x">The scale x coordinate.</param>
     * <param name="scale_y">The scale y coordinate.</param>
     * <returns>The scale matrix.</returns>
     **************************************************************************************************/
    static Matrix3x3 GetScaleMatrix(double scale_x, double scale_y);

    /**************************************************************************************************
     * <summary>Gets scale matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scale">The scale.</param>
     * <returns>The scale matrix.</returns>
     **************************************************************************************************/
    static Matrix3x3 GetScaleMatrix(const a2de::Vector2D& scale);

    /**************************************************************************************************
     * <summary>Sets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowOne(const Vector3D& row);

    /**************************************************************************************************
     * <summary>Sets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowTwo(const Vector3D& row);

    /**************************************************************************************************
     * <summary>Sets row three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowThree(const Vector3D& row);

    /**************************************************************************************************
     * <summary>Gets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row one.</returns>
     **************************************************************************************************/
    Vector3D GetRowOne() const;

    /**************************************************************************************************
     * <summary>Gets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row one.</returns>
     **************************************************************************************************/
    Vector3D GetRowOne();

    /**************************************************************************************************
     * <summary>Gets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row two.</returns>
     **************************************************************************************************/
    Vector3D GetRowTwo() const;

    /**************************************************************************************************
     * <summary>Gets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row two.</returns>
     **************************************************************************************************/
    Vector3D GetRowTwo();

    /**************************************************************************************************
     * <summary>Gets row three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row three.</returns>
     **************************************************************************************************/
    Vector3D GetRowThree() const;

    /**************************************************************************************************
     * <summary>Gets row three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row three.</returns>
     **************************************************************************************************/
    Vector3D GetRowThree();

    /**************************************************************************************************
     * <summary>Gets column one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column one.</returns>
     **************************************************************************************************/
    Vector3D GetColumnOne() const;

    /**************************************************************************************************
     * <summary>Gets column one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column one.</returns>
     **************************************************************************************************/
    Vector3D GetColumnOne();

    /**************************************************************************************************
     * <summary>Gets column two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column two.</returns>
     **************************************************************************************************/
    Vector3D GetColumnTwo() const;

    /**************************************************************************************************
     * <summary>Gets column two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column two.</returns>
     **************************************************************************************************/
    Vector3D GetColumnTwo();

    /**************************************************************************************************
     * <summary>Gets column three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column three.</returns>
     **************************************************************************************************/
    Vector3D GetColumnThree() const;

    /**************************************************************************************************
     * <summary>Gets column three.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column three.</returns>
     **************************************************************************************************/
    Vector3D GetColumnThree();

    /**************************************************************************************************
     * <summary>Sets an index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the.</param>
     * <param name="value">The value.</param>
     **************************************************************************************************/
    void SetIndex(unsigned int index, double value);

    /**************************************************************************************************
     * <summary>Gets an index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the.</param>
     * <returns>The index.</returns>
     **************************************************************************************************/
    double GetIndex(unsigned int index) const;

    /**************************************************************************************************
     * <summary>Gets an index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the.</param>
     * <returns>The index.</returns>
     **************************************************************************************************/
    double GetIndex(unsigned int index);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Matrix3x3& operator=(const Matrix3x3& rhs);

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
    static double CalculateDeterminant(const Matrix3x3& mat);

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
     * <returns>A Matrix3x3.</returns>
     **************************************************************************************************/
    static Matrix3x3 Transpose(const Matrix3x3& mat);

    /**************************************************************************************************
     * <summary>Inverses the given matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="mat">The matrix.</param>
     * <returns>A Matrix3x3.</returns>
     **************************************************************************************************/
    static Matrix3x3 Inverse(const Matrix3x3& mat);

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
    bool operator==(const Matrix3x3& rhs) const;

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Matrix3x3& rhs) const;

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator*(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator*(double scalar);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector3D operator*(const Vector3D& rhs) const;

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Vector3D operator*(const Vector3D& rhs);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3& operator*=(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3& operator*=(double scalar);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator+(const Matrix3x3& rhs) const;

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator+(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Addition assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3& operator+=(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator-(const Matrix3x3& rhs) const;

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator-(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Subtraction assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3& operator-=(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator/(const Matrix3x3& rhs) const;

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator/(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Division assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3& operator/=(const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix3x3 operator-();

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The first value to multiply.</param>
     * <param name="rhs">   The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Matrix3x3 operator*(double scalar, const Matrix3x3& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="lhs">The first value to multiply.</param>
     * <param name="rhs">The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector3D operator*(const Matrix3x3& lhs, const Vector3D& rhs);

protected:
private:
    //[00 01 02]
    //[10 11 12]
    //[20 21 22]

    /**************************************************************************************************
     * <summary>The indicies.</summary>
     **************************************************************************************************/
    std::array<double, 9> _indicies;

};

A2DE_END

#endif