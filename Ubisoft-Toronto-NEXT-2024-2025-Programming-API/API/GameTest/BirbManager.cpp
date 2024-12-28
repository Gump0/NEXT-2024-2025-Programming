///////////////////////////////////////////////////////////////////////////////
// Filename: BirbManager.cpp
// Responsible with managing birb spawns and birb data management
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "BirbManager.h"
#include "BirbMove.h"

void BirbManager::SpawnBirb() {
	if (birbs.size() >= maxBirbCount) { // check number of Birb instances
		std::cout << "Cannot spawn more birbs. Maximum count reached.\n";
		return;
	}
	auto birb = std::make_unique<BirbMove>(); // create new birb instance
	float spawnHeight = RandomSpawnHeight(); // generate spawn height
	bool direciton = RandomDir(); // generate spawn location and flying direction

	birb->InitBirbSprites(spawnHeight, direciton); // call InitBirbSprites in specific class instance

	birbs.push_back(std::move(birb));
}

void BirbManager::UpdateBirbs()
{
	for (const auto& birb : birbs)
	{
		birb->BirbController(); // move birbs
	}
}

void BirbManager::DestroyBirb() {

}

void BirbManager::BirbKill() {

}

void BirbManager::RenderBirbs() {
	for (auto& birb : birbs) {
		birb->RenderBirb();
	}
}

void BirbManager::UpdateBirbAnims(float deltaTime) {
	for (auto& birb : birbs) {
		birb->UpdateAnim(deltaTime);
	}
}

bool BirbManager::RandomDir() { // (0) left == false || (1) right == true
	int randRoll = rand() % 2; // Roll random int (either 0 or 1)
	switch (randRoll) {
	case true:
		return true;
		break;

	case false:
		return false;
		break;

	default: // for debug
		return true;
		break;
	}
}

float BirbManager::RandomSpawnHeight() {
	return 75 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (750 - 75)));
}