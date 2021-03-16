#include "juegoPM.h"

void mostrarHelp(); // Hace un cout de todos los comandos disponnibles
int acciones(string comando, int modo); // Devuelve un entero en funcion del comando introducido y del modo en el que este el jugador

void mainJuegoPM() {
	tJuegoPM juego;
	
	bool haGanado = true;

	// Si inicia correctamente procede a jugar
	if (iniciar(juego)) {
		haGanado = jugar(juego);

		if (haGanado) {
			cout << "\n\nLO CONSEGUISTE!!\n\n";
		}
		else {
			cout << "\n\nPerdiste :(\n\n";
		}
	}
}

int menu() {
	int eleccion = 0;

	cout << "\n\n";
	cout << "\tMenu:\n";
	cout << "1 <-> Jugar modo 1D\n";
	cout << "2 <-> Jugar modo 2D\n";
	cout << "0 <-> Salir\n";

	do {
		cout << "Opción: ";
		cin >> eleccion;
	} while (eleccion < 0 || eleccion > 2);

	cout << "\n\n";

	return eleccion;
}

bool iniciar(tJuegoPM& jpm) {
	bool ok = false;

	// Muestra el menu y devuelve el modo escogido
	int modo = menu();

	jpm.modo = modo;

	// Si carga el modulo correctamente devuelve true
	if (jpm.modo != 0 && cargar(jpm)){
		ok = true;
	}

	return ok;
}

bool cargar(tJuegoPM& jpm) {
	string fichero;
	bool ok = false;

	// Pide al usuario el nombre del fichero
	cout << "Introduzca el nombre del fichero: ";
	cin >> fichero;

	// Actualiza el nombre de fichero segun el modo
	if (jpm.modo == 1) {
		fichero += "_1D.txt";
	}
	else if (jpm.modo == 2) {
		fichero += "_2D.txt";
	}
	else {
		cout << "\n\nModo desconocido\n\n";
	}

	ifstream archivo;
	archivo.open(fichero);

	if (archivo.is_open()) {
		// Carga la imagen del jugador y a continuación la imagen objetivo
		cargar(jpm.imagenJugador, archivo);
		cargar(jpm.imagenObjetivo, archivo);

		// Cargar el numero de intentos máximos
		archivo >> jpm.maxIntentos;
		ok = true;
	}
	else {
		cout << "\n\nNo se pudo abrir el archivo\n\n";
	}
	archivo.close();

	return ok;
}

void mostrar(const tJuegoPM& jpm) {
	// IMAGEN JUGADOR

	// Fila de numeros
	cout << "   ";
	for (int i = 0; i < jpm.imagenJugador.numC; i++) {
		if (i < 10) {
			cout << i << " ";
		}
		else {
			cout << i;
		}
	}

	cout << endl;

	// Muestra la imagen cambiando el color del fondo
	for (int fila = 0; fila < jpm.imagenJugador.numF; fila++) {
		cout << setw(2) << left << fila << " ";
		for (int col = 0; col < jpm.imagenJugador.numC; col++) {
			colorCTA(0, uint8(jpm.imagenJugador.elementos[fila][col]));
			cout << "  ";
			colorCTA(15, 0);
		}
		cout << endl;
	}

	cout << "\n\n";

	// IMAGEN OBJETIVO

	// Fila de numeros
	cout << "   ";
	for (int i = 0; i < jpm.imagenObjetivo.numC; i++) {
		if (i < 10) {
			cout << i << " ";
		}
		else {
			cout << i;
		}
	}

	cout << endl;

	// Muestra la imagen cambiando el color del fondo
	for (int fila = 0; fila < jpm.imagenObjetivo.numF; fila++) {
		cout << setw(2) << left << fila << " ";
		for (int col = 0; col < jpm.imagenObjetivo.numC; col++) {
			colorCTA(0, uint8(jpm.imagenObjetivo.elementos[fila][col]));
			cout << "  ";
			colorCTA(15, 0);
		}
		cout << endl;
	}

	cout << "\n";

	// Muestra los intentos
	cout << "INTENTOS" << endl;
	cout << "Máximos: " << jpm.maxIntentos << endl;
	cout << "Actuales: " << jpm.intentosActuales << endl;
	cout << "Restantes: " << jpm.maxIntentos - jpm.intentosActuales << endl;

	cout << "\n\n";
}

bool jugar(tJuegoPM& jpm) {
	bool ganador = true;

	// Muestra el tablero antes de empezar
	mostrar(jpm);

	while (jpm.intentosActuales < jpm.maxIntentos && !(jpm.imagenJugador == jpm.imagenObjetivo)) {

		// Si la accion es valida cuenta un intento
		if (accion(jpm)) {
			jpm.intentosActuales++;
		}

		mostrar(jpm);
		pausa();
	}

	// Si al acabar de jugar la imagen es distinta o se ha pasado de intentos cuenta como perdido
	if (!(jpm.imagenJugador == jpm.imagenObjetivo)) {
		ganador = false;
	}
	else if (jpm.intentosActuales > jpm.maxIntentos) {
		ganador = false;
	}

	return ganador;
}

bool accion(tJuegoPM& jpm) {
	string accion, comando, espacio = " ";
	int aux1 = -100, aux2 = -100, aux3 = -100, aux4 = -100;
	bool accionPermitida = true;

	// Pide la accion por pantalla
	cout << "Introduzca una accion: (HP para ayuda) ";
	
	cin.ignore();
	getline(cin, accion);

	// Saca el comando
	comando = accion.substr(0, accion.find(espacio));

	// acciones() devuelve el numero del case en funcion del comando y del modo
	int n = acciones(comando, jpm.modo);
	
	// 2 switchs, 1 para cada modo, dentro de cada uno de ellos se lee los demas numeros auxiliares
	if (jpm.modo == 1) {
		switch (n) {

		case 1:
			aux1 = stoi(accion.substr(3, accion.find(espacio)));
			aux2 = stoi(accion.substr(5, accion.find(espacio)));

			if (!swapF(jpm.imagenJugador, aux1, aux2)) {
				accionPermitida = false;
			}
			break;

		case 2:
			aux1 = stoi(accion.substr(3, accion.find(espacio)));
			aux2 = stoi(accion.substr(5, accion.find(espacio)));

			if (!swapC(jpm.imagenJugador, aux1, aux2)) {
				accionPermitida = false;
			}
			break;

		case 3:
			aux1 = stoi(accion.substr(3, accion.find(espacio)));
			
			if (!swapD(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 4:
			aux1 = stoi(accion.substr(3, accion.find(espacio)));

			if (!voltearF(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 5:
			aux1 = stoi(accion.substr(3, accion.find(espacio)));

			if (!voltearC(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 6:
			aux1 = stoi(accion.substr(3, accion.find(espacio)));

			if (!voltearD(jpm.imagenJugador, aux1)) {

			}
			break;

		case 7:
			mostrarHelp();
			accionPermitida = false;
			break;

		default:
			cout << "Comando no reconocido, help para mostrar comandos permitidos";
			accionPermitida = false;
			break;
		}
	}
	else  if (jpm.modo == 2){
		switch (n) {
		
		case 1:
			voltearV(jpm.imagenJugador);
			break;

		case 2:
			voltearH(jpm.imagenJugador);
			break;

		case 3:
			rotarD(jpm.imagenJugador);
			break;

		case 4:
			aux1 = stoi(accion.substr(3, accion.find(espacio)));
			aux2 = stoi(accion.substr(5, accion.find(espacio)));
			aux3 = stoi(accion.substr(7, accion.find(espacio)));
			aux4 = stoi(accion.substr(9, accion.find(espacio)));

			if (!swapAdy(jpm.imagenJugador, { aux1, aux2 }, { aux3, aux4 })) {
				accionPermitida = false;
			}
			break;

		case 5:

			if (!voltearID(jpm.imagenJugador)) {
				accionPermitida = false;
			}
			break;

		case 6:
			mostrarHelp();
			accionPermitida = false;
			break;

		default:
			cout << "\n\nComando no reconocido, help para mostrar comandos permitidos\n\n";
			accionPermitida = false;
			break;
		}
	}
	else {
		cout << "Modo no reconocido";
	}

	if (!accionPermitida) {
		cout << "\n\nNo se pudo realizar la acción\n\n";
	}

	return accionPermitida;
}

void mostrarHelp() {
	cout << "\n\n";
	cout << "Comandos permitidos!!" << endl;
	cout << "MODO 1D" << endl;
	cout << "SF * + : Intercambiar las filas * y +" << endl;
	cout << "SC * + : Intercambiar las columnas * y +" << endl;
	cout << "SD * : Intercambia las diagonales * y -*" << endl;
	cout << "VF * : Voltea la fila *" << endl;
	cout << "VC * : Voltea la columna *" << endl;
	cout << "VD * : Voltea al diagonal *" << endl;
	cout << "\n";
	cout << "MODO 2D" << endl;
	cout << "VV : Voltear con respecto a la Vertical" << endl;
	cout << "VH : Voltear con respecto a la Horizontal" << endl;
	cout << "RD : Rotar en sentido horario" << endl;
	cout << "SA + * # ~ : Intercambia las posiciones de las vecinas de las coordenadas {+, *} y {#, ~}" << endl;
	cout << "VD : Voltear con respecto a la diagonal principal" << endl;
	cout << "\n\n";
}

int acciones(string comando, int modo){
	int ind = -1;

	// Los .length() se usan para comprobar que la cadena no viene solo con el comando sin indicar los demas valores

	if (modo == 1) {
		if (comando == "SF" && comando.length() >= 6) {
			ind = 1;
		}
		else if (comando == "SC" && comando.length() >= 6) {
			ind = 2;
		}
		else if (comando == "SD" && comando.length() >= 4) {
			ind = 3;
		}
		else if (comando == "VF" && comando.length() >= 4) {
			ind = 4;
		}
		else if (comando == "VC" && comando.length() >= 4) {
			ind = 5;
		}
		else if (comando == "VD" && comando.length() >= 4) {
			ind = 6;
		}
		else if (comando == "HP") {
			ind = 7;
		}
	}
		
	else if (modo == 2){
		if (comando == "VV") {
			ind = 1;
		}
		else if (comando == "VH") {
			ind = 2;
		}
		else if (comando == "RD") {
			ind = 3;
		}
		else if (comando == "SA" &&comando.length() >= 10) {
			ind = 4;
		}
		else if (comando == "VD") {
			ind = 5;
		}
		else if (comando == "HP") {
			ind = 6;
		}
	}

	return ind;
}