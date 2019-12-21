#ifndef GAMEMANAGER
#define GAMEMANAGER

#include"MoveSceneManager.h"
#include"BattleSceneManager.h"
#include "PlayerInfo.h"

//�C���޲z��
//�޲z�C�����@��
class GameManager 
{
private:
	//�Q�ΦX��
	//���U�� ���ʳ����޲z�� �P �԰������޲z��
	MoveSceneManager MSM;
	BattleSceneManager BSM;

	//�O�_�D�J���_�_��
	bool Encounter;

	//���a��T
	PlayerInfo player;

	public:
		//�غc�l
		GameManager()
		{
			BSM.SetPlayerInfo(&player);
			Encounter = false;
		}

		//�B�z�ϥΪ̪���J
		//�|�̱��p�b ���ʳ����޲z�� �P �԰������޲z�� ������

		//�D�J���_�_�����ܡA�|�i�J�԰��A���� �԰������޲z�� �B�z�ϥΪ̪���J
		//�Ϥ��S�i�J�԰��ɡA�O�� ���ʳ����޲z�� �B�z�ϥΪ̪���J
		void HandleInput()
		{
			//�D�J���_�_�����ܡA��BattleSceneManager �B�z�ϥΪ̪���J
			if (Encounter)
			{
				//�B�z�ϥΪ̪���J
				BSM.HandleInput();

				//�B�z�����ܭn���e�@���A���M�|�S���Y�ɧ�s
				BSM.Draw();

				//�Y�԰��������ܡA�U�@��HandleInput()�}�l�A�|�浹MoveSceneManager �B�z�ϥΪ̪���J
				if (BSM.BattleEnd())
				{
					Encounter = false;
				}
			}
			//�Ϥ��A��MoveSceneManager �B�z�ϥΪ̪���J
			else
			{
				//�B�z�ϥΪ̪���J
				MSM.HandleInput();

				//�B�z�����ܭn���e�@���A���M�|�S���Y�ɧ�s
				MSM.Draw();

				//�ݦ��S���v�����a

				//�������O�C��Block���|�v�����a
				//�����o����
				//�p�G��Block���|�v�����a�A�N�O��ª��Ũ禡
				MSM.Heal(&player);

				//���o�D�J�����_�_��
				//�p�G�S���D�J���󯫩_�_�����ܡA
				//encountered_pokemon�|�Onullptr
				Interface_Pokemon* encountered_pokemon = MSM.EncounterPokemon();

				//�D�J���_�_������
				if (encountered_pokemon != nullptr)
				{
					//�p�G�D�J���_�_�����ܡA�N��ܶi�J�԰�
					//���ɳ]�w BattleSceneManager �̡A�D�J�쪺���_�_��
					BSM.SetEncounteredPokemon(encountered_pokemon);

					//�ç�Encounter�]��true�A
					//�o�@�|�ʡA�|�ɭPGameManager��HandleInput()�浹BattleSceneManager �B�z�ϥΪ̪���J
					Encounter = true;		
				}
			}
		}

		//�e�X�Ӧ����e��
		//�|�̱��p�b ���ʳ����޲z�� �P �԰������޲z�� ������

		//�D�J���_�_�����ܡA�|�i�J�԰��A���� �԰������޲z�� �e�X�e��
		//�Ϥ��S�i�J�԰��ɡA�O�� ���ʳ����޲z�� �e�X�e��
		void Draw()
		{
			//�D�J���_�_�����ܡA��BattleSceneManager�e
			if (Encounter)
			{
				BSM.Draw();
			}
			//�Ϥ��A��MoveSceneManager�e
			else
			{
				MSM.Draw();
			}
		}
};



#endif