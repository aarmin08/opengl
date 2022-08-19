#pragma once

#include "Entity.hpp"
#include <memory>
#include <vector>
#include <iostream>

class World {
private :
    // world should be able to spwan entities, and should be able to
public :
    std::vector<std::unique_ptr<Entity>> entities;

    World() {};

    template<typename T, typename... TC>
    T &Spawn(TC... config) {
        auto en = std::make_unique<T>(std::forward<TC>(config)...);
        std::cout << sizeof(en) << std::endl;
        if (en == nullptr) {
            std::cerr << "Failed to make entity \n";
            exit(1);
        }
        entities.push_back(std::move(en));
        std::cout << "a" << std::endl;
        entities.back().get()->Awake();
        entities.back().get()->Start();
        return *static_cast<T *>(entities.back().get());
    }


}; 
