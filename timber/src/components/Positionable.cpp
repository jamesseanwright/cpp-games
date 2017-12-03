#include "Positionable.hpp"

using namespace std;

const string NAME = "Positionable";

Positionable::Positionable(float x, float y) {
    this->name = NAME;
    this->x = x;
    this->y = y;
}