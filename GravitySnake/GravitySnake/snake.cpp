#include "stdafx.h"
#include "snake.h"
#include "Box2D/Box2D.h"
#include <conio.h>
#include <iostream>;
#include <ctime>;
using namespace std;


float32 timeStep = 1.0f / 60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;
float targetPosX;
float targetPosY;



void snake:: update(b2World &world)
{
	world.Step(timeStep, velocityIterations, positionIterations);
}
//function to apply force to the snake object based on key input
void snake:: applyForce(b2Body* player) {
	char input = _getch();

	float moveX = 0;
	float moveY = 0;

	if (input == 'w') {
		moveY = 25;
	}
	else if (input == 'a') {
		moveX = -25;
	}
	else if (input == 's') {
		moveY = -25;
	}
	else if (input == 'd') {
		moveX = 25;
	}
	
	else {

	}

	//b2Vec2 force(moveX, moveY);
	cout << moveX << " " << moveY << endl;
	player->ApplyForceToCenter(b2Vec2(moveX, moveY), true);
	input = 'k';
}
//moves target to a random position
void snake:: moveTarget(b2Body* target)
{
	srand((int)time(0));
	targetPosX = (rand() % 10) - 5.0f;
	targetPosY = (rand() % 10) - 5.0f;
	
	target->SetTransform(b2Vec2(targetPosX, targetPosY), target->GetAngle());
	//target->SetTransform(b2Vec2(targetPosX,targetPosY), 1);

}

//helper functions for getting the target position
float snake:: targetX() {
	return targetPosX;
}
float snake:: targetY() {
	return targetPosY;
}
void snake ::display(b2Body* player, b2Body* target) 
{
	b2Vec2 playerPosition = player->GetPosition();
	b2Vec2 targetPosition = target->GetPosition();
	
	

	cout << "Player X is: " << playerPosition.x << " Player Y is: " << playerPosition.y << " Target X is: " << targetPosition.x << " Target Y is: " << targetPosition.y<< endl;

	


}
