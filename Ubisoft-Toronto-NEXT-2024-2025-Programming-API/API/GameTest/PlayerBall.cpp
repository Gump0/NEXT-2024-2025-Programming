///////////////////////////////////////////////////////////////////////////////
// Filename: PlayerBall.cpp
// Definition file containing logic for player ball
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "PlayerBall.h"

enum // animation states
{
	ball_norm, // when ball is normal ;)
	ball_hot, // when ball is within wall breaking threshhold
};


void PlayerBall::PlayerController() {
	if (!canMove) return;


}

void PlayerBall::BallRigidBody(float deltaTime) {
	float d = rateOfDecel * deltaTime;
	
	worldPosX += ballVelocityX -= d;
	worldPosY += ballVelocityY -= d;
	ballSprite->SetPosition(worldPosX, worldPosY);

	if (std::abs(ballVelocityX) < 0.01f) ballVelocityX = 0.0f;
	if (std::abs(ballVelocityY) < 0.01f) ballVelocityY = 0.0f;
}

void PlayerBall::ApplyForce(float x, float y) {
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
