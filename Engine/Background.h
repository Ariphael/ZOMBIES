#pragma once
#include "Graphics.h"
class Background
{
public:
	Background();
	void DrawBackground(int r, int g, int b, Graphics& gfx);
	void DrawRock(int x, int y, int w, int h, Graphics& gfx);
	~Background();
};

