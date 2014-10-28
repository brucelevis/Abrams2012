#include "CMatrix2x2.h"

A2DE_BEGIN

Matrix2x2::Matrix2x2() : _indicies() { /* DO NOTHING */ }

Matrix2x2::Matrix2x2(const Matrix2x2& other) : _indicies(other._indicies) { /* DO NOTHING */ }

Matrix2x2::Matrix2x2(double m00, double m01, double m10, double m11) : _indicies() { _indicies[0] = m00; _indicies[1] = m01; _indicies[2] = m10; _indicies[3] = m11; }

Matrix2x2::Matrix2x2(const Vector2D& row_one, const Vector2D& row_two) : _indicies() { _indicies[0] = row_one.GetX(); _indicies[1] = row_one.GetY(); _indicies[2] = row_two.GetX(); _indicies[3] = row_two.GetY(); }

Matrix2x2::~Matrix2x2() { /* DO NOTHING */ }

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& rhs) {
    if(this == &rhs) return *this;

    this->_indicies = rhs._indicies;

    return *this;
}

Matrix2x2 Matrix2x2::GetIdentity() {
    return Matrix2x2(1.0, 0.0, 0.0, 1.0);
}

void Matrix2x2::SetRowOne(const Vector2D& row) {
    _indicies[0] = row.GetX();
    _indicies[1] = row.GetY();
}
void Matrix2x2::SetRowTwo(const Vector2D& row) {
    _indicies[2] = row.GetX();
    _indicies[3] = row.GetY();
}

a2de::Vector2D Matrix2x2::GetRowOne() const {
    return Vector2D(_indicies[0], _indicies[1]);
}

a2de::Vector2D Matrix2x2::GetRowOne() {
    return static_cast<const Matrix2x2&>(*this).GetRowOne();
}

a2de::Vector2D Matrix2x2::GetRowTwo() const {
    return Vector2D(_indicies[2], _indicies[3]);
}

a2de::Vector2D Matrix2x2::GetRowTwo() {
    return static_cast<const Matrix2x2&>(*this).GetRowTwo();
}

a2de::Vector2D Matrix2x2::GetColumnOne() const {
    return Vector2D(_indicies[0], _indicies[2]);
}

a2de::Vector2D Matrix2x2::GetColumnOne() {
    return static_cast<const Matrix2x2&>(*this).GetColumnOne();
}

a2de::Vector2D Matrix2x2::GetColumnTwo() const {
    return Vector2D(_indicies[1], _indicies[3]);
}

a2de::Vector2D Matrix2x2::GetColumnTwo() {
    return static_cast<const Matrix2x2&>(*this).GetColumnTwo();
}

void Matrix2x2::SetIndex(unsigned int index, double value) {
    _indicies[index] = value;
}

double Matrix2x2::GetIndex(unsigned int index) const {
    return _indicies[index];
}

double Matrix2x2::GetIndex(unsigned int index) {
    return static_cast<const Matrix2x2&>(*this).GetIndex(index);
}

void Matrix2x2::Transpose() {
    //00 01   00 10
    //10 11   01 11
    //0  1    0  2
    //2  3    1  3
    _indicies[0] = _indicies[0];
    _indicies[1] = _indicies[2];
    _indicies[2] = _indicies[1];
    _indicies[3] = _indicies[3];
}

a2de::Matrix2x2 Matrix2x2::Transpose(const Matrix2x2& mat) {
    return Matrix2x2(mat.GetIndex(0), mat.GetIndex(2),
                     mat.GetIndex(1), mat.GetIndex(3));
}

void Matrix2x2::Inverse() {
    double det = this->CalculateDeterminant();
    if(a2de::Math::IsEqual(det, 0.0)) return;
    double inv_det = 1.0 / det;
    _indicies[0] = inv_det * _indicies[3];
    _indicies[1] = inv_det * -_indicies[1];
    _indicies[2] = inv_det * -_indicies[2];
    _indicies[3] = inv_det * _indicies[0];
}

a2de::Matrix2x2 Matrix2x2::Inverse(const Matrix2x2& mat) {
    return Matrix2x2((1.0 / mat.CalculateDeterminant()) * Matrix2x2(mat.GetIndex(3), -mat.GetIndex(1), -mat.GetIndex(2), mat.GetIndex(0)));
}

double Matrix2x2::CalculateDeterminant(const Matrix2x2& mat) {
    //a b
    //c d
    //ad - bc
    return (mat._indicies[0] * mat._indicies[3] - mat._indicies[1] * mat._indicies[2]);
}

double Matrix2x2::CalculateDeterminant() const {
    return CalculateDeterminant(*this);
}

double Matrix2x2::CalculateDeterminant() {
    return static_cast<const Matrix2x2&>(*this).CalculateDeterminant();
}

double Matrix2x2::CalculateTrace() const {
    //a b
    //c d
    //a + d
    return (_indicies[0] + _indicies[3]);
}

double Matrix2x2::CalculateTrace() {
    return static_cast<const Matrix2x2&>(*this).CalculateTrace();
}

bool Matrix2x2::operator==(const Matrix2x2& rhs) const {
    return (this->_indicies[0] == rhs._indicies[0] && this->_indicies[1] == rhs._indicies[1] && this->_indicies[2] == rhs._indicies[2] && this->_indicies[3] == rhs._indicies[3]);
}

bool Matrix2x2::operator==(const Matrix2x2& rhs) {
    return static_cast<const Matrix2x2&>(*this).operator==(rhs);
}

bool Matrix2x2::operator!=(const Matrix2x2& rhs) const {
    return !(*this == rhs);
}

bool Matrix2x2::operator!=(const Matrix2x2& rhs) {
    return static_cast<const Matrix2x2&>(*this).operator!=(rhs);
}

a2de::Matrix2x2 Matrix2x2::operator*(const Matrix2x2& rhs) {
    return Matrix2x2(this->_indicies[0] * rhs._indicies[0] + this->_indicies[1] * rhs._indicies[2], this->_indicies[0] * rhs._indicies[1] + this->_indicies[1] * rhs._indicies[3],
                     this->_indicies[2] * rhs._indicies[0] + this->_indicies[3] * rhs._indicies[2], this->_indicies[2] * rhs._indicies[1] + this->_indicies[3] * rhs._indicies[3]);
}

a2de::Matrix2x2 Matrix2x2::operator*(double scalar) {
    return Matrix2x2(scalar * _indicies[0], scalar * _indicies[1], scalar * _indicies[2], scalar * _indicies[3]);
}

const double * const Matrix2x2::operator*() const {
    return &_indicies[0];
}

//
//a2de::Vector2D Matrix2x2::operator*(const Vector2D& rhs) {
//    return Vector2D(a2de::Vector2D::DotProduct(this->GetRowOne(), rhs),
//        a2de::Vector2D::DotProduct(this->GetRowTwo(), rhs));
//}

Matrix2x2& Matrix2x2::operator*=(const Matrix2x2& rhs) {
    if(this == &rhs) return *this;

    _indicies[0] = this->_indicies[0] * rhs._indicies[0] + this->_indicies[1] * rhs._indicies[2];
    _indicies[1] = this->_indicies[0] * rhs._indicies[1] + this->_indicies[1] * rhs._indicies[3];
    _indicies[2] = this->_indicies[2] * rhs._indicies[0] + this->_indicies[3] * rhs._indicies[2];
    _indicies[3] = this->_indicies[2] * rhs._indicies[1] + this->_indicies[3] * rhs._indicies[3];

    return *this;
}

Matrix2x2& Matrix2x2::operator*=(double scalar) {
    _indicies[0] *= scalar;
    _indicies[1] *= scalar;
    _indicies[2] *= scalar;
    _indicies[3] *= scalar;
    return *this;
}

a2de::Matrix2x2 Matrix2x2::operator+(const Matrix2x2& rhs) {
    return Matrix2x2(this->_indicies[0] + rhs._indicies[0], this->_indicies[1] + rhs._indicies[1], this->_indicies[2] + rhs._indicies[2], this->_indicies[3] + rhs._indicies[3]);
}

Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& rhs) {
    if(this == &rhs) return *this;

    this->_indicies[0] += rhs._indicies[0];
    this->_indicies[1] += rhs._indicies[1];
    this->_indicies[2] += rhs._indicies[2];
    this->_indicies[3] += rhs._indicies[3];

    return *this;
}

a2de::Matrix2x2 Matrix2x2::operator-(const Matrix2x2& rhs) {
    return Matrix2x2(this->GetIndex(0) - rhs.GetIndex(0), this->GetIndex(1) - rhs.GetIndex(1), this->GetIndex(2) - rhs.GetIndex(2), this->GetIndex(3) - rhs.GetIndex(3));
}

Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& rhs) {

    this->_indicies[0] -= rhs._indicies[0];
    this->_indicies[1] -= rhs._indicies[1];
    this->_indicies[2] -= rhs._indicies[2];
    this->_indicies[3] -= rhs._indicies[3];

    return *this;
}

a2de::Matrix2x2 Matrix2x2::operator/(const Matrix2x2& rhs) {
    return Matrix2x2((*this) * a2de::Matrix2x2::Inverse(rhs));
}

Matrix2x2& Matrix2x2::operator/=(const Matrix2x2& rhs) {

    this->_indicies[0] /= rhs._indicies[0];
    this->_indicies[1] /= rhs._indicies[1];
    this->_indicies[2] /= rhs._indicies[2];
    this->_indicies[3] /= rhs._indicies[3];

    return *this;
}

Matrix2x2 Matrix2x2::operator-() {
    return Matrix2x2(-this->GetRowOne(), -this->GetRowTwo());
}

a2de::Vector2D Matrix2x2::GetTranslationMatrix(double x, double y) {
    return Vector2D(x, y);
}

a2de::Matrix2x2 Matrix2x2::GetRotationMatrix(double angle) {
    return Matrix2x2(std::cos(angle), -std::sin(angle), std::sin(angle), std::cos(angle));
}

a2de::Matrix2x2 Matrix2x2::GetScaleMatrix(double scale_x, double scale_y) {
    return Matrix2x2(scale_x, 0.0, 0.0, scale_y);
}

Matrix2x2 operator*(double scalar, const Matrix2x2& rhs) {
    return Matrix2x2(scalar * rhs.GetIndex(0), scalar * rhs.GetIndex(1), scalar * rhs.GetIndex(2), scalar * rhs.GetIndex(3));
}

Vector2D operator*(const a2de::Matrix2x2& lhs, const Vector2D& rhs) {

    return Vector2D(a2de::Vector2D::DotProduct(lhs.GetRowOne(), rhs),
        a2de::Vector2D::DotProduct(lhs.GetRowTwo(), rhs));

}


A2DE_END