//---------------------------------------------------------------------------------
// Player.h
// Handles player inputs, and player shoot mechanic.
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access CSimpleSprite class
#include "BirbManager.h" // access to birbmanager class methods
class Player
{
public:
	void InitPlayerSprites(); // Initialize Player Sprites
	void UpdatePlayerCrosshair(); // Updates the players position
	void UpdateCrosshairAnims(float deltaTime); // Update player sprites
	void RenderCrosshair(); // Renders the players crosshair
	void Shoot(); // Handles shooting logic
private:
	float moveX = 500.0f, moveY = 400.0f; // stores data regarding the players position
	float sensitivity = 6.5f; // detirmines how fast the players cursor moves
	int animSpeed = 1.0f / 15.0f;

	CSimpleSprite* crosshairSprite; // reference to crosshair sprite
};