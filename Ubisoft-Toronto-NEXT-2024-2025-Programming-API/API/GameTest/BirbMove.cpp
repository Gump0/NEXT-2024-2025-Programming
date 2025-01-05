///////////////////////////////////////////////////////////////////////////////
// Filename: BirbMove.cpp
// Birb NPC Move Script && Animations
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "app\app.h" // to access CSimpleSprite class
#include "BirbMove.h"

enum // animation states
{
	anim_FlyRight,
	anim_FlyLeft,
	anim_Idle,
	anim_Death,
};

void BirbMove::KillBirb() {

}

void BirbMove::InitBirbSprites(float height, bool flyDir) {
	birbSprite = App::CreateSprite(".\\gamedata\\BirdSprite.bmp", 8, 3);
	flyDirection = flyDir;
	if (flyDirection) { // if true (going right)
		birbSprite->SetPosition(0.0f, height);
		birbSprite->CreateAnimation(anim_FlyRight, animSpeed, { 16,17,18,19,20,21,22,23 });
		birbSprite->SetAnimation(anim_FlyRight);
		birbSprite->SetScale(5.0f);

	}
	else { // if false (going left)
		birbSprite->SetPosition(1100.0f, height); // spawn at the very far right for now
		birbSprite->CreateAnimation(anim_FlyLeft, animSpeed, { 8,9,10,11,12,13,14,15 });
		birbSprite->SetAnimation(anim_FlyLeft);
		birbSprite->SetScale(5.0f);
	}
}

void BirbMove::BirbController() {
	switch (flyDirection) {
	case true: // when flying right
			birbSprite->SetAnimation(anim_FlyRight);
			birbSprite->GetPosition(moveX, moveY);
			moveX += moveSpeed;
			birbSprite->SetPosition(moveX, moveY);
		break;

	case false: // when flying left
		birbSprite->SetAnimation(anim_FlyLeft);
		birbSprite->GetPosition(moveX, moveY);
		moveX -= moveSpeed;
		birbSprite->SetPosition(moveX, moveY);
		break;
	}
}

void BirbMove::RenderBirb() {
	birbSprite->Draw();
}

void BirbMove::UpdateAnim(float deltaTime) {
	birbSprite->Update(deltaTime);
}

bool BirbMove::BirbInBounds() {
	if (moveX > 1200 || moveX < -200) {
		return true;
	}
	return false;
}

bool BirbMove::IsHit(float x, float y) {
	if (x > moveX - 20 && x < moveX + 20)
		if(y > moveY - 20 && y < moveY + 20)
			return true;
	return false;
}