//---------------------------------------------------------------------------------
// PlayerBall.h
// Header file that contains all methods/used data in player ball class file
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access api methods

class PlayerBall
{
public:
	void BallUpdate(float deltaTime); // encapsulates local methods dependant on update method

	void DrawMouseLine(); // draws line between mouse and ball for visual stuff
	void CalculateForce(float normalX, float normalY); // pass through normalized vectors and use elapsed time sine wave to calculate force applied
	void ApplyForce(float x, float y); // method that applies directional vector to ball hit.
	void WallBounce(); // when ball hits wall, invert it's current velocity vector

	// SPRITES AND BALL INITIALIZATION
	void InitPlayerBall(float spawnX, float spawnY); // serves as a constructor for this class, also inits sprites at spawn location
	void RenderBall(); // renders ball during game run-time
	void DisplayHitCount(); // displays the total number of times the ball was hit
	void ResetMoveCount(); // on level switch, reset the hitCount total to zero

	int hitCount = 0; // integer that keeps track of how many times the player has hit the ball
	float worldPosX = 500.0f, worldPosY = 400.0f; // detirmines the balls position in world-space

	CSimpleSprite* ballSprite; // reference to ball sprite
private:
	void PlayerController(float deltaTime); // allows the player to control and hit the ball.
	void BallRigidBody(float deltaTime); // called after ball is hit, this method is ran in update until balls current velocity = 0
	void UpdateAnim(float deltaTime); // updates balls animations

	// BALL VARIABLES
	float ballVelocityX, ballVelocityY; // stores balls current velocity values
	const float rateOfDecel = 0.033f; // Detirmines a rate in which the ball decelerates
	const float mass = 0.8f; // value used for calculating physics stuff in kg? WHAT KINDA PLANET IS 0.8KG?!?!

	const float ballSize = 200.0f; // detirmines the height+width of ball in pixels ( for collision )
	const float ballScale = 0.35f; // used by InitPlayerBall() method to set balls scale
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