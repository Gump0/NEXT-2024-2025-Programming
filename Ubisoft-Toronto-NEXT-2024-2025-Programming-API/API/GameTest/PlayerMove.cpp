///////////////////////////////////////////////////////////////////////////////
// Filename: PlayerMove.cpp
// Chracter Move Script && Animations
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "app\app.h" // to access CSimpleSprite class
#include "PlayerMove.h"

enum // animation states
{
	anim_FlyRight,
	anim_FlyLeft,
	anim_Idle,
	anim_Death,
};

PlayerMove::PlayerMove() {
	currentHP = maxHP;
}

int PlayerMove::GetPlayerHP() {
	return currentHP;
}

void PlayerMove::TakeDamage(int amount) {
	currentHP -= amount;
	if (currentHP <= 0) {
		//do sum abt it
	}
}

void PlayerMove::PlayerController() {

}

void PlayerMove::InitPlayerSprites() {
	birbSprite = App::CreateSprite(".\\gamedata\\BirdSprite.bmp", 8, 3);
	birbSprite->SetPosition(400.0f, 400.0f);
	birbSprite->CreateAnimation(anim_FlyLeft, moveSpeed, { 9,10,11,12,13,14,15,16 });
	birbSprite->CreateAnimation(anim_FlyRight, moveSpeed, { 17,18,19,20,21,22,23,24 });
	birbSprite->CreateAnimation(anim_Idle, moveSpeed, { 1,1,2,2,2,1,1 });
	birbSprite->SetScale(5.0f);
}
