// GravitySnake.cpp : Defines the entry point for the console application.
//
//Main function handling physics world creation, as well as main game loop.
#include "stdafx.h"
#include <iostream>
#include "Box2D\Box2D.h"
#include "snake.h"
using namespace std;

int main()
{
	bool play = true;
	char input = 0;
	b2Vec2 gravity(0.0f, -.098f);
	snake sn1;
	int timesCollided = 0;
	int maxCollisions = 10;
	//creates world and sets gravity
	b2World world(gravity);

	
	b2BodyDef targetDef;

	targetDef.type = b2_staticBody;
	targetDef.position.Set(1.0f, 4.0f);

	b2Body* target = world.CreateBody(&targetDef);

	b2PolygonShape staticBox;
	staticBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef staticFixture;

	staticFixture.shape = &staticBox;

	staticFixture.density = 1.0f;

	staticFixture.friction = .3f;

	target->CreateFixture(&staticFixture);



	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;


	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	sn1.moveTarget(target);
	//variable just used in order to use cin to start the game
	char start = 'a';
	//simple main game function to wait to start the game until the user decides
	cout << "Welcome to Snake" << endl;
	cout << "Please hit p, then enter, to begin." << endl;
	cout << "_________________________________________" << endl;
	cin >> start;
	while(play) {
		
		sn1.display(body, target);
		if (_kbhit()) {
			input = _getch();
			if(input == 27)
			{
				play = false;
			}
			sn1.applyForce(body);
		}
		
		b2Vec2 position = body->GetPosition();
		b2Vec2 targetPosition = target->GetPosition();

		if ((position.x - targetPosition.x <= 2 && position.x - targetPosition.x >= -2) && (position.y - targetPosition.y <= 2 && position.y - targetPosition.y >= -2)) 
		{
			sn1.moveTarget(target);
			timesCollided++;
		}

		if (timesCollided == maxCollisions) {
			play = false;
			cout << "Youve won!" << endl;
		}
		
		sn1.update(world);

		


		
		
	}
	
	
	
	


    return 0;
}

