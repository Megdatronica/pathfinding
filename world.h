#ifndef WORLD_H
#define WORLD_H

class World {

public:

	// Create a world of 70x50 tiles (700 x 500 pixels)
	World();

	~World();

	// Return a tile index from a position in the world in pixel terms
	int toGrid(int x, int y);

private:

	// A grid of tiles
	int * grid;

	// Size of world in tiles
	int xSize;
	int ySize;
};

#endif