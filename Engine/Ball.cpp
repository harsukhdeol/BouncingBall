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
		ReboundX();
		pos.x += wall.left - circleRect.left;
		collided = true;
	}
	else if (circleRect.right > wall.right)
	{
		ReboundX();
		pos.x += wall.right - circleRect.right;
		collided = true;
	}

	if (circleRect.top < wall.top)
	{
		ReboundY();
		pos.y += wall.top - circleRect.top;
		collided = true;
	}
	else if (circleRect.bottom > wall.bottom)
	{
		ReboundY();
		pos.y += wall.top - circleRect.top;
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
