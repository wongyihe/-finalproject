#ifndef LIZARDON
#define LIZARDON
#include<iostream>
#include<string>
#include"Pokemon.h"
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
		name = "噴火龍";
		Level = level;
		hp = int(Level + 10 + Level * 1.56);
		maxhp =int( Level + 10 + Level * 1.56);
		attack = int(Level*1.68);
		defense =int( Level * 1.56);
		spatk = int(Level*2.18);
		spdef = int(Level*1.7);
		speed = int(Level * 2);
	}
	
};


#endif