//---------------------------------------------------------------------------------
// LevelData.h
// Contains data and parameters used for the LevelData class
//---------------------------------------------------------------------------------
#pragma once
#include "BoundryManager.h"

class LevelData
{
public:
    std::vector<Wall> GetLevel1Walls(); // return level 1 walls
    std::vector<Wall> GetLevel2Walls(); // return level 2 walls
    std::vector<Wall> GetLevel3Walls(); // return level 3 walls
    std::vector<Wall> GetTheEndLevel(); // return level 3 walls

    static const float playerSpawnPoints[8]; // stores player spawn positions
    static const float haloSpawnPoints[8]; // stores halo spawn points

private:
    std::vector<Wall> walls; // wall specific to level
};