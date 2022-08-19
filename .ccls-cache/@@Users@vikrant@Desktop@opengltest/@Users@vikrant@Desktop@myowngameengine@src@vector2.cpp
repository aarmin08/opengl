#include "vector2.hpp"

Vector2d::Vector2d(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2d& Vector2d::add(const Vector2d& other) {
    this->x += other.x; 
    this->y += other.y;

    return *this;
}

Vector2d& Vector2d::subtract(const Vector2d& other) {
    this->x -= other.x;
    this->y -= other.y;

    return *this; 
}

Vector2d& Vector2d::divide(const Vector2d& other) {
    this->x /= other.x;
    this->y /= other.y;

    return *this;
}

Vector2d& Vector2d::Zero() {
    this->x = 0;
    this->y = 0; 

    return *this; 
}

Vector2d& Vector2d::multiply(const Vector2d& other) {
    this->x *= other.x;
    this->y *= other.y;

    return *this;
}

Vector2d& operator+(Vector2d& left, const Vector2d& right) {
    return left.add(right);
}
Vector2d& operator-(Vector2d& left, const Vector2d& right) {
    return left.subtract(right);
}
Vector2d& operator*(Vector2d& left, const Vector2d& right) {
    return left.multiply(right);
}
Vector2d& operator/(Vector2d& left, const Vector2d& right) {
    return left.divide(right);
}

Vector2d& Vector2d::operator+=(const Vector2d& other) {
    return this->add(other);
}

Vector2d& Vector2d::operator*=(const Vector2d& other) {
    return this->multiply(other);
}

Vector2d& Vector2d::operator/=(const Vector2d& other) {
    return this->divide(other);
}

Vector2d& Vector2d::operator-=(const Vector2d& other) {
    return this->subtract(other);
}

Vector2d& Vector2d::operator*(const int& i) {
    this->x *= i;
    this->y *= i; 

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vector2d &vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

