#include "drawableTetromino.h"
#include "shapeStruct.h"

void drawableTetromino::moveSides(float direction)
{
    for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += direction; }
    if (!checkCollision()) for (int i = 0; i < 4; i++) a[i] = b[i];
}

void drawableTetromino::rotate(bool isRotating)
{
    Point p = a[1];
    for (int i = 0; i < 4; i++) b[i] = a[i];
    if (isRotating)
    {
        for (int i = 0; i < 4; i++)
        {
            int x = a[i].y - p.y;
            int y = a[i].x - p.x;
            a[i].x = p.x - x;
            a[i].y = p.y + y;
        }
        if (!checkCollision()) for (int i = 0; i < 4; i++) a[i] = b[i];
    }
    isRotating = false;
}

void drawableTetromino::moveDown()
{
    for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
    if (!checkCollision()) for (int i = 0; i < 4; i++) { a[i] = b[i]; }
}

void drawableTetromino::draw()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (field[i][j] == 0) continue;
            s.setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
            s.setPosition(j * 18, i * 18);
            s.move(28, 31);
            window.draw(s);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        s.setPosition(a[i].x * 18, (a[i].y - 1) * 18);
        this->colorInit();
        s.move(28, 31);
        window.draw(s);
    }
}

void drawableTetromino::initPiece()
{
    this->t.loadFromFile("tiles.png");
    this->s.setTexture(t);
    this->colorInit();
}

void drawableTetromino::config()
{
    if (!checkCollision())
    {
        for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = color;
        color = 1 + rand() % 7;
        int n = rand() % 7;
        for (int i = 0; i < 4; i++)
        {
            a[i].x = figures[n][i] % 2;
            a[i].y = figures[n][i] / 2;
        }
    }
}

void drawableTetromino::pieceFalling()
{
    for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
}

void drawableTetromino::colorInit()
{
    this->s.setTextureRect(sf::IntRect(color * 18, 0, 18, 18));
}

bool drawableTetromino::checkCollision()
{
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
        else if (field[a[i].y][a[i].x]) return 0;
    return 1;
}

int drawableTetromino::checkLines()
{
    int k = M - 1;
    int check = 0;

    for (int i = M - 1; i > 0; i--)
    {
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (field[i][j]) {
                count++;
            }
            field[k][j] = field[i][j];
        }
        if (count < N)
        {
            k--;
        }
        else if (count == N) {
            check++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (field[k + 2][i]) {
            check = -1;
        }
    }
    return check;
}

drawableTetromino::drawableTetromino(sf::RenderWindow& window)
        : window(window)
{
    srand(time(NULL));
    this->initPiece();
    this->hud = HUDptr(new drawableHUD(this->window));
    color = 1;
    TetrisVars::deltaTime = 0.5;
}

