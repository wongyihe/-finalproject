#ifndef RECOVERBLOCK
#define RECOVERBLOCK
#include<iostream>
#include"Block.h"  //���Ҫ�^��class Interface_Block ������붨�xclass Interface_Block�Ę��^�n
using namespace std;

//�؏�Ѫ���ĵذ�

//�����վ�ρ�����@ʾ  "�������挚ؐ�����؏�!" 
//�K��system("pause")׌ʹ����ݔ�������I�����^�m

//�ذ���@ʾ"��"
class RecoverBlock : public Interface_Block
{
public:
	//���@ʾ"��"
	void Draw(){ cout << "��"; }
	bool IsEncounter()
	{
		return false;
	}
	Interface_Pokemon* GetEncounteredPokemon()
	{
		//�A�O�؂�null pointer �յ�ָ��
		return nullptr;
	};
	virtual void Heal(PlayerInfo *p)
	{

		p->Restore();
		cout << "�������挚ؐ�����؏�!" << endl;
		system("pause");
	}

	//�����վ�ρ�����@ʾ  "�������挚ؐ�����؏�!" 

	//�K��system("pause")׌ʹ����ݔ�������I�����^�m

};

#endif 