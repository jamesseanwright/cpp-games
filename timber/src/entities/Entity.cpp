#include <unordered_map>
#include <vector>
#include <string>
#include "Entity.hpp"
#include "../components/Component.hpp"

Entity::Entity(vector<Component>* compv) {
    for (Component component : *compv) {
        this->components[component.getName()] = &component;
    }
}

template<Component T>
T* Entity::getComponent(std::string name) {
    return (T*) this->components[name];
}