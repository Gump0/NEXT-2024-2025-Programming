//---------------------------------------------------------------------------------
// LevelData.h
// Contains data and parameters used for the LevelData class
//---------------------------------------------------------------------------------
#pragma once
#include "BoundryManager.h"

class LevelData
{
public:
	//LevelData(const std::vector<Wall>& levelWalls) : walls(levelWalls) {} // constructor used to init level data

    const std::vector<Wall>& getWalls() const {
        return walls;
    }

    std::vector<Wall> GetLevel1Walls();
private:
    std::vector<Wall> walls; // wall specific to level
};

