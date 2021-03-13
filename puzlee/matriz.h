#pragma once

#include <iostream>
#include <fstream>
#include "coordenada.h"

const int MAX_DIM = 64;

typedef char tMatriz[MAX_DIM][MAX_DIM];

struct tMatrizChar {
	tMatriz elementos;
	int numF;
	int numC;
};

bool cargar(tMatrizChar& mat, istream& ent);

bool operator == (const tMatrizChar& mat1, const tMatrizChar& mat2);

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar& mat, int c1, int c2);
bool swapD(tMatrizChar& mat, int d);

bool voltearF(tMatrizChar& mat, int f);
bool voltearC(tMatrizChar& mat, int c);
bool voltearD(tMatrizChar& mat, int d);
void voltearV(tMatrizChar& mat);
void voltearH(tMatrizChar& mat);

void rotarD(tMatrizChar& mat);

bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2);

bool VoltearID(tMatrizChar& mat);