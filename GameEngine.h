#ifndef TETRISITIS_GAMEENGINE_H
#define TETRISITIS_GAMEENGINE_H


#pragma once
#include "Vars.h"
#include "EventHandler.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "drawableTetromino.h"

class GameEngine {

    sf::RenderWindow& window; /**< Referencja do g��wnego okna gry pozwalaj�ca odwo�a� si� do niego z poziomu metod znajduj�cych si� w klasie */
    sf::Text scoreLabelText; /**< Obiekt klasy Text odpowiadaj�cy za wy�wietlanie na ekranie napisu etykiety dla punktacji */
    sf::Text linesCompletedText; /**< Obiekt tekstowy klasy z SFML wy�wietlaj�cy etykiet� dla uko�czonych wierszy */
    sf::Text scoreText; /**< Wy�wietlanie liczby odpowiadaj�cej bie��cemu wynikowi gracza */
    sf::Font font; /**< Obiekt klasy Font odpowiadaj�cy za za�adowanie czcionki do programu */
    int scoreValue; /**< Zmienna klasy przechowuj�ca bie��cy wynik gracza */
    currentTetromino tetromino; /**< Wska�nik shared pointer typu currentTetromino daj�cy dost�p do metod publicznych klasy drawableTetromino */
    eventPtr event_ptr; /**< Wska�nik shared pointer typu eventPtr daj�cy dost�p do metod publicznych klasy EventHandler */
    HUDptr hud; /**< Wska�nik shared pointer typu HUDptr daj�cy dost�p do metod publicznych klasy drawableHUD */
public:
    /*! \brief G��wna metoda rysuj�ca na ekranie obiekty renderowalne z pozosta�ych klas (bitmapy, bloki, tekst)
        Odpowiada ona za skompletowanie wszystkich metod rysuj�cych z pozosta�ych klas na potrzeby wywo�ania ich w funkcji main programu.
     */
    void draw();
    /*! \brief G��wna metoda typu update, kt�ra na bie��co sprawdza i wykonuje akcje
        \param event referencja do obiektu klasy Event zarz�dzaj�cego zdarzeniami
        Metoda ta zgodnie z licznikiem czasu obs�uguje aktualizowanie i wywo�ywanie poszczeg�lnych zdarze� w programie.
        Zatem aktualizuj�c zdarzenia zgodnie z op�nieniem tzw. "delay" wykonywane s� etapy takie jak konfiguracja bloku,
        sprawdzanie wierszy wraz z ko�cow� obs�ug� naliczania punkt�w, oraz uko�czonych linii, a tak�e wywo�anie zdarzenia ko�ca gry.
     */
    void update(sf::Event &event);
    /*! \brief G��wna funkcja zarz�dzaj�ca zdarzeniami zwi�zanymi z ruchem blok�w
        \param event referencja do obiektu klasy Event zarz�dzaj�cego zdarzeniami na potrzeby korzystania ze zdarze� klawiszowych
     */
    void moveEvents(sf::Event &event);
    /*! \brief Konstruktor zawieraj�cy deklaracje zmiennych i wska�nik�w typu shared pointer na potrzeby klasy
        \param window Referencja do okna g��wnego programu
     */
    explicit GameEngine(sf::RenderWindow& window);

    void pause();
    int gameOver();
    bool paused;
    bool gameOverState;
};


#endif //TETRISITIS_GAMEENGINE_H
