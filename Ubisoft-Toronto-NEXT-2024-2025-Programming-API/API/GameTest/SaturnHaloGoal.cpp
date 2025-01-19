///////////////////////////////////////////////////////////////////////////////
// Filename: SaturnHaloGoal.cpp
// Class that handles all logic related to the miniputt goal!
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SaturnHaloGoal.h"

enum { // animation states
	halo_norm, // halo idle
};

void SaturnHaloGoal::UpdateHalo(float deltaTime) { // general local update method
	UpdateAnim(deltaTime);
}

bool SaturnHaloGoal::BallCollisionCheck(float ballX, float ballY) { // Check if ball collides with goal
	float size = haloSize * haloScale;
	if (ballX > worldPosX - size && ballX < worldPosX + size)
		if (ballY > worldPosY - size && ballY < worldPosY + size) {
			EndLevel();
			return true;
		}
	return false;
}

void SaturnHaloGoal::EndLevel() { // method called when player collides with this object
	App::PlaySound(".\\GameData\\halosound.wav", false);
}

void SaturnHaloGoal::InitHaloGoal(float spawnX, float spawnY) { // initialize this object
	haloSprite = App::CreateSprite(".\\GameData\\halo.bmp", 2, 2);
	haloSprite->SetPosition(spawnX, spawnY);
	haloSprite->CreateAnimation(halo_norm, animSpeed, { 0,1,2 });
	haloSprite->SetAnimation(halo_norm);
	haloSprite->SetScale(haloScale);
	worldPosX = spawnX; worldPosY = spawnY; // set world pos :)
}

void SaturnHaloGoal::RenderHalo() { // call api Draw method
	haloSprite->Draw();
}

void SaturnHaloGoal::UpdateAnim(float deltaTime) { // call api sprite update method
	haloSprite->Update(deltaTime);
}