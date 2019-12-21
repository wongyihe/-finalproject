#ifndef PIKACHU
#define PIKACHU
#include<iostream>
#include<string>
#include"Pokemon.h"
using namespace std;

//¥Ö¥d¥C
class Pikachu :public Interface_Pokemon
{
public:

	Pikachu(int level)
	{
		name = "Æ¤¿¨Çð";
		Level = level;
		hp = int(Level + 10 + Level*0.7);
		maxhp = int(Level + 10 + Level*0.7);
		attack = int(Level*1.1);
		defense = int(Level*0.8);
		spatk = int(Level*1.0);
		spdef = int(Level*1.0);
		speed = int(Level*1.8);

	}
	
};

#endif