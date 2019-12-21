#ifndef REDBLOCK
#define REDBLOCK
#include<iostream>
#include"Block.h" //因為要繼承class Interface_Block 必須引入定義class Interface_Block的標頭檔
#include"Red_Pikachu.h"
using namespace std;

//小智的皮卡丘的所在

//只會遭遇小智的皮卡丘

//地板會顯示"智"
class RedBlock : public Interface_Block
{
public:
	//會顯示"智"
	void Draw(){ cout << "智"; }

	//有100%機率遭遇神奇寶貝 
	virtual bool IsEncounter()
	{
		return true;
	}
 Interface_Pokemon* GetEncounteredPokemon()
	{
		//預設回傳null pointer 空的指標
		Interface_Pokemon *getencountered_pokemon =new Red_Pikachu(40);
		
			return getencountered_pokemon;
	};

	//遭遇的神奇寶貝只有下面這一種可能:
	//小智的皮卡丘   40級


};

#endif 