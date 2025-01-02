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
#include "BirbManager.h"
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// Create class instances.
//------------------------------------------------------------------------

BirbManager birbManager; // instance of BirbManager class ( See BirbManager For Details )
CSimpleSprite* backgroundTexture;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init() {
	//Initialize background texture
	backgroundTexture = App::CreateSprite(".\\gamedata\\sky-bg-art.bmp", 1, 1);
	backgroundTexture->SetPosition(400.0f, 400.0f);

	// Initialize birbs
	int numberOfBirbs = 6; // Determines the maximum number of birbs that can be active at a time
	for (int i = 0; i < numberOfBirbs; i++) {
		birbManager.SpawnBirb();
	}
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(const float deltaTime) {
	birbManager.UpdateBirbs();
	birbManager.UpdateBirbAnims(deltaTime);
	
	
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
void Render() {	
	backgroundTexture->Draw();
	birbManager.RenderBirbs();
}
//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown() {	
	
}