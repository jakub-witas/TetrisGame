#ifndef TETRISITIS_DRAWABLEHUD_H
#define TETRISITIS_DRAWABLEHUD_H

/**
* @file drawableHUD.h
* @brief Klasa dzia�aj�ca jako ob�uga interfejsu tzw. HUD
*/
#pragma once
#include "Vars.h"
#include <sstream>

/*! \class drawableHUD
 *	\brief Klasa odpowiadaj�ca za interfejs gry
 *
 *	Klasa ta zawiera obiekty, oraz metody u�yte na potrzeby interfejsu tzw. HUD. Metody tej klasy odpowiadaj� m.in. za dzia�ania takie jak:
 *  przyotowanie t�a do wy�wietlenia na ekranie, renderowanie w oknie przygotowanych tekstur, tworzenie obiekt�w tekstowych sk�adaj�cych
 *  si� na sekcj� punktacji czy informacji o stanie rozgrywki
 */
class drawableHUD
{
    sf::RenderWindow& window; /**< Referencja do obiektu typu window klasy RenderWindow dostarczonej przez bibliotek� SFML. Wykorzystana zosta�a w celu mo�liwo�ci rysowania element�w interfejsu takich jak punktacja, czy t�o w oknie g��wnym gry poprzez odwo�anie do okna w p�tli g��wnej gry w funkcji main */
    sf::Texture background; /**< Obiekt background klasy Texture pozwalaj�cy za�adowa� do programu tekstur� zawieraj�c� t�o */
    sf::Sprite bg; /**< Gotowa do narysowania (renderowania) na ekranie, graficzna reprezentacja tekstury konieczna do wy�wietlenia t�a */
    sf::Text scoreLabelText; /**< Obiekt klasy Text odpowiadaj�cy za wy�wietlanie na ekranie napisu etykiety dla punktacji */
    sf::Text linesCompletedText; /**< Obiekt tekstowy klasy z SFML wy�wietlaj�cy etykiet� dla uko�czonych wierszy */
    sf::Text scoreText; /**< Wy�wietlanie liczby odpowiadaj�cej bie��cemu wynikowi gracza */
    sf::Font font; /**< Obiekt klasy Font odpowiadaj�cy za za�adowanie czcionki do programu */
    sf::Text linesCompletedValue; /**< Obiekt klasy Text, kt�ry s�u�y jako licznik uko�czonych wierszy */
    int linesVal; /**< Zmienna przechowuj�ca bie��c� ilo�� uko�czonych wierszy */
    /**< Zmienna klasy przechowuj�ca bie��cy wynik gracza */
public:
    /*! \brief Metoda inicjuj�ca t�o gry, kt�re nast�pnie po jej wykonaniu jest gotowe do narysowania w oknie
        Dzia�anie metody polega na za�adowaniu tekstury do pliku, a nast�pnie na�o�enie jej na Sprite czyli graficzn� reprezentacj�
        obiektu.
     */
    void backgroundInit();
    /*! \brief Metoda rysuj�ca za�adowane do programu t�o gry w oknie
        Bardzo prosta metoda, kt�ra przy pomocy funcji "draw" z biblioteki SFML rysuje uprzednio przygotowane t�o w oknie g��wnym
        programu.
     */
    void drawBackground();
    /*! \brief Metoda inicjuj�ca etykiet� punktacji
        Metoda ta odpowiadaja za przygotowanie etykiety punktacji z tekstem "Score:" do za�adowania do silnika gry,
        kt�ry nast�pnie wyswietli j� w oknie. Konfiguracja polega na: za�adowaniu czcionki z pliku i na�o�enia jej na obiekt,
        ustawienie parametr�w takich jak tekst, rozmiar, kolor, styl, czy pozycja, a nast�pnie wywo�aniu funkcji draw dla gotowego
        obiektu
     */
    void scoreLabel();
    /*! \brief Metoda obs�uguj�ca inkrementacj� wyniku gracza
        Prosta metoda inkrementuj�ca wynik gracza wraz z uka�czaniem przez niego kolejnych wierszy.
     */
    void updateScore();
    /*! \brief Metoda przygotowuj�ca do wy�wietlenia etykiet� uko�czonych wierszy */
    void linesCompletedLabel();
    /*! \brief Metoda pozwalaj�ca wy�wietli� w oknie punktacj� w postaci obiektu klasy Text
        Metoda pozwala przygotowa� graficzn� reprezentacj� wyniku gracza. Jej dzia�anie polega na ustawieniu czcionki, przekonwertowaniu
        tekstu na warto�� numeryczn�, ustawieniu podstawowych parametr�w takich jak kolor, rozmiar, pozycja, styl, oraz wy�wietleniu
        gotowego obiektu w oknie
     */
    void score();
    /*! \brief Metoda wy�wietlaj�ca w oknie bie��c� ilo�� linii uko�czonch przez gracza jako obiekt typu Text
        Metoda ta tworzy obiekt typu Text, kt�ry nast�pnie po przekonwertowaniu na typ numeryczny i nadaniu mu odpowiednich parametr�w
        takich jak czcionka, rozmiar, kolor itp. zostaje wy�wietlony na ekranie.
     */
    void linesCompletedValueText();
    /*! \brief Metoda inkremenruj�ca ilo�� uko�czonych wierszy o 1 */
    void linesUpdate();
    /*! \brief Metoda rysuj�ca granice pola gry
        Przy pomocy obiekt�w typu RectangleShape metoda ta rysuje linie, kt�re s�u�� jako granice pola gry. Po nadaniu odpowiednich
        parametr�w dla ka�dej z 3 linii zostaje ona wy�wietlona w oknie przy pomocy funkcji window.draw().
     */
    void gameBorders();
    /*! \brief Konstruktor klasy drawableHUD
        \param window Referencja do okna g��wnego w celu rysowania na nim wygenerowanych obiekt�w
        Konstruktor ustawia warto�� pocz�tkow� zmiennej wyniku, oraz inicjuje metod� backgroundInit
     */

    explicit drawableHUD(sf::RenderWindow &window);

    int scoreValue;
};




#endif //TETRISITIS_DRAWABLEHUD_H
