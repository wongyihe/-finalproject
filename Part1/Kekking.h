#ifndef KEKKING
#define KEKKING
#include<iostream>
#include<string>
#include"Pokemon.h"
using namespace std;

//叫安
class Kekking :public Interface_Pokemon
{
public:
	//﹀秖そΑ:    单 + 10 + 单 * 3
	//ю阑:      单 * 3.2
	//ň縨:      单 * 2
	//疭ю阑:  单 * 1.9
	//疭ň縨:  单 * 1.3
	//硉:        单 * 2
	Kekking(int level)
	{
		name = "請假王";
		Level = level;
		hp = int(Level + 10 + Level * 3);
		maxhp = int(Level + 10 + Level * 3);
			attack =int( Level*3.2);
		defense = int(Level*2);
		spatk = int(Level*1.9);
		spdef = int(Level*1.3);
		speed = int(Level*2);
	}
	
};


#endif