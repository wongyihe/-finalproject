#ifndef NUKENIN
#define NUKENIN
#include<iostream>
#include<string>
#include"Pokemon.h"
using namespace std;

//��ߧԪ�
class Nukenin :public Interface_Pokemon
{
public:
	//��q����:    �û����O1
	//�����O:      ���� * 1.8
	//���m�O:      ���� * 0.9
	//�S������O:  ���� * 0.6
	//�S���m�O:  ���� * 0.6
	//�t��:        ���� * 0.8
	Nukenin(int level)
	{
		name = "Ó������";
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