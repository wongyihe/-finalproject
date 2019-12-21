#ifndef BATTLESCENEANAGER
#define BATTLESCENEANAGER

#include<iomanip>
#include"BlankBlock.h"
#include"PlayerBlock.h"
#include"Vector_2.h"
#include"PlayerInfo.h"

//�M���B�z�԰��������޲z��
class BattleSceneManager
{

private:
	//�x�s�ثe�D�J�����_�_��
	//�`�N�o�O�@��pointer
	Interface_Pokemon* encountered_pokemon;

	//�Y�԰������Abattle_end�N�|�Otrue
	//�P��GameManager�|�z�LBattleEnd()�o���԰������P�_
	//�æb�԰������ɡA�N�D���v��BattleSceneManager��^MoveSceneManager
	bool battle_end;

	PlayerInfo *player;


	int inputstage;
	void Sub_Battle_Flow(Interface_Pokemon* attacking_pokemon, Interface_Skill * attacking_skill, Interface_Pokemon* defending_pokemon)
	{
		//�ˬd�O�_���i(�w��а���������)
		if (attacking_pokemon->IsTruant())
		{
			cout << attacking_pokemon->GetName() << " �а���..."<< endl;
			attacking_pokemon->Attacked();
			system("pause");
			return;
		}

		cout << attacking_pokemon->GetName() << " �ϥX�F " << attacking_skill->GetName() << endl;

		system("pause");

		//���P�_�O�_�R��
		//�Y�S�����|��� �S�������T��

		if (attacking_skill->IsMissed())
		{
			system("CLS");
			Draw();
			cout << attacking_pokemon->GetName() << " �� " << attacking_skill->GetName() << " �S������!" << endl;
			system("pause");
		}
		//���������p
		else
		{
			//�N�ۦ��P���pokemon��ưe��u��pokemon
			//���u��Pokemon�B�z�����쪺�ˮ`
			//�æ^�ǰT��
			string message = defending_pokemon->UnderAttack(attacking_pokemon, attacking_skill);
			system("CLS");
			Draw();
			cout << message;
			system("pause");
			/*
			//�p�G�u��hp�k0
			if (defending_pokemon->GetHP() == 0)
			{
				system("CLS");
				Draw();
				cout << defending_pokemon->GetName() << " �O�ܤF" << endl;
				system("pause");
				battle_end = true;
				return;
			}*/
		}
		//�o�˴N��O�����L�F
		//�а����b�����L�᪺�U�^�X�|�а�������
		attacking_pokemon->Attacked();
	}
	void SkillBattle()
	{
		char inputchar;
		int input;
		Interface_Pokemon* playerpokemon = player->GetCurrentPokemon();
		for (int i = 0; i < playerpokemon->GetSkillNumber(); i++)
		{
			Interface_Skill* currentskill = playerpokemon->GetSkill(i);
			cout << i + 1 << ". " << left << setw(12) << currentskill->GetName()
				<< " | " << left << setw(10) << currentskill->GetType() << " | " << left << setw(6) << currentskill->GetPower() 
				<< " | " << currentskill->GetDescription()<< endl;
		}

		cin >> inputchar;

		input = inputchar - 48;//��char������^int

		if (input > 0 && input <= playerpokemon->GetSkillNumber())
		{
			//�i�J�o�̪�ܪ��a��ܨèϥΤF�ޯ�

			//�H���M�w��诫�_�_���ϥΪ��ޯ�
			int randomskill = rand() % encountered_pokemon->GetSkillNumber();
			Interface_Skill* friend_pokemon_skill = playerpokemon->GetSkill(input - 1);
			Interface_Skill* encountered_pokemon_skill = encountered_pokemon->GetSkill(randomskill);

			Interface_Pokemon* first_attack_pokemon;
			Interface_Pokemon* second_attack_pokemon;
			Interface_Skill* first_attack_skill;
			Interface_Skill* second_attack_skill;
			//�����o�����u���v(Priority) �b���C�����u�Φb�q���@�{(Quick Attack��)
			//�u���v���̯������
			//�Y�u���v�@�� �|�����ӯ��_�_����Speed�� �Ѱ�������

			if (friend_pokemon_skill->GetPriority() == encountered_pokemon_skill->GetPriority())
			{
				if (playerpokemon->GetSpeed() >= encountered_pokemon->GetSpeed())
				{
					first_attack_pokemon = playerpokemon;
					second_attack_pokemon = encountered_pokemon;
					first_attack_skill = friend_pokemon_skill;
					second_attack_skill = encountered_pokemon_skill;
				}
				else
				{
					first_attack_pokemon = encountered_pokemon;
					second_attack_pokemon = playerpokemon;
					first_attack_skill = encountered_pokemon_skill;
					second_attack_skill = friend_pokemon_skill;
				}
			}
			else if (friend_pokemon_skill->GetPriority() > encountered_pokemon_skill->GetPriority())
			{
				first_attack_pokemon = playerpokemon;
				second_attack_pokemon = encountered_pokemon;
				first_attack_skill = friend_pokemon_skill;
				second_attack_skill = encountered_pokemon_skill;
			}
			else
			{
				first_attack_pokemon = encountered_pokemon;
				second_attack_pokemon = playerpokemon;
				first_attack_skill = encountered_pokemon_skill;
				second_attack_skill = friend_pokemon_skill;
			}

			system("CLS");
			Draw();

			Sub_Battle_Flow(first_attack_pokemon, first_attack_skill, second_attack_pokemon);

			if (playerpokemon->GetHP() == 0)
			{
				//�Y�O���a�����_�_�����`
				system("CLS");
				Draw();
				cout << playerpokemon->GetName() << " �O�ܤF" << endl;
				system("pause");
				//�N�������_�_��������Ʀ��`����
				inputstage = 2;
				return;
				//���Ʀ��`�C������
			}
			if (encountered_pokemon->GetHP() == 0)
			{
				system("CLS");
				Draw();
				cout << encountered_pokemon->GetName() << " �O�ܤF" << endl;
				system("pause");
				battle_end = true;
				return;
			}

			system("CLS");
			Draw();

			Sub_Battle_Flow(second_attack_pokemon, second_attack_skill, first_attack_pokemon);

			system("CLS");
			Draw();

			if (playerpokemon->GetHP() == 0)
			{
				//�Y�O���a�����_�_�����`
				system("CLS");
				Draw();
				cout << playerpokemon->GetName() << " �O�ܤF" << endl;
				system("pause");
				//�N�������_�_��������Ʀ��`����
				inputstage = 2;
				return;
				//���Ʀ��`�C������
			}
			if (encountered_pokemon->GetHP() == 0)
			{
				system("CLS");
				Draw();
				cout << encountered_pokemon->GetName() << " �O�ܤF" << endl;
				system("pause");
				battle_end = true;
				return;
			}

			//�����@���� �^�kstage0
			inputstage = 0;
		}
	}
	void ChangePokemon()
	{
		system("CLS");
		Draw();

		char inputchar;
		int input;
		
		for (int i = 0; i < 4; i++)
		{
			Interface_Pokemon* playerpokemon = player->GetPokemon(i);
			cout << i + 1 << ". " << left << setw(12) << playerpokemon->GetName()
				<< " | HP: " << playerpokemon->GetHP() << " / " << playerpokemon->GetMaxHP();

			if (playerpokemon->GetHP() == 0)
			{
				cout << "  �԰�����";
			}
			cout << endl;
		}

		cin >> inputchar;

		input = inputchar - 48;//��char������^int

		if (input >= 1 && input <= 4)
		{
			if (player->GetPokemon(input - 1)->GetHP() > 0)
			{
				player->ChangeCurrentPokemon(input - 1);
				player->GetCurrentPokemon()->BattleStart();
				inputstage = 0;
			}
		}

	}
public:

	//�غc�l
	BattleSceneManager()
	{
		battle_end = false;
		inputstage = 0;
		
	}

	void SetPlayerInfo(PlayerInfo *player)
	{
		this->player = player;
	}

	//�u�n�D�J���_�_���N�|�i�J�԰�����
	//�b�԰������ɡAHandleInput()�|�ھڪ��a����J�ӧ��ܤ@�Ǫ��A
	void HandleInput()
	{
		char inputchar;
		int input;
		if (inputstage == 0)
		{
			cout << "1. �ϥΧޯ�԰�" << endl;
			cout << "2. �洫���_�_��" << endl;
			cout << "3. �k�]" << endl;

			cin >> inputchar;
			input = inputchar - 48;//��char������^int

			if (input >= 1&&input<=3)
			{
				inputstage = input;
			
			}
			else if (input == 2)
			{
				inputstage = 2;
				
			}
			else if (input == 3)
			{
				inputstage = 3;
				
			}
		}
		else if (inputstage == 1)
		{
			SkillBattle();
		}
		else if (inputstage == 2)
		{
			ChangePokemon();
		}
		else if (inputstage ==3)
		{
			cout << "�k�]�F!" << endl;
			system("pause");
			battle_end = true;
		}
		
		
		
	//	cout << "�����N�䵲���԰�" << endl;
	//	system("pause");
	
	}
	//�ˬd�O�_�����԰�
	bool BattleEnd()
	{
		return battle_end;
	}

	//�e�X�԰��e��
	void Draw()
	{
		system("CLS");
		cout << "�D�J���_�_��: " << encountered_pokemon->GetName() << endl;
		encountered_pokemon->DrawInformations();
		cout << "--------------------------" << endl;
		cout << "�ڤ诫�_�_��: " << endl;
		player->GetCurrentPokemon()->DrawInformations();

	}

	//�]�w�D�J�����_�_��
	//�ó]�w�԰��D����
	void SetEncounteredPokemon(Interface_Pokemon * encountered_pokemon)
	{
		free(this->encountered_pokemon);

		this->encountered_pokemon = encountered_pokemon;

		//�а����b�԰��}�l�ɭn��������X��
		this->player->GetCurrentPokemon()->BattleStart();
		battle_end = false;
		inputstage = 0;
	}
};

#endif