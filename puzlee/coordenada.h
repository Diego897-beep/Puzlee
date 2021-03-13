#pragma once

#include <iostream>
#include "matriz.h"

struct tCoor {
	int F = 0;
	int C = 0;
};

// Comprueba si 2 coordenadas son iguales
bool operator == (tCoor c1, tCoor c2);

// Comprueba si 2 coordenadas son distintas
bool operator != (tCoor c1, tCoor c2);

// Comprueba si una coordenada esta dentro del rango permitido
bool coordenadaValida(tCoor c);

// Comprueba si una coordenada esta dentro del rango de una matriz
bool coordenadaValida(const tMatrizChar& m, tCoor c);

// Devuelve la suma de dos coordenadas
tCoor operator + (tCoor c1, tCoor c2);