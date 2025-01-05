//---------------------------------------------------------------------------------
// BirbMove.h
// Handles player movement, animations and player stats
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access CSimpleSprite class
#include "BirbManager.h" // Access birbmanager methods

class BirbManager;

class BirbMove
{
public:
	BirbMove(float spawnHeight, bool flyDirection, BirbManager* manager)
		: moveY(spawnHeight), flyDirection(flyDirection), manager(manager) {}

	void KillBirb(); // special destroy method when player kills birb
	void BirbController(); // method that handles player movement and sprites
	void InitBirbSprites(float height, bool flyDir); // instantiates birb 
	void RenderBirb(); // method to be called by BirbManager class to render birb sprite
	void UpdateAnim(float deltaTime); // called by BirbManager class to update birb animations

	bool BirbInBounds(); // destroy birb isntance from memory if out of bounds
	bool IsHit(float x, float y); // checks to see if birb has been shot

	CSimpleSprite* birbSprite;
private:
	BirbManager* manager;

	float moveSpeed = 5.0f, animSpeed = 1.0f / 15.0f;
	float moveX, moveY;
	float birbWidth, birbHeight;
	bool flyDirection;
};