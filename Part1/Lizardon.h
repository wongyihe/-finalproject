#ifndef LIZARDON
#define LIZARDON
#include<iostream>
#include<string>
#include"Pokemon.h"
using namespace std;

//�Q���s
class Lizardon :public Interface_Pokemon
{
public:
	//��q����:    ���� + 10 + ���� * 1.56
	//�����O:      ���� * 1.68
	//���m�O:      ���� * 1.56
	//�S������O:  ���� * 2.18
	//�S���m�O:  ���� * 1.7
	//�t��:        ���� * 2
	Lizardon(int level)
	{
		name = "������";
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