#include "coordenada.h"

bool operator == (tCoor c1, tCoor c2) {
	return (c1.F == c2.F) && (c1.C == c2.C);
}

bool operator != (tCoor c1, tCoor c2) {
	return !(c1 == c2);
}

bool coordenadaValida(tCoor c) {
	return (c.F >= 0 && c.F < MAX_DIM && c.C >= 0 && c.C < MAX_DIM);
}

bool coordenadaValida(const tMatrizChar& m, tCoor c) {
	return coordenadaValida(c) && c.F < m.numF&& c.C < m.numC;
}

tCoor operator + (tCoor c1, tCoor c2) {
	return {c1.F + c2.F, c1.C + c2.C};
}

bool vecinosValidos(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool val = true;
	if (pos1.F == 0 || pos1.F == mat.numF - 1 || pos1.C == 0 || pos1.C == mat.numC - 1 || pos2.F == 0 || pos2.F == mat.numF - 1 || pos2.C == 0 || pos2.C == mat.numC - 1) {
		val = false;
	}
	else if (abs(pos1.F - pos2.F) < 3 && abs(pos1.C - pos2.C) < 3) {
		val = false;
	}
	return val;
}