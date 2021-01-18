#pragma once
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const Rect& rect, Color c);
	void Draw(Graphics& gfx) const;
private:
	Rect rect;
	Color color;
	bool destroyed = false;
};