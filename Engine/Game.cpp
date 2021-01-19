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
	walls(Vec2(0.0f, 0.0f), float(gfx.ScreenWidth), float(gfx.ScreenHeight)),
	ball(Vec2(50.0f, 50.0f), Vec2(300.0f, 300.0f)),
	soundPad(L"Sounds//arkPad.wav"),
	soundBrick(L"Sounds//arkBrick.wav"),
	paddle(Vec2(0,550), 150.0f, 30.f)
{
	const Vec2 topLeft(20.f, 20.f);
	int i = 0;
	for (int y = 0; y < brickCols; y++) {
		Color c = colors[y];
		for (int x = 0; x < brickRows; x++)
		{
			Vec2 topRight(x *brickWidth, y * brickHeight);
			bricks[i] = Brick(Rect(topLeft+topRight, brickWidth, brickHeight), c);
			i++;
		}
	}
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

	bool collisionHappened = false;
	float curDist; 
	int curCollisionIndex;

	for (int i = 0; i < nBricks; i++) {
		if (bricks[i].CheckBallCollision(ball))
		{
			const float newDist =Vec2( bricks[i].GetCenter() - ball.GetPos()).GetLengthSq();
			if (collisionHappened)
			{
				if (curDist > newDist)
				{
					curDist = newDist;
					curCollisionIndex = i;

				}
			}
			else {
				curDist = newDist;
				curCollisionIndex = i;
				collisionHappened = true;
			}
		}
	}

	if (collisionHappened)
	{
		bricks[curCollisionIndex].ExecuteBallCollision(ball);
		soundBrick.Play();
	}

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
	for (const Brick& b : bricks) {
		b.Draw(gfx);
	}
	paddle.Draw(gfx);
	ball.Draw(gfx);
}
