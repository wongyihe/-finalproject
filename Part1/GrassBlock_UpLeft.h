#ifndef GRASSBLOCK_UL
#define GRASSBLOCK_UL
#include<iostream>
#include"Block.h"
#include"Pikachu.h"
#include"Lizardon.h"
#include"Kekking.h"
#include<time.h>
//���ϽǵĲݵ�

//���������挚ؐ

//�ݵؕ��@ʾ"��"
class GrassBlock_UpLeft : public Interface_Block
{
private:
	int r;
public:
	//�ݵؕ��@ʾ"��"
	void Draw(){ cout << "��"; }
	//��60%�C������
	 bool IsEncounter()
	{
		
		srand((unsigned)time(NULL));
		r = rand() % 10;
		if (r <= 5)return true;
		else return false;
	}
	//����؂�true��ʾ�������挚ؐ
	//��֮�t�]���������挚ؐ
	virtual Interface_Pokemon* GetEncounteredPokemon()
	{
		int p;
		int possible;
		possible = rand() % 100;
		p = rand() % 4;
		
		if (r <= 5){
			Interface_Pokemon *getencountered_pokemon ;
				if (possible <25) getencountered_pokemon=new Pikachu(5+p);
				else if (possible < 60)getencountered_pokemon = new Nukenin(10+p);
				else getencountered_pokemon = new Kekking(11+p);
			return getencountered_pokemon;
		}
		else return nullptr;
	};

	//����������挚ؐ
	//ԓ���挚ؐ���������N����:
	//25%�C�ʳ鵽 Ƥ����    �ȼ�5~8
	//35%�C�ʳ鵽 Ó������  �ȼ�10~13
	//40%�C�ʳ鵽 Ո����    �ȼ�11~14

};

#endif