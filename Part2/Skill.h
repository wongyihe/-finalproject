#ifndef SKILL
#define SKILL


#include <iostream>
#include<string>
using namespace std;


//��w�ޯश��
class Interface_Skill
{
protected:
	//�ޯ�W��
	string name;

	//�ޯ��ݩ�
	string type;

	//�ޯ�ˮ`����
	string damage_category;

	//�ޯ�y�z
	string description;

	//�ޯ�¤O
	float power;

	//�ޯ�R���v
	int accuracy;

	//�O�_�O�T�w�ˮ`�A�p�s����
	bool is_fixed_damage;

	//���o�T�w�ˮ`�ƭ�
	float fixed_damage;

	//�����u���סA�ƭȷU���U����
	int priority;

public:
	//�غc�l
	Interface_Skill()
	{
		this->accuracy = 100;
		this->is_fixed_damage = false;
		this->fixed_damage = 0;
		this->priority = 0;
	}
	//���o�O�_�S�R��
	virtual bool IsMissed()
	{
		return false;
	}

	//���o�ۦ��¤O
	virtual float GetPower()
	{
		return power;
	}
	

	//���ۦ��O�_�O�T�w�ˮ`�A�p�s����
	bool IsFixedDamage()
	{
		return this->is_fixed_damage;
	}

	//���o���ۦ����T�w�ˮ`�ƭ�
	float GetFixedDamage()
	{
		return this->fixed_damage;
	}

	//���o���ۦ��W��
	string GetName()
	{
		return this->name;
	}

	//���o���ۦ��ݩ�
	string GetType()
	{
		return type;
	}

	//���o���ۦ��ˮ`����
	string GetDamageCategory()
	{
		return damage_category;
	}

	//���o���ۦ����y�z
	string GetDescription()
	{
		return this->description;
	}

	//���o���ۦ����u����
	int GetPriority()
	{
		return this->priority;
	}
};

#endif 
