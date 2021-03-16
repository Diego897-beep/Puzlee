// Authors: Carlos Barona y Diego Flores

#pragma once

#include <iostream>

const int MAX_DIM = 64;

// Vector auxiliar para mirar las posiciones vecinas
const int vecF[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
const int vecC[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

// Devuelve la suma de dos coordenadas
tCoor operator + (tCoor c1, tCoor c2);
