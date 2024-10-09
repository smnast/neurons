#include "vector.h"

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