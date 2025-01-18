//---------------------------------------------------------------------------------
// BoundryManager.h
// Contains methods and variables used for the boundry manager class!
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access api methods

struct Wall {				// wall constructor
	float x, y;             // wall position
	float width, height;    // wall dimensions
};

class BoundryManager
{
public:
	void UpdateWalls(float ballX, float ballY); // general update method to encapsulate methods
	void ConstructWalls(const std::vector<Wall>& walls /*List of walls*/); // builds the level based of the list of walls passed in this method
	void DrawWalls(); // uses DrawLine() method provided to draw visual boundries
private:
	bool CollisionCheck(float ballX, float ballY); // in charge of checking when the ball collides with a wall

	std::vector<Wall> c_walls; // stores the walls currently being used in run-time
};