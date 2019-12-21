#ifndef BATTLESCENEANAGER
#define BATTLESCENEANAGER

#include<iomanip>
#include"BlankBlock.h"
#include"PlayerBlock.h"
#include"Vector_2.h"
#include"PlayerInfo.h"

//專門處理戰鬥場景的管理者
class BattleSceneManager
{

private:
	//儲存目前遭遇的神奇寶貝
	//注意這是一個pointer
	Interface_Pokemon* encountered_pokemon;

	//若戰鬥結束，battle_end就會是true
	//同時GameManager會透過BattleEnd()得知戰鬥結束與否
	//並在戰鬥結束時，將主控權由BattleSceneManager轉回MoveSceneManager
	bool battle_end;

	PlayerInfo *player;


	int inputstage;
	void Sub_Battle_Flow(Interface_Pokemon* attacking_pokemon, Interface_Skill * attacking_skill, Interface_Pokemon* defending_pokemon)
	{
		//檢查是否偷懶(針對請假王的機制)
		if (attacking_pokemon->IsTruant())
		{
			cout << attacking_pokemon->GetName() << " 請假中..."<< endl;
			attacking_pokemon->Attacked();
			system("pause");
			return;
		}

		cout << attacking_pokemon->GetName() << " 使出了 " << attacking_skill->GetName() << endl;

		system("pause");

		//先判斷是否命中
		//若沒擊中會顯示 沒擊中的訊息

		if (attacking_skill->IsMissed())
		{
			system("CLS");
			Draw();
			cout << attacking_pokemon->GetName() << " 的 " << attacking_skill->GetName() << " 沒有擊中!" << endl;
			system("pause");
		}
		//擊中的狀況
		else
		{
			//將招式與攻方pokemon資料送到守方pokemon
			//讓守方Pokemon處理應受到的傷害
			//並回傳訊息
			string message = defending_pokemon->UnderAttack(attacking_pokemon, attacking_skill);
			system("CLS");
			Draw();
			cout << message;
			system("pause");
			/*
			//如果守方hp歸0
			if (defending_pokemon->GetHP() == 0)
			{
				system("CLS");
				Draw();
				cout << defending_pokemon->GetName() << " 力竭了" << endl;
				system("pause");
				battle_end = true;
				return;
			}*/
		}
		//這樣就算是攻擊過了
		//請假王在攻擊過後的下回合會請假不攻擊
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

		input = inputchar - 48;//把char的值轉回int

		if (input > 0 && input <= playerpokemon->GetSkillNumber())
		{
			//進入這裡表示玩家選擇並使用了技能

			//隨機決定對方神奇寶貝使用的技能
			int randomskill = rand() % encountered_pokemon->GetSkillNumber();
			Interface_Skill* friend_pokemon_skill = playerpokemon->GetSkill(input - 1);
			Interface_Skill* encountered_pokemon_skill = encountered_pokemon->GetSkill(randomskill);

			Interface_Pokemon* first_attack_pokemon;
			Interface_Pokemon* second_attack_pokemon;
			Interface_Skill* first_attack_skill;
			Interface_Skill* second_attack_skill;
			//先取得攻擊優先權(Priority) 在此遊戲中只用在電光一閃(Quick Attack裡)
			//優先權高者能先攻擊
			//若優先權一樣 會比較兩個神奇寶貝之Speed值 由高的先攻

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
				//若是玩家的神奇寶貝死亡
				system("CLS");
				Draw();
				cout << playerpokemon->GetName() << " 力竭了" << endl;
				system("pause");
				//就替換神奇寶貝直到全數死亡為止
				inputstage = 2;
				return;
				//全數死亡遊戲結束
			}
			if (encountered_pokemon->GetHP() == 0)
			{
				system("CLS");
				Draw();
				cout << encountered_pokemon->GetName() << " 力竭了" << endl;
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
				//若是玩家的神奇寶貝死亡
				system("CLS");
				Draw();
				cout << playerpokemon->GetName() << " 力竭了" << endl;
				system("pause");
				//就替換神奇寶貝直到全數死亡為止
				inputstage = 2;
				return;
				//全數死亡遊戲結束
			}
			if (encountered_pokemon->GetHP() == 0)
			{
				system("CLS");
				Draw();
				cout << encountered_pokemon->GetName() << " 力竭了" << endl;
				system("pause");
				battle_end = true;
				return;
			}

			//完成一輪後 回歸stage0
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
				cout << "  戰鬥不能";
			}
			cout << endl;
		}

		cin >> inputchar;

		input = inputchar - 48;//把char的值轉回int

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

	//建構子
	BattleSceneManager()
	{
		battle_end = false;
		inputstage = 0;
		
	}

	void SetPlayerInfo(PlayerInfo *player)
	{
		this->player = player;
	}

	//只要遭遇神奇寶貝就會進入戰鬥場景
	//在戰鬥場景時，HandleInput()會根據玩家的輸入來改變一些狀態
	void HandleInput()
	{
		char inputchar;
		int input;
		if (inputstage == 0)
		{
			cout << "1. 使用技能戰鬥" << endl;
			cout << "2. 交換神奇寶貝" << endl;
			cout << "3. 逃跑" << endl;

			cin >> inputchar;
			input = inputchar - 48;//把char的值轉回int

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
			cout << "逃跑了!" << endl;
			system("pause");
			battle_end = true;
		}
		
		
		
	//	cout << "按任意鍵結束戰鬥" << endl;
	//	system("pause");
	
	}
	//檢查是否結束戰鬥
	bool BattleEnd()
	{
		return battle_end;
	}

	//畫出戰鬥畫面
	void Draw()
	{
		system("CLS");
		cout << "遭遇神奇寶貝: " << encountered_pokemon->GetName() << endl;
		encountered_pokemon->DrawInformations();
		cout << "--------------------------" << endl;
		cout << "我方神奇寶貝: " << endl;
		player->GetCurrentPokemon()->DrawInformations();

	}

	//設定遭遇的神奇寶貝
	//並設定戰鬥非結束
	void SetEncounteredPokemon(Interface_Pokemon * encountered_pokemon)
	{
		free(this->encountered_pokemon);

		this->encountered_pokemon = encountered_pokemon;

		//請假王在戰鬥開始時要讓它能夠出招
		this->player->GetCurrentPokemon()->BattleStart();
		battle_end = false;
		inputstage = 0;
	}
};

#endif