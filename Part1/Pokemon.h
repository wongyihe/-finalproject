#ifndef POKEMON
#define POKEMON
#include<iostream>
#include<string>
using namespace std;

//�ƶ����挚ؐ�Ľ���
class Interface_Pokemon
{
protected:
	//�����c��헌���

	//����
	string name;

	//�ȼ�
	int Level;

	//Ѫ��(Ŀǰ��Ѫ��)
	int hp;

	//Ѫ������
	int maxhp;

	//������
	int attack;

	//���R��
	int defense;

	//���⹥����
	int spatk;

	//�ط�
	int spdef;

	//�ٶ�
	int speed;

public:

	//ݔ���������挚ؐ���YӍ
	virtual void DrawInformations()
	{
		cout << this->name << endl;
		cout << "LV: " << this->Level << endl;
		cout << "HP: " << this->hp << "/" << this->maxhp << endl;
		cout << "����: " << this->attack << endl;
		cout << "���R: " << this->defense << endl;
		cout << "�ع�: " << this->spatk << endl;
		cout << "�ط�: " << this->spdef << endl;
		cout << "�ٶ�: " << this->speed << endl;
	};

	//�֏ͣ��܌�hp�؏���hp������ֵ
	virtual void Restore()
	{
		this->hp = this->maxhp;
	}

	//ȡ���@�����挚ؐ������
	string GetName()
	{
		return this->name;
	}
};

#endif