#pragma once 

#ifndef USERENGINE_HPP 
#define USERENGINE_HPP

#include "Engine.hpp"

class UserEngine {
	private : 
		Manager* manager;
	public :
		// THIS IS A MSUT
		void SetManager(Manager* a) {
			manager = a; 
		}	
		//Called on app start
		void Start(); 
		void Update();
		void Draw(); 
}; 

#endif 
