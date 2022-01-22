#include <SFML/Graphics.hpp>
#include "GameEngine.h"


float TetrisVars::countTime = 0.0;
float TetrisVars::deltaTime = 0.0;
sf::Font font;
int main()
{
    sf::RenderWindow window(sf::VideoMode(TetrisVars::windowWidth + 200, TetrisVars::windowHeight), "Tetris", sf::Style::Resize);
    window.setFramerateLimit(30);
    font.loadFromFile("Arial.ttf");
    sf::Event event{};
    GameEngine game(window);
    sf::Clock clock;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        game.paused ^= true;
                    }
                    if (game.gameOverState)
                        window.close();
                    continue;
            }
            game.moveEvents(event);
        }

        window.clear();
        game.draw();
        sf::Time elapsed = clock.restart();
        TetrisVars::countTime += elapsed.asSeconds();

        if(!game.paused) game.update(event);
        else {
            game.pause();
            sf::Text PauseText("Paused", font, 28);
            PauseText.setPosition(sf::Vector2f(175, 150));
            PauseText.setFillColor(sf::Color(120, 120, 120));
            sf::Text PauseText2("ESC aby grac dalej", font, 24);
            PauseText2.setPosition(sf::Vector2f(110, 185));
            PauseText2.setFillColor(sf::Color(120, 120, 120));
            window.draw(PauseText);
            window.draw(PauseText2);
        }
        if (game.gameOverState) {
            int score = game.gameOver();
            window.clear();
            sf::Sprite pauseSprite;
            pauseSprite.setColor(sf::Color::Black);
            window.draw(pauseSprite);
            sf::Text PauseText("Game Over", font, 28);
            PauseText.setPosition(sf::Vector2f(175, 150));
            PauseText.setFillColor(sf::Color(200, 120, 120));
            std::stringstream ss;
            ss<< "Wynik: "<<score;
            sf::Text PauseText2(ss.str(), font, 24);
            PauseText2.setPosition(sf::Vector2f(200, 185));
            PauseText2.setFillColor(sf::Color(120, 120, 120));
            window.draw(PauseText);
            window.draw(PauseText2);
        }

        window.display();
    }
    return 0;
}