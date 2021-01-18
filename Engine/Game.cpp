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



Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	b(Rect(100.0f, 200.0f, 100.0f, 200.0f),
		Colors::Red),
	walls(Vec2(0.0f, 0.0f), float(gfx.ScreenWidth), float(gfx.ScreenHeight)),
	ball(Vec2(50.0f, 50.0f), Vec2(300.0f, 300.0f)),
	soundPad(L"Sounds//arkPad.wav"),
	soundBrick(L"Sounds//arkBrick.wav"),
	paddle(Vec2(0,550), 150.0f, 30.f)
{
}
void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	ball.Update(dt);
	ball.WallCollision(walls);
	paddle.Update(wnd.kbd, dt);
	paddle.WallCollision(walls);
	if (paddle.BallCollision(ball))
	{
		soundPad.Play();
	}

}

void Game::ComposeFrame()
{
	b.Draw(gfx);
	paddle.Draw(gfx);
	ball.Draw(gfx);
}
