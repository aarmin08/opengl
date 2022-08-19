#pragma once 

#ifndef RB_HPP
#define RB_HPP 

#include "components.hpp"
#include <math.h>
#include <unistd.h>

class RigidBody : public Component {
	private :
		float dt = 1 ; 
	public :
		TransformComponent* transform; 
		bool isKinematic = false; 
		float mass = 1;
		Collider* colliderBox; 	
		bool isColliding;
		Vector2d* force; 

		float torque;
		float angle; 
		float angularVelocity; 
		Vector2d linearVelocity; 

		Vector2d velocity; 

		float momentOfInertia; 

		void CalculateInertia(Collider* collider) {
			float m = this->mass; 
			float w = collider->collider.w; 
			float h = collider->collider.h; 

			this->momentOfInertia = m * (w * w + h) / 12; 
		}

		void ComputeForceAndTorque(RigidBody* rb) {
			Vector2d f = Vector2d(0, rb->mass * 2); 
			rb->force = &f;
			Vector2d r = Vector2d(rb->colliderBox->collider.w / 2, rb->colliderBox->collider.h / 2); 
			rb->torque = r._x * f._y - r._y * f._x; 
			std::cout << rb->torque << std::endl; 
		}

	
		RigidBody(bool kinematic, float mass) {
			this->isKinematic = kinematic; 
			this->mass = mass; 
		}

		RigidBody() = default;

		void init() override {

		};
		void AddForce(Vector2d* direction) {
		}

		Vector2d getVelocity() {
		}

		void update() override {
		}; 
}; 

#endif
