#ifndef GRASSBLOCK_DR
#define GRASSBLOCK_DR
#include<iostream>
#include<time.h>
#include"Block.h"
#include"Pikachu.h"
#include"Nukenin.h"
#include"Kekking.h"

//���½ǵĲݵ�

//���������挚ؐ

//�ݵؕ��@ʾ"��"
class GrassBlock_DownRight : public Interface_Block
{
private:
	int r;
public:
	//�ݵؕ��@ʾ"��"
	void Draw(){ cout << "��"; }

	//��75%�C������
	//����؂�true��ʾ�������挚ؐ
	//��֮�t�]���������挚ؐ
	bool IsEncounter()
	{

		srand((unsigned)time(NULL));
		r = rand() % 100;
		if (r < 75)return true;
		else return false;
	}

	//����������挚ؐ
	//ԓ���挚ؐ���������N����:
	//40%�C�ʳ鵽 Ƥ����  �ȼ�11~15
	//30%�C�ʳ鵽 ������  �ȼ�15~20
	//30%�C�ʳ鵽 Ո����  �ȼ�17~21
	virtual Interface_Pokemon* GetEncounteredPokemon()
	{
		int p,l;
		int possible;
		possible = rand() % 100;
		p = rand() % 5;
		l = rand() % 6;
		if (r <= 5){
			Interface_Pokemon *getencountered_pokemon;
			if (possible <40) getencountered_pokemon = new Pikachu(11 + p);
			else if (possible < 70)getencountered_pokemon = new Lizardon(15 + l);
			else getencountered_pokemon = new Kekking(17 + p);
			return getencountered_pokemon;
		}
		else return nullptr;
	};
};

#endif