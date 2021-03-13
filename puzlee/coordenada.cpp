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