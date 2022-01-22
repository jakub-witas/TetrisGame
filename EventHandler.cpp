#include "EventHandler.h"

EventHandler::EventHandler()= default;


void EventHandler::moveEvents(sf::Event &event, currentTetromino &tetromino, bool paused)
{
    if (sf::Event::KeyPressed && !paused)
    {

        if (event.key.code == sf::Keyboard::Down)
        {
            if (!tetromino->checkCollision())
            {
                TetrisVars::countTime = 0.0;
            }
            else
                tetromino->moveDown();
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            if (!tetromino->checkCollision())
            {
                TetrisVars::countTime = 0.0;
            }
            else
            {
                float moveDirection = -1;
                tetromino->moveSides(moveDirection);
            }
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            if (!tetromino->checkCollision())
            {
                TetrisVars::countTime = 0.0;
            }
            else
            {
                float moveDirection = 1;
                tetromino->moveSides(moveDirection);
            }
        }
        else if (event.key.code == sf::Keyboard::Up)
        {
            if (!tetromino->checkCollision())
            {
                TetrisVars::countTime = 0.0;
            }
            else
            {
                bool rotation = true;
                tetromino->rotate(rotation);
            }
        }
        else if (event.key.code == sf::Keyboard::Space)
        {
            for (int i = 0; i < 200; i++)
                tetromino->moveDown();
        }
    }
}