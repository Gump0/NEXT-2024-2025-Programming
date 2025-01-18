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
private:
    std::vector<Wall> walls; // wall specific to level
};