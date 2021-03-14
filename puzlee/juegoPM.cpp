#include "juegoPM.h"

void mainJuegoPM() {
	tJuegoPM juego;
	int modo = menu();
	bool haGanado = true;

	juego.modo = modo;

	if (juego.modo != 0 && iniciar(juego)) {
		haGanado = jugar(juego);

		if (haGanado) {
			cout << "LO CONSEGUISTE!!!";
		}
		else {
			cout << "perdiste puto :(";
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
		cout << "Opcion: ";
		cin >> eleccion;
	} while (eleccion < 0 || eleccion > 2);

	cout << "\n\n";

	return eleccion;
}

bool iniciar(tJuegoPM& jpm) {
	
	cargar(jpm);
}

bool cargar(tJuegoPM& jpm) {
	string fichero;

	cout << "Introduzca el nombre del fichero: ";
	cin >> fichero;

	if (jpm.modo == 1) {
		fichero + "_1D.txt";
	}
	else if (jpm.modo == 2) {
		fichero + "_2D.txt";
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
	}
	else {
		cout << "\n\nNo se pudo abrir el archivo\n\n";
	}
	archivo.close();
}

void mostrar(const tJuegoPM& jpm) {
	// Mostrar la foto del reto a resolver
	for (int fila = 0; fila < jpm.imagenJugador.numF; fila++) {
		for (int col = 0; col < jpm.imagenJugador.numC; col++) {
			colorCTA(0, uint8(jpm.imagenJugador.elementos[fila][col]));
			cout << ' ';
		}
		cout << endl;
	}

	// Mostrar la foto del objetivo
	for (int fila = 0; fila < jpm.imagenObjetivo.numF; fila++) {
		for (int col = 0; col < jpm.imagenObjetivo.numC; col++) {
			colorCTA(0, uint8(jpm.imagenObjetivo.elementos[fila][col]));
			cout << ' ';
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
	while (jpm.intentosActuales <= jpm.maxIntentos && !(jpm.imagenJugador == jpm.imagenObjetivo)) {

		if (accion(jpm)) {
			jpm.intentosActuales++;
		}

		mostrar(jpm);
	}

	if (!(jpm.imagenJugador == jpm.imagenObjetivo)) {
		ganador = false;
	}
	else if (jpm.intentosActuales > jpm.maxIntentos) {
		ganador = false;
	}

	return ganador;
}

bool accion(tJuegoPM& jpm) {
	char accion;
	int aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;

	cout << "Introduzca una accion: (Solo el comando) (help )  ";
	cin >> accion >> aux1 >> aux2 >> aux3 >> aux4;

	bool accionPermitida = true;
	tCoor pos1, pos2;
	

	if (jpm.modo == 1) {
		switch (accion) {

		case 'SF':

			if (!swapF(jpm.imagenJugador, aux1, aux2)) {
				accionPermitida = false;
			}
			break;

		case 'SC':

			if (!swapC(jpm.imagenJugador, aux1, aux2)) {
				accionPermitida = false;
			}
			break;

		case 'SD':

			if (!swapD(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 'VF':

			if (!voltearF(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 'VC':

			if (!voltearC(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 'VD':

			if (!voltearD(jpm.imagenJugador, aux1)) {

			}
			break;

		case 'help':
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
		switch (accion) {
		
		case 'VV':
			voltearV(jpm.imagenJugador);
			break;

		case 'VH':
			voltearH(jpm.imagenJugador);
			break;

		case 'RD':
			rotarD(jpm.imagenJugador);
			break;

		case 'SA':

			if (!swapAdy(jpm.imagenJugador, { aux1, aux2 }, { aux3, aux4 })) {
				accionPermitida = false;
			}
			break;

		case 'VD':

			if (!voltearD(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 'help':
			mostrarHelp();
			accionPermitida = false;
			break;

		default:
			cout << "Comando no reconocido, help para mostrar comandos permitidos";
			accionPermitida = false;
			break;
		}
	}
	else {
		cout << "Modo no reconocido";
	}

	if (!accionPermitida) {
		cout << "No se pudo realizar la acción" << endl;
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