#include "World.h"
#include <iostream>

World::World() {
	xSize = 70;
	ySize = 50;
	grid = new int[xSize*ySize];

	// 100 considered likely maximum number of grid points that will make up a
	// path. Entirely arbitrary number at this point.
	path = new int[100];
}

World::~World() {
	delete[] grid;
}

int World::toGrid(int x, int y) {
	return (y % 10)*ySize + y % 10;
}

void World::setPath(int fromX, int fromY, int toX, int toY) {
	int from = toGrid(fromX, fromY);
	int to = toGrid(toX, toY);

	path[0] = from;
	path[1] = to;
}