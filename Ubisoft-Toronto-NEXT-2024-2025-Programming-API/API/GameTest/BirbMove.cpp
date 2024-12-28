///////////////////////////////////////////////////////////////////////////////
// Filename: BirbMove.cpp
// Chracter Move Script && Animations
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

void BirbMove::DestroyBirb() {
	//delete BirbMove;
}

void BirbMove::KillBirb() {

}

void BirbMove::InitBirbSprites(float height, bool flyDir) {
	birbSprite = App::CreateSprite(".\\gamedata\\BirdSprite.bmp", 8, 3);
	flyDirection = flyDir;
	if (flyDirection) { // if true (going right)
		birbSprite->SetPosition(0.0f, height);
		birbSprite->CreateAnimation(anim_FlyRight, animSpeed, { 17,18,19,20,21,22,23,24 });
		birbSprite->SetAnimation(anim_FlyRight);
		birbSprite->SetScale(5.0f);

	}
	else { // if false (going left)
		birbSprite->SetPosition(800.0f, height); // spawn at the very far right for now
		birbSprite->CreateAnimation(anim_FlyLeft, animSpeed, { 9,10,11,12,13,14,15,16 });
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
		//DESTROY THE BIRB INSTANCE NOW!!!
		break;

	case false: // when flying left
		birbSprite->SetAnimation(anim_FlyLeft);
		birbSprite->GetPosition(moveX, moveY);
		moveX -= moveSpeed;
		birbSprite->SetPosition(moveX, moveY);
		//DESTROY THE BIRB INSTANCE NOW!!!
		break;
	}
}

void BirbMove::RenderBirb() {
	birbSprite->Draw();
}