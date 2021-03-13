#pragma once

#include <iostream>

struct tCoor {
	int F = 0;
	int C = 0;
};

bool operator == (tCoor c1, tCoor c2);
bool operator != (tCoor c1, tCoor c2);
tCoor operator + (tCoor c1, tCoor c2);