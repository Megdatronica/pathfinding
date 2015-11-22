#ifndef WORLD_H
#define WORLD_H

class World {

public:

	// Create a world of 70x50 tiles (700 x 500 pixels)
	World();

	~World();

	// Return a tile index from a position in the world in pixel terms
	int toGrid(int x, int y);

	// Return a tile index from an xy tile position within the world.
	int toIndex(int x, int y);
	
	// Set the current object's path to the path between the two given world
	// coordinates
	void setPath(int fromX, int fromY, int toX, int toY);

	// Return an array of four integers representing the tiles which are
	// adjacent to the square represented by the passed integer. The neighbours
	// will be given in clockwise order starting from the neighbour directly 
	// above. If a neighbour does not exist due to a border, the corresponding
	// value in the returned array will be -1. The caller must free this memory.
	int * getNeighbours(int tile);
		
private:

	// A grid of tiles
	int * grid;

	// Size of world in tiles
	const int xSize;
	const int ySize;

	// Current path taken by an object in the world - an array of tiles
	int * path;
};

#endif