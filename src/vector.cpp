#include "vector.h"
#include <math.h>

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D::~Vector2D() {}

Vector2D Vector2D::operator+(const Vector2D &other) const {
    return Vector2D(this->x + other.x, this->y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D &other) const {
    return Vector2D(this->x - other.x, this->y - other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(this->x * scalar, this->y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const {
    return Vector2D(this->x / scalar, this->y / scalar);
}

Vector2D &Vector2D::operator+=(const Vector2D &other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2D &Vector2D::operator*=(double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Vector2D &Vector2D::operator/=(double scalar) {
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

double Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector3D::Vector3D() : x(0), y(0) {}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3D::~Vector3D() {}

Vector3D Vector3D::operator+(const Vector3D &other) const {
    return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D &other) const {
    return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3D Vector3D::operator*(double scalar) const {
    return Vector3D(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vector3D Vector3D::operator/(double scalar) const {
    return Vector3D(this->x / scalar, this->y / scalar, this->z / scalar);
}

Vector3D &Vector3D::operator+=(const Vector3D &other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

Vector3D &Vector3D::operator*=(double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

Vector3D &Vector3D::operator/=(double scalar) {
    this->x /= scalar;
    this->y /= scalar;
    this->z /= scalar;
    return *this;
}

double Vector3D::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}