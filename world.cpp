#include "World.h"
#include <iostream>

World::World() : xSize(70), ySize(50) {
	grid = new int[xSize*ySize];

	// 100 considered likely maximum number of tiles that will make up a
	// path. Entirely arbitrary number at this point.
	path = new int[100];
}

World::~World() {
	delete[] grid;
}

int World::toGrid(int x, int y) {
	return (y / 10)*xSize + x / 10;
}

int World::toIndex(int x, int y) {
	return y*ySize + x;
}

void World::setPath(int fromX, int fromY, int toX, int toY) {
	int from = toGrid(fromX, fromY);
	int to = toGrid(toX, toY);

	path[0] = from;
	path[1] = to;
}

int * World::getNeighbours(int tile) {
	int* neighbours = new int[4];

	int xVal = tile % ySize;
	int yVal = tile / xSize;

	if(yVal == 0) {
		neighbours[0] = -1;
	} else {
		neighbours[0] = toIndex(xVal, yVal-1);
	}

	if(yVal == ySize-1) {
		neighbours[2] = -1;
	} else {
		neighbours[2] = toIndex(xVal, yVal+1);
	}

	if(xVal == 0) {
		neighbours[3] = -1;
	} else {
		neighbours[3] = toIndex(xVal-1, yVal);
	}

	if(xVal == xSize-1) {
		neighbours[1] = -1;
	} else {
		neighbours[1] = toIndex(xVal+1, yVal);
	}
	
	return neighbours;
}