#ifndef KEKKING
#define KEKKING
#include<iostream>
#include<string>
#include"Pokemon.h"
using namespace std;

//�а���
class Kekking :public Interface_Pokemon
{
public:
	//��q����:    ���� + 10 + ���� * 3
	//�����O:      ���� * 3.2
	//���m�O:      ���� * 2
	//�S������O:  ���� * 1.9
	//�S���m�O:  ���� * 1.3
	//�t��:        ���� * 2
	Kekking(int level)
	{
		name = "Ո����";
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