#ifndef REDPIKACHU
#define REDPIKACHU
#include<iostream>
#include<string>
#include"Pikachu.h"
using namespace std;

//�p�����֥d�C
class Red_Pikachu :public Pikachu
{
public:
	//�غc�l
	//�]���ORed_Pikachu�~�Ӧ�Pikachu
	//�����]�n�I�sPikachu���غc�l�A�öǤJ�Ѽ�

	//�`�N:
	//�غc�l���I�s���ǬO Pikachu�� �A�ӬORed_Pikachu 
	Red_Pikachu(int level) : Pikachu(level)//<--�o�N�O�I�sPikachu���غc�l
	{
		
	}

};

#endif