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

bool BirbMove::BirbDirection() { // left == false || right == true
	return false;
}

void BirbMove::DestroyBirb() {
	//delete BirbMove;
}

void BirbMove::KillBirb() {

}

void BirbMove::InitBirbSprites() {
	birbSprite = App::CreateSprite(".\\gamedata\\BirdSprite.bmp", 8, 3);
	birbSprite->SetPosition(800.0f, 400.0f); // spawn at the very far right for now
	birbSprite->CreateAnimation(anim_FlyLeft, animSpeed, { 9,10,11,12,13,14,15,16 });
	birbSprite->CreateAnimation(anim_FlyRight, animSpeed, { 17,18,19,20,21,22,23,24 });
	birbSprite->CreateAnimation(anim_Idle, animSpeed, { 1,1,2,2,2,1,1 });
	birbSprite->SetAnimation(anim_FlyRight);
	birbSprite->SetScale(5.0f);
}

void BirbMove::BirbController() {
	switch (BirbDirection()) {
	case true: // when flying right
		while (moveX > 0 - birbWidth) {
			birbSprite->SetAnimation(anim_FlyRight);
			birbSprite->GetPosition(moveX, moveY);
			moveX += moveSpeed;
			birbSprite->SetPosition(moveX, moveY);
		}
		//DESTROY THE BIRB INSTANCE NOW!!!
		break;

	case false: // when flying left
		//while (moveX < 1100 + birbWidth) {
		birbSprite->SetAnimation(anim_FlyLeft);
		birbSprite->GetPosition(moveX, moveY);
		moveX -= moveSpeed;
		birbSprite->SetPosition(moveX, moveY);
		//}
		//DESTROY THE BIRB INSTANCE NOW!!!
		break;
	}
}