#include "GameEngine.h"


GameEngine::GameEngine(sf::RenderWindow &window) : window(window)
{
    this->tetromino = currentTetromino(new drawableTetromino(this->window));
    this->event_ptr = eventPtr(new EventHandler());
    this->hud = HUDptr(new drawableHUD(this->window));
    paused = false;
    gameOverState = false;
}

void GameEngine::draw() {
    hud->drawBackground();
    tetromino->draw();
    hud->scoreLabel();
    hud->score();
    hud->linesCompletedLabel();
    hud->linesCompletedValueText();
    hud->gameBorders();
}

void GameEngine::update(sf::Event& event)
{
    if (TetrisVars::countTime > TetrisVars::deltaTime)
    {
        tetromino->config();
        int checkLines = tetromino->checkLines();
        if (checkLines == -1) {
            gameOver();
            return;
        }

        for (int i = 0; i < checkLines; i++)
        {
            hud->updateScore();
            scoreValue  = hud->scoreValue;
            hud->linesUpdate();
        }
        tetromino->pieceFalling();
        TetrisVars::countTime = 0;
    }
}

void GameEngine::pause() {

    window.clear();
    sf::Sprite pauseSprite;
    pauseSprite.setColor(sf::Color::Black);
    window.draw(pauseSprite);

}

int GameEngine::gameOver() {

    gameOverState = true;
    return hud->scoreValue;
}

void GameEngine::moveEvents(sf::Event &event)
{
    event_ptr->moveEvents(event, tetromino, paused);
}