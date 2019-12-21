#ifndef PLAYERINFORMATION
#define PLAYERINFORMATION


#include "Pokemon.h"
#include"Pikachu.h"
#include"Nukenin.h"
#include "Kekking.h"
#include "Lizardon.h"

//ª±®a¸ê°T
class PlayerInfo
{
private:
	int currentpokemon;
	Interface_Pokemon *pokemons[4];

public:
	PlayerInfo()
	{
		currentpokemon = 0;
		pokemons[0] = new Pikachu(20);
		pokemons[1] = new Lizardon(19);
		pokemons[2] = new Nukenin(18);
		pokemons[3] = new Kekking(18);

	}
	Interface_Pokemon * GetPokemon(int i)
	{
		return pokemons[i];
	}

	Interface_Pokemon * GetCurrentPokemon()
	{
		return pokemons[currentpokemon];
	}

	void ChangeCurrentPokemon(int i)
	{
		currentpokemon = i;
	}
	void Restore()
	{
		for (int i = 0; i < 4; i++)
			pokemons[i]->Restore();
	}
};

#endif 
