#ifndef TETRISITIS_EVENTHANDLER_H
#define TETRISITIS_EVENTHANDLER_H


/**
* @file EventHandler.h
* @brief Klasa dzia�aj�ca jako ob�uga zdarze� generowanych w programie
*/
#pragma once
#include "Vars.h"
#include "GameEngine.h"
#include "drawableTetromino.h"

/*! \class EventHandler
 *	\brief Klasa obs�ugi zdarze� w programie
 *
 *	Klasa ta obs�uguje i przetwarza zdarzenia klawiszowe, oraz wykonuje metody przypisane do tych zdarze� pozwalaj�c uzyska� mo�liwo�� ruchu bloku
 */
class EventHandler
{
public:
    /*! \brief Metoda realizuj�ca zdarzenia klawiszowe pobierane od u�ytkownika podczas gry
        \param event referencja pozwalaj�ca uzyska� dost�p do obiektu realizuj�cego zdarzenia znajduj�cego si� w p�tli g��wnej gry
        \param tetromino referencja do tzw "sprytnego wska�nika" pozwalaj�cego wykorzysta� metody z klasy drawableTetromino na potrzeby wykonania zdarze� przypisanych poszczeg�lnym klawiszom
        Metoda ta poprzez wywo�anie odpowiednich metod z klasy drawableTetromino pozwala zarz�dza� zdarzeniami generowanymi w programie
        podczas naci�ni�cia odpowiedniego klawisza spo�r�d obs�ugiwanych.
     */
    static void moveEvents(sf::Event &event, currentTetromino& tetromino, bool paused);
    /*! \brief Konstruktor klasy EventHandler */
    EventHandler();
};




#endif //TETRISITIS_EVENTHANDLER_H
