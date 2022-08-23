#pragma once 

#include <memory>
class Entity; 

class Component {
public :
	Entity* entity;

	virtual ~Component() {};
	virtual void Start() {}; 
	virtual void Awake() {};
	virtual void Update() {}; 
	virtual void Clean() {};

	virtual void Draw() {};

}; 
