#ifndef REDBLOCK
#define REDBLOCK
#include<iostream>
#include"Block.h" //���Ҫ�^��class Interface_Block ������붨�xclass Interface_Block�Ę��^�n
#include"Red_Pikachu.h"
using namespace std;

//С�ǵ�Ƥ���������

//ֻ������С�ǵ�Ƥ����

//�ذ���@ʾ"��"
class RedBlock : public Interface_Block
{
public:
	//���@ʾ"��"
	void Draw(){ cout << "��"; }

	//��100%�C���������挚ؐ 
	virtual bool IsEncounter()
	{
		return true;
	}
 Interface_Pokemon* GetEncounteredPokemon()
	{
		//�A�O�؂�null pointer �յ�ָ��
		Interface_Pokemon *getencountered_pokemon =new Red_Pikachu(40);
		
			return getencountered_pokemon;
	};

	//���������挚ֻؐ�������@һ�N����:
	//С�ǵ�Ƥ����   40��


};

#endif 