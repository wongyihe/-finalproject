#ifndef POKEMON
#define POKEMON
#include<iostream>
#include<string>
#include<iomanip>
#include"Skill.h"
using namespace std;

//��w���_�_��������
class Interface_Pokemon
{
protected:
	//�W�r�P�U���ݩ�

	//�W�r
	string name;

	//����
	int Level;

	//��q(�ثe����q)
	int hp;

	//��q�W��
	int maxhp;

	//�����O
	int attack;

	//���m�O
	int defense;

	//�S������O
	int spatk;

	//�S���m�O
	int spdef;

	//�t��
	int speed;

	//�����_�_���֦����ޯ�
	Interface_Skill *skills[4];

	//�ޯ��`��
	int skill_number;

	//�����_�_�����ݩ�
	//�̦h�P�ɦ����
	string type[2];

	//�����_�_���֦����ݩʼ�
	int type_number;

	string description;
public:

	//�U���o3�Ө禡�O���A��½�Ϊ�
	//�D�n�O�Φb�а������j�^�����W
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

	//��X�Ҧ����_�_������T
	virtual void DrawInformations()
	{
		cout << this->name << endl;
		cout <<left<<setw(10)<< "LV: " <<this->Level << endl;
		cout << left << setw(10) << "HP: " << this->hp << "/" << this->maxhp << endl;
		cout << left << setw(10) << "����: " << this->attack << endl;
		cout << left << setw(10) << "���m: " << this->defense << endl;
		cout << left << setw(10) << "�S��: " << this->spatk << endl;
		cout << left << setw(10) << "�S��: " << this->spdef << endl;
		cout << left << setw(10) << "�t��: " << this->speed << endl;
		cout << left << setw(10) << "�ݩ�: ";
		for (int i = 0; i < this->type_number; i++)
		{
			cout << this->type[i]<<" ";
		}
		cout << endl;
		cout << left << setw(10) << "�S���O: " << description << endl;
	};

	//��_�A��Nhp�^�_��hp���W����
	virtual void Restore()
	{
		this->hp = this->maxhp;
	}

	//�p��ˮ`���禡
	float Sub_DamageCalculation(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill, float type)
	{
		float STAB = 1;
		//�p�G��诫�_�_���ϥΪ��ۦ��ݩʡA�P��诫�_�_���ۨ����ݩʬۦP����
		//�¤O�|�W��50%   (1.5��)
		for (int i = 0; i < attacking_pokemon->GetTypeNumber(); i++)
		{
			if (attacking_pokemon->GetType(i) == attacking_skill->GetType())
			{
				STAB = 1.5;
			}
		}
		int damage;

		//�p�G�O�s����T�w�ˮ`���ܴN���έp��o��h�A������T�w�ˮ`���ƭȧY�i
		if (attacking_skill->IsFixedDamage())
		{
			damage = attacking_skill->GetFixedDamage();
		}
		else
		{
			float damage_term1 = (2.0f * attacking_pokemon->GetLevel() + 10) / 250.0f;

			float damage_ad;
			//���z�����ۦ����⦡
			if (attacking_skill->GetDamageCategory() == "���z")
			{
				damage_ad = (float)attacking_pokemon->GetAttack() / (float) this->GetDefense();
			}
			//�S������ۦ����⦡
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

	//�D���������禡
	virtual string UnderAttack(Interface_Pokemon * attacking_pokemon, Interface_Skill* attacking_skill)
	{
		//�`�N:
		//�o�Ө禡�S���g�ݩʬ۫g
		//�u�O���A��⦡�����������g�X�ӦӤw
		//�A�����b�l�����O��½Underattack
		//�g�X�ݩʥͫg������
		//�u�诫�_�_����1���ݩʳQ���ۦ��ݩʫg���ɭ�    �|����2���ˮ`    type�n�ܦ�2
		//�u�诫�_�_����2���ݩʳQ���ۦ��ݩʫg���ɭ�    �|����4���ˮ`    type�n�ܦ�4
		//�u�诫�_�_����1���ݩʫg����ۦ��ݩʫg���ɭ�  �|����0.5���ˮ`  type�n�ܦ�0.5
		//�u�诫�_�_����2���ݩʫg����ۦ��ݩʫg���ɭ�  �|����0.25���ˮ` type�n�ܦ�0.25

		float type = 1;

		//���o�ݩʪ��ͫg��A�ǤJ�p��ˮ`���禡�i�o��ˮ`��
		int damage = Sub_DamageCalculation(attacking_pokemon, attacking_skill, type);
		

		if (this->hp < damage)
			damage = this->hp;
		this->hp = this->hp - damage;


		//�A�����Ҽ{�ݩʥͫg�A�]�wtype����
		if (type == 1)
		{
			return this->GetName() + " ���� " + to_string(damage) + "�I�ˮ`\n";
		}
		else if (type >= 2)
		{
			return this->GetName() + " ���� " + to_string(damage) + "�I�ˮ`\n" + "�D�`����!\n";
		}
		else if (type == 0)
		{
			return "�S���ĪG...\n";
		}
		else
			return this->GetName() + " ���� " + to_string(damage) + "�I�ˮ`\n" + "����򦳮�...\n";
	
	}

	//���o�����_�_��������
	int GetLevel()
	{
		return this->Level;
	}

	//���o�����_�_�����`�ޯ�ƶq
	int GetSkillNumber()
	{
		return this->skill_number;
	}

	//���o�����_�_������i�ӧޯ�
	Interface_Skill* GetSkill(int i)
	{
		return this->skills[i];
	}

	//���o�����_�_�����ݩʼƶq
	int GetTypeNumber()
	{
		return this->type_number;
	}

	//���o�����_�_������i���ݩ�
	string GetType(int i)
	{
		return this->type[i];
	}

	//���o�o�ӯ��_�_����HP
	int GetHP()
	{
		return this->hp;
	}
	//���o�o�ӯ��_�_�����̤jHP
	int GetMaxHP()
	{
		return this->maxhp;
	}
	

	//���o�o�ӯ��_�_�����W�r
	string GetName()
	{
		return this->name;
	}
	//���o�o�ӯ��_�_���������O
	int GetAttack()
	{
		return this->attack;
	}
	//���o�o�ӯ��_�_�������m�O
	int GetDefense()
	{
		return this->defense;
	}

	//���o�o�ӯ��_�_�����S������O
	int GetSpecialAttack()
	{
		return this->spatk;
	}
	//���o�o�ӯ��_�_�����S���m�O
	int GetSpecialDefense()
	{
		return this->spdef;
	}

	//���o�o�ӯ��_�_�����t��
	int GetSpeed()
	{
		return this->speed;
	}
	
};

#endif