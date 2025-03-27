#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>


void handleInput(float deltaTime);

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "PingPong with SFML| By UmiKami");
    window.setFramerateLimit(144);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elepased = clock.restart();
        float deltaTime = elepased.asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        handleInput( deltaTime);
        // player.UpdateAnimation(deltaTime);
        //
        // player.Draw(window);

        window.display();
    }
}

bool IsKeyPressed(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

void handleInput(float deltaTime)
{
    sf::Vector2f inputDirection(0.f, 0.f);

    if (IsKeyPressed(sf::Keyboard::Key::A))
    {
        inputDirection.x = -1;
    }

    if (IsKeyPressed(sf::Keyboard::Key::D))
    {
        inputDirection.x = 1;
    }

    if (IsKeyPressed(sf::Keyboard::Key::S))
    {
        inputDirection.y = 1;
    }

    if (IsKeyPressed(sf::Keyboard::Key::W))
    {
        inputDirection.y = -1;
    }

    // player->SetSpeed(100);
    //
    // if (inputDirection.x != 0 && inputDirection.y != 0)
    // {
    //     player->SetSpeed(player->GetSpeed() / std::sqrt(2.f));
    // }
    //
    //
    // player->Move(inputDirection, deltaTime);
}
