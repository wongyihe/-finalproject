#ifndef NUKENIN
#define NUKENIN
#include<iostream>
#include<string>
#include"Pokemon.h"
#include"Shadow_Ball.h"
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
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//�`�N:
		//���D�ۦ��ݩʫg���ߧԪ�(���ߧԪ̯���y��2���ˮ`)
		//���M���|���ߧԪ̳y������ˮ`
		//�H�U�C�ݩ�(Type)���ۦ�������ߧԪ̮ɡA����y��2���ˮ`:
		//Fire:        2��
		//Ghost:       2��
		//Flying:      2��

		//�s����復�y��0�I�ˮ`�A�Хh�k�U�����O�T�w�s����S��k������ߧԪ�

	

	}
	
};


#endif