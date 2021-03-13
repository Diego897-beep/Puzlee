#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "matriz.h"
#include "UtilidadesSYS.h"

using namespace std;


struct tJuegoPM {
	tMatrizChar imagenJugador;
	tMatrizChar imagenObjetivo;
	int maxIntentos = 0;
	int intentosActuales = 0;
	int modo = 0;
};

void mainJuegoPM();
int menu();
bool iniciar(tJuegoPM& jpm, string modo);
bool cargar(tJuegoPM& jpm);
void mostrar(const tJuegoPM& jpm);
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);