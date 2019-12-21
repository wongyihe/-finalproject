#ifndef POKEMON
#define POKEMON
#include<iostream>
#include<string>
#include<iomanip>
#include"Skill.h"
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

	//特殊防禦力
	int spdef;

	//速度
	int speed;

	//此神奇寶貝擁有的技能
	Interface_Skill *skills[4];

	//技能總數
	int skill_number;

	//此神奇寶貝的屬性
	//最多同時有兩種
	string type[2];

	//此神奇寶貝擁有的屬性數
	int type_number;

	string description;
public:

	//下面這3個函式是讓你推翻用的
	//主要是用在請假王的隔回攻擊上
	virtual void BattleStart()
	{

	}
	virtual void Attacked()
	{

	}
	virtual bool IsTruant()
	{
		return false;
	}

	//輸出所有神奇寶貝的資訊
	virtual void DrawInformations()
	{
		cout << this->name << endl;
		cout <<left<<setw(10)<< "LV: " <<this->Level << endl;
		cout << left << setw(10) << "HP: " << this->hp << "/" << this->maxhp << endl;
		cout << left << setw(10) << "攻擊: " << this->attack << endl;
		cout << left << setw(10) << "防禦: " << this->defense << endl;
		cout << left << setw(10) << "特攻: " << this->spatk << endl;
		cout << left << setw(10) << "特防: " << this->spdef << endl;
		cout << left << setw(10) << "速度: " << this->speed << endl;
		cout << left << setw(10) << "屬性: ";
		for (int i = 0; i < this->type_number; i++)
		{
			cout << this->type[i]<<" ";
		}
		cout << endl;
		cout << left << setw(10) << "特殊能力: " << description << endl;
	};

	//恢復，能將hp回復至hp的上限值
	virtual void Restore()
	{
		this->hp = this->maxhp;
	}

	//計算傷害的函式
	float Sub_DamageCalculation(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill, float type)
	{
		float STAB = 1;
		//如果攻方神奇寶貝使用的招式屬性，與攻方神奇寶貝自身的屬性相同的話
		//威力會上升50%   (1.5倍)
		for (int i = 0; i < attacking_pokemon->GetTypeNumber(); i++)
		{
			if (attacking_pokemon->GetType(i) == attacking_skill->GetType())
			{
				STAB = 1.5;
			}
		}
		int damage;

		//如果是龍之怒固定傷害的話就不用計算這麼多，直接抓固定傷害的數值即可
		if (attacking_skill->IsFixedDamage())
		{
			damage = attacking_skill->GetFixedDamage();
		}
		else
		{
			float damage_term1 = (2.0f * attacking_pokemon->GetLevel() + 10) / 250.0f;

			float damage_ad;
			//物理攻擊招式的算式
			if (attacking_skill->GetDamageCategory() == "物理")
			{
				damage_ad = (float)attacking_pokemon->GetAttack() / (float) this->GetDefense();
			}
			//特殊攻擊招式的算式
			else
			{
				damage_ad = (float)attacking_pokemon->GetSpecialAttack() / (float) this->GetSpecialDefense();
			}

			float damage_base = attacking_skill->GetPower();


			float modifier = STAB * type;
			damage = (damage_term1*damage_ad*damage_base + 2)*modifier;
		}
		return damage;
	}

	//遭受攻擊的函式
	virtual string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		//注意:
		//這個函式沒有寫屬性相剋
		//只是幫你把算式複雜的部份寫出來而已
		//你必須在衍生類別推翻Underattack
		//寫出屬性生剋的部份
		//守方神奇寶貝有1個屬性被攻方招式屬性剋的時候    會受到2倍傷害    type要變成2
		//守方神奇寶貝有2個屬性被攻方招式屬性剋的時候    會受到4倍傷害    type要變成4
		//守方神奇寶貝有1個屬性剋制攻方招式屬性剋的時候  會受到0.5倍傷害  type要變成0.5
		//守方神奇寶貝有2個屬性剋制攻方招式屬性剋的時候  會受到0.25倍傷害 type要變成0.25

		float type = 1;

		//取得屬性的生剋後，傳入計算傷害的函式可得到傷害值
		int damage = Sub_DamageCalculation(attacking_pokemon, attacking_skill, type);
		

		if (this->hp < damage)
			damage = this->hp;
		this->hp = this->hp - damage;


		//你必須考慮屬性生剋，設定type的值
		if (type == 1)
		{
			return this->GetName() + " 受到 " + to_string(damage) + "點傷害\n";
		}
		else if (type >= 2)
		{
			return this->GetName() + " 受到 " + to_string(damage) + "點傷害\n" + "非常有效!\n";
		}
		else if (type == 0)
		{
			return "沒有效果...\n";
		}
		else
			return this->GetName() + " 受到 " + to_string(damage) + "點傷害\n" + "不怎麼有效...\n";
	
	}

	//取得此神奇寶貝的等級
	int GetLevel()
	{
		return this->Level;
	}

	//取得此神奇寶貝的總技能數量
	int GetSkillNumber()
	{
		return this->skill_number;
	}

	//取得此神奇寶貝的第i個技能
	Interface_Skill* GetSkill(int i)
	{
		return this->skills[i];
	}

	//取得此神奇寶貝的屬性數量
	int GetTypeNumber()
	{
		return this->type_number;
	}

	//取得此神奇寶貝的第i個屬性
	string GetType(int i)
	{
		return this->type[i];
	}

	//取得這個神奇寶貝的HP
	int GetHP()
	{
		return this->hp;
	}
	//取得這個神奇寶貝的最大HP
	int GetMaxHP()
	{
		return this->maxhp;
	}
	

	//取得這個神奇寶貝的名字
	string GetName()
	{
		return this->name;
	}
	//取得這個神奇寶貝的攻擊力
	int GetAttack()
	{
		return this->attack;
	}
	//取得這個神奇寶貝的防禦力
	int GetDefense()
	{
		return this->defense;
	}

	//取得這個神奇寶貝的特殊攻擊力
	int GetSpecialAttack()
	{
		return this->spatk;
	}
	//取得這個神奇寶貝的特殊防禦力
	int GetSpecialDefense()
	{
		return this->spdef;
	}

	//取得這個神奇寶貝的速度
	int GetSpeed()
	{
		return this->speed;
	}
	
};

#endif