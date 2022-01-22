#ifndef TETRISITIS_DRAWABLETETROMINO_H
#define TETRISITIS_DRAWABLETETROMINO_H


/**
* @file drawableTetromino.h
* @brief Klasa obs�uguj�ca logik� i konstruowanie blok�w do renderowania na ekranie
*/
#pragma once
#include "Vars.h"
#include <SFML/Graphics/Sprite.hpp>
#include "DrawableHUD.h"
#include "GameEngine.h"

/*! \class drawableTetromino
 *	\brief Klasa odpowiadaj�ca za wszystkie akcje i zachowania zwi�zane z danym blokiem
 *
 *	Klasa ta zawiera obiekty, oraz metody u�yte na potrzeby logiki i zachowa� bloku. Metody i zmienne zawarte w tej klasie
 *	odpowiadaj� m.in. za ruch bloku, rotacje, sprawdzanie kolizji, kolorowanie blok�w, sprawdzanie wierszy, konfigurowanie
 *	kszta�t�w, czy te� rysowanie ko�cowego obiektu w oknie.
 */
class drawableTetromino
{
    sf::RenderWindow& window; /**< Referencja do okna g��wnego programu pozwalaj�ca przekaza� do niego ko�cowy obiekt gotowy do narysowania */
    sf::Texture t; /**< Tekstura zawieraj�ca bitmap� z blokami z kt�rej wycinane i konstruowane s� kszta�ty */
    sf::Sprite s; /**< Gotowa do renderowania graficzna reprezentacja bloku */
    int blockNumber; /**< Zmienna przechowuj�ca informacje o bie��cym numerze bloku na potrzeby konfiguracji i wy�wietlenia go na ekranie */
    int color; /**< Zmienna przechowuj�ca informacje o kolorze rysowanego bloku */
    HUDptr hud; /**< Wska�nik shared pointer typu HUDptr pozwalaj�cy uzyska� dost�p do dowolnych publicznych metod klasy drawableHUD */

public:
    /*! \brief Metoda obs�uguj�ca ruch bloku w p�aszczy�nie poziomej (lewo, prawo)
        \param direction parametr odpowiadaj�cy za okre�lenie kierunku poruszania, w zale�no�ci od wci�ni�tego klawisza przyjmuje dodatni� lub ujemn� warto��
        Dzia�anie metody polega na zmianie pozycji w p�aszczy�nie poziomej dla ka�dego kwadracika sk�adaj�cego si� na gotowy blok.
        Operacja ta odbywa si� w p�tli iteruj�cej czterokrotnie dla ka�dego kwadracika. Do metody zosta�o dodane r�wnie� zabezpieczenie
        przed kolizj�, kt�re jeszcze przed wykonaniem ruchu zapisuje pozycje wszystkich kwadracik�w do specjalnego bufora, a nast�pnie
        sprawdza czy �aden z nich nie koliduje z pozosta�ymi obiektami gry. Je�li kolizja nast�pi ruch zostanie cofni�ty.
     */
    void moveSides(float direction);
    /*! \brief Metoda obs�uguj�ca ruch rotacyjny bloku
        \param isRotating parametr odpowiadaj�cy za okre�lenie czy rotacja nast�puje czy te� nie zatem w zale�no�ci od przypadku przyjmuje warto�ci kolejno true lub false
        Rotacja polega na wyznaczeniu punktu, kt�ry mo�na nazwa� centrum rotacji, a nast�pnie z wykorzystaniem zmiennych pomocniczych
        obracania czyli zmieniania iteracyjnie pozycji ka�dego z 4 kwadracik�w w taki spos�b aby po zako�czonej operacji prezentowa�y
        one blok obr�cony o 90 stopni. Rotacja zosta�a zabezpieczona przed kolizj� zatem operacja zostaje odwr�cona ilekro� blok b�dzie
        kolidowa� z innymi obiektami gry. Dodatkowe zabezpieczenia przed niepo��danymi zdarzeniami zosta�y r�wnie� umieszczone w metodzie
        moveEvents klasy EventHandler.
     */
    void rotate(bool isRotating);
    /*! \brief Metoda dla poruszania bie��cym tetrimino w d� (kierunek jest tu tylko jeden wi�c u�ycie parametru nie jest konieczne)
        Dzia�anie tej metody powi�zane jest z obs�ug� zdarze�. Ilekro� gracz naci�nie strza�k� kierunkow� w d� p�tla for iteracyjnie
        zmieni pozycje kwadracik�w przemieszczaj�c blok o jeden wiersz ni�ej. Zabezpieczenie metody przed kolizj� i niepo��danym
        dzia�aniem zosta�o umieszczone zar�wno w jej ciele jak i klasie obs�ugi zdarze� EventHandler tak aby nie mo�na by�o poruszy�
        blokiem, kt�ry ju� opad� na stos, oraz w razie napotkania kolizji odm�wi� akcji.
     */
    void moveDown();
    /*! \brief G��wna metoda odpowiadaj�ca za rysowanie skonstruowanego i gotowego obiektu bloku
        Metoda ta dzi�ki p�tlom for iteruje w obr�bie pola gry wycinaj�c tekstury z bitmapy, ustawiaj�c pozycj�, odsuwaj�c
        nieco pole gry od kraw�dzi okna i rysuj�c bloki kt�re ju� si� tam znajduj� tak aby by�y one widoczne na
        stosie na dole planszy. Kolejna p�tla for poni�ej odpowiada ju� za rysowanie bie��cego bloku nadaj�c mu pozycj�,
        wylosowany kolor, oraz w/w tzw. "offset".
     */
    void draw();
    /*! \brief Metoda obs�uguj�ca inicjowanie bloku na kt�re sk�ada si� mi�dzy innymi wst�pne utworzenie tekstury
        Metoda ta �aduje tekstur� z pliku, nak�ada j� na obiekt typu Sprite, oraz przydziela kolor bloku spo�r�d 7 dost�pnych mo�liwo�ci.
     */
    void initPiece();
    /*! \brief Metoda w kt�rej konstruowane s� bloki, kt�re nast�pnie gotowe s� do narysowania i manipulacji nimi w grze
        Metoda ta po uprzednim sprawdzeniu kolizji, losuje i przypisuje kolor na odpowiedni� pozycj� w obr�bie pola na kt�rej
        znajduje si� blok. Nast�pnie po wylosowaniu rodzaju bloku spo�r�d 7 mo�liwych wykonywany jest algorytm, kt�ry na
        podstawie tablicy figures wybiera odpowiednie elementy (zestawy cyfr odpowiadaj�ce danemu blokowi) na kt�rych wykonuje on
        operacje modulo, oraz dzielenia w celu przypisania kwadracikom odpowiedniej pozycji. W ten spos�b uzyskujemy gotowy kszta�t bloku.
     */
    void config();
    /*! \brief Metoda odpowiadaj�ca za samoczynne opadanie bloku zgodnie z ustalonym op�nieniem wynosz�cym 0.5s
        Metoda ta zgodnie z op�nieniem 0.5 sekundy iteracyjnie zmienia pozycj� kwadracik�w tak aby uzyska� przemieszczenie
        bie��cego bloku o jeden wiersz w d�.
     */
    void pieceFalling();
    /*! \brief Metoda zajmuj�ca si� wst�pnym pozyskaniem koloru dla rysowanego bloku
        W metodzie tej na potrzeby uzyskania koloru z bitmapy na kt�rej znajduj� si� klocki wyci�ta zostaje ta cz��, kt�ra odpowiada
        zadanemu kolorowi.
     */
    void colorInit();
    /*! \brief G��wna metoda sprawdzaj�ca r�ne typy kolizji wykorzystywana w wielu metodach projektu
        Metoda ta iteracyjnie przeprowadzaj�c operacj� sprawdzania pozycji kwadracik�w sk�adaj�cych si� na blok bada kolizj� z kraw�dziami
        pola gry, oraz pozosta�ymi blokami. Po wykonaniu metoda zwraca warto�� odpowiadaj�c� sytuacji kt�ra nast�pi�a (wykrycie lub brak
        kolizji).
     */
    bool checkCollision();
    /*! \brief Metoda zajmuj�ca si� sprawdzaniem czy zosta�y uko�czone jakiekolwiek wiersze. Je�li tak s� one usuwane
        Metoda ta iteracyjnie badaj�c stan pola gry pozwala na sprawdzenie, czy jakiekolwiek wiersze zosta�y ju� uko�czone.
        Je�li taka sytuacja nast�pi kompletne wiersze zostaj� usuni�te, a warto�� zwracana przez t� metod� zostaje przekazana do metody
        update w celu inkrementacji warto�ci wyniku gracza. Metoda ta obs�uguj� r�wnie� sytuacj� kiedy gra zostaje zako�czona tzn.
        je�li pole gry zosta�o zape�nione w danym pionie, uk�adanie blok�w nie mo�e by� kontynuowane.
     */
    int checkLines();
    /*! \brief Konstruktor klasy drawableTetromino gdzie nast�puje inicjowanie wybranych metod, zmiennych i pozosta�ych element�w koniecznych dla danej klasy
        \param window referencja do okna g��wnego gry konieczna w celu przekazania wszystkich utworzonych obiekt�w renderowalnych do wy�wietlenia przez silnik gry
        Konstruktor tej klasy zawiera deklaracj� ziarna generatora liczb losowych, wywo�anie metody inicjuj�cej blok, deklaracj� wska�nika
        shared pointer posiadaj�cego metody klasy drawableHUD, oraz deklaracj� pocz�tkowego koloru i warto�ci op�nienia dla timera.
     */
    drawableTetromino(sf::RenderWindow& window);
};




#endif //TETRISITIS_DRAWABLETETROMINO_H
