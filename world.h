#ifndef WORLD_H
#define WORLD_H

class World {

public:

	// Create a world of 70x50 tiles (700 x 500 pixels)
	World();

	~World();

	// Return a tile index from a position in the world in pixel terms
	int toGrid(int x, int y);
	
	// Set the current object's path to the path between the two given world
	// coordinates
	void setPath(int fromX, int fromY, int toX, int toY);
		
private:

	// A grid of tiles
	int * grid;

	// Size of world in tiles
	int xSize;
	int ySize;

	// Current path taken by an object in the world - an array of tiles
	int * path;
};

#endif