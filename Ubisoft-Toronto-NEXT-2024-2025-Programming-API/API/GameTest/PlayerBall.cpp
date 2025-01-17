///////////////////////////////////////////////////////////////////////////////
// Filename: PlayerBall.cpp
// Logic for the player's "golf ball"
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "PlayerBall.h"

enum { // animation states
	ball_norm, // when ball is normal ;)
	ball_hot, // when ball is within wall breaking threshhold
};

void PlayerBall::BallRigidBody(float deltaTime) {
	float d = rateOfDecel * deltaTime;
	//X axis physics calculations
	switch (negativeX) {
	case false:
		if (ballVelocityX > 0.0f)
			worldPosX += ballVelocityX -= d;
		break;

	case true:
		if (ballVelocityX < 0.0f)
			worldPosX += ballVelocityX += d;
		break;
	}
	//Y axis physics calculations
	switch (negativeY) {
	case false:
		if (ballVelocityY > 0.0f)
			worldPosY += ballVelocityY -= d;
		break;

	case true:
		if (ballVelocityY < 0.0f)
			worldPosY += ballVelocityY += d;
		break;
	}
	if (ballVelocityX == 0.0f && ballVelocityY == 0.0f) canMove = true;

	ballSprite->SetPosition(worldPosX, worldPosY);
	if (std::abs(ballVelocityX) < 0.1f) ballVelocityX = 0.0f;
	if (std::abs(ballVelocityY) < 0.1f) ballVelocityY = 0.0f;
}

void PlayerBall::ApplyForce(float x, float y) {
	//canMove = false;
	negativeX = (x < 0.0f);
	negativeY = (y < 0.0f);

	float forceAppliedX = x * mass;
	float forceAppliedY = y * mass;
	
	ballVelocityX += forceAppliedX;
	ballVelocityY += forceAppliedY;
}

// RENDER STUFF
void PlayerBall::InitPlayerBall(float spawnX, float spawnY) {
	ballSprite = App::CreateSprite(".\\GamaData\\starball.bmp", 3, 1);
	ballSprite->SetPosition(spawnX, spawnY);
	ballSprite->CreateAnimation(ball_norm, animSpeed, { 0,1,2 });
	// CREATE HOT ANIMATIONS ONCE WE GET THERE XD
	ballSprite->SetAnimation(ball_norm);
	ballSprite->SetScale(0.50f);
}

void PlayerBall::RenderBall() {
	ballSprite->Draw();
}

void PlayerBall::UpdateAnim(float deltaTime) {
	ballSprite->Update(deltaTime);
}
