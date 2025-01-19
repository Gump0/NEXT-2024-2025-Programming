///////////////////////////////////////////////////////////////////////////////
// Filename: GameManager.cpp
// In charge of overseeing game-state keeping track of..
// Current level, player/goal spawn, information display.
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "GameManager.h"

void GameManager::BuildWorld(int levelIndex) {
	// index 0 = level 1
	// index 1 = level 2
	// index 2 = level 3
	switch (levelIndex) {
	case 0:
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

void GameManager::NextLevel() {
	levelIndex++;
	if (levelIndex >= totalLevelCount)
		// Maybe go to "The End" Screen??
		levelIndex = 0;
	BuildWorld(levelIndex);
}

bool GameManager::CheckPlayerCollision(float ballPosX, float ballPosY, float deltaTime) {
	if (boundryMan.CollisionCheck(ballPosX, ballPosY, deltaTime))
		return true;
	return false;
}

void GameManager::DrawBoundries() {
	boundryMan.DrawWalls();
}

void GameManager::DestroyCurrentLevel() {

}

int GameManager::GetLevelIndex() {
	return levelIndex;
}