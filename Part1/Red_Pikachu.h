#ifndef REDPIKACHU
#define REDPIKACHU
#include<iostream>
#include<string>
#include"Pikachu.h"
using namespace std;

//С�ǵ�Ƥ����
class Red_Pikachu :public Pikachu
{
public:
	//������
	//�����Red_Pikachu�^����Pikachu
	//���ҲҪ����Pikachu�Ľ����ӣ��K���녢��

	//ע��:
	//�����ӵĺ�������� Pikachu�� �ف���Red_Pikachu 
	Red_Pikachu(int level) : Pikachu(level)//<--�@���Ǻ���Pikachu�Ľ�����
	{
		name = "С�ǵ�Ƥ����";
		Level = level;
		hp = int(Level + 10 + Level*0.7);
		maxhp = int(Level + 10 + Level*0.7);
		attack =int( Level*1.1);
		defense = int(Level*0.8);
		spatk = int(Level*1.0);
		spdef = int(Level*1.0);
		speed = int(Level*1.8);
	}

};

#endif