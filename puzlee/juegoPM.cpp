#include "juegoPM.h"

void mainJuegoPM();

int menu() {
	int eleccion = 0;

	cout << "\n\n";
	cout << "\tMenu:\n";
	cout << "1 <-> Jugar modo 1D\n";
	cout << "2 <-> Jugar modo 2D\n";

	do {
		cout << "Opcion: ";
		cin >> eleccion;
	} while (eleccion < 0 || eleccion > 2);

	cout << "\n\n";

	return eleccion;
}

bool iniciar(tJuegoPM& jpm, string modo);

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
	istream entrada;
	archivo.open(fichero);

	if (archivo.is_open()) {
		// Aquí no se
		// Cargar las 2 matrices

		// cargar(jpm.imagenJugador, entrada);
		// cargar(jpm.imagenObjetivo, entrada);

		// Cargar el numero de intentos máximos
		archivo >> jpm.maxIntentos;
	}
	else {
		cout << "\n\nNo se pudo abrir el archivo\n\n";
	}
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
	cout << "Totales: " << jpm.maxIntentos << endl;
	cout << "Actuales: " << jpm.intentosActuales << endl;
	cout << "Restantes: " << jpm.maxIntentos - jpm.intentosActuales << endl;

	cout << "\n\n";
}

bool jugar(tJuegoPM& jpm);

void accion(tJuegoPM& jpm) {
	char accion;

	cout << "Introduzca una accion: (help para mostrar leyenda) ";
	cin >> accion;

	bool accionPermitida = true;

	if (jpm.modo == 1) {
		switch (accion) {

		case 'SF':
			// lo que sea
			break;
		case 'SC':
			// lo que sea
			break;
		case 'SD':
			// intercambiar diagonales
			break;
		case 'VF':
			// voltear fila
			break;
		case 'VC':
			// voltear columnas
			break;
		case 'VD':
			// voltear la diagonal
			break;
		case 'help':
			// cout de los comandos permitidos
			break;

		default:
			// cout de comando no reconocido
			break;
		}
	}
	else {

	}






	if (!accionPermitida) {
		cout << "No se pudo realizar la acción" << endl;
	}
}