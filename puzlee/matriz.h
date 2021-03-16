// Authors: Carlos Barona y Diego Flores

#pragma once

#include <iostream>
#include <fstream>
#include "coordenada.h"

using namespace std;

typedef unsigned char uchar;

typedef uchar tVector[MAX_DIM];
typedef uchar tMatriz[MAX_DIM][MAX_DIM];

struct tMatrizChar {
	tMatriz elementos;
	int numF;
	int numC;
};

// Trata de cargar la matriz y si puede duevuelve ok
bool cargar(tMatrizChar& mat, ifstream& ent);

// Operador de igualdad en matrices
bool operator == (const tMatrizChar& mat1, const tMatrizChar& mat2);

// Intercambia las posiciones pos1 y pos2 en la matriz mat
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);

// Intercambia las filas f1 y f2 en la matriz mat
bool swapF(tMatrizChar& mat, int f1, int f2);

// Intercambia las columnas c1 y c2 en la matriz mat
bool swapC(tMatrizChar& mat, int c1, int c2);

// Intercambia la diagonal d en la matriz d
bool swapD(tMatrizChar& mat, int d);

// Voltea los elementos de la fila f en la matriz mat
bool voltearF(tMatrizChar& mat, int f);

// Voltea los elementos de la columna c en la matriz mat
bool voltearC(tMatrizChar& mat, int c);

// Voltea los elementos de la diagonal d en la matriz mat
bool voltearD(tMatrizChar& mat, int d);

// Voltea la matriz entera a partir del eje vertical central
void voltearV(tMatrizChar& mat);

// Voltea la matriz entera a partir del eje horizontal central
void voltearH(tMatrizChar& mat);

// Rota la matriz en sentido horario
void rotarD(tMatrizChar& mat);

// Intercambia las posiciones vecinas de pos1 y pos2 de la matriz mat
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2);

// Voltea la matriz entera a partir de la diagonal principal
bool voltearID(tMatrizChar& mat);

// Comprueba si la coordenada c esta dentro del rango de la matriz m
bool coordenadaValidaEnMatriz(const tMatrizChar& m, tCoor c);

// Comprueba si 2 coordenadas estan a la distancia minima para poder aplicar el swapAdy()
bool vecinosValidos(tMatrizChar& mat, tCoor pos1, tCoor pos2);