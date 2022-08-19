#pragma once 

#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "Entity.hpp" 

class Manager {
	private : 
		std::vector<std::unique_ptr<Entity>> entities;
	public : // addentity, jupdate and stuf
		void update() {
			for (auto& c : entities) {
				std::cout << "Update" << std::endl; 
				c->update(); 
			}
		}

		void start() {
			std::cout << entities.size() << std::endl; 
			for (auto& c : entities) {
				std::cout << "Entered for loop for starti" << std::endl;
				c->start(); 
			}
		}

		void draw() {
			for (auto& c : entities) {
				c->draw(); 
			}
		}

		void clean() {
			for (auto& c : entities) {
				c->clean();
			}
		}
		void refresh() {
			entities.erase(std::remove_if(std::begin(entities), std::end(entities), [] (const std::unique_ptr<Entity>& e) {
						return !e->IsActive(); 
						}), std::end(entities)); 
		}

		Entity& addEntity() {
			Entity* e = new Entity(); 
			std::unique_ptr<Entity> uPtr {e}; 
			entities.emplace_back(std::move(uPtr));
			return *e; 
		}
};

#endif 
