#ifndef GAMEMANAGER
#define GAMEMANAGER

#include"MoveSceneManager.h"
#include"BattleSceneManager.h"
#include "PlayerInfo.h"

//遊戲管理者
//管理遊戲的一切
class GameManager 
{
private:
	//利用合成
	//底下有 移動場景管理者 與 戰鬥場景管理者
	MoveSceneManager MSM;
	BattleSceneManager BSM;

	//是否遭遇神奇寶貝
	bool Encounter;

	//玩家資訊
	PlayerInfo player;

	public:
		//建構子
		GameManager()
		{
			BSM.SetPlayerInfo(&player);
			Encounter = false;
		}

		//處理使用者的輸入
		//會依情況在 移動場景管理者 與 戰鬥場景管理者 間切換

		//遭遇神奇寶貝的話，會進入戰鬥，並讓 戰鬥場景管理者 處理使用者的輸入
		//反之沒進入戰鬥時，是讓 移動場景管理者 處理使用者的輸入
		void HandleInput()
		{
			//遭遇神奇寶貝的話，用BattleSceneManager 處理使用者的輸入
			if (Encounter)
			{
				//處理使用者的輸入
				BSM.HandleInput();

				//處理完的話要重畫一次，不然會沒有即時更新
				BSM.Draw();

				//若戰鬥結束的話，下一次HandleInput()開始，會交給MoveSceneManager 處理使用者的輸入
				if (BSM.BattleEnd())
				{
					Encounter = false;
				}
			}
			//反之，用MoveSceneManager 處理使用者的輸入
			else
			{
				//處理使用者的輸入
				MSM.HandleInput();

				//處理完的話要重畫一次，不然會沒有即時更新
				MSM.Draw();

				//看有沒有治療玩家

				//雖說不是每個Block都會治療玩家
				//但都得執行
				//如果該Block不會治療玩家，就是單純的空函式
				MSM.Heal(&player);

				//取得遭遇的神奇寶貝
				//如果沒有遭遇任何神奇寶貝的話，
				//encountered_pokemon會是nullptr
				Interface_Pokemon* encountered_pokemon = MSM.EncounterPokemon();

				//遭遇神奇寶貝的話
				if (encountered_pokemon != nullptr)
				{
					//如果遭遇神奇寶貝的話，就表示進入戰鬥
					//此時設定 BattleSceneManager 裡，遭遇到的神奇寶貝
					BSM.SetEncounteredPokemon(encountered_pokemon);

					//並把Encounter設成true，
					//這一舉動，會導致GameManager把HandleInput()交給BattleSceneManager 處理使用者的輸入
					Encounter = true;		
				}
			}
		}

		//畫出該有的畫面
		//會依情況在 移動場景管理者 與 戰鬥場景管理者 間切換

		//遭遇神奇寶貝的話，會進入戰鬥，並讓 戰鬥場景管理者 畫出畫面
		//反之沒進入戰鬥時，是讓 移動場景管理者 畫出畫面
		void Draw()
		{
			//遭遇神奇寶貝的話，用BattleSceneManager畫
			if (Encounter)
			{
				BSM.Draw();
			}
			//反之，用MoveSceneManager畫
			else
			{
				MSM.Draw();
			}
		}
};



#endif