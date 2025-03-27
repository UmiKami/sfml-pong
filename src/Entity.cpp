//
// Created by umikami on 3/26/25.
//

#include "Entity.h"

#include <iostream>
#include <utility>

Entity::Entity(): sprite(texture)
{
    if (!texture.loadFromFile("assets/characters.png", false, {{0, 32}, {32, 32}}))
    {
        std::cout << "Failed to load texture from file\n";
        return;
    }

    sprite.setTexture(texture);

}

Entity::Entity(sf::Vector2f position) : sprite(texture), position(position)
{
    if (!texture.loadFromFile("assets/characters.png", false, {{0, 32}, {32, 32}}))
    {
        std::cout << "Failed to load texture from file\n";
        return;
    }

    sprite.setTexture(texture);
}
Entity::Entity(sf::Vector2f position, std::vector<Entity *> colliderEntities) : position(position), colliderEntities(std::move(colliderEntities)), sprite(texture)
{
    if (!texture.loadFromFile("assets/characters.png", false, {{0, 32}, {32, 32}}))
    {
        std::cout << "Failed to load texture from file\n";
        return;
    }

    sprite.setTexture(texture);
}

Entity::Entity(sf::Vector2f position, sf::Vector2i size, const std::filesystem::path &texturePath): sprite(texture)
{
    this->position = position;

    if (!texture.loadFromFile(texturePath, false, {{0, 32}, size}))
    {
        std::cout << "Failed to load texture from file\n";
        return;
    }

    sprite.setTexture(texture);
    sprite.setPosition(position);
}

Entity::Entity(sf::Vector2f position, sf::Vector2i size, std::filesystem::path texturePath, sf::Color color) : sprite(texture)
{
    this->position = position;

    if (!texture.loadFromFile(texturePath, false, {{0, 32}, size}))
    {
        std::cout << "Failed to load texture from file\n";
        return;
    }

    sprite.setTexture(texture);
    sprite.setColor(color);
    sprite.setPosition(position);
}

Entity::Entity(sf::Texture texture) : texture(texture), sprite(this->texture)
{
   sprite.setTexture(this->texture);
}

Entity::Entity(sf::Sprite sprite) : sprite(sprite)
{
    texture = sprite.getTexture();
}

void Entity::Move(sf::Vector2f direction, float deltaTime)
{
    sprite.move(direction * speed * deltaTime);
}

void Entity::Draw(sf::RenderWindow *window)
{
    window->draw(sprite);
}

void Entity::OnCollision()
{
    std::cout << "Collision detected!\n";
}

bool Entity::IsColliding()
{
    sf::FloatRect bounds = sprite.getGlobalBounds();

    for (Entity *otherEntity : colliderEntities)
    {
        sf::FloatRect otherBox = otherEntity->sprite.getGlobalBounds();

        if (const std::optional intersection = bounds.findIntersection(otherBox))
        {
            OnCollision();
            return true;
        }
    }

    return false;
}

void Entity::SetColliderEntities(std::vector<Entity *> entities)
{
}

void Entity::AddColliderEntity(Entity *entity)
{
}

void Entity::SetSpeed(float speed)
{
}

void Entity::SetColor(sf::Color color)
{
}

void Entity::SetDirection(sf::Vector2f direction)
{
}

void Entity::SetPosition(sf::Vector2f pos)
{
}

sf::Vector2f Entity::GetPosition()
{
}

sf::Vector2f Entity::GetDirection()
{
}

sf::Color Entity::GetColor()
{
}

float Entity::GetSpeed()
{
}
