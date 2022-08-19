#pragma once 

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <bitset>
#include <array>

#include <iostream>

#include "Component.hpp"

using ComponentID = std::size_t; 

inline ComponentID getComponentTypeId() {
	static ComponentID lastId = 0;
	return lastId++; 
} 

template <typename T> inline ComponentID getId() noexcept {
	static ComponentID id = getComponentTypeId(); 
	return id; 
}

constexpr std::size_t maxComponents = 32; 

using ComponentBitset = std::bitset<maxComponents>; 
using ComponentArray = std::array<Component*, maxComponents>; 

class Entity {
	private : 
		std::vector<std::unique_ptr<Component>> components; 
		bool isActive = true; 

		ComponentArray cArr; 
		ComponentBitset set; 

	public : 
		void update() {
			for (auto& c : cArr) {
				std::cout << "UUU" << std::endl; 
				c->Update(); 
			}
		}

		void start() {
			for (auto& c : cArr) {
				std::cout << "entity start" << std::endl; 
				c->Start(); 
			}
		}

		void draw() {
			for(auto& c : cArr) {
				c->Draw(); 
			}
		}

		void clean() {
			for (auto& c : cArr) {
				c->Clean(); 
			}
		}

		bool IsActive() { return isActive;} 
		void Destroy() {isActive = false; }

		template <typename T, typename... TArgs> T& addComponent(TArgs... args) {
			T* c(new T(std::forward<TArgs>(args)...));
			c->entity = this; 
			std::unique_ptr<Component> uPtr {c};
			components.emplace_back(std::move(uPtr)); 
			cArr[getId<T>()] = c;
			set[getId<T>()] = true; 
			std::cout << "Added" << std::endl; 
			return *c; 
		}

		template <typename T> T& getComponent()const {
			auto ptr(cArr[getId<T>()]);
			std::cout << "Gaming" << std::endl; 
			return *static_cast<T*>(ptr); 
		}

		template <typename T> T& hasComponent() const {
			return set[getId<T>()]; 
		}
};

#endif
