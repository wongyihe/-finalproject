#ifndef LIZARDON
#define LIZARDON
#include<iostream>
#include<string>
#include"Pokemon.h"
#include"Flamethrower.h"
#include"Wing_attack.h"
#include"Dragon_rage.h"
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
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//�Q���s����U�C�ݩ�(Type)���ۦ������ɡAtype�ܼƪ��ȷ|�p�U����:
		//��:    0.5��
		//�q:    2��

		

	}
	
};


#endif