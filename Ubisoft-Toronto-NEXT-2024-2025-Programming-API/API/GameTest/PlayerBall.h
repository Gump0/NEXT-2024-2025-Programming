//---------------------------------------------------------------------------------
// PlayerBall.h
// Header file that contains all methods/used data in player ball class file
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access api methods

class PlayerBall
{
public:
	void PlayerController(float deltaTime); // allows the player to control and hit the ball.
	void DrawMouseLine(); // draws line between mouse and ball for visual stuff
	void BallRigidBody(float deltaTime); // called after ball is hit, this method is ran in update until balls current velocity = 0
	void CalculateForce(float normalX, float normalY); // pass through normalized vectors and use elapsed time sine wave to calculate force applied
	void ApplyForce(float x, float y); // method that applies directional vector to ball hit.

	// SPRITES AND BALL INITIALIZATION
	void InitPlayerBall(float spawnX, float spawnY); // serves as a constructor for this class, also inits sprites at spawn location
	void RenderBall(); // renders ball during game run-time
	void UpdateAnim(float deltaTime); // updates balls animations
	void DebugXY(); // Used to show the mouse position vs ball location for debugging

	bool canMove = true; // boolean that controls when 'Player Controller' class is called
	CSimpleSprite* ballSprite; // reference to ball sprite
private:
	// BALL VARIABLES
	float ballVelocityX, ballVelocityY; // stores balls current velocity values
	float worldPosX = 500.0f, worldPosY = 400.0f; // detirmines the balls position in world-space (THE FIRST TWO IS WORLD POS X/Y, LAST IS MOUSE POS X/Y)
	const float rateOfDecel = 0.033f; // Detirmines a rate in which the ball decelerates
	const float mass = 0.8f; // value used for calculating physics stuff in kg? WHAT KINDA PLANET IS 0.8KG?!?!

	const float ballSize = 200.0f; // detirmines the height+width of ball in pixels
	const float animSpeed = 1.0f / 15.0f; // used for sprite animations

	// PLAYER CONTROLLER VARIABLES
	float mouseX, mouseY; // Used to store current player mouse position
	float normalizedX, normalizedY; // Stores final normalized calculation used for CalculateForce() method
	float elapsedTime; // Tracks time mouse button has been held for
	float power; // stores power ratio between 0-1
	float lerp(float a, float b, float t) { // used to interperlate between two values by t
		return a + t * (b - a);				// where t is between 0 - 1
	}

	float forceX, forceY; // temp
};