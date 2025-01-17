//---------------------------------------------------------------------------------
// PlayerBall.h
// Header file that contains all methods/used for animated background
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access api methods
class StarBackground
{
public:
	void InitSpaceBackground(); // serves as a constructor for this class
	void RenderBackground(); // renders background during game run-time
	void AnimateBackground(float deltaTime); // animates background sprite-sheet

	CSimpleSprite* starSprite; // reference to ball sprite
private:
	const float animSpeed = 1.0f / 2.0f; // used for sprite animations
};

