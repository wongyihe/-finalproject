#ifndef PIKACHU
#define PIKACHU
#include<iostream>
#include<string>
#include"Pokemon.h"
#include"Thunder.h"
#include"ThunderBolt.h"
#include"Quick_attack.h"
#include"Slam.h"
using namespace std;

//ブ
class Pikachu :public Interface_Pokemon
{
public:
	//﹀秖そΑ:    单 + 10 + 单 * 0.7
	//ю阑:      单 * 1.1
	//ň縨:      单 * 0.8
	//疭ю阑:  单 * 1
	//疭ň縨:  单 * 1
	//硉:        单 * 1.8
	Pikachu(int level)
	{
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//ブ妮┦(Type)┷Αю阑type跑计穦э跑:
		//︽:    0.5
		//筿:  0.5

	}
	
};

#endif