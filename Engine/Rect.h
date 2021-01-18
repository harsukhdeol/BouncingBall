#pragma once
#include "Vec2.h"
class Rect
{
public:
	Rect() = default;
	Rect(float left_in, float right_in, float top_in, float bottom_in);
	Rect(const Vec2& topleft, float width, float height);
	Rect(const Vec2& topleft, const Vec2& bottomright);
	static Rect FromCenter(const Vec2& center, float halfWidth, float halfHeight); //create member fxn bc constructor already has same shape
	bool isOverlapping(Rect& other) const;
	Rect GetExpanded(const float padding) const;

public:
	float top;
	float left;
	float right;
	float bottom;
};