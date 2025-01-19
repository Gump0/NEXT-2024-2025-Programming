///////////////////////////////////////////////////////////////////////////////
// Filename: LevelData.cpp
// Stores data related to each level ( if I have time to make more than one )
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "LevelData.h"

//------------------------------------------------------------------------
// LEVEL DATA
//------------------------------------------------------------------------

std::vector<Wall> level1Walls = {   // Predefine wall data for Level 1
    {500, 25, 1100, 50},    // north wall
    {500, 750, 1100, 50},   // south wall
    {25, 385, 50, 675},     // west wall
    {1000, 385, 50, 675},   // east wall

    {350, 300, 250, 50},    // middle blocks
    {650, 550, 250, 50},
};

std::vector<Wall> level2Walls = {   // Predefine wall data for Level 2
    {500, 25, 1100, 50},    // north wall
    {500, 750, 1100, 50},   // south wall
    {25, 385, 50, 675},     // west wall
    {1000, 385, 50, 675},   // east wall

    {200, 375, 300, 300},   // side blocks
    {825, 375, 300, 300},
    {650, 500, 50, 50},
    {375, 250, 50, 50},
    {520, 600, 150, 15},     // top block
};

std::vector<Wall> level3Walls = {   // Predefine wall data for Level 3
    {500, 25, 1100, 50},    // north wall
    {500, 750, 1100, 50},   // south wall
    {25, 385, 50, 675},     // west wall
    {1000, 385, 50, 675},   // east wall

    {250, 475, 50, 500},   // first east wall
    {600, 300, 50, 500},   // second westbound wall
    {925, 675, 100, 100},

    {385, 300, 25, 25},   // the anoyying blocks
    {500, 415, 25, 25},
    {350, 650, 25, 25},
    {685, 260, 25, 25},
    {800, 470, 25, 25},
    {930, 315, 25, 25},
};

std::vector<Wall> theEndLevel = {   // Predefine wall data for Level 4 ( END SCREEN )
    {500, 25, 1100, 50},    // north wall
    {500, 750, 1100, 50},   // south wall
    {25, 385, 50, 675},     // west wall
    {1000, 385, 50, 675},   // east wall

};

//------------------------------------------------------------------------
// SPAWN DATA
//------------------------------------------------------------------------

const float LevelData::playerSpawnPoints[8] =
{ 150.0f, 150.0f,
  500.0f, 125.0f,
  150.0f, 635.0f,
  500.0f, 400.0f };

const float LevelData::haloSpawnPoints[8] =
{ 850.0f, 650.0f,       // level 1 points = index 0 + 1 ( x, y )
  515.0f, 700.0f,       // level 2 points = index 2 + 3 ( x, y ).....
  850.0f, 125.0f, 
  -100.0f, -100.0f };

std::vector<Wall> LevelData::GetLevel1Walls() {
    return level1Walls;
}

std::vector<Wall> LevelData::GetLevel2Walls() {
    return level2Walls;
}

std::vector<Wall> LevelData::GetLevel3Walls() {
    return level3Walls;
}

std::vector<Wall> LevelData::GetTheEndLevel() {
    return theEndLevel;
}