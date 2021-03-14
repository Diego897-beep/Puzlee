#include "matriz.h"

bool cargar(tMatrizChar& mat, ifstream& ent) {
	bool ok = true;
	int aux = 0;

	ent >> mat.numF >> mat.numC;

	if (mat.numF < 0 || mat.numF >= MAX_DIM || mat.numC < 0 || mat.numC >= MAX_DIM) {
		ok = false;
	}
	else {
		for (int f = 0; f < mat.numF; f++) {
			for (int c = 0; c < mat.numC; c++) {
				ent >> aux;
				mat.elementos[f][c] = uchar(aux);
			}
		}
	}
	
	return ok;
}

bool operator == (const tMatrizChar& mat1, const tMatrizChar& mat2) {
	bool sonIguales = true;
	int fila = 0;
	int columna = 0;

	if (mat1.numF != mat2.numF || mat1.numC != mat2.numC) {
		sonIguales = false;
	}

	while (fila < mat1.numF && sonIguales) {
		while (columna < mat1.numC && sonIguales) {
			if (mat1.elementos[fila][columna] != mat2.elementos[fila][columna]) {
				sonIguales = false;
			}

			columna++;
		}

		fila++;
		columna = 0;
	}

	return sonIguales;
}

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool sePuede = true;
	

	if (!coordenadaValida(mat, pos1) || !coordenadaValida(mat, pos2)) {
		sePuede = false;
	}
	else {
		uchar aux = 'a';

		aux = mat.elementos[pos1.F][pos1.C];
		mat.elementos[pos1.F][pos1.C] = mat.elementos[pos2.F][pos2.C];
		mat.elementos[pos2.F][pos2.C] = aux;
	}

	return sePuede;
}

bool swapF(tMatrizChar& mat, int f1, int f2) {
	bool sePuede = true;
	
	if (f1 >= mat.numF || f2 >= mat.numF) {
		sePuede = false;
	}
	else {
		uchar aux = 'a';

		for (int c = 0; c < mat.numC; c++) {
			aux = mat.elementos[f1][c];

			mat.elementos[f1][c] = mat.elementos[f2][c];
			mat.elementos[f2][c] = aux;
		}
	}

	return sePuede;
}

bool swapC(tMatrizChar& mat, int c1, int c2) {
	bool sePuede = true;

	if (c1 >= mat.numC || c2 >= mat.numC || c1 < 0 || c2 < 0) {
		sePuede = false;
	}
	else {
		uchar aux = 'a';

		for (int f = 0; f < mat.numC; f++) {
			aux = mat.elementos[f][c1];

			mat.elementos[f][c1] = mat.elementos[f][c2];
			mat.elementos[f][c2] = aux;
		}
	}

	return sePuede;
}

bool swapD(tMatrizChar& mat, int d) {
	bool sePuede = true;

	if (mat.numF != mat.numC || d >= mat.numC) {
		sePuede = false;
	}

	else {
		uchar aux = 'a';
		int f = 0;

		while (d < mat.numC) {
			aux = mat.elementos[f][d];

			mat.elementos[f][d] = mat.elementos[d][f];
			mat.elementos[d][f] = aux;

			d++;
			f++;
		}
	}

	return sePuede;
}

bool voltearF(tMatrizChar& mat, int f) {
	bool sePuede = true;

	if (f >= mat.numF || f < 0) {
		sePuede = false;
	} 
	else {
		tVector fila_i;
		for (int i = 0; i < mat.numC; i++) {
			fila_i[i] = mat.elementos[f][i];
		}

		for (int i = 0; i < mat.numC; i++) {
			mat.elementos[f][i] = fila_i[mat.numC - 1 - i];
		}
	}
	return sePuede;
};

bool voltearC(tMatrizChar& mat, int c) {
	bool sePuede = true;
	
	if (c > mat.numC || c < 0) {
		sePuede = false;
	}
	else {
		tVector col_i;
		for (int i = 0; i < mat.numF; i++) {
			col_i[i] = mat.elementos[i][c];
		}

		for (int i = 0; i < mat.numF; i++) {
			mat.elementos[i][c] = col_i[mat.numF - 1 - i];
		}
	}
	return sePuede;
};

bool voltearD(tMatrizChar& mat, int d) {
	bool sePuede = true;
	
	if ((d > mat.numC)|| (mat.numF != mat.numC)) {
		sePuede = false;
	}
	else {
		tVector diag_i;
		if (d >= 0) {
			for (int i = 0; i < mat.numF - d; i++) {
				for (int j = 0; j < mat.numC - d; j++){
					diag_i[i] = mat.elementos[i][j + d];
				}
			}

			for (int i = 0; i < mat.numF - d; i++) {
				for (int j = 0; j < mat.numC - d; j++){
					mat.elementos[i][j + d] = diag_i[mat.numF - d - i];
				}
			}
		}
		else {
			for (int i = 0; i < mat.numF + d; i++) {
				for (int j = 0; j < mat.numC + d; j++){
					diag_i[i] = mat.elementos[i - d][j];
				}
			}

			for (int i = 0; i < mat.numF; i++) {
				for (int j = 0; j < mat.numC; j++){
					mat.elementos[i - d][j] = diag_i[mat.numF + d - i];
				}
			}
		}
	}
	return sePuede;
};

void voltearV(tMatrizChar& mat) {
	for (int i = 0; i < (mat.numC / 2); i++) {
		swapC(mat, i, mat.numC - 1 - i);
	}
	
}

void voltearH(tMatrizChar& mat) {
	for (int i = 0; i < (mat.numC / 2); i++) {
		swapF(mat, i, mat.numC - 1 - i);
	}
};

void rotarD(tMatrizChar& mat) {
	tMatrizChar aux = mat;

	mat.numF = aux.numC;
	mat.numC = aux.numF;

	for (int fila = 0; fila < mat.numF; fila++) {
		for (int col = 0; col < mat.numC; col++) {
			mat.elementos[col][aux.numF - 1 - fila] = aux.elementos[fila][col];
		}
	}
}

bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool sePuede = true;
	if (!vecinosValidos(mat, pos1, pos2)) {
		sePuede = false;
	}
	else {
		for (int i = 0; i < 8; i++) {
			swap(mat, {pos1.F + vecF[i], pos1.C + vecC[i]}, { pos2.F + vecF[i], pos2.C + vecC[i] });
		}
	}
	return sePuede;
}

bool voltearID(tMatrizChar& mat) {
	bool sePuede = true;

	if (mat.numF != mat.numF) {
		sePuede = false;
	}

	else {
		uchar aux = 'a';

		for (int fila = 0; fila < mat.numF; fila++) {
			for (int col = 0; col < mat.numC; col++) {
				aux = mat.elementos[fila][col];

				mat.elementos[fila][col] = mat.elementos[col][fila];
				mat.elementos[col][fila] = aux;
			}
		}
	}
	return sePuede;
}