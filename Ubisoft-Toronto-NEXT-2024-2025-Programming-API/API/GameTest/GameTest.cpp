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

StarBackground starB; // star background instance
PlayerBall playerBall; // playerball instance
SaturnHaloGoal saturn; // saturn goal instance

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init() {
	starB.InitSpaceBackground();
	playerBall.InitPlayerBall(0.0f, 0.0f);
	saturn.InitHaloGoal(850.0f, 600.0f);

	// Start looping track (made by me :D)
	// Shameless plug https://soundcloud.com/gumpthe1/what-how
	//App::PlaySound(".\\GameData\\loopingtrack.wav", true);
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(const float deltaTime) {
	playerBall.BallRigidBody(deltaTime);
	playerBall.PlayerController(deltaTime);
	saturn.UpdateHalo(deltaTime);
	//Animations
	starB.AnimateBackground(deltaTime);
	playerBall.UpdateAnim(deltaTime);

	if (App::IsKeyPressed(VK_RBUTTON)) playerBall.ApplyForce(2.5f, 2.5f); //for debugging shiz
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render() {	
	starB.RenderBackground();
	playerBall.RenderBall();
	playerBall.DrawMouseLine();
	playerBall.DebugXY();
	saturn.RenderHalo();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown() {	

}