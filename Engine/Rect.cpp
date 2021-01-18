#include "Rect.h"


Rect::Rect(float left_in, float right_in, float top_in, float bottom_in):
	left(left_in), right(right_in), top(top_in), bottom(bottom_in)
{}

Rect::Rect(const Vec2 & topleft, float width, float height)
	: Rect(topleft, topleft + Vec2(width, height))
{}

Rect::Rect(const Vec2& topleft, const Vec2& bottomright)
	: Rect(topleft.x, bottomright.x, topleft.y, bottomright.y)
{}

Rect Rect::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	return Rect(center-Vec2(halfWidth, halfHeight),center+Vec2(halfWidth, halfHeight) );
}

bool Rect::isOverlapping(Rect& other) const
{
	return right>other.left&&left<other.right&&bottom>other.top&&top<other.bottom;
}

Rect Rect::GetExpanded(const float padding) const
{
	return Rect(left - padding, right + padding, top - padding, bottom + padding);
}
