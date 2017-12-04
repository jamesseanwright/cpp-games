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
    SpriteRenderable* spriteRenderable = entity->getComponent<SpriteRenderable*>(SPRITE_RENDERABLE_NAME); // TODO: better way of handling template param?
    Positionable* positionable = entity->getComponent<Positionable*>(POSITIONABLE_NAME);
    sf::Sprite* sprite = spriteRenderable->getSprite();

    sprite->setPosition(positionable->getX(), positionable->getY());

    this->window->draw(*sprite);
}