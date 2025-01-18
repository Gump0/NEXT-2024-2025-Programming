///////////////////////////////////////////////////////////////////////////////
// Filename: SaturnHaloGoal.cpp
// Class that stores all logic related to the miniputt goal!
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SaturnHaloGoal.h"

enum { // animation states
	halo_norm, // halo idle
};

void SaturnHaloGoal::UpdateHalo(float deltaTime) {
	BallCollisionCheck();
	UpdateAnim(deltaTime);
}

void SaturnHaloGoal::BallCollisionCheck() {

}

void SaturnHaloGoal::EndLevel() {

}

void SaturnHaloGoal::InitHaloGoal(float spawnX, float spawnY) {
	haloSprite = App::CreateSprite(".\\GameData\\halo.bmp", 2, 2);
	haloSprite->SetPosition(spawnX, spawnY);
	haloSprite->CreateAnimation(halo_norm, animSpeed, { 0,1,2 });
	haloSprite->SetAnimation(halo_norm);
	haloSprite->SetScale(haloScale);
	worldPosX = spawnX; worldPosY = spawnY; // set world pos :)
}

void SaturnHaloGoal::RenderHalo() {
	haloSprite->Draw();
}

void SaturnHaloGoal::UpdateAnim(float deltaTime) {
	haloSprite->Update(deltaTime);
}