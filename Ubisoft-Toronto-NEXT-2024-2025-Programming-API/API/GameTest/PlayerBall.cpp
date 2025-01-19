///////////////////////////////////////////////////////////////////////////////
// Filename: PlayerBall.cpp
// Logic for the player's "golf ball"
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "cmath"
#include "PlayerBall.h"

enum { // animation states
	ball_norm, // when ball is normal ;)
	ball_hot, // when ball is within wall breaking threshhold
};

void PlayerBall::BallUpdate(float deltaTime) {
	PlayerController(deltaTime);
	BallRigidBody(deltaTime);
	UpdateAnim(deltaTime);
}

void PlayerBall::PlayerController(float deltaTime) {
	if (!App::IsKeyPressed(VK_LBUTTON)) { CalculateForce(normalizedX, normalizedY); return; }
	// Calculate directional vector
	// V = (x2 - x1, y2 - y1)
	float dirX = worldPosX - mouseX; // inverse direction
	float dirY = worldPosY - mouseY; // inverse direction
	// output normalized vector between 0-1
	// |V| = sqrt(x^2 + y^2)
	float magnitude = sqrt(dirX * dirX + dirY * dirY);
	normalizedX = dirX / magnitude;
	normalizedY = dirY / magnitude;
	
	// loop through 0% - 100% power
	// y = sin(x)
	elapsedTime += deltaTime;
	power = std::sin(elapsedTime / 350);

	App::GetMousePos(mouseX, mouseY);
}

void PlayerBall::DrawMouseLine() {
	if (!App::IsKeyPressed(VK_LBUTTON)) return;
	float r = 1;
	float g = std::cos(elapsedTime / 350);;
	float b = std::cos(elapsedTime / 350);;
	App::DrawLine(worldPosX, worldPosY, mouseX, mouseY, r, g, b);
}

void PlayerBall::CalculateForce(float normalX, float normalY) {
	float forceX = lerp(2.5f, 25.0f, power);
	float forceY = lerp(2.5f, 25.0f, power);
	forceX *= normalX;
	forceY *= normalY;

	ApplyForce(forceX, forceY);

	normalizedX = 0.0f;
	normalizedY = 0.0f;
}

void PlayerBall::DebugXY() {
	std::string x1 = std::to_string(worldPosX);
	std::string y1 = std::to_string(worldPosY);
	std::string x2 = std::to_string(mouseX);
	std::string y2 = std::to_string(mouseY);
	std::string f = std::to_string(ballVelocityY);

	App::Print(500, 700, x1.c_str());
	App::Print(500, 650, y1.c_str());
	App::Print(500, 600, x2.c_str());
	App::Print(500, 550, y2.c_str());
	App::Print(500, 400, f.c_str());
}

void PlayerBall::BallRigidBody(float deltaTime) {
	float d = rateOfDecel * deltaTime;

	// X-axis physics calculations
	if (ballVelocityX != 0.0f) {
		worldPosX += ballVelocityX;							// Update position based on velocity
		ballVelocityX -= (ballVelocityX > 0.0f ? d : -d);	// Reduce velocity to zero by rateOfDecel
		if (std::abs(ballVelocityX) < 0.01f)				// Stop if velocity is negligible
			ballVelocityX = 0.0f;
	}

	// Y-axis physics calculations
	if (ballVelocityY != 0.0f) {
		worldPosY += ballVelocityY;             // same thing here :P
		ballVelocityY -= (ballVelocityY > 0.0f ? d : -d);
		if (std::abs(ballVelocityY) < 0.01f)
			ballVelocityY = 0.0f;
	}

	ballSprite->SetPosition(worldPosX, worldPosY);
}

void PlayerBall::ApplyForce(float x, float y) {
	float forceAppliedX = x * mass;
	float forceAppliedY = y * mass;
	
	ballVelocityX += forceAppliedX;
	ballVelocityY += forceAppliedY;

	moveCount++;
}

void PlayerBall::WallBounce() {
	ballVelocityX = -ballVelocityX;
	ballVelocityY = -ballVelocityY;
}

// RENDER STUFF
void PlayerBall::InitPlayerBall(float spawnX, float spawnY) {
	ballSprite = App::CreateSprite(".\\GameData\\starball.bmp", 3, 1);
	ballSprite->SetPosition(spawnX, spawnY);
	ballSprite->CreateAnimation(ball_norm, animSpeed, { 0,1,2 });
	// CREATE HOT ANIMATIONS ONCE WE GET THERE XD
	ballSprite->SetAnimation(ball_norm);
	ballSprite->SetScale(ballScale);

	worldPosX = spawnX;
	worldPosY = spawnY;
}

void PlayerBall::RenderBall() {
	ballSprite->Draw();
}

void PlayerBall::UpdateAnim(float deltaTime) {
	ballSprite->Update(deltaTime);
}
