#include <unordered_map>
#include <>
#include <string>
#include "Entity.hpp"
#include "../components/Component.hpp"

Entity::Entity(Component components []) {
    for (Component component : components) {
        this->components[component.getName()] = &component;
    }
}

template<typename T>
T Entity::getComponent(std::string name) {
    return (T) this->components[name];
}
