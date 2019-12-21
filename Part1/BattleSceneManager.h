#ifndef BATTLESCENEANAGER
#define BATTLESCENEANAGER

#include"BlankBlock.h"
#include"PlayerBlock.h"
#include"Vector_2.h"

//���T̎����Y�����Ĺ�����
class BattleSceneManager
{

private:
	//����Ŀǰ���������挚ؐ
	//ע���@��һ��pointer
	Interface_Pokemon* encountered_pokemon;

	//�����Y�Y����battle_end�͕���true
	//ͬ�rGameManager��͸�^BattleEnd()��֪���Y�Y���c��
	//�K�ڑ��Y�Y���r�������ؙ���BattleSceneManager�D��MoveSceneManager
	bool battle_end;
public:

	//������
	BattleSceneManager()
	{
		battle_end = false;
	}

	//ֻҪ�������挚ؐ�͕��M����Y����
	//�ڑ��Y�����r��HandleInput()��������ҵ�ݔ����׃һЩ��B
	void HandleInput()
	{
		cout << "�������I�Y�����Y" << endl;
		system("pause");
		battle_end = true;
	}
	//�z���Ƿ�Y�����Y
	bool BattleEnd()
	{
		return battle_end;
	}

	//�������Y����
	void Draw()
	{
		system("CLS");
		cout << "�������挚ؐ: " << encountered_pokemon->GetName() << endl;
		encountered_pokemon->DrawInformations();
	}

	//�O�����������挚ؐ
	//�K�O�����Y�ǽY��
	void SetEncounteredPokemon(Interface_Pokemon * encountered_pokemon)
	{
		free(this->encountered_pokemon);

		this->encountered_pokemon = encountered_pokemon;

		battle_end = false;
	}
};

#endif