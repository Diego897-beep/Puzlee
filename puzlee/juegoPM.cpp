#include "juegoPM.h"

void mostrarHelp();
int acciones(string comando, int& aux1, int& aux2, int& aux3, int& aux4, int modo);

void mainJuegoPM() {
	tJuegoPM juego;
	int modo = menu();
	bool haGanado = true;

	juego.modo = modo;

	if (juego.modo != 0 && iniciar(juego)) {
		haGanado = jugar(juego);

		if (haGanado) {
			cout << "LO CONSEGUISTE!!! Enhorabuena Sra. García :D" << endl;
		}
		else {
			cout << "Perdiste puto :(";
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

	if (cargar(jpm));{
		ok = true;
	}
	return ok;
}

bool cargar(tJuegoPM& jpm) {
	string fichero;
	bool ok = false;

	cout << "Introduzca el nombre del fichero: ";
	cin >> fichero;

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
	// Mostrar la foto del reto a resolver
	for (int fila = 0; fila < jpm.imagenJugador.numF; fila++) {
		for (int col = 0; col < jpm.imagenJugador.numC; col++) {
			colorCTA(0, uint8(jpm.imagenJugador.elementos[fila][col]));
			cout << ' ';
			colorCTA(15, 0);
		}
		cout << endl;
	}

	cout << "\n\n";

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

	mostrar(jpm);

	while (jpm.intentosActuales <= jpm.maxIntentos && !(jpm.imagenJugador == jpm.imagenObjetivo)) {

		if (accion(jpm)) {
			jpm.intentosActuales++;
		}

		mostrar(jpm);
		pausa();
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
	//string accion;
	int n;
	int aux1 = 0, aux2 = 0, aux3 = 0, aux4 = 0;

	cout << "Introduzca una accion: (HP para ayuda) ";
	cin >> n;
	cin >> aux1;
	cin >> aux2;
	cin >> aux3;
	cin >> aux4;
	//getline(cin, accion);

	bool accionPermitida = true;

	
	//int n = acciones(accion, aux1, aux2, aux2, aux4, jpm.modo);
	
	if (jpm.modo == 1) {
		switch (n) {

		case 1:
			

			if (!swapF(jpm.imagenJugador, aux1, aux2)) {
				accionPermitida = false;
			}
			break;

		case 2:

			if (!swapC(jpm.imagenJugador, aux1, aux2)) {
				accionPermitida = false;
			}
			break;

		case 3:

			if (!swapD(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 4:

			if (!voltearF(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 5:

			if (!voltearC(jpm.imagenJugador, aux1)) {
				accionPermitida = false;
			}
			break;

		case 6:

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

int acciones(string comando, int& aux1, int& aux2, int& aux3, int& aux4, int modo){
	string accion;
	int ind = -1;
	
	accion[0] = comando[0];
	accion[1] = comando[1];
	

	if (modo == 1) {
		if (accion == "SF") {
			aux1 = comando[3];
			aux2 = comando[5];

			ind = 1;
		}

		else if (accion == "SC") {
			aux1 = comando[3];
			aux2 = comando[5];

			ind = 2;
		}
		else if (accion == "SD") {
			aux1 = comando[3];

			ind = 3;
		}
		else if (accion == "VF") {
			aux1 = comando[3];

			ind = 4;
		}
		else if (accion == "VC") {
			aux1 = comando[3];

			ind = 5;
		}
		else if (accion == "VD") {
			aux1 = comando[3];

			ind = 6;
		}
		else if (accion == "HP") {
			ind = 7;
		}
	}
		
	else if (modo == 2){
		if (accion == "VV") {
			ind = 1;
		}
		else if (accion == "VH") {
			ind = 2;
		}
		else if (accion == "RD") {
			ind = 3;
		}
		else if (accion == "SA") {
			aux1 = comando[3];
			aux2 = comando[5];
			aux3 = comando[7];
			aux4 = comando[9];

			ind = 4;
		}
		else if (accion == "VD") {
			ind = 5;
		}
		else if (accion == "HP") {
			ind = 6;
		}
	}

	return ind;
}