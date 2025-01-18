///////////////////////////////////////////////////////////////////////////////
// Filename: LevelData.cpp
// Stores data related to each level ( if I have time to make more than one )
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "LevelData.h"

std::vector<Wall> level1Walls = {   // Predefine wall data for Level 1
    {500, 25, 1100, 50},
    {500, 750, 1100, 50},
    {25, 385, 50, 675},
    {1000, 385, 50, 675},
};

std::vector<Wall> LevelData::GetLevel1Walls() {
    return level1Walls;
}