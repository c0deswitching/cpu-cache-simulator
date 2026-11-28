#include "ReplacementAlgorithms.h"
#include <cstdlib>

void RandomReplacement::SetWays(uint8_t numOfWays) {
	// set the number of cache ways
	ways = numOfWays;
}

uint8_t RandomReplacement::GetVictim() const {
	// choose a random victim
	return rand() % ways;
}