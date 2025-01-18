//---------------------------------------------------------------------------------
// SaturnHaloGoal.h
// Contains methods and variables used for the saturn halo!
// ( aka mini-putt flag )
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access api methods

class SaturnHaloGoal
{
public:
	void UpdateHalo(float deltaTime); // encapsulates local methods dependant on update method
	// SPRITES AND HALO INITIALIZATION
	void InitHaloGoal(float spawnX, float spawnY); // inits halo goal sprites
	void RenderHalo(); // calls render function for haloSprite
	void UpdateAnim(float deltaTime); // updates the halos

	CSimpleSprite* haloSprite; // reference to halo sprite
private:
	void BallCollisionCheck(); // checks for collision with the playerball
	void EndLevel(); // called when ball reaches end

	float worldPosX = 0.0f, worldPosY = 0.0f; // detirmines the halos position in world-space ( INITIALIZED BY InitHaloGoal() )
	const float haloSize = 200.0f; // detirmines the height+width of halo in pixels ( for collision )
	const float haloScale = 0.35f; // used by InitHaloGoal() method to set halos scale
	const float animSpeed = 1.0f / 15.0f; // used for sprite animations
};