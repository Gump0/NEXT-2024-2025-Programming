//---------------------------------------------------------------------------------
// BirbMove.h
// Handles player movement, animations and player stats
//---------------------------------------------------------------------------------
#pragma once
class BirbMove
{
public:
	bool BirbDirection();
	void KillBirb(); // special destroy method when player kills birb
	void DestroyBirb(); // destroy birb isntance from memory
	void BirbController(); // method that handles player movement and sprites
	void InitBirbSprites();
	CSimpleSprite* birbSprite;
private:
	float moveSpeed = 5.0f, animSpeed = 1.0f / 15.0f;
	float moveX, moveY;
	float birbWidth, birbHeight;
};