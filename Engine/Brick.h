#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Rect& rect, Color c);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(Ball& ball) const;
	void ExecuteBallCollision(Ball& ball) ;
	Vec2 GetCenter() const;

private:
	static constexpr float padding = 1.f;
	Rect rect;
	Color color;
	bool destroyed = false;
};