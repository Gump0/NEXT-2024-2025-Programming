//---------------------------------------------------------------------------------
// BirbMove.h
// Handles player movement, animations and player stats
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access CSimpleSprite class
class BirbMove
{
public:
	void KillBirb(); // special destroy method when player kills birb
	void DestroyBirb(); // destroy birb isntance from memory
	void BirbController(); // method that handles player movement and sprites
	void InitBirbSprites(float height, bool flyDir); // instantiates birb 
	void RenderBirb(); // method to be called by BirbManager class to render birb sprite
	CSimpleSprite* birbSprite;
private:
	float moveSpeed = 5.0f, animSpeed = 1.0f / 15.0f;
	float moveX, moveY;
	float birbWidth, birbHeight;
	bool flyDirection;
};