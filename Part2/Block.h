#ifndef IBLOCK
#define IBLOCK
#include"PlayerInfo.h"
#include"Pokemon.h"

//制定Block介面 
class Interface_Block  
{
public:
	//Draw函式會決定這塊地板應該畫出什麼
	//如空白地板是"■"
	//草地是"草"

	//由於是抽象函式(abstract function)，你必須要推翻(override)它
	virtual void Draw()=0;

	//檢查是否遭遇神奇寶貝
	//如果遭遇神奇寶貝的話會回傳true，反之false

	//並不是每種Block都會遇敵喔

	//預設是回傳false，若不想用這個virtual function可以推翻(override)它
	virtual bool IsEncounter()
	{
		return false;
	}

	//取得遭遇的神奇寶貝

	//如果遇敵的話才會使用這個函式

	//預設是回傳nullptr，若不想用這個virtual function可以推翻(override)它
	virtual Interface_Pokemon* GetEncounteredPokemon()
	{
		//預設回傳null pointer 空的指標
		return nullptr;
	};

	//治療玩家的神奇寶貝

	//並不是每種Block都會治療玩家的神奇寶貝

	//預設是空函式(什麼都不作)，若不想用這個virtual function可以推翻(override)它
	virtual void Heal(PlayerInfo *p)
	{
	}


	
};

#endif