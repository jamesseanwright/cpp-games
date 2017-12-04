#include <SFML/Graphics.hpp>
#include "SpriteRenderSystem.hpp"
#include "../components/SpriteRenderable.hpp"
#include "../components/Positionable.hpp"

SpriteRenderSystem::SpriteRenderSystem(sf::RenderWindow* window) {
    this->window = window;
}

SpriteRenderSystem SpriteRenderSystem::create(sf::RenderWindow* window) {
    return SpriteRenderSystem(window);
}

void SpriteRenderSystem::next(Entity* entity, float deltaSecs) {
    SpriteRenderable spriteRenderable = entity->getComponent<SpriteRenderable>(SpriteRenderable::NAME);
    Positionable positionable = entity->getComponent(Positionable::NAME);

    this->window.draw(spriteRenderable->getSprite());
}