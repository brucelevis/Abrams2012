#include "CMatrix4x4.h"

#include "CMatrix3x3.h"

#include "CVector3D.h"
#include "CVector4D.h"

A2DE_BEGIN


Matrix4x4::Matrix4x4() : _indicies() { /* DO NOTHING */ }

Matrix4x4::Matrix4x4(double m00, double m01, double m02, double m03, double m10, double m11, double m12, double m13, double m20, double m21, double m22, double m23, double m30, double m31, double m32, double m33) {
    _indicies[0] =  m00;  _indicies[1] = m01;  _indicies[2] =  m02;  _indicies[3] = m03;
    _indicies[4] =  m10;  _indicies[5] = m11;  _indicies[6] =  m12;  _indicies[7] = m13;
    _indicies[8] =  m20;  _indicies[9] = m21;  _indicies[10] = m22; _indicies[11] = m23;
    _indicies[12] = m30; _indicies[13] = m31;  _indicies[14] = m32; _indicies[15] = m33;
}

Matrix4x4::Matrix4x4(const Vector4D& row_one, const Vector4D& row_two, const Vector4D& row_three, const Vector4D& row_four) {
    _indicies[0]  = row_one.GetX();   _indicies[1]  = row_one.GetY();   _indicies[2]  = row_one.GetZ();   _indicies[3]  = row_one.GetW(); 
    _indicies[4]  = row_two.GetX();   _indicies[5]  = row_two.GetY();   _indicies[6]  = row_two.GetZ();   _indicies[7]  = row_two.GetW(); 
    _indicies[8]  = row_three.GetX(); _indicies[9]  = row_three.GetY(); _indicies[10] = row_three.GetZ(); _indicies[11] = row_three.GetW(); 
    _indicies[12] = row_four.GetX();  _indicies[13] = row_four.GetY();  _indicies[14] = row_four.GetZ();  _indicies[15] = row_four.GetW(); 
}

Matrix4x4::Matrix4x4(const Matrix4x4& other) : _indicies(other._indicies) { /* DO NOTHING */ }

Matrix4x4::~Matrix4x4() { /* DO NOTHING */ }

a2de::Matrix4x4 Matrix4x4::GetIdentity() {
    return Matrix4x4(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix4x4 Matrix4x4::GetTranslationMatrix(double x, double y, double z) {
    return Matrix4x4(1.0, 0.0, 0.0, x, 0.0, 1.0, 0.0, y, 0.0, 0.0, 1.0, z, 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix4x4 Matrix4x4::GetTranslationMatrix(const a2de::Vector3D& position) {
    return GetTranslationMatrix(position.GetX(), position.GetY(), position.GetZ());
}

a2de::Matrix4x4 Matrix4x4::GetRotationMatrix(const a2de::Vector3D& rotations) {
    return GetRotationMatrix(rotations.GetX(), rotations.GetY(), rotations.GetZ());
}

a2de::Matrix4x4 Matrix4x4::GetRotationMatrix(double Xangle, double Yangle, double Zangle) {
    return Get3DZRotationMatrix(Zangle) * Get3DXRotationMatrix(Xangle) * Get3DYRotationMatrix(Yangle);
}

a2de::Matrix4x4 Matrix4x4::Get2DRotationMatrix(double angle) {
    return Get3DZRotationMatrix(angle);
}

a2de::Matrix4x4 Matrix4x4::Get3DXRotationMatrix(double angle) {
    return Matrix4x4(1.0, 0.0, 0.0, 0.0, 0.0, std::cos(angle), -std::sin(angle), 0.0, 0.0, std::sin(angle), std::cos(angle), 0.0, 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix4x4 Matrix4x4::Get3DYRotationMatrix(double angle) {
    return Matrix4x4(std::cos(angle), 0.0, std::sin(angle), 0.0, 0.0, 1.0, 0.0, 0.0, -std::sin(angle), 0.0, std::cos(angle), 0.0, 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix4x4 Matrix4x4::Get3DZRotationMatrix(double angle) {
    return Matrix4x4(std::cos(angle), -std::sin(angle), 0.0, 0.0, std::sin(angle), std::cos(angle), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix4x4 Matrix4x4::GetScaleMatrix(double scale_x, double scale_y, double scale_z) {
    return Matrix4x4(scale_x, 0.0, 0.0, 0.0, 0.0, scale_y, 0.0, 0.0, 0.0, 0.0, scale_z, 0.0, 0.0, 0.0, 0.0, 1.0);
}

a2de::Matrix4x4 Matrix4x4::GetScaleMatrix(const a2de::Vector3D& scale) {
    return GetScaleMatrix(scale.GetX(), scale.GetY(), scale.GetZ());
}

void Matrix4x4::SetRowOne(const Vector4D& row) {
    _indicies[0] = row.GetX();
    _indicies[1] = row.GetY();
    _indicies[2] = row.GetZ();
    _indicies[3] = row.GetW();
}

void Matrix4x4::SetRowTwo(const Vector4D& row) {
    _indicies[4] = row.GetX();
    _indicies[5] = row.GetY();
    _indicies[6] = row.GetZ();
    _indicies[7] = row.GetW();
}

void Matrix4x4::SetRowThree(const Vector4D& row) {
    _indicies[8]  = row.GetX();
    _indicies[9]  = row.GetY();
    _indicies[10] = row.GetZ();
    _indicies[11] = row.GetW();
}

void Matrix4x4::SetRowFour(const Vector4D& row) {
    _indicies[12] = row.GetX();
    _indicies[13] = row.GetY();
    _indicies[14] = row.GetZ();
    _indicies[15] = row.GetW();
}

a2de::Vector4D Matrix4x4::GetRowOne() const {
    return Vector4D(_indicies[0], _indicies[1], _indicies[2], _indicies[3]);
}

a2de::Vector4D Matrix4x4::GetRowOne() {
    return static_cast<const Matrix4x4&>(*this).GetRowOne();
}

a2de::Vector4D Matrix4x4::GetRowTwo() const {
    return Vector4D(_indicies[4], _indicies[5], _indicies[6], _indicies[7]);
}

a2de::Vector4D Matrix4x4::GetRowTwo() {
    return static_cast<const Matrix4x4&>(*this).GetRowTwo();
}

a2de::Vector4D Matrix4x4::GetRowThree() const {
    return Vector4D(_indicies[8], _indicies[9], _indicies[10], _indicies[11]);
}

a2de::Vector4D Matrix4x4::GetRowThree() {
    return static_cast<const Matrix4x4&>(*this).GetRowThree();
}

a2de::Vector4D Matrix4x4::GetRowFour() const {
    return Vector4D(_indicies[12], _indicies[13], _indicies[14], _indicies[15]);
}

a2de::Vector4D Matrix4x4::GetRowFour() {
    return static_cast<const Matrix4x4&>(*this).GetRowFour();
}

a2de::Vector4D Matrix4x4::GetColumnOne() const {
    return Vector4D(_indicies[0], _indicies[4], _indicies[8], _indicies[12]);
}

a2de::Vector4D Matrix4x4::GetColumnOne() {
    return static_cast<const Matrix4x4&>(*this).GetColumnOne();
}

a2de::Vector4D Matrix4x4::GetColumnTwo() const {
    return Vector4D(_indicies[1], _indicies[5], _indicies[9], _indicies[13]);
}

a2de::Vector4D Matrix4x4::GetColumnTwo() {
    return static_cast<const Matrix4x4&>(*this).GetColumnTwo();
}

a2de::Vector4D Matrix4x4::GetColumnThree() const {
    return Vector4D(_indicies[2], _indicies[6], _indicies[10], _indicies[14]);
}

a2de::Vector4D Matrix4x4::GetColumnThree() {
    return static_cast<const Matrix4x4&>(*this).GetColumnThree();
}

a2de::Vector4D Matrix4x4::GetColumnFour() const {
    return Vector4D(_indicies[3], _indicies[7], _indicies[11], _indicies[15]);
}

a2de::Vector4D Matrix4x4::GetColumnFour() {
    return static_cast<const Matrix4x4&>(*this).GetColumnFour();
}

void Matrix4x4::SetIndex(unsigned int index, double value) {
    _indicies[index] = value;
}

double Matrix4x4::GetIndex(unsigned int index) const {
    return _indicies[index];
}

double Matrix4x4::GetIndex(unsigned int index) {
    return static_cast<const Matrix4x4&>(*this).GetIndex(index);
}

Matrix4x4& Matrix4x4::operator=(const Matrix4x4& rhs) {
    if(this == &rhs) return *this;

    this->_indicies = rhs._indicies;

    return *this;
}

void Matrix4x4::Transpose() {

    //[00 01 02 03] [0   1  2  3]
    //[10 11 12 13] [4   5  6  7]
    //[20 21 22 23] [8   9 10 11]
    //[30 31 32 33] [12 13 14 15]
    //
    //[00 10 20 30] [0 4 8  12]
    //[01 11 21 31] [1 5 9  13]
    //[02 12 22 32] [2 6 10 14]
    //[03 13 23 33] [3 7 11 15]

    _indicies[0] = _indicies[0];
    _indicies[1] = _indicies[4];
    _indicies[2] = _indicies[8];
    _indicies[3] = _indicies[12];

    _indicies[4] = _indicies[1];
    _indicies[5] = _indicies[5];
    _indicies[6] = _indicies[9];
    _indicies[7] = _indicies[13];

    _indicies[8] = _indicies[2];
    _indicies[9] = _indicies[6];
    _indicies[10] = _indicies[10];
    _indicies[11] = _indicies[14];

    _indicies[12] = _indicies[3];
    _indicies[13] = _indicies[7];
    _indicies[14] = _indicies[11];
    _indicies[15] = _indicies[15];

}

a2de::Matrix4x4 Matrix4x4::Transpose(const Matrix4x4& mat) {
    return Matrix4x4(mat._indicies[0], mat._indicies[4], mat._indicies[8], mat._indicies[12],
                     mat._indicies[1], mat._indicies[5], mat._indicies[9], mat._indicies[13],
                     mat._indicies[2], mat._indicies[6], mat._indicies[10], mat._indicies[14],
                     mat._indicies[3], mat._indicies[7], mat._indicies[11], mat._indicies[15]);
}

void Matrix4x4::Inverse() {
    *this = Matrix4x4::Inverse(*this);
}

a2de::Matrix4x4 Matrix4x4::Inverse(const Matrix4x4& mat) {

    //Minors, Cofactors, Adjugates method.
    //See http://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html

    //[00 01 02 03] [0   1  2  3]
    //[10 11 12 13] [4   5  6  7]
    //[20 21 22 23] [8   9 10 11]
    //[30 31 32 33] [12 13 14 15]

    //Calculate minors
    double m00 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[5], mat._indicies[6], mat._indicies[7], mat._indicies[9], mat._indicies[10], mat._indicies[11], mat._indicies[13], mat._indicies[14], mat._indicies[15]));
    double m01 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[4], mat._indicies[6], mat._indicies[7], mat._indicies[8], mat._indicies[10], mat._indicies[11], mat._indicies[12], mat._indicies[14], mat._indicies[15]));
    double m02 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[4], mat._indicies[5], mat._indicies[7], mat._indicies[8], mat._indicies[9], mat._indicies[11], mat._indicies[12], mat._indicies[13], mat._indicies[15]));
    double m03 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[4], mat._indicies[5], mat._indicies[6], mat._indicies[8], mat._indicies[9], mat._indicies[10], mat._indicies[12], mat._indicies[13], mat._indicies[14]));

    double m10 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[1], mat._indicies[2], mat._indicies[3], mat._indicies[9], mat._indicies[10], mat._indicies[11], mat._indicies[13], mat._indicies[14], mat._indicies[15]));
    double m11 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[2], mat._indicies[3], mat._indicies[8], mat._indicies[10], mat._indicies[11], mat._indicies[12], mat._indicies[14], mat._indicies[15]));
    double m12 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[4], mat._indicies[5], mat._indicies[7], mat._indicies[8], mat._indicies[9], mat._indicies[11], mat._indicies[12], mat._indicies[13], mat._indicies[15]));
    double m13 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[1], mat._indicies[2], mat._indicies[8], mat._indicies[9], mat._indicies[10], mat._indicies[12], mat._indicies[13], mat._indicies[14]));

    double m20 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[1], mat._indicies[2], mat._indicies[3], mat._indicies[5], mat._indicies[6], mat._indicies[7], mat._indicies[13], mat._indicies[14], mat._indicies[15]));
    double m21 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[2], mat._indicies[3], mat._indicies[4], mat._indicies[6], mat._indicies[7], mat._indicies[12], mat._indicies[14], mat._indicies[15]));
    double m22 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[1], mat._indicies[3], mat._indicies[4], mat._indicies[5], mat._indicies[7], mat._indicies[12], mat._indicies[13], mat._indicies[15]));
    double m23 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[1], mat._indicies[2], mat._indicies[4], mat._indicies[5], mat._indicies[6], mat._indicies[12], mat._indicies[13], mat._indicies[14]));

    double m30 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[1], mat._indicies[2], mat._indicies[3], mat._indicies[5], mat._indicies[6], mat._indicies[7], mat._indicies[9], mat._indicies[10], mat._indicies[11]));
    double m31 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[2], mat._indicies[3], mat._indicies[4], mat._indicies[6], mat._indicies[7], mat._indicies[8], mat._indicies[10], mat._indicies[11]));
    double m32 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[1], mat._indicies[3], mat._indicies[4], mat._indicies[5], mat._indicies[7], mat._indicies[8], mat._indicies[9], mat._indicies[11]));
    double m33 = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[0], mat._indicies[1], mat._indicies[2], mat._indicies[4], mat._indicies[5], mat._indicies[6], mat._indicies[8], mat._indicies[9], mat._indicies[10]));
    
    Matrix4x4 cofactors(m00, -m01, m02, -m03,
                        -m10, m11, -m12, m13,
                        m20, -m21, m22, -m23,
                        -m30, m31, -m32, m33);

    Matrix4x4 adjugate(Matrix4x4::Transpose(cofactors));

    double det_mat = mat.CalculateDeterminant();
    double inv_det = 1.0 / det_mat;

    return inv_det * adjugate;
}

double Matrix4x4::CalculateDeterminant(const Matrix4x4& mat) {


    //[00 01 02 03] [0   1  2  3]
    //[10 11 12 13] [4   5  6  7]
    //[20 21 22 23] [8   9 10 11]
    //[30 31 32 33] [12 13 14 15]

    double a = mat._indicies[0];
    double det_not_a = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[5], mat._indicies[6], mat._indicies[7], 
                                                                 mat._indicies[9], mat._indicies[10], mat._indicies[11],
                                                                 mat._indicies[13], mat._indicies[14], mat._indicies[15]));

    double b = mat._indicies[1];
    double det_not_b = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[4], mat._indicies[6], mat._indicies[7], 
                                                                 mat._indicies[8], mat._indicies[10], mat._indicies[11],
                                                                 mat._indicies[12], mat._indicies[14], mat._indicies[15]));

    double c = mat._indicies[2];
    double det_not_c = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[4], mat._indicies[5], mat._indicies[7], 
                                                                 mat._indicies[8], mat._indicies[9], mat._indicies[11],
                                                                 mat._indicies[12], mat._indicies[13], mat._indicies[15]));

    double d = mat._indicies[3];
    double det_not_d = Matrix3x3::CalculateDeterminant(Matrix3x3(mat._indicies[4], mat._indicies[5], mat._indicies[6], 
                                                                 mat._indicies[8], mat._indicies[9], mat._indicies[10],
                                                                 mat._indicies[12], mat._indicies[13], mat._indicies[14]));

    return (a * det_not_a) - (b * det_not_b) + (c * det_not_c) - (d * det_not_d);
}

double Matrix4x4::CalculateDeterminant() const {
    return Matrix4x4::CalculateDeterminant(*this);
}

double Matrix4x4::CalculateDeterminant() {
    return static_cast<const Matrix4x4&>(*this).CalculateDeterminant();
}

double Matrix4x4::CalculateTrace() const {
    return (_indicies[0] + _indicies[5] + _indicies[10] + _indicies[15]);
}

double Matrix4x4::CalculateTrace() {
    return static_cast<const Matrix4x4&>(*this).CalculateTrace();
}

bool Matrix4x4::operator==(const Matrix4x4& rhs) const {
    return (this->_indicies[0]  == rhs._indicies[0]  && this->_indicies[1]  == rhs._indicies[1]  && this->_indicies[2]  == rhs._indicies[2]  && this->_indicies[3]  == rhs._indicies[3]  &&
            this->_indicies[4]  == rhs._indicies[4]  && this->_indicies[5]  == rhs._indicies[5]  && this->_indicies[6]  == rhs._indicies[6]  && this->_indicies[7]  == rhs._indicies[7]  &&
            this->_indicies[8]  == rhs._indicies[8]  && this->_indicies[9]  == rhs._indicies[9]  && this->_indicies[10] == rhs._indicies[10] && this->_indicies[11] == rhs._indicies[11] &&
            this->_indicies[12] == rhs._indicies[12] && this->_indicies[13] == rhs._indicies[13] && this->_indicies[14] == rhs._indicies[14] && this->_indicies[15] == rhs._indicies[15]);
}

bool Matrix4x4::operator==(const Matrix4x4& rhs) {
    return static_cast<const Matrix4x4&>(*this).operator==(rhs);
}

bool Matrix4x4::operator!=(const Matrix4x4& rhs) const {
    return !(*this == rhs);
}

bool Matrix4x4::operator!=(const Matrix4x4& rhs) {
    return static_cast<const Matrix4x4&>(*this).operator!=(rhs);
}

a2de::Matrix4x4 Matrix4x4::operator*(const Matrix4x4& rhs) {
    return Matrix4x4(a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnOne()), a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnTwo()), a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnThree()), a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnFour()),
                     a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnOne()), a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnTwo()), a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnThree()), a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnFour()),
                     a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnOne()), a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnTwo()), a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnThree()), a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnFour()),
                     a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnOne()), a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnTwo()), a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnThree()), a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnFour()));

}

a2de::Matrix4x4 Matrix4x4::operator*(double scalar) {
    return Matrix4x4(scalar * _indicies[0], scalar * _indicies[1], scalar * _indicies[2], scalar * _indicies[3],
                     scalar * _indicies[4], scalar * _indicies[5], scalar * _indicies[6], scalar * _indicies[7],
                     scalar * _indicies[8], scalar * _indicies[9], scalar * _indicies[10], scalar * _indicies[11],
                     scalar * _indicies[12], scalar * _indicies[13], scalar * _indicies[14], scalar * _indicies[15]);
}

a2de::Vector4D Matrix4x4::operator*(const Vector4D& rhs) {
    return Vector4D(a2de::Vector4D::DotProduct(this->GetRowOne(), rhs),
                    a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs),
                    a2de::Vector4D::DotProduct(this->GetRowThree(), rhs),
                    a2de::Vector4D::DotProduct(this->GetRowFour(), rhs));
}

const double * const Matrix4x4::operator*() const {
    return &_indicies[0];
}

Matrix4x4& Matrix4x4::operator*=(const Matrix4x4& rhs) {
    if(this == &rhs) return *this;

    _indicies[0] = a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnOne());
    _indicies[1] = a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnTwo());
    _indicies[2] = a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnThree());
    _indicies[3] = a2de::Vector4D::DotProduct(this->GetRowOne(), rhs.GetColumnFour());

    _indicies[4] = a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnOne());
    _indicies[5] = a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnTwo());
    _indicies[6] = a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnThree());
    _indicies[7] = a2de::Vector4D::DotProduct(this->GetRowTwo(), rhs.GetColumnFour());

    _indicies[8] = a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnOne());
    _indicies[9] = a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnTwo());
    _indicies[10] = a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnThree());
    _indicies[11] = a2de::Vector4D::DotProduct(this->GetRowThree(), rhs.GetColumnFour());

    _indicies[12] = a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnOne());
    _indicies[13] = a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnTwo());
    _indicies[14] = a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnThree());
    _indicies[15] = a2de::Vector4D::DotProduct(this->GetRowFour(), rhs.GetColumnFour());

    return *this;
}

Matrix4x4& Matrix4x4::operator*=(double scalar) {

    _indicies[0] *= scalar;
    _indicies[1] *= scalar;
    _indicies[2] *= scalar;
    _indicies[3] *= scalar;

    _indicies[4] *= scalar;
    _indicies[5] *= scalar;
    _indicies[6] *= scalar;
    _indicies[7] *= scalar;

    _indicies[8] *= scalar;
    _indicies[9] *= scalar;
    _indicies[10] *= scalar;
    _indicies[11] *= scalar;

    _indicies[12] *= scalar;
    _indicies[13] *= scalar;
    _indicies[14] *= scalar;
    _indicies[15] *= scalar;

    return *this;
}

a2de::Matrix4x4 Matrix4x4::operator+(const Matrix4x4& rhs) {
    return Matrix4x4(this->_indicies[0] + rhs._indicies[0], this->_indicies[1] + rhs._indicies[1], this->_indicies[2] + rhs._indicies[2], this->_indicies[3] + rhs._indicies[3],
                     this->_indicies[4] + rhs._indicies[4], this->_indicies[5] + rhs._indicies[5], this->_indicies[6] + rhs._indicies[6], this->_indicies[7] + rhs._indicies[7],
                     this->_indicies[8] + rhs._indicies[8], this->_indicies[9] + rhs._indicies[9], this->_indicies[10] + rhs._indicies[10], this->_indicies[11] + rhs._indicies[11],
                     this->_indicies[12] + rhs._indicies[12], this->_indicies[13] + rhs._indicies[13], this->_indicies[14] + rhs._indicies[14], this->_indicies[15] + rhs._indicies[15]);
}

Matrix4x4& Matrix4x4::operator+=(const Matrix4x4& rhs) {

    this->_indicies[0] += rhs._indicies[0];
    this->_indicies[1] += rhs._indicies[1];
    this->_indicies[2] += rhs._indicies[2];
    this->_indicies[3] += rhs._indicies[3];

    this->_indicies[4] += rhs._indicies[4];
    this->_indicies[5] += rhs._indicies[5];
    this->_indicies[6] += rhs._indicies[6];
    this->_indicies[7] += rhs._indicies[7];

    this->_indicies[8] += rhs._indicies[8];
    this->_indicies[9] += rhs._indicies[9];
    this->_indicies[10] += rhs._indicies[10];
    this->_indicies[11] += rhs._indicies[11];
    
    this->_indicies[12] += rhs._indicies[12];
    this->_indicies[13] += rhs._indicies[13];
    this->_indicies[14] += rhs._indicies[14];
    this->_indicies[15] += rhs._indicies[15];

    return *this;
}

a2de::Matrix4x4 Matrix4x4::operator-(const Matrix4x4& rhs) {
    return Matrix4x4(this->_indicies[0] - rhs._indicies[0], this->_indicies[1] - rhs._indicies[1], this->_indicies[2] - rhs._indicies[2], this->_indicies[3] - rhs._indicies[3],
                     this->_indicies[4] - rhs._indicies[4], this->_indicies[5] - rhs._indicies[5], this->_indicies[6] - rhs._indicies[6], this->_indicies[7] - rhs._indicies[7],
                     this->_indicies[8] - rhs._indicies[8], this->_indicies[9] - rhs._indicies[9], this->_indicies[10] - rhs._indicies[10], this->_indicies[11] - rhs._indicies[11],
                     this->_indicies[12] - rhs._indicies[12], this->_indicies[13] - rhs._indicies[13], this->_indicies[14] - rhs._indicies[14], this->_indicies[15] - rhs._indicies[15]);
}

Matrix4x4& Matrix4x4::operator-=(const Matrix4x4& rhs) {

    this->_indicies[0] = this->_indicies[0] - rhs._indicies[0];
    this->_indicies[1] = this->_indicies[1] - rhs._indicies[1];
    this->_indicies[2] = this->_indicies[2] - rhs._indicies[2];
    this->_indicies[3] = this->_indicies[3] - rhs._indicies[3];

    this->_indicies[4] = this->_indicies[4] - rhs._indicies[4];
    this->_indicies[5] = this->_indicies[5] - rhs._indicies[5];
    this->_indicies[6] = this->_indicies[6] - rhs._indicies[6];
    this->_indicies[7] = this->_indicies[7] - rhs._indicies[7];

    this->_indicies[8] = this->_indicies[8] - rhs._indicies[8];
    this->_indicies[9] = this->_indicies[9] - rhs._indicies[9];
    this->_indicies[10] = this->_indicies[10] - rhs._indicies[10];
    this->_indicies[11] = this->_indicies[11] - rhs._indicies[11];

    this->_indicies[12] = this->_indicies[12] - rhs._indicies[12];
    this->_indicies[13] = this->_indicies[13] - rhs._indicies[13];
    this->_indicies[14] = this->_indicies[14] - rhs._indicies[14];
    this->_indicies[15] = this->_indicies[15] - rhs._indicies[15];

    return *this;
}

a2de::Matrix4x4 Matrix4x4::operator/(const Matrix4x4& rhs) {
    return Matrix4x4((*this) * a2de::Matrix4x4::Inverse(rhs));
}

Matrix4x4& Matrix4x4::operator/=(const Matrix4x4& rhs) {

    Matrix4x4 inv(a2de::Matrix4x4::Inverse(rhs));
    Matrix4x4 result = (*this * inv);

    this->_indicies = result._indicies;
    
    return *this;
}

Matrix4x4 Matrix4x4::operator-() {
    return Matrix4x4(-this->GetRowOne(), -this->GetRowTwo(), -this->GetRowThree(), -this->GetRowFour());
}

Matrix4x4 operator*(double scalar, const Matrix4x4& rhs) {
    return Matrix4x4(scalar * rhs._indicies[0], scalar * rhs._indicies[1], scalar * rhs._indicies[2], scalar * rhs._indicies[3],
        scalar * rhs._indicies[4], scalar * rhs._indicies[5], scalar * rhs._indicies[6], scalar * rhs._indicies[7],
        scalar * rhs._indicies[8], scalar * rhs._indicies[9], scalar * rhs._indicies[10], scalar * rhs._indicies[11],
        scalar * rhs._indicies[12], scalar * rhs._indicies[13], scalar * rhs._indicies[14], scalar * rhs._indicies[15]);
}

Vector4D operator*(const Matrix4x4& lhs, const Vector4D& rhs) {
    return Vector4D(a2de::Vector4D::DotProduct(lhs.GetRowOne(), rhs),
                    a2de::Vector4D::DotProduct(lhs.GetRowTwo(), rhs),
                    a2de::Vector4D::DotProduct(lhs.GetRowThree(), rhs),
                    a2de::Vector4D::DotProduct(lhs.GetRowFour(), rhs));
}


A2DE_END