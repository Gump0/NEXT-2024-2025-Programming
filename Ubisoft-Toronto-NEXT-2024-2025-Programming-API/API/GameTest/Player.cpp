///////////////////////////////////////////////////////////////////////////////
// Filename: Player.cpp
// Handles player inputs, and player shoot mechanic.
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Player.h"
#include "BirbManager.h" // access to birbmanager class methods
#include "app\app.h"

enum // animation states
{
	anim_Crosshair,
	anim_CrossShoot,
};

void Player::InitPlayerSprites() {
	crosshairSprite = App::CreateSprite(".\\gamedata\\crosshairanims.bmp", 2, 2);
	crosshairSprite->SetPosition(moveX, moveY);
	crosshairSprite->CreateAnimation(anim_Crosshair, animSpeed, {0,1,2,3});
	crosshairSprite->SetAnimation(anim_Crosshair);
	crosshairSprite->SetScale(0.5f);
}

void Player::UpdatePlayerCrosshair() {
	crosshairSprite->SetAnimation(anim_Crosshair);
	if (App::GetController().GetLeftThumbStickX() > 0.5f) {
		crosshairSprite->GetPosition(moveX, moveY);
		moveX += sensitivity;
		crosshairSprite->SetPosition(moveX, moveY);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f) {
		crosshairSprite->GetPosition(moveX, moveY);
		moveX -= sensitivity;
		crosshairSprite->SetPosition(moveX, moveY);
	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f) {
		crosshairSprite->GetPosition(moveX, moveY);
		moveY += sensitivity;
		crosshairSprite->SetPosition(moveX, moveY);
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f) {
		crosshairSprite->GetPosition(moveX, moveY);
		moveY -= sensitivity;
		crosshairSprite->SetPosition(moveX, moveY);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false)) {
		Shoot();
	}
}

void Player::RenderCrosshair() {
	crosshairSprite->Draw();
}

void Player::UpdateCrosshairAnims(float deltaTime) {
	crosshairSprite->Update(deltaTime);
}

void Player::Shoot() {
	birbManager.CollisionCheck(moveX, moveY);
}
