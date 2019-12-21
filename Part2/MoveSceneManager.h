#ifndef MOVESCENEANAGER
#define MOVESCENEANAGER
#include "GrassBlock_UpLeft.h"
#include "GrassBlock_DownRight.h"
#include"BlankBlock.h"
#include"PlayerBlock.h"
#include"RecoverBlock.h"
#include"RedBlock.h"
#include"Vector_2.h"

//移動場景管理者
class MoveSceneManager
{
private:
	//用二維Interface_Block陣列來存地圖
	//這是一個7x8的pointer array
	//因為Interface_Block不能被實體化 

	//順帶一提Interface_Block block_array[7][8]之類的宣告是不合法的(少一個*)
	//因為Interface_Block是abstract class 不能被實體化
	//而Interface_Block block_array[7][8]卻會實體化 7*8 個Interface_Block

	//你必須用多型的方式，實現Interface_Block的衍生類別
	//並限制衍生類別的介面為Interface_Block
	//如Interface_Block *IB = new BlankBlock();
	Interface_Block *block_array[7][8];

	Interface_Block *player_block;

	//儲存玩家位置
	Vector_2 player_position;

	//儲存玩家輸入字元
	char inputchar;

	//檢查是否移動過
	bool moved;
	
public:
	//建構子
	MoveSceneManager()
	{
		//預設是沒有移動過的狀態
		moved = false;
		//以下的程式碼用來初始化地圖陣列
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				//注意這裡的block_array[i][j]是指向Interface_Block類別的pointer，
				//BlankBlock因繼承Interface_Block，因此也"是一個"Interface_Block
				block_array[i][j] = new BlankBlock();
			}
		}
		for (int i = 1; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				block_array[i][j] = new GrassBlock_UpLeft();
		}
		for (int i = 5; i < 7; i++)
		{
			for (int j = 3; j < 8; j++)
				block_array[i][j] = new GrassBlock_DownRight();
		}
		block_array[3][7] = new RecoverBlock();
		block_array[6][0] = new RedBlock();
		player_block = new PlayerBlock();
	}
	//處理使用者輸入
	void HandleInput()
	{
		//讓使用者輸入w s a d
		cout << "請輸入w、s、a或d來移動" << endl;
		cin >> inputchar;
		
		
		//先歸回無移動的狀態
		moved = false;
		//處理鍵盤輸入

		//在這只是處理玩家位置player_position
		//讓它隨使用者輸入而改變x與y的值

		//注意:
		//x範圍是左0到右7
		//y範圍是上0到下6
		switch (inputchar)
		{
		case 'w': case 'W':
			if (player_position.y > 0)
			{
				player_position.y--;
				moved = true;
			}
			break;
		case 's': case 'S':
			if (player_position.y <6)
			{
				player_position.y++;
				moved = true;
			}
			break;
		case 'a': case 'A':
			if (player_position.x > 0)
			{
				player_position.x--;
				moved = true;
			}
			break;
		case 'd': case 'D':
			if (player_position.x <7)
			{
				player_position.x++;
				moved = true;
			}
			break;
		default:
			break;
		}
	}

	//補血函式
	void Heal(PlayerInfo *player)
	{
		//呼叫玩家所站著的Block的補血函式

		//並不是所有Block都會補血
		//若一個Block不會補血，那只需要讓該Block的補血函式是空函式即可
		//如{ }
		block_array[player_position.y][player_position.x]->Heal(player);
	}

	//是否遭遇Pokemon
	//如果遭遇的話會回傳一個Interface_Pokemon pointer
	//若否則是回傳nullptr
	Interface_Pokemon* EncounterPokemon()
	{
		//有移動過才能判斷有沒有遇敵
		//例如一直卡在最左邊的草裡 瘋狂按a往左移 也是不會遇敵的
		if (moved)
		{
			//先判斷有沒有遇敵 依各block種類有遇敵的機率
			if (block_array[player_position.y][player_position.x]->IsEncounter())
			{
				//進入戰鬥
				//進入戰鬥的準備
				Interface_Pokemon *encountered_pokemon = block_array[player_position.y][player_position.x]->GetEncounteredPokemon();
				//回傳遭遇到的Pokemon至GameManager
				//當GameManager收到這個Pokemon時
				//便會切換到戰鬥場景 使用BattleSceneManager
				return encountered_pokemon;
				
			}
			else
				return nullptr;
		}
		return nullptr;

	}
	void Draw()
	{
		system("CLS");
		for (int i = 0; i < 7; i++)
		{
			
			for (int j = 0; j < 8; j++)
			{
				if (player_position.x == j && player_position.y == i)
				{
					player_block->Draw();
				}
				else
				{
					cout << "  ";
				}
				
			}
			cout << endl;
			for (int j = 0; j < 8; j++)
			{
				block_array[i][j]->Draw();
			}
			cout << endl;
			
		}
		
	}
};
#endif