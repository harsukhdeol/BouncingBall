#include "Paddle.h"

Paddle::Paddle(Vec2& pos, float width, float height)
	: pos(pos), width(width), height(height)
{
}

void Paddle::Draw(Graphics& gfx) const
{
	 Rect rect = GetRect();

	gfx.DrawRect(rect, sideColor);
	rect.left += padding;
	rect.right -= padding;
	gfx.DrawRect(rect, c);

}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		pos.x += speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
}

bool Paddle::BallCollision(Ball& ball) const
{
	if (ball.GetVel().y>0 && GetRect().isOverlapping(ball.GetRect()))
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::WallCollision(const Rect& wall)
{
	const Rect rect = GetRect();
	if (rect.left < wall.left) {
		pos.x += wall.left - rect.left;
	}
	else if (rect.right > wall.right)
	{
		pos.x += wall.right - rect.right;
	}
}

Rect Paddle::GetRect() const
{
	return Rect(pos, width, height);
}
