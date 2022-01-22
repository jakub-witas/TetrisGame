#ifndef TETRISITIS_VARS_H
#define TETRISITIS_VARS_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class drawableHUD;
class drawableTetromino;
class EventHandler;
/*! \brief Deklaracja wska�nika shared pointer typu currentTetromino, kt�ry pozwala uzyska� dost�p do metod publicznych klasy drawableTetromino */
using currentTetromino = std::shared_ptr<drawableTetromino>;
/*! \brief Deklaracja wska�nika shared pointer typu eventPtr, kt�ry pozwala uzyska� dost�p do metod publicznych klasy EventHandler */
using eventPtr = std::shared_ptr<EventHandler>;
/*! \brief Deklaracja wska�nika shared pointer typu HUDptr, kt�ry pozwala uzyska� dost�p do metod publicznych klasy drawableHUD */
using HUDptr = std::shared_ptr<drawableHUD>;

/*! \brief Struktura odpowiadaj�ca za deklaracj� og�lnych sta�ych z zmiennych wykorzystywanych w metodach ca�ego programu */
struct TetrisVars
{
    static float countTime; /**< Zmienna s�u��ca na potrzeby licznika tzw. timer, kt�ry obs�uguj� zdarzenia zwi�zane z up�ywaj�cym czasem dzia�ania programu */
    static float deltaTime; /**< Zmienna wykorzystywana w liczniku czasu na potrzeby ustalenia op�nienia z jakim b�dzie on dzia�a� */
    static const int windowHeight = 400; /**< Sta�a definiuj�ca rozmiar okna w pionie */
    static const int windowWidth = 280; /**< Sta�a definiuj�ca rozmiar okna w poziomie */
};

#endif //TETRISITIS_VARS_H
