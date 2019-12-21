#ifndef RECOVERBLOCK
#define RECOVERBLOCK
#include<iostream>
#include"Block.h"  //因為要繼承class Interface_Block 必須引入定義class Interface_Block的標頭檔
using namespace std;

//回復血量的地板

//當玩家站上來後會顯示  "所有神奇寶貝生命回復!" 
//並用system("pause")讓使用者輸入任意鍵後再繼續

//地板會顯示"回"
class RecoverBlock : public Interface_Block
{
public:
	//會顯示"回"
	void Draw(){ cout << "回"; }
	bool IsEncounter()
	{
		return false;
	}
	Interface_Pokemon* GetEncounteredPokemon()
	{
		//預設回傳null pointer 空的指標
		return nullptr;
	};
	virtual void Heal(PlayerInfo *p)
	{

		p->Restore();
		cout << "所有神奇寶貝生命回復!" << endl;
		system("pause");
	}

	//當玩家站上來後會顯示  "所有神奇寶貝生命回復!" 

	//並用system("pause")讓使用者輸入任意鍵後再繼續

};

#endif 