#include "DrawableHUD.h"

void drawableHUD::backgroundInit()
{
    this->background.loadFromFile("background.png");
    this->bg.setTexture(background);
}

void drawableHUD::drawBackground()
{
    window.draw(bg);
}

void drawableHUD::scoreLabel()
{
    font.loadFromFile("Arial.ttf");
    scoreLabelText.setFont(font);
    scoreLabelText.setString("Score:");
    scoreLabelText.setCharacterSize(22);
    scoreLabelText.setFillColor(sf::Color::White);
    scoreLabelText.setStyle(sf::Text::Bold);
    scoreLabelText.setPosition(sf::Vector2f(320, 50));
    window.draw(scoreLabelText);
}

void drawableHUD::updateScore()
{
    scoreValue += 100;
}

void drawableHUD::linesCompletedLabel()
{
    font.loadFromFile("Arial.ttf");
    linesCompletedText.setFont(font);
    linesCompletedText.setString("Lines completed:");
    linesCompletedText.setCharacterSize(22);
    linesCompletedText.setFillColor(sf::Color::White);
    linesCompletedText.setStyle(sf::Text::Bold);
    linesCompletedText.setPosition(sf::Vector2f(TetrisVars::windowWidth - 10, 250));
    window.draw(linesCompletedText);
}

void drawableHUD::score()
{
    font.loadFromFile("Arial.ttf");
    scoreText.setFont(font);
    std::stringstream ss;
    ss << scoreValue;
    scoreText.setString(ss.str());
    scoreText.setCharacterSize(22);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(sf::Vector2f(320, 100));
    window.draw(scoreText);
}

void drawableHUD::linesCompletedValueText()
{
    font.loadFromFile("Arial.ttf");
    linesCompletedValue.setFont(font);
    std::stringstream ss;
    ss << linesVal;
    linesCompletedValue.setString(ss.str());
    linesCompletedValue.setCharacterSize(22);
    linesCompletedValue.setFillColor(sf::Color::White);
    linesCompletedValue.setStyle(sf::Text::Bold);
    linesCompletedValue.setPosition(sf::Vector2f(320, 300));
    window.draw(linesCompletedValue);
}

void drawableHUD::linesUpdate()
{
    this->linesVal++;
}

void drawableHUD::gameBorders()
{
    sf::RectangleShape border1;
    border1.setSize(sf::Vector2f(2, 390));
    border1.setFillColor(sf::Color::Red);
    border1.setPosition(28, 0);
    window.draw(border1);
    sf::RectangleShape border2;
    border2.setSize(sf::Vector2f(2, 390));
    border2.setFillColor(sf::Color::Red);
    border2.setPosition(208, 0);
    window.draw(border2);
    sf::RectangleShape border3;
    border3.setSize(sf::Vector2f(180, 2));
    border3.setFillColor(sf::Color::Red);
    border3.setPosition(30, 390);
    window.draw(border3);
}

drawableHUD::drawableHUD(sf::RenderWindow& window)
        : window(window)
{
    this->backgroundInit();
    this->scoreValue = 0;
    this->linesVal = 0;
}
