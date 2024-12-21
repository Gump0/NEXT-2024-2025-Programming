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
#include "PlayerMove.h"
//------------------------------------------------------------------------
// 

//------------------------------------------------------------------------
// Create class instances.
//------------------------------------------------------------------------

PlayerMove playerMove; // instance of playermove class

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{
	playerMove.InitPlayerSprites();
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(const float deltaTime)
{
	//UpdatePlayerSprites();
	//------------------------------------------------------------------------
	// Sample Sound.
	//------------------------------------------------------------------------
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_B, true))
		{
			App::PlaySound(".\\TestData\\Test.wav", true);
		}
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_X, true))
		{
			App::StopSound(".\\TestData\\Test.wav");
		}
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{	
	playerMove.birbSprite->Draw();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{	
	
}