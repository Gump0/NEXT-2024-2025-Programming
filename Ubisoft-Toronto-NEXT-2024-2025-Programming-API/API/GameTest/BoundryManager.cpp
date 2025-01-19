///////////////////////////////////////////////////////////////////////////////
// Filename: BoundryManager.cpp
// In charge with creating a dynamic, modular collision system/level builder
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "BoundryManager.h"

void BoundryManager::ConstructWalls(const std::vector<Wall>& walls) {
	c_walls = walls;
}

void BoundryManager::DrawWalls() {
	for (const Wall& wall : c_walls) {
		App::DrawLine(wall.x - (wall.width / 2), wall.y + (wall.height / 2), wall.x + (wall.width / 2), wall.y + (wall.height / 2)); // top face
		App::DrawLine(wall.x - (wall.width / 2), wall.y - (wall.height / 2), wall.x + (wall.width / 2), wall.y - (wall.height / 2)); // bottom face
		App::DrawLine(wall.x - (wall.width / 2), wall.y + (wall.height / 2), wall.x - (wall.width / 2), wall.y - (wall.height / 2)); // left face
		App::DrawLine(wall.x + (wall.width / 2), wall.y + (wall.height / 2), wall.x + (wall.width / 2), wall.y - (wall.height / 2)); // right face
	}
}

bool BoundryManager::CollisionCheck(float ballX, float ballY, float deltaTime) {
	for (Wall& wall : c_walls) {
		if (wall.cooldown > 0)
			wall.cooldown -= deltaTime;
		if (wall.cooldown <= 0)
			if (ballX + 10 > wall.x - (wall.width/2) && ballX - 10 < wall.x + (wall.width/2))
				if (ballY + 10 > wall.y - (wall.height/2) && ballY - 10 < wall.y + (wall.height/2)) {
					App::PlaySound(".\\GameData\\hitsound.wav", false);
					wall.cooldown = 0.50f;
					return true;
				}
	}
	return false;
}