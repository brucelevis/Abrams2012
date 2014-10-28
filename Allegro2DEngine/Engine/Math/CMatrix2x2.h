#ifndef A2DE_CMATRIX2X2_H
#define A2DE_CMATRIX2X2_H

#include "../a2de_vals.h"
#include "CVector2D.h"
#include <array>

A2DE_BEGIN

/**************************************************************************************************
 * <summary>A 2x2 matrix.</summary>
 * <remarks>Casey Ugone, 10/25/2014.</remarks>
 **************************************************************************************************/
class Matrix2x2 {
public:

    /**************************************************************************************************
     * <summary>Default constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    Matrix2x2();

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="m00">First row, first column.</param>
     * <param name="m01">First row, second column.</param>
     * <param name="m10">Second row, first column.</param>
     * <param name="m11">Second row, second column.</param>
     **************************************************************************************************/
    Matrix2x2(double m00, double m01, double m10, double m11);

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row_one">Row one.</param>
     * <param name="row_two">Row two.</param>
     **************************************************************************************************/
    Matrix2x2(const Vector2D& row_one, const Vector2D& row_two);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="other">The other matrix.</param>
     **************************************************************************************************/
    Matrix2x2(const Matrix2x2& other);

    /**************************************************************************************************
     * <summary>Destructor.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    ~Matrix2x2();

    /**************************************************************************************************
     * <summary>Gets the identity matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The identity matrix.</returns>
     **************************************************************************************************/
    static Matrix2x2 GetIdentity();

    /**************************************************************************************************
     * <summary>Gets translation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="x">The x coordinate.</param>
     * <param name="y">The y coordinate.</param>
     * <returns>The translation matrix.</returns>
     **************************************************************************************************/
    static Vector2D GetTranslationMatrix(double x, double y);

    /**************************************************************************************************
     * <summary>Gets rotation matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="angle">The angle in radians.</param>
     * <returns>The rotation matrix.</returns>
     **************************************************************************************************/
    static Matrix2x2 GetRotationMatrix(double angle);

    /**************************************************************************************************
     * <summary>Gets scale matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scale_x">The scale x coordinate.</param>
     * <param name="scale_y">The scale y coordinate.</param>
     * <returns>The scale matrix.</returns>
     **************************************************************************************************/
    static Matrix2x2 GetScaleMatrix(double scale_x, double scale_y);

    /**************************************************************************************************
     * <summary>Sets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowOne(const Vector2D& row);

    /**************************************************************************************************
     * <summary>Sets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="row">The row.</param>
     **************************************************************************************************/
    void SetRowTwo(const Vector2D& row);

    /**************************************************************************************************
     * <summary>Gets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row one.</returns>
     **************************************************************************************************/
    Vector2D GetRowOne() const;

    /**************************************************************************************************
     * <summary>Gets row one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row one.</returns>
     **************************************************************************************************/
    Vector2D GetRowOne();

    /**************************************************************************************************
     * <summary>Gets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row two.</returns>
     **************************************************************************************************/
    Vector2D GetRowTwo() const;

    /**************************************************************************************************
     * <summary>Gets row two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The row two.</returns>
     **************************************************************************************************/
    Vector2D GetRowTwo();

    /**************************************************************************************************
     * <summary>Gets column one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column one.</returns>
     **************************************************************************************************/
    Vector2D GetColumnOne() const;

    /**************************************************************************************************
     * <summary>Gets column one.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column one.</returns>
     **************************************************************************************************/
    Vector2D GetColumnOne();

    /**************************************************************************************************
     * <summary>Gets column two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column two.</returns>
     **************************************************************************************************/
    Vector2D GetColumnTwo() const;

    /**************************************************************************************************
     * <summary>Gets column two.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The column two.</returns>
     **************************************************************************************************/
    Vector2D GetColumnTwo();

    /**************************************************************************************************
     * <summary>Sets the element at the specified index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the element.</param>
     * <param name="value">The value of the element.</param>
     **************************************************************************************************/
    void SetIndex(unsigned int index, double value);

    /**************************************************************************************************
     * <summary>Gets the element at the specified index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the element.</param>
     * <returns>The element.</returns>
     **************************************************************************************************/
    double GetIndex(unsigned int index) const;

    /**************************************************************************************************
     * <summary>Gets the element at the specified index.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="index">Zero-based index of the element.</param>
     * <returns>The element.</returns>
     **************************************************************************************************/
    double GetIndex(unsigned int index);

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this object.</returns>
     **************************************************************************************************/
    Matrix2x2& operator=(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Transposes this matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Transpose();

    /**************************************************************************************************
     * <summary>Inverses this matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     **************************************************************************************************/
    void Inverse();

    /**************************************************************************************************
     * <summary>Calculates the determinant.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="mat">The matrix.</param>
     * <returns>The calculated determinant.</returns>
     **************************************************************************************************/
    static double CalculateDeterminant(const Matrix2x2& mat);

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
     * <returns>A Matrix2x2.</returns>
     **************************************************************************************************/
    static Matrix2x2 Transpose(const Matrix2x2& mat);

    /**************************************************************************************************
     * <summary>Inverses the given matrix.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="mat">The matrix.</param>
     * <returns>A Matrix2x2.</returns>
     **************************************************************************************************/
    static Matrix2x2 Inverse(const Matrix2x2& mat);

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Matrix2x2& rhs) const;

    /**************************************************************************************************
     * <summary>Equality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are considered equivalent.</returns>
     **************************************************************************************************/
    bool operator==(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Matrix2x2& rhs) const;

    /**************************************************************************************************
     * <summary>Inequality operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>true if the parameters are not considered equivalent.</returns>
     **************************************************************************************************/
    bool operator!=(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Indirection operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    const double * const operator*() const;

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2 operator*(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2 operator*(double scalar);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2& operator*=(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Multiplication assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The scalar.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2& operator*=(double scalar);

    /**************************************************************************************************
     * <summary>Addition operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2 operator+(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Addition assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2& operator+=(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Negation operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2 operator-(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Subtraction assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2& operator-=(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Division operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2 operator/(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Division assignment operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2& operator/=(const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Subtraction operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    Matrix2x2 operator-();

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="scalar">The first value to multiply.</param>
     * <param name="rhs">   The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Matrix2x2 operator*(double scalar, const Matrix2x2& rhs);

    /**************************************************************************************************
     * <summary>Multiplication operator.</summary>
     * <remarks>Casey Ugone, 10/25/2014.</remarks>
     * <param name="lhs">The first value to multiply.</param>
     * <param name="rhs">The second value to multiply.</param>
     * <returns>The result of the operation.</returns>
     **************************************************************************************************/
    friend Vector2D operator*(const Matrix2x2& lhs, const Vector2D& rhs);

protected:
private:
    //[00 01]
    //[10 11]

    /**************************************************************************************************
     * <summary>The indicies.</summary>
     **************************************************************************************************/
    std::array<double, 4> _indicies;

};

A2DE_END

#endif