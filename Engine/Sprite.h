#pragma once
#include "Graphics.h"
class Sprite
{
public:
	Sprite();
	void DrawZombie(int x, int y, Graphics& gfx);
	void DrawTank(float X, float Y, Graphics& gfx);
	void DrawBullet(int x, int y, Graphics& gfx);
	void DrawGameOver(int x, int y, Graphics& gfx);
	~Sprite();
};

