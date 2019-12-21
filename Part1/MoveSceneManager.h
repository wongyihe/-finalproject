#ifndef MOVESCENEANAGER
#define MOVESCENEANAGER
#include "GrassBlock_UpLeft.h"
#include "GrassBlock_DownRight.h"
#include"BlankBlock.h"
#include"PlayerBlock.h"
#include"RecoverBlock.h"
#include"RedBlock.h"
#include"Vector_2.h"

//�Ƅӈ���������
class MoveSceneManager
{
private:
	//�ö��SInterface_Block��Ё��؈D
	//�@��һ��7x8��pointer array
	//���Interface_Block���ܱ����w�� 

	//혎�һ��Interface_Block block_array[7][8]֮������ǲ��Ϸ���(��һ��*)
	//���Interface_Block��abstract class ���ܱ����w��
	//��Interface_Block block_array[7][8]�s�����w�� 7*8 ��Interface_Block

	//�����ö��͵ķ�ʽ�����FInterface_Block������e
	//�K��������e�Ľ����Interface_Block
	//��Interface_Block *IB = new BlankBlock();
	Interface_Block *block_array[7][8];

	Interface_Block *player_block;

	//�������λ��
	Vector_2 player_position;

	//�������ݔ����Ԫ
	char inputchar;

	//�z���Ƿ��Ƅ��^
	bool moved;
	
public:
	//������
	MoveSceneManager()
	{
		//�A�O�Ǜ]���Ƅ��^�Ġ�B
		moved = false;
		//���µĳ�ʽ�a�Á��ʼ���؈D���
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				//ע���@�e��block_array[i][j]��ָ��Interface_Blocke��pointer��
				//BlankBlock���^��Interface_Block�����Ҳ"��һ��"Interface_Block
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
	//̎��ʹ����ݔ��
	void HandleInput()
	{
		//׌ʹ����ݔ��w s a d
		cout << "Ոݔ��w��s��a��d���Ƅ�" << endl;
		cin >> inputchar;
		
		
		//�Țw�؟o�ƄӵĠ�B
		moved = false;
		//̎���I�Pݔ��

		//���@ֻ��̎�����λ��player_position
		//׌���Sʹ����ݔ�����׃x�cy��ֵ

		//ע��:
		//x��������0����7
		//y��������0����6
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

	//�aѪ��ʽ
	void Heal(PlayerInfo *player)
	{
		//���������վ����Block���aѪ��ʽ

		//�K��������Block�����aѪ
		//��һ��Block�����aѪ����ֻ��Ҫ׌ԓBlock���aѪ��ʽ�ǿպ�ʽ����
		//��{ }
		block_array[player_position.y][player_position.x]->Heal(player);
	}

	//�Ƿ�����Pokemon
	//���������Ԓ���؂�һ��Interface_Pokemon pointer
	//����t�ǻ؂�nullptr
	Interface_Pokemon* EncounterPokemon()
	{
		//���Ƅ��^�����Д��Л]������
		//����һֱ��������߅�Ĳ��e ����a������ Ҳ�ǲ���������
		if (moved)
		{
			//���Д��Л]������ ����block�N��������ęC��
			if (block_array[player_position.y][player_position.x]->IsEncounter())
			{
				//�M����Y
				//�M����Y�Ĝʂ�
				Interface_Pokemon *encountered_pokemon = block_array[player_position.y][player_position.x]->GetEncounteredPokemon();
				//�؂���������Pokemon��GameManager
				//��GameManager�յ��@��Pokemon�r
				//����ГQ�����Y���� ʹ��BattleSceneManager
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