#ifndef NUKENIN
#define NUKENIN
#include<iostream>
#include<string>
#include"Pokemon.h"
using namespace std;

//叉催г
class Nukenin :public Interface_Pokemon
{
public:
	//﹀秖そΑ:    ッ环常琌1
	//ю阑:      单 * 1.8
	//ň縨:      单 * 0.9
	//疭ю阑:  单 * 0.6
	//疭ň縨:  单 * 0.6
	//硉:        单 * 0.8
	Nukenin(int level)
	{
		name = "脫殼忍者";
		Level = level;
		hp = 1;
		maxhp = 1;
		attack = int(Level*1.8);
		defense = int(Level*0.9);
		spatk = int(Level*0.6);
		spdef = int(Level*0.6);
		speed = int(Level*0.8);

	}
	
};


#endif