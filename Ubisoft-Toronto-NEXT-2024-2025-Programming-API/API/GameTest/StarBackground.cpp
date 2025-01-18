///////////////////////////////////////////////////////////////////////////////
// Filename: StarBackground.cpp
// Simple class that stores logic for star background animation :)
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "StarBackground.h"

enum {
	background_idle,
};

void StarBackground::InitSpaceBackground() {
	starSprite = App::CreateSprite(".\\GameData\\bg-stars-space.bmp", 3, 2);
	starSprite->SetPosition(400.0f, 500.0f); // center of screen
	starSprite->CreateAnimation(background_idle, animSpeed, { 0,1,2,3,4,5 });
	starSprite->SetAnimation(background_idle);
	starSprite->SetScale(2.5f);
}

void StarBackground::RenderBackground() {
	starSprite->Draw();
}

void StarBackground::AnimateBackground(float deltaTime) {
	starSprite->Update(deltaTime);
}
