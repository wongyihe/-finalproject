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

//�֥d�C
class Pikachu :public Interface_Pokemon
{
public:
	//��q����:    ���� + 10 + ���� * 0.7
	//�����O:      ���� * 1.1
	//���m�O:      ���� * 0.8
	//�S������O:  ���� * 1
	//�S���m�O:  ���� * 1
	//�t��:        ���� * 1.8
	Pikachu(int level)
	{
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//�֥d�C����U�C�ݩ�(Type)���ۦ������ɡAtype�ܼƪ��ȷ|�p�U����:
		//����:    0.5��
		//�q:  0.5��

	}
	
};

#endif