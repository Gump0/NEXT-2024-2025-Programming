///////////////////////////////////////////////////////////////////////////////
// Filename: GameTest.cpp
// Provides a demo of how to use the API
///////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
#include "StarBackground.h"
#include "PlayerBall.h"
#include "SaturnHaloGoal.h"
#include "GameManager.h"

StarBackground starB; // star background instance
PlayerBall playerBall; // playerball instance
SaturnHaloGoal saturn; // saturn goal instance
GameManager gm; // gamemanager instance

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init() {
	starB.InitSpaceBackground();				// build animated background
	playerBall.InitPlayerBall(150.0f, 150.0f);	// spawn first level player (at level 1 spawn point)
	saturn.InitHaloGoal(850.0f, 650.0f);		// spawn first level halo (at level 1 spawn point)

	gm.BuildWorld(0);							// generate level 1

	// Start looping track ( made by me :D )
	// Shameless plug https://soundcloud.com/gumpthe1/what-how
	App::PlaySound(".\\GameData\\loopingtrack.wav", true);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(const float deltaTime) {
	playerBall.BallUpdate(deltaTime); // pass deltaTime to general local update method

	saturn.UpdateHalo(deltaTime); // pass deltaTime to general local update method

	if (saturn.BallCollisionCheck(playerBall.worldPosX, playerBall.worldPosY)) { // if ball hits goal move to next level ( if possible )
		gm.NextLevel();
		playerBall.InitPlayerBall(gm.currentBallSpawnX, gm.currentBallSpawnY);
		playerBall.ResetMoveCount();
		saturn.InitHaloGoal(gm.currentHaloSpawnX, gm.currentHaloSpawnY);
	}

	if (gm.CheckPlayerCollision(playerBall.worldPosX, playerBall.worldPosY, deltaTime)) // make ball bounce if it collides with wall
		playerBall.WallBounce();

	//Animations
	starB.AnimateBackground(deltaTime); // pass deltaTime to animate background
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render() {	
	starB.RenderBackground();		// render animated background
	
	playerBall.RenderBall();		// render player's ball
	playerBall.DrawMouseLine();		// draw laser between mouse cursor and ball
	playerBall.DisplayHitCount();	// display total hits made during hole
	
	saturn.RenderHalo();			// render final goal

	if(gm.GetLevelIndex() == gm.totalLevelCount - 1) // display final level message
		App::Print(450, 450, "Thanks for Playing!");
	
	gm.DrawBoundries(); // draw boundary walls
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown() {	

}