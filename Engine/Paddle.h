#pragma once
#include "Ball.h"
#include "Keyboard.h"
class Paddle

{
public:
	Paddle(Vec2& pos, float width, float height);
	void Draw(Graphics& gfx)const;
	void Update(const Keyboard& kbd, float dt);
	bool BallCollision(Ball& ball) const;
	void WallCollision(const Rect& wall);
	Rect GetRect() const;

private:
	static constexpr float padding = 30.0f;
	Vec2 pos;
	float width;
	float height;
	static constexpr float speed = 360.0f;
	static constexpr Color c = { 200,255,115 };
	static constexpr Color sideColor = { 255,255,255};
	
};