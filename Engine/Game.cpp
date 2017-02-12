/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <chrono>
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}
//faoiwegj iowaejg
void Game::UpdateModel()
{	
	if (!GameOver) {
			if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
				TankX += vx;
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
				TankX -= vx;
			}
		if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
			if (counter == 0) {
				BulletX.push_back((int)floor(TankX) + 8);
				BulletY.push_back((int)floor(TankY));
				counter = reload;
			}
			else {
				counter--;
			}
		}
		else {
			if (counter > 0) {
				counter--;
			}
		}

		if (BulletX.size() > 0 && BulletY.size() > 0) {

			for (size_t i = 0; i < BulletX.size() && i < BulletY.size(); i++) {
				BulletY[i] -= BulletV;
			}
			if (BulletY[0] <= 0) {
				for (size_t i = 0; i < BulletX.size() - 1 && i < BulletY.size() - 1; i++) {
					BulletX[i] = BulletX[i + 1];
					BulletY[i] = BulletY[i + 1];
				}
				BulletX.pop_back();
				BulletY.pop_back();
			}
		}
		if (TankX <= 49) {
			TankX += 48 - TankX;
		}
		if (TankX + 25 >= 749) {
			TankX += 733 - TankX;
		}
		if (Zcounter <= 0) {
			ZombieX.push_back(rand() % Graphics::ScreenHeight + 50);
			ZombieY.push_back(4);
			if (ZombieX[ZombieX.size() - 1] <= 50) {
				ZombieX[ZombieX.size() - 1] += 51 - ZombieX[ZombieX.size() - 1];
			}
			if (ZombieX[ZombieX.size() - 1] + 40 >= 749) {
				ZombieX[ZombieX.size() - 1] += 709 - ZombieX[ZombieX.size() - 1];
			}
			Zcounter = 15;
		}
		else if (Zcounter > 0) {
			Zcounter--;
		}
		if (ZMoveC == 5) {
			for (size_t i = 0; i < ZombieY.size(); i++) {
				ZombieY[i] += 10;
			}
			ZMoveC = 0;
		}
		else {
			ZMoveC++;
		}
		for (size_t i = 0; i < ZombieX.size() && i < ZombieY.size(); i++) {
			
			for (size_t c = 0; c < BulletX.size() && c < BulletY.size(); c++) {
				if (BulletX[c] >= ZombieX[i] && BulletX[c] <= ZombieX[i] + 40) {
					if (BulletY[c] <= ZombieY[i] + 30) {
						for (size_t a = i; a < ZombieX.size() - 1 && a < ZombieY.size() - 1; a++) {
							ZombieX[a] = ZombieX[a + 1];
							ZombieY[a] = ZombieY[a + 1];
						}
						ZombieX.pop_back();
						ZombieY.pop_back();
					}

				}
				if (i >= ZombieX.size() && i >= ZombieY.size()) {
					i += (ZombieX.size() - 1) - i;
				}
			}
			
		}
		for (size_t i = 0; i < ZombieX.size() && i < ZombieY.size(); i++) {
			if (ZombieY[i] > TankY) {
				GameOver = true;
			}
	}
	}
}


void Game::ComposeFrame()
{
	
	if (!GameOver) {
		land.DrawBackground(0, 128, 0, gfx);
		land.DrawRock(0, 0, 50, Graphics::ScreenHeight - 2, gfx);
		land.DrawRock(749, 0, 50, Graphics::ScreenHeight - 2, gfx);
		sprite.DrawTank(TankX, TankY, gfx);
		for (size_t i = 0; i < BulletX.size() && i < BulletY.size(); i++) {
			if (BulletX[i] > 49 && BulletX[i] < 749) {
				sprite.DrawBullet(BulletX[i], BulletY[i], gfx);
			}
		}
		for (size_t i = 0; i < ZombieX.size() && i < ZombieY.size(); i++) {
			sprite.DrawZombie(ZombieX[i], ZombieY[i], gfx);
		}
	}
	else {
		sprite.DrawGameOver(400-42, 300-32, gfx);
	}
	//0.167 seconds
	//
}
