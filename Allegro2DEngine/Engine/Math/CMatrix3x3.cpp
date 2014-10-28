#include "CMatrix3x3.h"

#include "CMatrix2x2.h"

A2DE_BEGIN

Matrix3x3::Matrix3x3() : _indicies() { /* DO NOTHING */ }

Matrix3x3::Matrix3x3(const Matrix3x3& other) : _indicies(other._indicies) { /* DO NOTHING */ }

Matrix3x3::Matrix3x3(double m00, double m01, double m02, double m10, double m11, double m12, double m20, double m21, double m22) : _indicies() {
    _indicies[0] = m00; _indicies[1] = m01; _indicies[2] = m02;
    _indicies[3] = m10; _indicies[4] = m11; _indicies[5] = m12;
    _indicies[6] = m20; _indicies[7] = m21; _indicies[8] = m22;
}

Matrix3x3::Matrix3x3(const Vector3D& row_one, const Vector3D& row_two, const Vector3D& row_three) : _indicies() {
    _indicies[0] = row_one.GetX();   _indicies[1] = row_one.GetY();   _indicies[2] = row_one.GetZ();
    _indicies[3] = row_two.GetX();   _indicies[4] = row_two.GetY();   _indicies[5] = row_two.GetZ();
    _indicies[6] = row_three.GetX(); _indicies[7] = row_three.GetY(); _indicies[8] = row_three.GetZ();
}

Matrix3x3::~Matrix3x3() { /* DO NOTHING */ }

Matrix3x3& Matrix3x3::operator=(const Matrix3x3& rhs) {
    if(this == &rhs) return *this;

    this->_indicies = rhs._indicies;

    return *this;
}

Matrix3x3 Matrix3x3::GetIdentity() {
    return Matrix3x3(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix3x3 Matrix3x3::GetTranslationMatrix(double x, double y) {
    return Matrix3x3(1.0, 0.0, x, 0.0, 1.0, y, 0.0, 0.0, 1.0);
}

a2de::Matrix3x3 Matrix3x3::GetTranslationMatrix(const Vector2D& pos) {
    return GetTranslationMatrix(pos.GetX(), pos.GetY());
}

a2de::Matrix3x3 Matrix3x3::GetRotationMatrix(double angle) {
    return Matrix3x3(std::cos(angle), -1.0 * std::sin(angle), 0.0, std::sin(angle), std::cos(angle), 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix3x3 Matrix3x3::GetScaleMatrix(double scale_x, double scale_y) {
    return Matrix3x3(scale_x, 0.0, 0.0, 0.0, scale_y, 0.0, 0.0, 0.0, 1.0);

}

a2de::Matrix3x3 Matrix3x3::GetScaleMatrix(const Vector2D& scale) {
    return GetScaleMatrix(scale.GetX(), scale.GetY());

}

void Matrix3x3::SetRowOne(const Vector3D& row) {
    _indicies[0] = row.GetX();
    _indicies[1] = row.GetY();
    _indicies[2] = row.GetZ();
}

void Matrix3x3::SetRowTwo(const Vector3D& row) {
    _indicies[3] = row.GetX();
    _indicies[4] = row.GetY();
    _indicies[5] = row.GetZ();
}

void Matrix3x3::SetRowThree(const Vector3D& row) {
    _indicies[6] = row.GetX();
    _indicies[7] = row.GetY();
    _indicies[8] = row.GetZ();
}

a2de::Vector3D Matrix3x3::GetRowOne() const {
    return Vector3D(_indicies[0], _indicies[1], _indicies[2]);
}

a2de::Vector3D Matrix3x3::GetRowOne() {
    return static_cast<const Matrix3x3&>(*this).GetRowOne();
}

a2de::Vector3D Matrix3x3::GetRowTwo() const {
    return Vector3D(_indicies[3], _indicies[4], _indicies[5]);
}

a2de::Vector3D Matrix3x3::GetRowTwo() {
    return static_cast<const Matrix3x3&>(*this).GetRowTwo();
}

a2de::Vector3D Matrix3x3::GetRowThree() const {
    return Vector3D(_indicies[6], _indicies[7], _indicies[8]);
}

a2de::Vector3D Matrix3x3::GetRowThree() {
    return static_cast<const Matrix3x3&>(*this).GetRowThree();
}

a2de::Vector3D Matrix3x3::GetColumnOne() const {
    return Vector3D(_indicies[0], _indicies[3], _indicies[6]);
}

a2de::Vector3D Matrix3x3::GetColumnOne() {
    return static_cast<const Matrix3x3&>(*this).GetColumnOne();
}

a2de::Vector3D Matrix3x3::GetColumnTwo() const {
    return Vector3D(_indicies[1], _indicies[4], _indicies[7]);
}

a2de::Vector3D Matrix3x3::GetColumnTwo() {
    return static_cast<const Matrix3x3&>(*this).GetColumnTwo();
}

a2de::Vector3D Matrix3x3::GetColumnThree() const {
    return Vector3D(_indicies[2], _indicies[5], _indicies[8]);
}

a2de::Vector3D Matrix3x3::GetColumnThree() {
    return static_cast<const Matrix3x3&>(*this).GetColumnThree();
}

void Matrix3x3::SetIndex(unsigned int index, double value) {
    _indicies[index] = value;
}

double Matrix3x3::GetIndex(unsigned int index) const {
    return _indicies[index];
}

double Matrix3x3::GetIndex(unsigned int index) {
    return static_cast<const Matrix3x3&>(*this).GetIndex(index);
}

void Matrix3x3::Transpose() {
    //00 01 02    00 10 20
    //10 11 21    01 11 21
    //20 21 22    02 21 22
    //0  1  2     0  3  6
    //3  4  5     1  4  7
    //6  7  8     2  5  8
    _indicies[0] = _indicies[0];
    _indicies[1] = _indicies[3];
    _indicies[2] = _indicies[6];
    _indicies[3] = _indicies[1];
    _indicies[4] = _indicies[4];
    _indicies[5] = _indicies[7];
    _indicies[6] = _indicies[2];
    _indicies[7] = _indicies[5];
    _indicies[8] = _indicies[8];
}

a2de::Matrix3x3 Matrix3x3::Transpose(const Matrix3x3& mat) {
    return Matrix3x3(mat.GetIndex(0), mat.GetIndex(3), mat.GetIndex(6),
                     mat.GetIndex(1), mat.GetIndex(4), mat.GetIndex(7),
                     mat.GetIndex(2), mat.GetIndex(5), mat.GetIndex(8));
}

void Matrix3x3::Inverse() {
    *this = Matrix3x3::Inverse(*this);
}

a2de::Matrix3x3 Matrix3x3::Inverse(const Matrix3x3& mat) {

    //Minors, Cofactors, Adjugates method.
    //See http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
    
    //[00 01 02] [0 1 2]
    //[10 11 12] [3 4 5]
    //[20 21 22] [6 7 8]

    //Calculate minors
    double m00 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[4], mat._indicies[5], mat._indicies[7], mat._indicies[8]));
    double m01 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[3], mat._indicies[5], mat._indicies[6], mat._indicies[7]));
    double m02 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[3], mat._indicies[4], mat._indicies[6], mat._indicies[7]));

    double m10 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[1], mat._indicies[2], mat._indicies[7], mat._indicies[8]));
    double m11 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[0], mat._indicies[2], mat._indicies[6], mat._indicies[7]));
    double m12 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[0], mat._indicies[1], mat._indicies[6], mat._indicies[7]));

    double m20 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[1], mat._indicies[2], mat._indicies[4], mat._indicies[5]));
    double m21 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[0], mat._indicies[2], mat._indicies[3], mat._indicies[5]));
    double m22 = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[0], mat._indicies[1], mat._indicies[3], mat._indicies[4]));

    Matrix3x3 cofactors(m00, -m01, m02,
                       -m10, m11, -m12,
                        m20, -m21, m22);

    Matrix3x3 adjugate(Matrix3x3::Transpose(cofactors));

    double det_mat = mat.CalculateDeterminant();
    double inv_det = 1.0 / det_mat;

    return inv_det * adjugate;
}

double Matrix3x3::CalculateDeterminant(const Matrix3x3& mat) {
    //a b
    //c d
    //ad - bc
    double a = mat._indicies[0];
    double det_not_a = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[4], mat._indicies[5], mat._indicies[7], mat._indicies[8]));

    double b = mat._indicies[1];
    double det_not_b = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[3], mat._indicies[5], mat._indicies[6], mat._indicies[8]));

    double c = mat._indicies[2];
    double det_not_c = Matrix2x2::CalculateDeterminant(Matrix2x2(mat._indicies[3], mat._indicies[4], mat._indicies[6], mat._indicies[7]));

    return (a * det_not_a) - (b * det_not_b) + (c * det_not_c);
}

double Matrix3x3::CalculateDeterminant() const {
    return Matrix3x3::CalculateDeterminant(*this);
}

double Matrix3x3::CalculateDeterminant() {
    return static_cast<const Matrix3x3&>(*this).CalculateDeterminant();
}

double Matrix3x3::CalculateTrace() const {
    //0 1 2
    //3 4 5
    //6 7 8
    //0 + 4 + 8
    return (_indicies[0] + _indicies[4] + _indicies[8]);
}

double Matrix3x3::CalculateTrace() {
    return static_cast<const Matrix3x3&>(*this).CalculateTrace();
}

bool Matrix3x3::operator==(const Matrix3x3& rhs) const {
    return (   a2de::Math::IsEqual(this->_indicies[0], rhs._indicies[0]) && a2de::Math::IsEqual(this->_indicies[1], rhs._indicies[1]) && a2de::Math::IsEqual(this->_indicies[2], rhs._indicies[2])
            && a2de::Math::IsEqual(this->_indicies[3], rhs._indicies[3]) && a2de::Math::IsEqual(this->_indicies[4], rhs._indicies[4]) && a2de::Math::IsEqual(this->_indicies[5], rhs._indicies[5])
            && a2de::Math::IsEqual(this->_indicies[6], rhs._indicies[6]) && a2de::Math::IsEqual(this->_indicies[7], rhs._indicies[7]) && a2de::Math::IsEqual(this->_indicies[8], rhs._indicies[8]));
}

bool Matrix3x3::operator==(const Matrix3x3& rhs) {
    return static_cast<const Matrix3x3&>(*this).operator==(rhs);
}

bool Matrix3x3::operator!=(const Matrix3x3& rhs) const {
    return !(*this == rhs);
}

bool Matrix3x3::operator!=(const Matrix3x3& rhs) {
    return static_cast<const Matrix3x3&>(*this).operator!=(rhs);
}

a2de::Matrix3x3 Matrix3x3::operator*(const Matrix3x3& rhs) {

    a2de::Vector3D r1(this->GetRowOne());
    a2de::Vector3D r2(this->GetRowTwo());
    a2de::Vector3D r3(this->GetRowThree());

    a2de::Vector3D c1(rhs.GetColumnOne());
    a2de::Vector3D c2(rhs.GetColumnTwo());
    a2de::Vector3D c3(rhs.GetColumnThree());

    return Matrix3x3(a2de::Vector3D::DotProduct(r1, c1), a2de::Vector3D::DotProduct(r1, c2), a2de::Vector3D::DotProduct(r1, c3),
                     a2de::Vector3D::DotProduct(r2, c1), a2de::Vector3D::DotProduct(r2, c2), a2de::Vector3D::DotProduct(r2, c3),
                     a2de::Vector3D::DotProduct(r3, c1), a2de::Vector3D::DotProduct(r3, c2), a2de::Vector3D::DotProduct(r3, c3));
}

a2de::Matrix3x3 Matrix3x3::operator*(double scalar) {
    return Matrix3x3(scalar * _indicies[0], scalar * _indicies[1], scalar * _indicies[2],
                     scalar * _indicies[3], scalar * _indicies[4], scalar * _indicies[5],
                     scalar * _indicies[6], scalar * _indicies[7], scalar * _indicies[8]);
}

a2de::Vector3D Matrix3x3::operator*(const Vector3D& rhs) const {
    return Vector3D(a2de::Vector3D::DotProduct(this->GetRowOne(),   rhs),
                    a2de::Vector3D::DotProduct(this->GetRowTwo(),   rhs),
                    a2de::Vector3D::DotProduct(this->GetRowThree(), rhs));
}

a2de::Vector3D Matrix3x3::operator*(const Vector3D& rhs) {
    return static_cast<const Matrix3x3&>(*this).operator*(rhs);
}

const double * const Matrix3x3::operator*() const {
    return &_indicies[0];
}

Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& rhs) {
    if(this == &rhs) return *this;

    _indicies[0] = a2de::Vector3D::DotProduct(this->GetRowOne(), rhs.GetColumnOne());
    _indicies[1] = a2de::Vector3D::DotProduct(this->GetRowOne(), rhs.GetColumnTwo());
    _indicies[2] = a2de::Vector3D::DotProduct(this->GetRowOne(), rhs.GetColumnThree());

    _indicies[3] = a2de::Vector3D::DotProduct(this->GetRowTwo(), rhs.GetColumnOne());
    _indicies[4] = a2de::Vector3D::DotProduct(this->GetRowTwo(), rhs.GetColumnTwo());
    _indicies[5] = a2de::Vector3D::DotProduct(this->GetRowTwo(), rhs.GetColumnThree());

    _indicies[6] = a2de::Vector3D::DotProduct(this->GetRowThree(), rhs.GetColumnOne());
    _indicies[7] = a2de::Vector3D::DotProduct(this->GetRowThree(), rhs.GetColumnTwo());
    _indicies[8] = a2de::Vector3D::DotProduct(this->GetRowThree(), rhs.GetColumnThree());


    return *this;
}

Matrix3x3& Matrix3x3::operator*=(double scalar) {
    _indicies[0] *= scalar;
    _indicies[1] *= scalar;
    _indicies[2] *= scalar;
    _indicies[3] *= scalar;
    _indicies[4] *= scalar;
    _indicies[5] *= scalar;
    _indicies[6] *= scalar;
    _indicies[7] *= scalar;
    _indicies[8] *= scalar;
    return *this;
}

a2de::Matrix3x3 Matrix3x3::operator+(const Matrix3x3& rhs) const {
    return Matrix3x3(this->_indicies[0] + rhs._indicies[0], this->_indicies[1] + rhs._indicies[1], this->_indicies[2] + rhs._indicies[2],
        this->_indicies[3] + rhs._indicies[3], this->_indicies[4] + rhs._indicies[4], this->_indicies[5] + rhs._indicies[5],
        this->_indicies[6] + rhs._indicies[6], this->_indicies[7] + rhs._indicies[7], this->_indicies[8] + rhs._indicies[8]);
}

a2de::Matrix3x3 Matrix3x3::operator+(const Matrix3x3& rhs) {
    return static_cast<const Matrix3x3&>(*this).operator+(rhs);
}

Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& rhs) {
    if(this == &rhs) return *this;

    this->_indicies[0] += rhs._indicies[0];
    this->_indicies[1] += rhs._indicies[1];
    this->_indicies[2] += rhs._indicies[2];
    this->_indicies[3] += rhs._indicies[3];
    this->_indicies[4] += rhs._indicies[4];
    this->_indicies[5] += rhs._indicies[5];
    this->_indicies[6] += rhs._indicies[6];
    this->_indicies[7] += rhs._indicies[7];
    this->_indicies[8] += rhs._indicies[8];

    return *this;
}

a2de::Matrix3x3 Matrix3x3::operator-(const Matrix3x3& rhs) const {
    return Matrix3x3(this->_indicies[0] - rhs._indicies[0], this->_indicies[1] - rhs._indicies[1], this->_indicies[2] - rhs._indicies[2],
        this->_indicies[3] - rhs._indicies[3], this->_indicies[4] - rhs._indicies[4], this->_indicies[5] - rhs._indicies[5],
        this->_indicies[6] - rhs._indicies[6], this->_indicies[7] - rhs._indicies[7], this->_indicies[8] - rhs._indicies[8]);
}

a2de::Matrix3x3 Matrix3x3::operator-(const Matrix3x3& rhs) {
    return static_cast<const Matrix3x3&>(*this).operator-(rhs);
}

Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& rhs) {

    this->_indicies[0] -= rhs._indicies[0];
    this->_indicies[1] -= rhs._indicies[1];
    this->_indicies[2] -= rhs._indicies[2];
    this->_indicies[3] -= rhs._indicies[3];
    this->_indicies[4] -= rhs._indicies[4];
    this->_indicies[5] -= rhs._indicies[5];
    this->_indicies[6] -= rhs._indicies[6];
    this->_indicies[7] -= rhs._indicies[7];
    this->_indicies[8] -= rhs._indicies[8];

    return *this;
}

a2de::Matrix3x3 Matrix3x3::operator/(const Matrix3x3& rhs) const {
    Matrix3x3 result(*this);
    result *= a2de::Matrix3x3::Inverse(rhs);
    return result;
}

a2de::Matrix3x3 Matrix3x3::operator/(const Matrix3x3& rhs) {
    return static_cast<const Matrix3x3&>(*this).operator/(rhs);
}

Matrix3x3& Matrix3x3::operator/=(const Matrix3x3& rhs) {

    Matrix3x3 inv(a2de::Matrix3x3::Inverse(rhs));
    Matrix3x3 result = (*this * inv);

    this->_indicies = result._indicies;

    return *this;
}

Matrix3x3 Matrix3x3::operator-() {
    return Matrix3x3(-this->GetRowOne(), -this->GetRowTwo(), -this->GetRowThree());
}

Matrix3x3 operator*(double scalar, const Matrix3x3& rhs) {
    return Matrix3x3(scalar * rhs._indicies[0], scalar * rhs._indicies[1], scalar * rhs._indicies[2],
                     scalar * rhs._indicies[3], scalar * rhs._indicies[4], scalar * rhs._indicies[5],
                     scalar * rhs._indicies[6], scalar * rhs._indicies[7], scalar * rhs._indicies[8]);
}

a2de::Vector3D operator*(const Matrix3x3& lhs, const Vector3D& rhs) {
    return Vector3D(a2de::Vector3D::DotProduct(lhs.GetRowOne(), rhs),
                    a2de::Vector3D::DotProduct(lhs.GetRowTwo(), rhs),
                    a2de::Vector3D::DotProduct(lhs.GetRowThree(), rhs));
}


A2DE_END