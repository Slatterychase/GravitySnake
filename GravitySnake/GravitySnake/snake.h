#pragma once
#include "stdafx.h"
#include "snake.h"
#include "Box2D/Box2D.h"
#include <conio.h>
#include <iostream>
#include <ctime>


class snake
{
public:
	void update(b2World &world);

	void applyForce(b2Body* player) ;
	void moveTarget(b2Body* target);


		float targetX();
	float targetY();
	void display(b2Body* player, b2Body* target);
	
};

