#ifndef KEKKING
#define KEKKING
#include<iostream>
#include<string>
#include"Pokemon.h"
#include"ChipAway.h"
#include"Flail.h"
using namespace std;

//�а���
class Kekking :public Interface_Pokemon
{
private:
	//�O�_�b���i��
	bool is_truant;
public:
	//�A������½�o�U���o�T�Ө禡�ӹ�@�X�а������i���ĪG
	//�԰��}�l�����]���S���b���i
	void BattleStart()
	{
		
	}
	//�p�G�����L����
	//�S���i�n�ܰ��i
	//���i�n�ܨS���i
	void Attacked()
	{
		
	}
	//���o�O�_�b���i
	bool IsTruant()
	{
		
	}


	//��q����:    ���� + 10 + ���� * 3
	//�����O:      ���� * 3.2
	//���m�O:      ���� * 2
	//�S������O:  ���� * 1.9
	//�S���m�O:  ���� * 1.3
	//�t��:        ���� * 2
	Kekking(int level)
	{
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//�а�������U�C�ݩ�(Type)���ۦ������ɡAtype�ܼƪ��ȷ|�p�U����:
		//���F:    0��
		

	}
};


#endif