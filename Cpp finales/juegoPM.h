// Authors: Carlos Barona y Diego Flores

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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

// Funcion principal del juego
void mainJuegoPM();

// Muestra el menu con las 3 opciones distintas
int menu();

// Inicia la situacion la principal del juego
bool iniciar(tJuegoPM& jpm);

// Trata de cargar la situacion inicial del juego y devuelve true si lo ha hecho correctamente
bool cargar(tJuegoPM& jpm);

// Muestra la situacion actual del juego
void mostrar(const tJuegoPM& jpm);

// La funcion principal que ejecuta las acciones y muestra la situacion actual y comprueba si ha ganado el jugador o ha perdido (true or false)
bool jugar(tJuegoPM& jpm);

// Pide una accion por teclado y comprueba si se ha podido ejecutar correctamente
bool accion(tJuegoPM& jpm);