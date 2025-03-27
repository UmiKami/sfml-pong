//
// Created by umikami on 3/26/25.
//
#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <vector>

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace sf
{
    class CircleShape;
}

namespace sf
{
    class RectangleShape;
}

class Entity
{
public:
    Entity();
    explicit Entity(sf::Vector2f position);
    Entity(sf::Vector2f position, std::vector<Entity*> colliderEntities);
    Entity(sf::Vector2f position, sf::Vector2i size, const std::filesystem::path &texturePath);
    Entity(sf::Vector2f position, sf::Vector2i size, std::filesystem::path texturePath, sf::Color color);
    explicit Entity(sf::Texture texture);
    explicit Entity(sf::Sprite sprite);
private:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f direction;
    sf::Color color;
    float speed = 1000;
    std::vector<Entity*> colliderEntities;
public:
    virtual void Move(sf::Vector2f direction, float deltaTime);
    virtual void Draw(sf::RenderWindow* window);
    virtual void OnCollision();
    bool IsColliding();
    void SetColliderEntities(std::vector<Entity*> entities);
    void AddColliderEntity(Entity* entity);
    void SetSpeed(float speed);
    void SetColor(sf::Color color);
    void SetDirection(sf::Vector2f direction);
    void SetPosition(sf::Vector2f pos);
    sf::Vector2f GetPosition();
    sf::Vector2f GetDirection();
    sf::Color GetColor();
    float GetSpeed();
};



#endif //ENTITY_H
