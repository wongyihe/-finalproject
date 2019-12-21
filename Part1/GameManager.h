#ifndef GAMEMANAGER
#define GAMEMANAGER

#include"MoveSceneManager.h"
#include"BattleSceneManager.h"
#include "PlayerInfo.h"

//�[�������
//�����[���һ��
class GameManager
{
private:
	//���úϳ�
	//������ �Ƅӈ��������� �c ���Y����������
	MoveSceneManager MSM;
	BattleSceneManager BSM;

	//�Ƿ��������挚ؐ
	bool Encounter;

	//����YӍ
	PlayerInfo player;

public:
	//������
	GameManager()
	{
		Encounter = false;
	}

	//̎��ʹ���ߵ�ݔ��
	//������r�� �Ƅӈ��������� �c ���Y���������� �g�ГQ

	//�������挚ؐ��Ԓ�����M����Y���K׌ ���Y���������� ̎��ʹ���ߵ�ݔ��
	//��֮�]�M����Y�r����׌ �Ƅӈ��������� ̎��ʹ���ߵ�ݔ��
	void HandleInput()
	{
		//�������挚ؐ��Ԓ����BattleSceneManager ̎��ʹ���ߵ�ݔ��
		if (Encounter)
		{
			//̎��ʹ���ߵ�ݔ��
			BSM.HandleInput();

			//̎�����ԒҪ�خ�һ�Σ���Ȼ���]�м��r����
			BSM.Draw();

			//�����Y�Y����Ԓ����һ��HandleInput()�_ʼ�������oMoveSceneManager ̎��ʹ���ߵ�ݔ��
			if (BSM.BattleEnd())
			{
				Encounter = false;
			}
		}
		//��֮����MoveSceneManager ̎��ʹ���ߵ�ݔ��
		else
		{
			//̎��ʹ���ߵ�ݔ��
			MSM.HandleInput();

			//̎�����ԒҪ�خ�һ�Σ���Ȼ���]�м��r����
			MSM.Draw();

			//���Л]���ί����

			//�m�f����ÿ��Block�����ί����
			//�����È���
			//���ԓBlock�����ί���ң����ǆμ��Ŀպ�ʽ
			MSM.Heal(&player);

			//ȡ�����������挚ؐ
			//����]�������κ����挚ؐ��Ԓ��
			//encountered_pokemon����nullptr
			Interface_Pokemon* encountered_pokemon = MSM.EncounterPokemon();

			//�������挚ؐ��Ԓ
			if (encountered_pokemon != nullptr)
			{
				//����������挚ؐ��Ԓ���ͱ�ʾ�M����Y
				//�˕r�O�� BattleSceneManager �e�������������挚ؐ
				BSM.SetEncounteredPokemon(encountered_pokemon);

				//�K��Encounter�O��true��
				//�@һ�e�ӣ�������GameManager��HandleInput()���oBattleSceneManager ̎��ʹ���ߵ�ݔ��
				Encounter = true;
			}
		}
	}

	//����ԓ�еĮ���
	//������r�� �Ƅӈ��������� �c ���Y���������� �g�ГQ

	//�������挚ؐ��Ԓ�����M����Y���K׌ ���Y���������� ��������
	//��֮�]�M����Y�r����׌ �Ƅӈ��������� ��������
	void Draw()
	{
		//�������挚ؐ��Ԓ����BattleSceneManager��
		if (Encounter)
		{
			BSM.Draw();
		}
		//��֮����MoveSceneManager��
		else
		{
			MSM.Draw();
		}
	}
};



#endif