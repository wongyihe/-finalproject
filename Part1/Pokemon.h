#ifndef POKEMON
#define POKEMON
#include<iostream>
#include<string>
using namespace std;

//制定神奇寶貝的介面
class Interface_Pokemon
{
protected:
	//名字與各項屬性

	//名字
	string name;

	//等級
	int Level;

	//血量(目前的血量)
	int hp;

	//血量上限
	int maxhp;

	//攻擊力
	int attack;

	//防禦力
	int defense;

	//特殊攻擊力
	int spatk;

	//特防
	int spdef;

	//速度
	int speed;

public:

	//輸出所有神奇寶貝的資訊
	virtual void DrawInformations()
	{
		cout << this->name << endl;
		cout << "LV: " << this->Level << endl;
		cout << "HP: " << this->hp << "/" << this->maxhp << endl;
		cout << "攻擊: " << this->attack << endl;
		cout << "防禦: " << this->defense << endl;
		cout << "特攻: " << this->spatk << endl;
		cout << "特防: " << this->spdef << endl;
		cout << "速度: " << this->speed << endl;
	};

	//恢復，能將hp回復至hp的上限值
	virtual void Restore()
	{
		this->hp = this->maxhp;
	}

	//取得這個神奇寶貝的名字
	string GetName()
	{
		return this->name;
	}
};

#endif