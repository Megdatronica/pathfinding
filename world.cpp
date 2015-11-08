#include "World.h"
#include <iostream>

World::World() {
	xSize = 70;
	ySize = 50;
	grid = new int[xSize*ySize];
}

World::~World() {
	delete[] grid;
}

int World::toGrid(int x, int y) {
	return (y % 10)*ySize + y % 10;
}