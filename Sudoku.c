// gcc Sudoku.c -o Sudoku.out
// ./main.out
//=========================================================================================================================================
// Librerias:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//=========================================================================================================================================
// Macros:
#define FILA 9
#define COLUMNA 9
#define ORDEN 10
//=========================================================================================================================================
// Declaracion de variables globales: [TABLEROS]
// 81 elementos por arreglo, utilizados para realizar los tableros de juego, 10 niveles diferentes dentro de la misma dificultad.
int EASY[10][81]={ 
                    {7,3,0,0,0,0,0,2,0,5,0,0,9,0,0,8,0,4,0,0,2,3,4,0,5,0,0,0,0,0,0,7,0,0,8,9,9,0,6,2,5,0,0,0,0,4,0,0,0,0,0,2,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,3,1,0,0,5,0,4,3,0,0,0,0,1,0},
                    {0,0,0,0,9,0,6,5,0,0,0,0,0,0,0,0,0,7,0,0,0,5,0,7,0,4,0,0,5,2,0,1,0,0,0,0,0,0,0,0,2,9,0,0,0,0,3,0,4,0,0,0,0,9,0,1,6,0,5,0,2,3,0,8,0,0,0,0,4,7,0,0,0,0,0,0,7,3,0,9,0},
                    {0,1,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,2,0,0,3,9,0,0,0,6,5,0,0,8,0,0,0,4,9,0,9,0,0,1,0,3,6,0,0,0,0,0,0,0,7,0,1,0,3,0,2,0,5,0,7,0,7,0,5,0,6,0,0,0,0,0,0,6,7,0,0,0,9,0},
                    {6,0,4,0,0,0,9,2,8,3,9,0,0,0,0,0,1,6,0,0,0,0,0,0,0,0,0,0,5,0,2,0,7,0,0,0,9,0,1,8,4,0,0,0,0,0,7,0,9,0,3,0,0,0,0,0,0,5,0,0,0,0,1,8,0,0,0,0,0,0,6,3,0,0,0,7,0,8,0,0,0},
                    {1,0,0,0,5,0,7,0,0,0,5,0,2,0,0,3,8,9,0,0,4,0,3,8,0,0,0,0,0,8,0,0,9,0,7,0,2,0,0,0,0,0,4,9,0,0,0,5,0,0,0,0,0,0,3,7,6,0,0,0,0,0,5,0,0,0,0,0,0,8,0,1,0,0,0,0,0,3,2,6,0},
                    {3,6,0,0,0,0,0,9,0,0,8,9,5,0,0,0,2,0,0,0,5,0,9,2,0,0,0,0,0,0,0,8,5,0,0,0,0,0,7,0,4,1,3,0,0,0,1,6,2,0,0,7,0,0,0,7,0,0,0,0,0,0,2,0,0,0,0,5,0,0,6,0,0,0,0,4,0,0,0,8,0},
                    {0,0,0,2,0,0,5,6,7,0,0,0,5,0,8,0,0,1,3,0,0,0,0,0,8,0,4,8,0,0,0,0,1,0,0,0,1,0,2,0,0,0,3,7,8,0,6,0,0,0,0,0,0,0,2,0,7,0,5,0,0,1,0,0,0,0,0,0,3,2,0,0,0,3,0,4,0,9,0,0,0},
                    {6,0,0,5,0,0,7,0,0,0,9,0,2,4,0,0,3,0,4,0,0,0,0,0,0,0,0,0,0,0,0,3,8,0,4,7,0,0,0,4,0,0,8,0,0,0,0,9,7,0,5,0,0,6,0,6,0,0,2,0,0,8,3,1,0,0,0,0,0,0,0,9,0,0,0,0,8,0,6,0,0},
                    {0,0,0,1,0,0,0,8,0,5,0,6,3,0,0,0,0,1,0,0,0,0,0,9,0,3,5,0,0,7,0,0,3,0,0,0,0,0,1,7,0,0,0,6,0,9,6,0,0,0,8,0,0,0,0,0,4,0,3,0,0,9,7,0,3,0,2,0,0,8,5,0,0,0,8,0,5,6,0,0,4},
                    {0,2,0,0,0,9,6,0,0,0,9,3,0,0,0,4,0,0,0,7,0,0,3,0,5,8,0,7,0,0,3,0,0,8,0,0,0,1,0,0,0,6,0,9,2,0,0,6,0,0,5,0,0,3,0,0,2,0,4,1,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,3,0,0},
                 };
int MEDIUM[10][81]={
                    {0,0,2,9,0,5,0,0,0,0,0,0,0,0,6,0,0,3,7,0,1,0,0,8,4,0,0,0,0,0,7,0,0,0,0,4,0,9,6,3,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,8,0,3,9,0,3,5,0,0,0,0,0,0,0},
                    {4,0,0,6,0,9,0,0,0,0,0,0,0,5,0,0,9,0,8,0,2,0,0,4,0,0,0,0,3,0,4,8,0,0,0,5,0,8,0,7,0,0,0,0,0,1,0,0,0,0,0,4,0,7,9,0,0,0,0,0,2,0,0,0,6,0,5,0,0,0,0,9,0,0,5,0,0,8,0,0,0},
                    {0,0,5,2,8,0,0,1,0,6,0,0,0,0,0,0,0,5,9,0,0,0,0,0,7,0,0,2,0,0,0,0,6,0,0,8,3,9,0,0,0,0,5,0,0,0,8,0,5,0,2,6,0,1,8,0,0,7,5,0,0,0,3,5,3,7,6,0,0,0,0,0,0,0,0,0,3,8,0,0,0},
                    {0,1,0,0,0,0,3,0,0,0,0,3,0,0,7,8,0,0,0,7,0,0,0,5,0,2,4,0,0,0,2,0,0,0,3,8,0,0,0,0,0,0,5,0,0,0,2,0,0,0,9,0,0,0,0,0,6,3,0,0,0,9,0,0,0,0,6,8,0,0,0,5,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,9,3,0,7,0,0,0,5,0,0,6,2,0,0,0,0,9,0,4,0,0,0,0,0,0,0,9,7,0,0,0,2,0,6,0,0,0,0,5,0,0,1,4,0,0,0,0,0,9,0,0,1,0,0,3,0,4,0,0,0,0,0,0,0,0,0,0,0,0,5,3,7,0,0,0,0,0},
                    {9,0,0,3,0,0,0,0,0,0,0,5,0,0,6,0,0,0,0,0,0,0,0,7,3,0,4,0,0,7,0,0,0,1,0,8,5,0,0,0,6,0,0,0,0,1,0,0,5,0,0,4,0,0,2,0,0,0,4,0,0,0,0,0,0,0,1,0,9,7,0,0,0,6,0,7,0,5,0,0,0},
                    {1,8,0,0,0,0,0,0,7,2,0,0,0,8,9,0,0,0,0,6,0,0,0,0,0,5,0,8,0,0,0,0,7,0,0,0,4,0,3,0,0,0,2,0,0,0,0,0,0,0,5,6,0,0,0,0,0,0,6,4,0,0,3,0,0,0,1,0,0,5,0,0,0,0,0,2,0,0,8,0,0},
                    {0,0,0,0,0,0,0,4,9,0,5,0,0,0,0,0,0,0,2,0,0,0,5,1,0,0,7,0,0,8,1,0,0,0,0,0,0,0,0,3,0,0,6,0,0,0,1,0,6,0,7,3,0,8,4,0,0,0,0,6,0,0,0,6,0,0,0,2,0,0,0,0,0,9,0,0,0,0,0,0,1},
                    {9,1,0,7,2,0,0,0,0,0,0,0,0,0,3,6,4,0,0,7,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,3,0,0,8,0,7,0,0,2,0,4,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,9,5,0,8,9,0,0,0,3,0,0},
                    {0,0,0,3,9,0,0,5,0,7,0,0,0,0,0,2,0,9,8,0,0,0,4,0,3,0,0,0,0,0,0,1,0,4,0,0,0,0,0,8,0,0,9,0,0,4,0,0,0,0,2,0,0,0,0,0,9,0,7,6,0,0,8,0,0,0,5,0,0,0,0,6,0,0,5,0,0,0,0,0,0}
                   };
int HARD[10][81]={
                    {9,0,3,0,0,0,0,0,6,0,0,0,0,0,2,0,0,0,0,6,0,3,7,0,0,0,9,3,0,1,6,0,0,0,0,0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,0,0,3,4,0,1,8,0,2,0,7,0,0,0,0,6,8,0,0,0,9,5,0,0,0,0,0,0,0,8,0},
                    {3,0,1,0,0,0,0,0,0,0,5,0,0,3,8,0,0,0,0,0,0,4,0,0,0,0,0,9,1,0,0,0,7,8,0,0,0,0,0,0,0,3,6,9,0,8,4,0,0,0,0,1,7,0,0,8,0,0,0,0,0,1,0,0,0,0,0,1,0,5,0,0,0,3,0,2,0,9,0,6,0},
                    {0,0,2,5,0,0,3,0,0,0,0,0,4,0,0,7,9,0,0,0,0,0,0,0,4,5,0,3,0,0,0,4,0,0,0,1,9,0,5,0,6,0,0,0,0,0,7,1,0,0,0,0,3,0,0,0,0,3,2,8,0,0,0,8,0,0,0,0,9,0,0,0,0,0,0,0,5,0,6,0,0},
                    {0,0,0,5,8,0,6,0,0,0,0,0,6,0,2,0,0,0,0,0,0,0,0,0,7,1,0,8,3,0,0,0,0,0,4,0,0,0,6,1,0,0,0,0,0,2,0,0,7,0,0,0,3,5,3,0,5,0,9,0,0,0,8,0,0,0,0,0,0,9,0,0,0,0,0,0,1,0,0,0,0},
                    {0,0,0,0,8,0,3,9,0,2,0,5,0,6,4,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,3,0,1,7,0,0,0,0,0,0,0,0,2,0,0,0,1,0,8,0,0,0,6,0,0,4,0,0,0,3,0,0,0,0,2,3,0,0,0,5,0,0},
                    {0,0,4,0,0,5,1,0,0,9,6,0,0,0,0,2,0,0,0,0,0,0,0,0,7,8,0,1,0,0,0,6,0,0,2,0,0,0,0,5,0,3,0,0,8,0,0,0,0,0,8,9,0,0,0,7,0,0,0,0,0,0,3,0,0,0,0,3,1,0,0,0,8,0,5,7,0,4,0,0,0},
                    {0,4,0,0,0,0,0,0,2,1,0,0,2,8,0,9,6,0,0,0,0,0,6,0,0,0,3,0,0,0,0,0,0,0,0,0,0,7,0,1,0,0,0,4,0,2,0,0,7,0,8,0,0,9,0,0,6,0,1,0,0,5,0,0,0,0,0,0,0,0,0,8,0,5,7,0,2,0,0,0,6},
                    {9,0,0,0,0,6,5,7,0,0,0,0,0,0,0,1,0,0,0,6,0,0,4,0,0,0,3,0,1,3,2,0,0,0,9,0,0,7,0,0,0,0,0,0,0,2,0,9,0,0,7,0,0,0,4,0,0,0,0,0,8,0,2,7,0,0,0,0,0,0,3,0,0,0,0,1,0,4,0,0,7},
                    {0,0,0,7,5,0,0,0,9,6,0,3,8,0,0,0,0,0,0,0,5,0,9,0,0,4,0,0,0,0,0,0,0,0,0,0,4,0,1,0,0,6,8,0,0,0,0,0,1,2,0,0,6,0,8,0,4,0,0,0,1,0,0,9,0,0,0,0,7,0,0,0,0,7,0,0,0,0,5,2,0},
                    {0,0,0,0,6,8,5,0,0,1,0,0,3,0,0,0,0,7,0,8,0,4,0,0,0,0,0,0,0,0,5,9,0,0,1,0,0,0,3,0,2,0,0,0,0,0,6,4,0,0,0,9,0,0,0,2,0,0,7,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,2,8,0,0}
                 };
// 81 elementos por arreglo, utilizados para realizar la busqueda de soluciones del juego, 10 niveles diferentes dentro de la misma dificultad.                 
int SOLEASY[10][81]={
    {7,3,4,8,1,5,9,2,6,5,6,1,9,2,7,8,3,4,8,9,2,3,4,6,5,7,1,3,2,5,1,7,4,6,8,9,9,7,6,2,5,8,1,4,3,4,1,8,6,9,3,2,5,7,1,5,7,4,6,2,3,9,8,2,8,9,7,3,1,4,6,5,6,4,3,5,8,9,7,1,2},
    {3,7,4,8,9,2,6,5,1,5,2,9,6,4,1,3,8,7,1,6,8,5,3,7,9,4,2,9,5,2,3,1,6,4,7,8,4,8,1,7,2,9,5,6,3,6,3,7,4,8,5,1,2,9,7,1,6,9,5,8,2,3,4,8,9,3,2,6,4,7,1,5,2,4,5,1,7,3,8,9,6},
    {9,1,4,5,2,6,8,3,7,6,5,3,1,8,7,9,2,4,2,7,8,3,9,4,1,5,6,5,6,1,8,7,3,2,4,9,8,9,7,4,1,2,3,6,5,3,4,2,6,5,9,7,8,1,1,3,9,2,4,5,6,7,8,7,2,5,9,6,8,4,1,3,4,8,6,7,3,1,5,9,2},
    {6,1,4,3,7,5,9,2,8,3,9,7,4,8,2,5,1,6,5,8,2,6,9,1,3,4,7,4,5,8,2,1,7,6,3,9,9,3,1,8,4,6,2,7,5,2,7,6,9,5,3,1,8,4,7,2,3,5,6,4,8,9,1,8,4,5,1,2,9,7,6,3,1,6,9,7,3,8,4,5,2},
    {1,8,3,9,5,6,7,2,4,6,5,7,2,1,4,3,8,9,9,2,4,7,3,8,1,5,6,4,3,8,1,6,9,5,7,2,2,6,1,3,7,5,4,9,8,7,9,5,4,8,2,6,1,3,3,7,6,8,2,1,9,4,5,5,4,2,6,9,7,8,3,1,8,1,9,5,4,3,2,6,7},
    {3,6,2,1,7,4,8,9,5,7,8,9,5,6,3,1,2,4,1,4,5,8,9,2,6,7,3,9,3,4,7,8,5,2,1,6,8,2,7,6,4,1,3,5,9,5,1,6,2,3,9,7,4,8,4,7,8,9,1,6,5,3,2,2,9,1,3,5,8,4,6,7,6,5,3,4,2,7,9,8,1},
    {9,1,8,2,3,4,5,6,7,7,2,4,5,6,8,9,3,1,3,5,6,9,1,7,8,2,4,8,7,9,3,4,1,6,5,2,1,4,2,6,9,5,3,7,8,5,6,3,7,8,2,1,4,9,2,9,7,8,5,6,4,1,3,4,8,5,1,7,3,2,9,6,6,3,1,4,2,9,7,8,5},
    {6,8,2,5,9,3,7,1,4,7,9,1,2,4,6,5,3,8,4,5,3,8,7,1,9,6,2,5,2,6,9,3,8,1,4,7,3,1,7,4,6,2,8,9,5,8,4,9,7,1,5,3,2,6,9,6,5,1,2,7,4,8,3,1,3,8,6,5,4,2,7,9,2,7,4,3,8,9,6,5,1},
    {4,9,3,1,7,5,6,8,2,5,8,6,3,2,4,9,7,1,7,1,2,6,8,9,4,3,5,8,2,7,5,6,3,1,4,9,3,4,1,7,9,2,5,6,8,9,6,5,4,1,8,7,2,3,6,5,4,8,3,1,2,9,7,1,3,9,2,4,7,8,5,6,2,7,8,9,5,6,3,1,4},
    {4,2,8,5,7,9,6,3,1,5,9,3,1,6,8,4,2,7,6,7,1,2,3,4,5,8,9,7,4,9,3,1,2,8,5,6,3,1,5,4,8,6,7,9,2,2,8,6,7,9,5,1,4,3,8,3,2,6,4,1,9,7,5,9,6,7,8,5,3,2,1,4,1,5,4,9,2,7,3,6,8},
    };
int SOLMEDIUM[10][81]={
    {8,3,2,9,4,5,6,1,7,9,4,5,1,7,6,8,2,3,7,6,1,2,3,8,4,5,9,5,1,8,7,6,2,9,3,4,2,9,6,3,5,4,7,8,1,4,7,3,8,9,1,2,6,5,6,8,9,4,1,3,5,7,2,1,2,4,5,8,7,3,9,6,3,5,7,6,2,9,1,4,8},
    {4,5,3,6,1,9,8,7,2,6,7,1,8,5,2,3,9,4,8,9,2,3,7,4,5,6,1,7,3,9,4,8,1,6,2,5,5,8,4,7,2,6,9,1,3,1,2,6,9,3,5,4,8,7,9,4,7,1,6,3,2,5,8,2,6,8,5,4,7,1,3,9,3,1,5,2,9,8,7,4,6},
    {4,7,5,2,8,3,9,1,6,6,1,8,9,4,7,3,2,5,9,2,3,1,6,5,7,8,4,2,5,1,3,7,6,4,9,8,3,9,6,8,1,4,5,7,2,7,8,4,5,9,2,6,3,1,8,4,2,7,5,9,1,6,3,5,3,7,6,2,4,8,4,9,1,6,9,4,3,8,2,5,7},
    {2,1,5,4,6,8,3,7,9,4,9,3,1,2,7,8,5,6,6,7,8,9,3,5,1,2,4,7,5,4,2,1,6,9,3,8,8,6,9,7,4,2,5,1,2,3,2,1,8,5,9,4,6,7,5,8,6,3,7,4,2,9,1,9,3,2,6,8,1,7,4,5,1,4,7,5,9,2,6,8,3},
    {6,2,1,5,9,3,8,7,4,4,7,5,1,8,6,2,3,9,3,8,9,2,4,7,1,6,5,5,3,8,9,7,1,6,4,2,9,6,7,4,2,8,5,1,3,1,4,2,3,6,5,7,9,8,2,1,6,8,3,9,4,5,7,7,9,4,6,5,2,3,8,1,8,5,3,7,1,4,9,2,6},
    {9,4,2,3,1,8,6,7,5,7,3,5,4,9,6,8,1,2,8,1,6,2,5,7,3,9,4,6,2,7,9,3,4,1,5,8,5,9,4,8,6,1,2,3,7,1,8,3,5,7,2,4,6,9,2,7,9,6,4,3,5,8,1,3,5,8,1,2,9,7,4,6,4,6,1,7,8,5,9,2,3},
    {1,8,5,3,4,6,8,2,7,2,4,7,5,8,9,3,6,1,3,6,9,7,1,2,4,5,8,8,5,6,4,2,7,1,3,9,4,7,3,6,9,1,2,8,5,9,1,2,8,3,5,6,7,4,5,2,8,9,6,4,7,1,3,6,3,4,1,7,8,5,9,2,7,9,1,2,5,3,8,4,6},
    {1,3,7,2,6,8,5,4,9,8,5,9,4,7,3,1,2,6,2,4,6,9,5,1,8,3,7,3,6,8,1,9,2,7,5,4,9,7,4,3,8,5,6,1,2,5,1,2,6,4,7,3,9,8,4,2,6,7,1,6,9,8,5,6,8,1,5,2,9,4,7,3,7,9,5,8,3,4,2,6,1},
    {9,1,4,7,2,6,5,3,8,8,5,2,1,9,3,6,4,7,6,7,3,5,8,4,9,1,2,1,2,6,8,3,9,7,5,4,7,9,5,2,4,1,8,6,3,3,4,8,6,7,5,1,2,9,4,3,1,9,5,7,2,8,6,2,6,7,3,1,8,4,9,5,5,8,9,4,6,2,3,7,1},
    {2,4,6,3,9,7,8,5,1,7,5,3,6,8,1,2,4,9,8,9,1,2,4,5,3,6,7,9,6,2,7,1,3,4,8,5,5,3,7,8,6,4,9,1,2,4,1,8,9,5,2,6,7,3,1,2,9,4,7,6,5,3,8,3,7,4,5,2,8,1,9,6,6,8,5,1,3,9,7,2,4}
};
int SOLHARD[10][81]={
    {9,7,3,1,8,4,5,2,6,8,5,4,9,6,2,3,1,7,1,6,2,3,7,5,8,4,9,3,8,1,6,4,7,9,5,2,4,9,5,2,3,1,6,7,8,6,2,7,5,9,8,1,3,4,5,1,8,4,2,9,7,6,3,7,4,6,8,1,3,2,9,5,2,3,9,7,5,6,4,8,1},
    {3,9,1,7,2,5,4,8,6,4,5,7,6,3,8,9,2,1,2,6,8,4,9,1,3,5,7,9,1,6,5,4,7,8,3,2,5,7,2,1,8,3,6,9,4,8,4,3,9,6,2,1,7,5,6,8,5,3,7,4,2,1,9,7,2,9,8,1,6,5,4,3,1,3,4,2,5,9,7,6,8},
    {4,9,2,5,7,6,3,1,8,5,8,6,4,3,1,7,9,2,1,3,7,8,9,2,4,5,6,3,2,8,9,4,7,5,6,1,9,4,5,1,6,3,8,2,7,6,7,1,2,8,5,9,3,4,7,6,9,3,2,8,1,4,5,8,5,4,6,1,9,2,7,3,2,1,3,7,5,4,6,8,9},
    {7,2,3,5,8,1,6,9,4,1,4,9,6,7,2,5,8,3,5,6,8,3,4,9,7,1,2,8,3,7,9,2,5,1,4,6,4,5,6,1,3,8,2,7,9,2,9,1,7,6,4,8,3,5,3,1,5,2,9,7,4,6,8,6,7,4,8,5,3,9,2,1,9,8,2,4,1,6,3,5,7},
    {1,7,4,2,8,5,3,9,6,2,3,5,9,6,4,8,1,7,6,8,9,1,3,7,4,2,5,3,5,2,4,7,9,6,8,1,4,6,8,3,2,1,7,5,6,7,9,1,6,5,8,2,3,4,5,1,7,8,4,2,9,6,3,8,4,6,5,9,3,1,7,2,9,2,3,7,1,6,5,4,8},
    {7,8,4,9,2,5,1,3,6,9,6,3,1,8,7,2,4,5,5,1,2,3,4,6,7,8,9,1,5,8,4,6,9,3,2,7,2,9,7,5,1,3,4,6,8,3,4,6,2,7,8,9,5,1,4,7,1,6,5,2,8,9,3,6,2,9,8,3,1,5,7,4,8,3,5,7,9,4,6,1,2},
    {6,4,9,3,7,1,5,8,2,1,3,5,2,8,4,9,6,7,7,8,2,5,6,9,4,1,3,5,6,3,4,9,2,8,7,1,9,7,8,1,3,6,2,4,5,2,1,4,7,5,8,6,3,9,8,2,6,9,1,7,3,5,4,3,9,1,6,4,5,7,2,8,4,5,7,8,2,3,1,9,6},
    {9,4,2,3,1,6,5,7,8,8,3,5,7,2,9,1,4,6,1,6,7,8,4,5,9,2,3,5,1,3,2,6,8,7,9,4,6,7,4,9,3,1,2,8,5,2,8,9,4,5,7,3,6,1,4,9,6,5,7,3,8,1,2,7,5,1,6,8,2,4,3,9,3,2,8,1,9,4,6,5,7},
    {2,4,8,7,5,1,6,3,9,6,9,3,8,4,2,7,5,1,7,1,5,6,9,3,2,4,8,3,6,9,5,7,8,4,1,2,4,2,1,9,3,6,8,7,5,5,8,7,1,2,4,9,6,3,8,3,4,2,6,5,1,9,7,9,5,2,4,1,7,3,8,6,1,7,6,3,8,9,5,2,4},
    {7,3,9,2,6,8,5,4,1,1,4,6,3,5,9,2,8,7,2,8,5,4,1,7,3,6,9,8,7,2,5,9,3,4,1,6,9,1,3,6,2,4,7,5,8,5,6,4,7,8,1,9,2,3,3,2,1,8,7,5,6,9,4,4,5,8,9,3,6,1,7,2,6,9,7,1,4,2,8,3,5}
};
//=========================================================================================================================================
// Invocacion de funciones: [Prototipos]
int main(); 																								// none -> int
int totalayuda(int nivel);																					// int -> int
void generartableros(int tablero[][COLUMNA], char table[][COLUMNA],int sol[][COLUMNA], int nivel, int x);	// int char int int int -> none
void mostrartablero(int tablero[][COLUMNA]);																// int -> void
int opciones(int ayu, int totalay);																			// int int -> void
void ayuda(int tabero[][COLUMNA], int sol[][COLUMNA], char table[][COLUMNA]);								// int int char -> none
int borrar(int tablero[][COLUMNA], char table[][COLUMNA]);													// int char -> int
int tablerocompleto(int tablero[][COLUMNA]);																// int -> int
int completa(int tablero[][COLUMNA],char table[][COLUMNA]);													// int char -> int
//=========================================================================================================================================
int main(){
	/*
	Nombre:
			Main
	Signatura:
				none->none
	Funcion:
			Inicializacion del programa, administrador de invocacion de funciones(generartableros, mostrartablero, totalayuda, ayuda)
			y muestra menu/mensajes por pantalla para la interaccion con el usuario.
	*/
 
	// Declaracion de variables:
    int orden[ORDEN]={0,1,2,3,4,5,6,7,8,9}; // list(number)
    int nivel, aux,cambio, i; // Number-Int
    srand(time(0)); // Obtencion de un numero aleatorio utilizando la fecha/hora del sistema.

    // Bucle de repeticion definido: 
    for(i=ORDEN;i>0;i--){
		// Declaracion de variables:
        aux=rand()%i; // Entrega un valor numerico aleatorio entro 0 e I.
        int valniv=1; 

        while(valniv==1){ // Inicia el juego.

			// Menu de seleccion de dificultad:
            printf("\n\n- Elija dificultad:\n\n\t1) Facil:     [Principiante]\n\t2) Medio:     [Normal]\n\t3) Dificil:   [Avanzado]\n");
            printf("\n- Utilice los numeros segun la respectiva dificultad:\t-> ");scanf("%d", &nivel);
            printf("\n");
            
            // Declaracion de variables:
            int totay;
            totay=totalayuda(nivel);

			// Condicional: se activara en caso de seleccionar valores validos de dificultad. (1/2/3)
            if(nivel==1 || nivel==2 || nivel ==3){ 

                // Declaracion de variables:
				int tablero[FILA][COLUMNA];
                char table[FILA][COLUMNA];
                int sol[FILA][COLUMNA];
                int fin=0;
                int ayu=0;
                int op;
                int bien=0;
                printf("===========================\n");
                // Invocacion de funciones:
                generartableros(tablero,table,sol,nivel,orden[aux]);
                mostrartablero(tablero);
                printf("===========================\n");
                while(fin==0){ // Bucle de repeticion indefinido: Su funcion es invocar la funcion de tablero, ayudas y mostrar mensajes en pantalla.
                    if(bien==1){
                        mostrartablero(tablero);
                    }
                    op=opciones(ayu,totay);
                    switch(op){
                    case 1:
                        if(ayu!=totay){
                            ayuda(tablero,sol,table);
                            bien=1;
                            ayu++;
                            break;
                        }else{
                            printf("No tienes mas ayudas\n");
                            break;
                        }
                    case 2:
                        bien=borrar(tablero,table);
                        break;
                    case 3:
                        bien=completa(tablero,table);
                        break;
                    default:
                        printf("Opcion invalida\n");
                        break;
                    }
                    fin=tablerocompleto(tablero);
                    if(fin==1){
                        printf("Felicitaciones! Tablero completo\n");
                    }
                }
            
				// Declaracion de variables:
                valniv=0;
                int juegonuevo=0;

                while(juegonuevo==0){ // En caso de finalizar el juego, se activa el bucle para repetir el proceso de juego o finalizarlo.
                    printf("\n\tQueres jugar de nuevo?\n1-SI\n2-NO\n\tIngrese su respuesta:\t-> ");
                    scanf("%d",&juegonuevo);
                    
                    if(juegonuevo==1){
                        break;
                    }
                    else if(juegonuevo==2){
                        printf("Gracias por jugar!!!!\n");
                        i=0;
                        break;
                    }
                    else{
                        printf("Opcion incorrect\n");
                        juegonuevo=0;
                        break;
                    }
                };
            }
            else{
                printf("\n\n\t[[[ OPCION INVALIDA: Por favor, utiliza los valores correspondientes al modo de juego. ]]]\n");
                valniv=1;
            }
        };
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        // Cambiar valor en tablero: ??????????????[REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        cambio=orden[aux]; 
        orden[aux]=orden[i];
        orden[i]=cambio;
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
        // [REVISAR FUNCION]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]
    }
    // Valor de retorno:
    return 0;
} // Fin de funcion main.
//=========================================================================================================================================
int totalayuda(int nivel){
	/*
	Nombre:
			totalayuda
	Signatura:
			int -> int
	Funcion:
			En dependencia del nivel, se entregara la cantidad de ayudas permitidas.
	 */
    switch(nivel){
		case 1:
			return 5;
		case 2:
			return 4;
		case 3:
			return 3;
		default:
			return 0;
    } // Fin switch
} // Fin totalayuda
//=========================================================================================================================================
void generartableros(int tablero[][COLUMNA],char table[][COLUMNA],int sol[][COLUMNA], int nivel,int x){
/*
	Nombre:
			generartableros
	Signatura:
			int char int int int -> none
	Funcion:
			Generar el tablero de juego, segun el nivel de dificultad.
*/
	// Declaracion de variables:
    int i=0, a;

    // Estructura de control:
    switch(nivel){
		
		case 1:
			for(a=0;a<FILA;a++){
				int b;
				for(b=0;b<COLUMNA;b++){
					tablero[a][b]=EASY[x][i];
					sol[a][b]=SOLEASY[x][i];
					if(EASY[x][i]==0){
						table[a][b]='-';
					}
					else{
						table[a][b]=EASY[x][i]+'0';
					}
                i++;
				} // Fin de loopFOr
			} // Fin de case 1
			break;
        
		case 2:
			for(a=0;a<FILA;a++){
				// Declaracion de variables:
				int b;
				
				for(b=0;b<COLUMNA;b++){
					tablero[a][b]=MEDIUM[x][i];
					sol[a][b]=SOLMEDIUM[x][i];
					if(MEDIUM[x][i]==0){
						table[a][b]='-';
					}
					else{
						table[a][b]=MEDIUM[x][i]+'0';
					}
                i++;
				}
			}
			break;
			
    case 3:
    
        for(a=0;a<FILA;a++){
			// Declaracion de variables:
        	int b;
        	
            for(b=0;b<COLUMNA;b++){
                tablero[a][b]=HARD[x][i];
                sol[a][b]=SOLHARD[x][i];
                if(HARD[x][i]==0){
                    table[a][b]='-';
                }
                else{
                    table[a][b]=HARD[x][i]+'0';
                }
                i++;
            }
        }
        break;
    } // Fin de switch.
} // Fin de generarTablero.
//=========================================================================================================================================
void mostrartablero(int tablero[][COLUMNA]){
		/*
	Nombre:
			mostrartablero
	Signatura:
			int -> none
	Funcion:
			Imprime en pantalla el tablero junto con las referencias numericas de columnas y filas.
	*/
    printf("   1 2 3   4 5 6   7 8 9\n");
    printf("  ----------------------\n");
    int i, j;
    for(i=0;i<3;i++){
        printf("%d |", i+1);
        for(j=0;j<3;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("| ");
        for(j=3;j<6;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("| ");
        for(j=6;j<9;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("\n");
    }
    printf("  -------+-------+------\n");
    for(i=3;i<6;i++){
        printf("%d |", i+1);
        for(j=0;j<3;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("| ");
        for(j=3;j<6;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("| ");
        for(j=6;j<9;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("\n");
    }
    printf("  -------+-------+------\n");
    for(i=6;i<9;i++){
        printf("%d |", i+1);
        for(j=0;j<3;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("| ");
        for(j=3;j<6;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("| ");
        for(j=6;j<9;j++){
            printf("%d ",tablero[i][j]);
        }
        printf("\n");
    }
    printf("  ----------------------\n");
} // fin de mostrartablero
//=========================================================================================================================================
int opciones(int ayu, int totay){
	/*
	Nombre:
			opciones
	Signatura:
			int int -> int
	Funcion:
			Mostrar en pantalla un panel de interaccion para que el usuario pueda tomar elecciones durante la ejecucion.
	 */
	// Declaracion de variables:
	int op;
	
	// Mensajes en pantalla:
    printf("\n\t\t-Ayudas empleadas: %d / %d\n",ayu,totay);
    printf("\t1) Ayuda\n\t2) Borrar\n\t3) Agregar numero\n");
    
    // Ingreso de datos por teclado:
    printf("\t\t - Ingresar:\t-> ");
    scanf("%d", &op);
	printf("\n");
    // Retorno de funcion: int
    return op;
}
//=========================================================================================================================================
int borrar(int tablero[][COLUMNA],char table[][COLUMNA]){
	/*
	Nombre:
			borrar
	Signatura:
			int char -> int
	Funcion:
			Al entregarle el numero de columna y fila, ingresados por teclado se comparara con los valores ingresados en sus argumentos.
			De ser posible, se eliminara el valor que corresponda a la ubicacion de fila y columna ingresada por teclado.
	*/
	//Declaracion de variables:
    int fila,columna;
    
    // Ingreso de datos por teclado:
    printf("Ingrese fila\n");
    scanf("%d", &fila);
    
    // Condicional: si fila es mayor a 0 y menor a 10.
    if(fila>0 && fila<10){
		// Ingreso de datos por teclado:
        printf("Ingrese columna\n");
        scanf("%d", &columna);
        
        // Condicional: si columna es mayor a 0 y menor a 10.
        if(columna>0 && columna<10){
			
            if(table[fila-1][columna-1]=='-'){
                printf("\tEstas seguro?\n1-SI\n2-NO\n");
                int c;
                scanf("%d",&c);
                if(c==1){
                    tablero[fila-1][columna-1]=0;
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                printf("\tNo se puede borrar este valor\n");
                return 0;
            }
        }
        else{
            printf("\tRango de columna incorrect\n");
            return 0;
        }
    }
    else{
        printf("\tRango de fila incompleto\n");
	// Valor de retorno:
    return 0;
    } // Fin Borrar
}
//=========================================================================================================================================
int tablerocompleto(int tablero[][COLUMNA]){
		/*
	Nombre:
			tablerocompleto
	Signatura:
			int -> int
	Funcion:
			Al ingresar un dato tipo ¨tablero¨ la funcion comenzara a verificar la ausencia del valor 0 en el tablero.
			En caso de no poseer NINGUN valor cero, se considera tablero completo.
	*/
	// Declaracion de variables:
    int c=0,a,b;
    
    // Bucle de repeticion definido: recorrer matriz.
    for(a=0;a<FILA;a++){
        for(b=0;b<COLUMNA;b++){
            if(tablero[a][b]!=0){
                c++;
            }else{
                return 0;
            }
        }
    }
    if(c==81){
        return 1;
    }
    return 0;
}
//=========================================================================================================================================
void ayuda(int tablero[][COLUMNA],int sol[][COLUMNA], char table[][COLUMNA]){
		/*
	Nombre:
			ayuda
	Signatura:
			int int char -> none
	Funcion:
			Buscara, de forma aleatoria, entre fila y columna el valor que corresponda y lo agregara.
			Entregara por pantalla la solucion de UN valor en el tablero.
	*/
	// Declaracion de variables:
    srand(time(0));
    int fi,co,aux;
    
    // Bucle de repeticion indefinido:
    do{
		// Busqueda aleatoria entre filas y columnas:
        fi=rand()%9;
        co=rand()%9;
        
        if(fi>0 && fi<9 && co>0 && co<9){
            if(table[fi][co]=='-'){
                if(tablero[fi][co]==0){
                    tablero[fi][co]=sol[fi][co];
                    table[fi][co]=sol[fi][co]+'0';
                    aux=1;
                }
                else{
                    aux=0;
                }
            }
            else{
                aux=0;
            }
        }
        else{
            aux=0;
        }
    }while(aux==0);
    
    // Mostrar por pantalla:
    printf("\n\tAYUDA:\n\t\t [Fila %d || columna %d]\t=\tValor: %d\n\n",fi+1,co+1,sol[fi][co]);
} // Fin de ayuda.
//=========================================================================================================================================
int completa(int tablero[][COLUMNA], char table[][COLUMNA]){
		/*
	Nombre:
			completa
	Signatura:
			int char -> int
	Funcion:
			Ingreso de datos por teclado y agregar el dato, de ser valido, al tablero de juego.
			Caso contrario notificar el problema.
	*/
	// Declaracion de variables:
    int num, fila, col, aux, au=1, i, j;
    
    // Bucle de repeticion indefinido:
    do{
        printf("\t- Que numero quiere ingresar?(entre 1 y 9)\t-> ");
        scanf("%d", &num);
        
        //validar rango de numero ingresado
        if(num>0 && num<10){
            do{
                printf("Ingrese fila\n");
                scanf("%d", &fila);
                //validar rango de fila ingresada
                if(fila>0 && fila<10){
                    do{
                        printf("Ingrese columna\n");
                        scanf("%d", &col);
                        //validar rango de columna ingresada
                        if(col>0 && col<10){
                            if(table[fila-1][col-1]=='-'){
                                //valida que no se repita en fila
                                for(i=0; i<FILA; i++){
                                    if(tablero[i][col-1]==num){
                                        au=0;
                                    }
                                }
                                if(au==1){
                                    //valida que no se repida en columna
                                    for(i=0; i<COLUMNA; i++){
                                        if(tablero[fila-1][i]==num){
                                            au=0;
                                        }
                                    }
                                    if(au==1){
                                          //validar que no se repita en cuadrado 3x3
                                          if(fila>0 && fila<4){
                                            if(col>0 && col<4){
                                                for(i=0;i<3;i++){
                                                    for(j=0;j<3;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }else if(col>3 && col<7){
                                                for(int i=0;i<3;i++){
                                                    for(int j=3;j<6;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }else if(col>6 && col<10){
                                                for(int i=0;i<3;i++){
                                                    for(int j=6;j<9;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }
                                        }else if(fila>3 && fila<7){
                                            if(col>0 && col<4){
                                                for(int i=3;i<6;i++){
                                                    for(int j=0;j<3;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }else if(col>3 && col<7){
                                                for(int i=3;i<6;i++){
                                                    for(int j=3;j<6;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }else if(col>6 && col<10){
                                                for(int i=3;i<6;i++){
                                                    for(int j=6;j<9;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }
                                        }else if(fila>6 && fila<10){
                                            if(col>0 && col<4){
                                                for(int i=6;i<9;i++){
                                                    for(int j=0;j<3;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }else if(col>3 && col<7){
                                                for(int i=6;i<9;i++){
                                                    for(int j=3;j<6;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }else if(col>6 && col<10){
                                                for(int i=6;i<9;i++){
                                                    for(int j=6;j<9;j++){
                                                        if(tablero[i][j]==num){
                                                            au=0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }else{
                                        printf("Numero repetido en columna\n");
                                    }
                                }else{
                                    printf("Numero repetido en fila\n");
                                }
                            }else{
                                printf("Valor predeterminado\n");
                            }
                            if(au==1){
                                tablero[fila-1][col-1]=num;
                                return 1;
                            }else if(au==0){
                                printf("Numero repetido en cuadrado 3x3\n");
                            }
                            aux=1;
                        }else{
                            printf("Numero de columna fuera de rango\n");
                            aux=0;
                        }
                    }while(aux==0);
                    aux=1;
                }else{
                    printf("Numero de fila fuera de rango\n");
                    aux=0;
                }
            }while(aux==0);
            aux=1;
        }else{
            printf("Numero fuera de rango\n");
            aux=0;
        }
    }while(aux==0);
    // Valor de retorno:
    return 0;
} // Fin de completa.
//=========================================================================================================================================
