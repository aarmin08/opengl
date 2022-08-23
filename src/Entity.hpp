#pragma once

#include "Component.hpp"
#include "glm/fwd.hpp"
#include <bitset>
#include <boost/any.hpp>
#include <cstddef>
#include <memory>

using ComponentID = std::size_t; 

inline ComponentID getComponentTypeID() {
	static ComponentID lastID = 0; 
	return lastID++;
}

template <typename T> inline ComponentID getComponentID() noexcept {
	static ComponentID typeID = getComponentTypeID(); 
	return typeID; 
}

constexpr std::size_t maxComponent = 32; 

using ComponentBitSet = std::bitset<maxComponent>;
using ComponentArray = std::array<Component*, maxComponent>; 

/* template <typename T = boost::any> */
class Entity {
private:
	bool active = true; 

	ComponentArray arr; 
	ComponentBitSet bitSet; 
    /* std::vector<std::unique_ptr<Component>> components; */
public :
	std::vector<std::unique_ptr<Component>> components; 
    virtual ~Entity() {};

    // Called on the first frame
    virtual void Start() {};

    //Called every frame
    virtual void Update() {};

    //Called a frame before the game starts
    virtual void Awake() {};

    //Incase you want to render, use this.
    virtual void Draw() {};

	bool isActive() { return active; }; 

	void Destroy() { active = false; }

	void update() { for (auto& c: components) { c->Update(); }; }
	void start() { for (auto&c : components ) { c->Start(); }; }
	void awake() { for (auto&c : components) { c->Awake(); }; }
	void draw() { for (auto&c : components ) { c->Draw(); }; }
    // If you have parameters, you can set the class's template value and configure a variable using that here. Supports full config-classes.
    /* virtual void Configure(T config) {}; */

	template<typename T, typename... args> T& addComponentToEntity(args... A) {
    	auto component = std::make_unique<T>(std::forward<args>(A)...);

    	components.emplace_back(std::move(component));
		arr[getComponentID<T>()] = components.back().get();
		bitSet[getComponentID<T>()] = true; 

		 components.back().get()->entity = this;
    	 components.back().get()->Awake();
    	 components.back().get()->Start();
    	return  *static_cast<T *>(components.back().get());;
    }
	
	template<typename T> T& getComponent() {
		// get the compponent
	}; 

private:
};

