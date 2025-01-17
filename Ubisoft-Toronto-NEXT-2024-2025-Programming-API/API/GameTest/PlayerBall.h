//---------------------------------------------------------------------------------
// PlayerBall.h
// Header file that contains all methods/used data in player ball class file
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access api methods

class PlayerBall
{
public:
	void PlayerController(); // allows the player to control and hit the ball.
	void BallRigidBody(); // called after ball is hit, this method is ran in update until balls current velocity = 0
	void ApplyForce(float x, float y); // method that applies directional vector to ball hit.

	// SPRITES AND BALL INITIALIZATION
	void InitPlayerBall(float spawnX, float spawnY); // serves as a constructor for this class, also inits sprites at spawn location
	void RenderBall(); // renders ball during game run-time
	void UpdateAnim(float deltaTime); // updates balls animations

	bool canMove; // boolean that controls when 'PlayerController()' method is called
	CSimpleSprite* ballSprite; // reference to ball sprite
private:
	float worldPosX, worldPosY; // detirmines the balls position in world-space
	const float ballSize = 200.0f; // detirmines the height+width of ball in pixels
	const float muCoeffiecent = 0.38f; // static variable used for physics calculations ( Friction Coeffiecent )

	const float animSpeed = 1.0f / 15.0f; // used for sprite animations
};

