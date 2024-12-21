//---------------------------------------------------------------------------------
// PlayerMove.h
// Handles player movement, animations and player stats
//---------------------------------------------------------------------------------
#pragma once
class PlayerMove
{
public:
	PlayerMove();
	int GetPlayerHP();
	void TakeDamage(int amount);
	void PlayerController(); // method that handles player movement and sprites
	void InitPlayerSprites();
	CSimpleSprite* birbSprite;
private:
	int maxHP = 5;
	int currentHP;
	float moveSpeed = 1.0f/15.0f;
};

