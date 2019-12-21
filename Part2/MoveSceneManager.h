#ifndef MOVESCENEANAGER
#define MOVESCENEANAGER
#include "GrassBlock_UpLeft.h"
#include "GrassBlock_DownRight.h"
#include"BlankBlock.h"
#include"PlayerBlock.h"
#include"RecoverBlock.h"
#include"RedBlock.h"
#include"Vector_2.h"

//���ʳ����޲z��
class MoveSceneManager
{
private:
	//�ΤG��Interface_Block�}�C�Ӧs�a��
	//�o�O�@��7x8��pointer array
	//�]��Interface_Block����Q����� 

	//���a�@��Interface_Block block_array[7][8]�������ŧi�O���X�k��(�֤@��*)
	//�]��Interface_Block�Oabstract class ����Q�����
	//��Interface_Block block_array[7][8]�o�|����� 7*8 ��Interface_Block

	//�A�����Φh�����覡�A��{Interface_Block���l�����O
	//�í���l�����O��������Interface_Block
	//�pInterface_Block *IB = new BlankBlock();
	Interface_Block *block_array[7][8];

	Interface_Block *player_block;

	//�x�s���a��m
	Vector_2 player_position;

	//�x�s���a��J�r��
	char inputchar;

	//�ˬd�O�_���ʹL
	bool moved;
	
public:
	//�غc�l
	MoveSceneManager()
	{
		//�w�]�O�S�����ʹL�����A
		moved = false;
		//�H�U���{���X�ΨӪ�l�Ʀa�ϰ}�C
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				//�`�N�o�̪�block_array[i][j]�O���VInterface_Block���O��pointer�A
				//BlankBlock�]�~��Interface_Block�A�]���]"�O�@��"Interface_Block
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
	//�B�z�ϥΪ̿�J
	void HandleInput()
	{
		//���ϥΪ̿�Jw s a d
		cout << "�п�Jw�Bs�Ba��d�Ӳ���" << endl;
		cin >> inputchar;
		
		
		//���k�^�L���ʪ����A
		moved = false;
		//�B�z��L��J

		//�b�o�u�O�B�z���a��mplayer_position
		//�����H�ϥΪ̿�J�ӧ���x�Py����

		//�`�N:
		//x�d��O��0��k7
		//y�d��O�W0��U6
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

	//�ɦ�禡
	void Heal(PlayerInfo *player)
	{
		//�I�s���a�ү��۪�Block���ɦ�禡

		//�ä��O�Ҧ�Block���|�ɦ�
		//�Y�@��Block���|�ɦ�A���u�ݭn����Block���ɦ�禡�O�Ũ禡�Y�i
		//�p{ }
		block_array[player_position.y][player_position.x]->Heal(player);
	}

	//�O�_�D�JPokemon
	//�p�G�D�J���ܷ|�^�Ǥ@��Interface_Pokemon pointer
	//�Y�_�h�O�^��nullptr
	Interface_Pokemon* EncounterPokemon()
	{
		//�����ʹL�~��P�_���S���J��
		//�Ҧp�@���d�b�̥��䪺��� �ƨg��a������ �]�O���|�J�Ī�
		if (moved)
		{
			//���P�_���S���J�� �̦Ublock�������J�Ī����v
			if (block_array[player_position.y][player_position.x]->IsEncounter())
			{
				//�i�J�԰�
				//�i�J�԰����ǳ�
				Interface_Pokemon *encountered_pokemon = block_array[player_position.y][player_position.x]->GetEncounteredPokemon();
				//�^�ǾD�J�쪺Pokemon��GameManager
				//��GameManager����o��Pokemon��
				//�K�|������԰����� �ϥ�BattleSceneManager
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