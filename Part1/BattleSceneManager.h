#ifndef BATTLESCENEANAGER
#define BATTLESCENEANAGER

#include"BlankBlock.h"
#include"PlayerBlock.h"
#include"Vector_2.h"

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
public:

	//建構子
	BattleSceneManager()
	{
		battle_end = false;
	}

	//只要遭遇神奇寶貝就會進入戰鬥場景
	//在戰鬥場景時，HandleInput()會根據玩家的輸入來改變一些狀態
	void HandleInput()
	{
		cout << "按任意鍵結束戰鬥" << endl;
		system("pause");
		battle_end = true;
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
	}

	//設定遭遇的神奇寶貝
	//並設定戰鬥非結束
	void SetEncounteredPokemon(Interface_Pokemon * encountered_pokemon)
	{
		free(this->encountered_pokemon);

		this->encountered_pokemon = encountered_pokemon;

		battle_end = false;
	}
};

#endif