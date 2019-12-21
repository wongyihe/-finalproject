#ifndef IBLOCK
#define IBLOCK
#include"PlayerInfo.h"
#include"Pokemon.h"

//��wBlock���� 
class Interface_Block  
{
public:
	//Draw�禡�|�M�w�o���a�O���ӵe�X����
	//�p�ťզa�O�O"��"
	//��a�O"��"

	//�ѩ�O��H�禡(abstract function)�A�A�����n��½(override)��
	virtual void Draw()=0;

	//�ˬd�O�_�D�J���_�_��
	//�p�G�D�J���_�_�����ܷ|�^��true�A�Ϥ�false

	//�ä��O�C��Block���|�J�ĳ�

	//�w�]�O�^��false�A�Y���Q�γo��virtual function�i�H��½(override)��
	virtual bool IsEncounter()
	{
		return false;
	}

	//���o�D�J�����_�_��

	//�p�G�J�Ī��ܤ~�|�ϥγo�Ө禡

	//�w�]�O�^��nullptr�A�Y���Q�γo��virtual function�i�H��½(override)��
	virtual Interface_Pokemon* GetEncounteredPokemon()
	{
		//�w�]�^��null pointer �Ū�����
		return nullptr;
	};

	//�v�����a�����_�_��

	//�ä��O�C��Block���|�v�����a�����_�_��

	//�w�]�O�Ũ禡(���򳣤��@)�A�Y���Q�γo��virtual function�i�H��½(override)��
	virtual void Heal(PlayerInfo *p)
	{
	}


	
};

#endif