#ifndef GRASSBLOCK_UL
#define GRASSBLOCK_UL
#include<iostream>
#include"Block.h"
#include"Pikachu.h"
#include"Lizardon.h"
#include"Kekking.h"
#include<time.h>
//左上角的草地

//會遭遇神奇寶貝

//草地會顯示"草"
class GrassBlock_UpLeft : public Interface_Block
{
private:
	int r;
public:
	//草地會顯示"草"
	void Draw(){ cout << "草"; }
	//有60%機率遇敵
	 bool IsEncounter()
	{
		
		srand((unsigned)time(NULL));
		r = rand() % 10;
		if (r <= 5)return true;
		else return false;
	}
	//如果回傳true表示遭遇神奇寶貝
	//反之則沒有遭遇神奇寶貝
	virtual Interface_Pokemon* GetEncounteredPokemon()
	{
		int p;
		int possible;
		possible = rand() % 100;
		p = rand() % 4;
		
		if (r <= 5){
			Interface_Pokemon *getencountered_pokemon ;
				if (possible <25) getencountered_pokemon=new Pikachu(5+p);
				else if (possible < 60)getencountered_pokemon = new Nukenin(10+p);
				else getencountered_pokemon = new Kekking(11+p);
			return getencountered_pokemon;
		}
		else return nullptr;
	};

	//如果遭遇神奇寶貝
	//該神奇寶貝有下列三種可能:
	//25%機率抽到 皮卡丘    等級5~8
	//35%機率抽到 脫殼忍者  等級10~13
	//40%機率抽到 請假王    等級11~14

};

#endif