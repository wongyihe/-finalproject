#ifndef PLAYERBLOCK
#define PLAYERBLOCK
#include<iostream>
#include"Block.h"  //���Ҫ�^��class Interface_Block ������붨�xclass Interface_Block�Ę��^�n
using namespace std;

//��ҵذ壬ֻ���@ʾ���λ���� 

//�����λ�Õ��@ʾ"P "
class PlayerBlock : public Interface_Block
{
public:
	//�@ʾ"P "
	void Draw(){ cout << "p "; }
};

#endif  