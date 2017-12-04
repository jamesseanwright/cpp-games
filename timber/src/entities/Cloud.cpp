#include "Entity.hpp";
#include "../components/SpriteRenderable.hpp";

Entity createCloud() {
    return Entity(new Component[1] {
        SpriteRenderable::create("graphics/cloud.png")
    })
}
