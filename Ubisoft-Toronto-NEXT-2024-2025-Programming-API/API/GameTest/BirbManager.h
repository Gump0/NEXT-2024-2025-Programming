//---------------------------------------------------------------------------------
// BirbMove.h
// Responsible with managing birb spawns and birb data management
//---------------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <list> // WAIT FOR EMAIL TO SEE IF INTERNAL LIBRARIES ARE ALLOWED
#include <memory> // For std::unique_ptr

class BirbMove;

class BirbManager
{
public:
	void SpawnBirb(); // Handles flight direction, spawn height and maximum birb count
	void DestroyBirb(BirbMove* birbToRemove); // Handles removing redundant birbs from memory
	void BirbKill(BirbMove* birbToRemove); // Handles killing birb when player shoots birb
	void UpdateBirbs(); // calls the "BirbController()" method across every instance of the BirbMove class
	void RenderBirbs(); // called in GameTest/GameManager class to render every birb to the screen
	void UpdateBirbAnims(float deltaTime); // ensure every birb is updating their corresponding animations
	void CollisionCheck(float x, float y); // handles collision checks called form player action
	
	std::string ReturnPlayerScoreToString(); // returns player score to GameTest

	int maxBirbCount = 6; // limits the # of birbs present on screen
private:
	bool RandomDir(); // Randomly choses left or right direction
	float RandomSpawnHeight(); // Randomly choses spawn height of birb
	int playerScore = 0; // tracks players current score
	
	std::list<BirbMove*> birbs;// List of pointers that tracks each instance of BirbMove class
};

extern BirbManager birbManager;