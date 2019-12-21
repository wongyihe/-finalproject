#ifndef GRASSBLOCK_DR
#define GRASSBLOCK_DR
#include<iostream>
#include<time.h>
#include"Block.h"
#include"Pikachu.h"
#include"Nukenin.h"
#include"Kekking.h"

//右下角的草地

//會遭遇神奇寶貝

//草地會顯示"草"
class GrassBlock_DownRight : public Interface_Block
{
private:
	int r;
public:
	//草地會顯示"草"
	void Draw(){ cout << "草"; }

	//有75%機率遇敵
	//如果回傳true表示遭遇神奇寶貝
	//反之則沒有遭遇神奇寶貝
	bool IsEncounter()
	{

		srand((unsigned)time(NULL));
		r = rand() % 100;
		if (r < 75)return true;
		else return false;
	}

	//如果遭遇神奇寶貝
	//該神奇寶貝有下列三種可能:
	//40%機率抽到 皮卡丘  等級11~15
	//30%機率抽到 噴火龍  等級15~20
	//30%機率抽到 請假王  等級17~21
	virtual Interface_Pokemon* GetEncounteredPokemon()
	{
		int p,l;
		int possible;
		possible = rand() % 100;
		p = rand() % 5;
		l = rand() % 6;
		if (r <= 5){
			Interface_Pokemon *getencountered_pokemon;
			if (possible <40) getencountered_pokemon = new Pikachu(11 + p);
			else if (possible < 70)getencountered_pokemon = new Lizardon(15 + l);
			else getencountered_pokemon = new Kekking(17 + p);
			return getencountered_pokemon;
		}
		else return nullptr;
	};
};

#endif