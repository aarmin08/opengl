#include "Entity.hpp"
#include <iostream>

class AnEntity : public Entity {
private :
    float s;
public :
    AnEntity(float s) {
        this->s = s;
    }

    void Awake() override {
		this->awake(); 
    }

    void Update() override {
		this->update();
    };

	void Draw() override {
		this->draw(); 
	}

    void Start() override {
		this->start(); 
    }
};
