#pragma once 

#include <iostream> 

class Vector2d {
private: 
	float x; 
	float y; 
public:
	const float& _x = x; 
	const float& _y = y;  

    Vector2d(float x, float y); 
	Vector2d(){
		x = 0.0f;
		y = 0.0f; 
	}; 

	Vector2d setVector(Vector2d vec){
		this->x = vec._x; 
		this->y = vec._y; 

		return *this; 
	}


	void setPos(float x,float y) {
		this->x = x; 
		this->y = y; 
	}

	void setX(float x) {
		this->x = x;
	} 

	void setY(float y) {
		this->y = y;
	}

    Vector2d& add(const Vector2d& other);
    Vector2d& multiply(const Vector2d& other);
    Vector2d& divide(const Vector2d& other);
    Vector2d& subtract(const Vector2d& other);
    Vector2d& Zero();

    friend Vector2d& operator+(Vector2d& left, const Vector2d& right);
    friend Vector2d& operator-(Vector2d& left, const Vector2d& right);
    friend Vector2d& operator*(Vector2d& left, const Vector2d& right);
    friend Vector2d& operator/(Vector2d& left, const Vector2d& right);

    Vector2d& operator+=(const Vector2d& other);
    Vector2d& operator-=(const Vector2d& other);
    Vector2d& operator*=(const Vector2d& other);
    Vector2d& operator/=(const Vector2d& other);

    Vector2d& operator*(const int& i);

    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec);
};
