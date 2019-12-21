#ifndef SKILL
#define SKILL


#include <iostream>
#include<string>
using namespace std;


//制定技能介面
class Interface_Skill
{
protected:
	//技能名稱
	string name;

	//技能屬性
	string type;

	//技能傷害種類
	string damage_category;

	//技能描述
	string description;

	//技能威力
	float power;

	//技能命中率
	int accuracy;

	//是否是固定傷害，如龍之怒
	bool is_fixed_damage;

	//取得固定傷害數值
	float fixed_damage;

	//攻擊優先度，數值愈高愈先攻
	int priority;

public:
	//建構子
	Interface_Skill()
	{
		this->accuracy = 100;
		this->is_fixed_damage = false;
		this->fixed_damage = 0;
		this->priority = 0;
	}
	//取得是否沒命中
	virtual bool IsMissed()
	{
		return false;
	}

	//取得招式威力
	virtual float GetPower()
	{
		return power;
	}
	

	//此招式是否是固定傷害，如龍之怒
	bool IsFixedDamage()
	{
		return this->is_fixed_damage;
	}

	//取得此招式的固定傷害數值
	float GetFixedDamage()
	{
		return this->fixed_damage;
	}

	//取得此招式名稱
	string GetName()
	{
		return this->name;
	}

	//取得此招式屬性
	string GetType()
	{
		return type;
	}

	//取得此招式傷害種類
	string GetDamageCategory()
	{
		return damage_category;
	}

	//取得此招式的描述
	string GetDescription()
	{
		return this->description;
	}

	//取得此招式的優先度
	int GetPriority()
	{
		return this->priority;
	}
};

#endif 
