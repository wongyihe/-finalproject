#ifndef KEKKING
#define KEKKING
#include<iostream>
#include<string>
#include"Pokemon.h"
#include"ChipAway.h"
#include"Flail.h"
using namespace std;

//請假王
class Kekking :public Interface_Pokemon
{
private:
	//是否在偷懶中
	bool is_truant;
public:
	//你必須推翻這下面這三個函式來實作出請假王偷懶的效果
	//戰鬥開始時應設為沒有在偷懶
	void BattleStart()
	{
		
	}
	//如果攻擊過的話
	//沒偷懶要變偷懶
	//偷懶要變沒偷懶
	void Attacked()
	{
		
	}
	//取得是否在偷懶
	bool IsTruant()
	{
		
	}


	//血量公式:    等級 + 10 + 等級 * 3
	//攻擊力:      等級 * 3.2
	//防禦力:      等級 * 2
	//特殊攻擊力:  等級 * 1.9
	//特殊防禦力:  等級 * 1.3
	//速度:        等級 * 2
	Kekking(int level)
	{
		
	}
	string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		float type = 1;
		//請假王受到下列屬性(Type)的招式攻擊時，type變數的值會如下改變:
		//幽靈:    0倍
		

	}
};


#endif