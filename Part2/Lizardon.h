#ifndef LIZARDON
#define LIZARDON
#include<iostream>
#include<string>
#include"Pokemon.h"
#include"Flamethrower.h"
#include"Wing_attack.h"
#include"Dragon_rage.h"
using namespace std;

//糛纒
class Lizardon :public Interface_Pokemon
{
public:
	//﹀秖そΑ:    单 + 10 + 单 * 1.56
	//ю阑:      单 * 1.68
	//ň縨:      单 * 1.56
	//疭ю阑:  单 * 2.18
	//疭ň縨:  单 * 1.7
	//硉:        单 * 2
	Lizardon(int level)
	{
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//糛纒妮┦(Type)┷Αю阑type跑计穦э跑:
		//:    0.5
		//筿:    2

		

	}
	
};


#endif