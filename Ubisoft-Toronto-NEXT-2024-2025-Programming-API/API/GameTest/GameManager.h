//---------------------------------------------------------------------------------
// GameManager.h
// Header file that contains all methods/used for the Gamemanager class
//---------------------------------------------------------------------------------
#pragma once
#include "app\app.h" // to access api methods
#include "BoundryManager.h" // boundry manager access
#include "LevelData.h" // level data access

class GameManager
{
public:
	BoundryManager boundryMan; // public boundry manager instance

	void BuildWorld(int levelIndex); // called on init and whenever player completes level, this rebuilds the entire level based off it's given index
	void NextLevel(); // increases 'levelIndex' then calls "BuildWorld" to rebuild level
	bool CheckPlayerCollision(float ballPosX, float ballPosY, float deltaTime); // calls boundryMan CollisionCheck() method
	void DrawBoundries(); // calls boundryMan ConstructWalls() method
	int GetLevelIndex(); // returns current level index

	float currentBallSpawnX, currentBallSpawnY; // sets ball spawn depending on level
	float currentHaloSpawnX, currentHaloSpawnY; // sets "golf hole" spawn depending on level

	int totalLevelCount = 4; // levels 1,2,3, end aka 4
private:
	LevelData lvlData; // local level data instance

	void DestroyCurrentLevel(); // called whenever "BuildWorld" is called, to wipe prevoius level
	
	int levelIndex = 0; // keep track of current level
};