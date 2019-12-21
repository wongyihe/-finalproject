#ifndef NUKENIN
#define NUKENIN
#include<iostream>
#include<string>
#include"Pokemon.h"
#include"Shadow_Ball.h"
using namespace std;

//脫殼忍者
class Nukenin :public Interface_Pokemon
{
public:
	//血量公式:    永遠都是1
	//攻擊力:      等級 * 1.8
	//防禦力:      等級 * 0.9
	//特殊攻擊力:  等級 * 0.6
	//特殊防禦力:  等級 * 0.6
	//速度:        等級 * 0.8
	Nukenin(int level)
	{
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//注意:
		//除非招式屬性剋制脫殼忍者(對脫殼忍者能夠造成2倍傷害)
		//不然不會對脫殼忍者造成任何傷害
		//以下列屬性(Type)的招式攻擊脫殼忍者時，能夠造成2倍傷害:
		//Fire:        2倍
		//Ghost:       2倍
		//Flying:      2倍

		//龍之怒對它造成0點傷害，請去右下角草叢確定龍之怒沒辦法打死脫殼忍者

	

	}
	
};


#endif