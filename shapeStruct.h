#ifndef TETRISITIS_SHAPESTRUCT_H
#define TETRISITIS_SHAPESTRUCT_H

/**
* @file shapeStruct.h
* @brief Plik nag��wkowy zawieraj�cy struktury, zmienne i tablice niezb�dne do zaprogramowania logiki gry, oraz obiekt�w
*/
#pragma once
///Sta�a przechowuj�ca wysoko�� planszy (w kolumnach)
const int M = 20;
///Sta�a przechowuj�ca szeroko�� planszy (w wierszach)
const int N = 10;
///Tablica typu int odpowiadaj�ca za pole gry
int field[M][N] = { 0 };

/** Struktura s�u��ca do okre�lania pozycji bloku na polu gry.
 *  Poprzez wykorzystanie tablic 4 elementowych (ka�dy blok sk�ada si� z 4 kwadracik�w), oraz zmiennych x i y mo�na manipulowa�
 *  po�o�eniem tetrimino na polu gry w dowolny spos�b.
 */
struct Point
{
    int x; /*!< Warto�� odpowiadaj�ca po�o�eniu klocka na planszy w p�aszczy�nie poziomej */
    int y; /*!< Warto�� odpowiadaj�ca po�o�eniu klocka na planszy w p�aszczy�nie pionowej */
}
///Tablice 4 elementowe pozwalaj�ce ustali� po�o�enie ka�dego z 4 element�w sk��daj�cych si� na tetrimino w p�tli
a[4], b[4];

/** Tablica dwuwymiarowa s�u��ca do tworzenia kszta�t�w tetrimino.
 *  Tablic� mo�na zaprezentowa� jak o 7 wierszy i 4 kolumny, z kt�rych ka�dy wiersz to zestaw cyfr odpowiadaj�cych jednemu blokowi.
 *  Przekazywane s� one do metody z algorytmem konfiguruj�cym, kt�ry interpretuje je jako gotowe kszta�ty.
 */
int figures[7][4] =
        {
                1,3,5,7, // I
                2,4,5,7, // Z
                3,5,4,6, // S
                3,5,4,7, // T
                2,3,5,7, // L
                3,5,7,6, // J
                2,3,4,5, // O
        };

#endif //TETRISITIS_SHAPESTRUCT_H
