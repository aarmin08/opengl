#pragma once 

#include <vector>

class Entity; 

#ifndef COMPONENT_HPP
#define COMPONENT_HPP 

class Component {
	public : 
		Entity* entity;
		virtual ~Component() {}; 
		virtual void Start() {}; // goes in init function of Engine loop 
		virtual void Update() {}; // goes in Update 
		virtual void Draw() {};// goes in render function in Engine loop
		virtual void Clean() {}; 
}; 

#endif 
