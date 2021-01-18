#include "Ball.h"
#include "SpriteCodex.h"
Ball::Ball(const Vec2& pos_in, const Vec2& vel_in)
	: pos(pos_in), vel(vel_in)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);

}

void Ball::Update(float dt)
{
	pos += vel * dt;
}

bool Ball::WallCollision(const Rect& wall)
{
	bool collided = false;
	const Rect circleRect = GetRect();

	if (circleRect.left < wall.left) {
		pos.x += wall.left - circleRect.left;
		ReboundX();
		collided = true;
	}
	else if (circleRect.right > wall.right)
	{
		pos.x += wall.right - circleRect.right;
		ReboundX();
		collided = true;
	}

	if (circleRect.top < wall.top)
	{
		pos.y += wall.top - circleRect.top;
		ReboundY();
		collided = true;
	}
	else if (circleRect.bottom > wall.bottom)
	{
		pos.y += wall.bottom - circleRect.bottom;
		ReboundY();
		collided = true;
	}
	return collided;
}

void Ball::ReboundX()
{
	vel.x *= -1;
}

void Ball::ReboundY()
{
	vel.y *= -1;
}

Rect Ball::GetRect() const
{
	return Rect:: FromCenter(pos, radius,radius);
}

Vec2 Ball::GetVel() const
{
	return vel;
}

Vec2 Ball::GetPos() const
{
	return pos;
}
