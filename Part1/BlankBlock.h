#ifndef BLANKBLOCK
#define BLANKBLOCK
#include<iostream>
#include"Block.h" //���Ҫ�^��class Interface_Block ������붨�xclass Interface_Block�Ę��^�n
#include"Pokemon.h"
using namespace std;

//�հ׵ذ壬�]�й���ֻ���Ƅ�

//�հ׵ذ���@ʾ"��"

class BlankBlock : public Interface_Block
{
public:void Draw(){ cout << "��"; }
	   bool IsEncounter()
	   {
		   return false;
	   }
	   Interface_Pokemon* GetEncounteredPokemon()
	   {
		   //�A�O�؂�null pointer �յ�ָ��
		   return nullptr;
	   };
	   void Heal(PlayerInfo *p)
	   {
	   }
};

#endif 