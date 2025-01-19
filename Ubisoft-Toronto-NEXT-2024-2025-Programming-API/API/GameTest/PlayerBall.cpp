///////////////////////////////////////////////////////////////////////////////
// Filename: PlayerBall.cpp
// Logic for the player's "golf ball"
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "cmath"
#include "PlayerBall.h"

enum { // animation states
	ball_norm, // when ball is normal ;)
};

void PlayerBall::BallUpdate(float deltaTime) {
	PlayerController(deltaTime);
	BallRigidBody(deltaTime);
	UpdateAnim(deltaTime);
}

void PlayerBall::PlayerController(float deltaTime) {
	static bool wasButtonPressed = false;
	bool isButtonPressed = App::IsKeyPressed(VK_LBUTTON);

	if (!isButtonPressed && wasButtonPressed) { // executes only if mouse button is released
		CalculateForce(normalizedX, normalizedY);
		hitCount++;
	}
	if (isButtonPressed) {
		// Calculate directional vector
		// V = (x2 - x1, y2 - y1)
		float dirX = worldPosX - mouseX;
		float dirY = worldPosY - mouseY;
		// output normalized vector between 0-1
		// |V| = sqrt(x^2 + y^2)
		float magnitude = sqrt(dirX * dirX + dirY * dirY);

		if (magnitude > 0.0f) {
			normalizedX = dirX / magnitude;
			normalizedY = dirY / magnitude;
		}
		// Loop through 0% - 100% power
		// y = sin(x) sorta
		elapsedTime += deltaTime;
		power = (std::sin(elapsedTime / 350) + 1.0f) / 2.0f;

		App::GetMousePos(mouseX, mouseY);
	}
	wasButtonPressed = isButtonPressed; // Update the previous button state
}

void PlayerBall::DrawMouseLine() {
	if (!App::IsKeyPressed(VK_LBUTTON)) return;
	float r = 1;
	float g = 1 - power;
	float b = 1 - power;
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
}

void PlayerBall::WallBounce() {
	ballVelocityX = -ballVelocityX;
	ballVelocityY = -ballVelocityY;
}

void PlayerBall::ResetMoveCount() {
	hitCount = 0;
}

// RENDER STUFF
void PlayerBall::InitPlayerBall(float spawnX, float spawnY) {
	ballSprite = App::CreateSprite(".\\GameData\\starball.bmp", 3, 1);
	ballSprite->SetPosition(spawnX, spawnY);
	ballSprite->CreateAnimation(ball_norm, animSpeed, { 0,1,2 });
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

void PlayerBall::DisplayHitCount() {
	std::string hitText = std::to_string(hitCount);
	App::Print(100, 100, hitText.c_str());
}
