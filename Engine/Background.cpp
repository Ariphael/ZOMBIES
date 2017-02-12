#include "Background.h"



Background::Background()
{
}

void Background::DrawBackground(int r, int g, int b, Graphics & gfx)
{
	for (int w = 0; w < Graphics::ScreenWidth; w++) {
		for (int h = 0; h < Graphics::ScreenHeight; h++) {
			gfx.PutPixel(w, h, r, g, b);
		}
	}
}

void Background::DrawRock(int x, int y, int w, int h, Graphics & gfx)
{
	for (int W = 0; W <= w; W++) {
		for (int H = 0; H <= h; H++) {
			gfx.PutPixel(x + W, y + H, 165, 42, 42);
		}
	}
}


Background::~Background()
{
}
