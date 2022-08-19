#include "UserEngine.hpp"
#include "Sprite.hpp"
#include <iostream>

Entity* entity1; 

void UserEngine::Start() {
	if (manager == nullptr) {
		std::cerr << "NO MANAGER" <<std::endl; 
	}
	else {
		entity1 = &manager->addEntity();  
		entity1->addComponent<Sprite>();
		std::cout << "Manager start" << std::endl; 
		manager->start();
		std::cout << "Finished start" << std::endl; 
	}
}

void UserEngine::Update() {
	manager->update(); 
}

void UserEngine::Draw() {
	manager->draw(); 
}
