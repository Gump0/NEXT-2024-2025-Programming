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

void PlayerBall::PlayerController() {
	if (!App::IsKeyPressed(VK_LBUTTON)) return;
	bool firstCall = true;
	// Calculate directional vector
	// V = (x2 - x1, y2 - y1)
	float dirX = worldPosX - mouseX; // inverse direction
	float dirY = worldPosY - mouseY; // inverse direction
	// output normalized vector between 0-1
	// |V| = sqrt(x^2 + y^2)
	float magnitude = sqrt(dirX * dirX + dirY * dirY);
	float normalizedX = dirX / magnitude;
	float normalizedY = dirY / magnitude;

	App::GetMousePos(mouseX, mouseY);
}

void PlayerBall::DebugXY() {
	std::string x1 = std::to_string(worldPosX);
	std::string y1 = std::to_string(worldPosY);
	std::string x2 = std::to_string(mouseX);
	std::string y2 = std::to_string(mouseY);

	App::Print(500, 700, x1.c_str());
	App::Print(500, 650, y1.c_str());
	App::Print(500, 600, x2.c_str());
	App::Print(500, 550, y2.c_str());


}

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
