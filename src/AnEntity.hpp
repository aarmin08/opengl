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
        std::cout << s << std::endl;
    }

    void Update() override {
		this->update();
    };

    void Start() override {
		this->start(); 
        std::cout << s << std::endl;
    }
};
