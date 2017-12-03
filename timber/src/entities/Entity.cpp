#include <unordered_map>
#include <vector>
#include "Entity.hpp"
#include "../components/Component.hpp"

using namespace std;

Entity::Entity(vector<Component>* compv) {
    for (Component component : *compv) {
        this->components[component.getName()] = &component;
    }
}