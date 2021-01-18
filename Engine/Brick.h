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
	bool BallCollision(Ball& ball);
private:
	Rect rect;
	Color color;
	bool destroyed = false;
};