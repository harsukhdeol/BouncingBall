#include "Brick.h"
#include <assert.h>
#include <cmath>

Brick::Brick(const Rect& rect, Color c):
rect(rect), color(c)
{}

void Brick::Draw(Graphics& gfx) const
{
	if(!destroyed) {

	gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Brick::CheckBallCollision(Ball& ball) const
{
	return !destroyed && rect.isOverlapping(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball& ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballPos = ball.GetPos();

	if (signbit(ball.GetVel().x) == signbit(ballPos.x - GetCenter().x))
	{
		ball.ReboundY();
	}
	else if (ballPos.x>= rect.left && ballPos.x<= rect.right)
	{
		ball.ReboundY();

	}
	else {
		ball.ReboundX();
	}
	destroyed = true;
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}

