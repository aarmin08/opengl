#pragma once 
#include <iostream>

class Vector2 {
private : 
	float x, y; 
public : 
	Vector2(float x, float y) {
		this->x = x; 
		this->y = y; 
	};
	//Util functions
	static Vector2& add(Vector2 a, Vector2 b); 
	static Vector2& subtract(Vector2 a, Vector2 b);
	static Vector2& divide(Vector2 a, Vector2 b); 
	static Vector2& multiply(Vector2 a, Vector2 b); 

	friend Vector2& operator/=(Vector2 left, Vector2 right);
	friend Vector2& operator+=(Vector2 left, Vector2 right); 
	friend Vector2& operator-=(Vector2 left, Vector2 right);
	friend Vector2& operator*=(Vector2 left, Vector2 right);

	friend std::ostream & operator << (std::ostream &, const Vector2& a); 
};
