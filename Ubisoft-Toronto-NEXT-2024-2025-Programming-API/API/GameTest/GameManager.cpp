///////////////////////////////////////////////////////////////////////////////
// Filename: GameManager.cpp
// In charge of overseeing game-state keeping track of..
// Current level, player/goal spawn, information display.
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "GameManager.h"

void GameManager::BuildWorld(int levelIndex) { // in charge with constructing new levels
	// index 0 = level 1					  // and passing correct data to other classes
	// index 1 = level 2
	// index 2 = level 3
	switch (levelIndex) { // probably not the best way to do this?
	case 0:				 // based off index passed into this method we grab the corresponding level
		boundryMan.ConstructWalls(lvlData.GetLevel1Walls());
		break;

	case 1:
		boundryMan.ConstructWalls(lvlData.GetLevel2Walls());
		break;

	case 2:
		boundryMan.ConstructWalls(lvlData.GetLevel3Walls());
		break;
	case 3:
		boundryMan.ConstructWalls(lvlData.GetTheEndLevel());
		break;
	}
	// Set ball and halo spawns correctly
	int ballSpawnIndex = levelIndex * 2; // Each level has 2 values (x, y)
	currentBallSpawnX = lvlData.playerSpawnPoints[ballSpawnIndex];
	currentBallSpawnY = lvlData.playerSpawnPoints[ballSpawnIndex + 1];

	int haloSpawnIndex = levelIndex * 2; // Each level has 2 values (x, y)
	currentHaloSpawnX = lvlData.haloSpawnPoints[haloSpawnIndex];
	currentHaloSpawnY = lvlData.haloSpawnPoints[haloSpawnIndex + 1];
}

void GameManager::NextLevel() { // increases level index and builds next level
	levelIndex++;
	if (levelIndex >= totalLevelCount)
		// Maybe go to "The End" Screen??
		levelIndex = 0;
	BuildWorld(levelIndex);
}

bool GameManager::CheckPlayerCollision(float ballPosX, float ballPosY, float deltaTime) { // calls boundryMan's collision check
	if (boundryMan.CollisionCheck(ballPosX, ballPosY, deltaTime))						 // returns true if player is touching
		return true;
	return false;
}

void GameManager::DrawBoundries() { // calls api draw method for each wall in boundryMan
	boundryMan.DrawWalls();
}

void GameManager::DestroyCurrentLevel() { // used to destroy old level data
										  // likely won't need since we update off parsed data
}

int GameManager::GetLevelIndex() { // returns the current level index
	return levelIndex;
}