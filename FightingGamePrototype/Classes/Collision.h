#pragma once

#include <SDL.h>
#include <iostream>
#include "GameObject.h"

using namespace std;

class Collision
{
public:

	static bool ObjectToObject(GameObject* GameObject1, GameObject* GameObject2);
	static bool PointToObject(int xPos, int yPos, GameObject* GameObject1);
};
