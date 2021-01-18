#include "Brick.h"

Brick::Brick(const Rect& rect, Color c):
rect(rect), color(c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, color);
}
