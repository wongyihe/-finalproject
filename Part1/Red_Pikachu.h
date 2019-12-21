#ifndef REDPIKACHU
#define REDPIKACHU
#include<iostream>
#include<string>
#include"Pikachu.h"
using namespace std;

//小智的皮卡丘
class Red_Pikachu :public Pikachu
{
public:
	//建構子
	//因為是Red_Pikachu繼承自Pikachu
	//必須也要呼叫Pikachu的建構子，並傳入參數

	//注意:
	//建構子的呼叫順序是 Pikachu先 再來是Red_Pikachu 
	Red_Pikachu(int level) : Pikachu(level)//<--這就是呼叫Pikachu的建構子
	{
		name = "小智的皮卡丘";
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