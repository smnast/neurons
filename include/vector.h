#ifndef VECTOR_H
#define VECTOR_H

class Vector2D {
public:
    Vector2D();
    Vector2D(double x, double y);
    ~Vector2D();

    Vector2D operator+(const Vector2D &other) const;
    Vector2D operator-(const Vector2D &other) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;

    double x;
    double y;
};

class Vector3D {
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();

    Vector3D operator+(const Vector3D &other) const;
    Vector3D operator-(const Vector3D &other) const;
    Vector3D operator*(double scalar) const;
    Vector3D operator/(double scalar) const;

    double x;
    double y;
    double z;
};

#endif // VECTOR_H