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
	BirbMove *newBirb = new BirbMove(RandomSpawnHeight(), RandomDir(), this);

	newBirb->InitBirbSprites(RandomSpawnHeight(), RandomDir());

	birbs.push_back(newBirb);
}

void BirbManager::DestroyBirb(BirbMove* birbToRemove) {
	auto it = std::find(birbs.begin(), birbs.end(), birbToRemove);
	if (it != birbs.end()) {
		delete* it;
		birbs.erase(it);
	}
}

void BirbManager::BirbKill(BirbMove* birbToRemove) {

}

void BirbManager::UpdateBirbs()
{
	for (auto it = birbs.begin(); it != birbs.end(); ) {
		BirbMove* birb = *it;
		if (birb->BirbInBounds()) { // Check if the birb is out of bounds
			delete birb;             // Delete the birb object
			it = birbs.erase(it);    // Erase from list and update the iterator
			SpawnBirb();             // Make new birb!! :D
		}
		else {
			birb->BirbController();  // Move birbs normally
			++it;
		}
	}
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