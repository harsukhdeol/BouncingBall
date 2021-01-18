#include "Brick.h"

Brick::Brick(const Rect& rect, Color c):
rect(rect), color(c)
{}

void Brick::Draw(Graphics& gfx) const
{
	if(!destroyed) {

	gfx.DrawRect(rect.GetExpanded(-padding), color);
	}
}

bool Brick::BallCollision(Ball& ball)
{
	if (!destroyed && rect.isOverlapping(ball.GetRect()))
	{
		ball.ReboundY();
		destroyed = true;
		return true;
	}
	return false;
}
