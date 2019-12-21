#ifndef IBLOCK
#define IBLOCK
#include"PlayerInfo.h"
#include"Pokemon.h"

//�ƶ�Block���� 
class Interface_Block  
{
public:
	//Draw��ʽ���Q���@�K�ذ呪ԓ����ʲ�N
	//��հ׵ذ���"��"
	//�ݵ���"��"

	//����ǳ���ʽ(abstract function)������Ҫ�Ʒ�(override)��
	virtual void Draw()=0;

	//�z���Ƿ��������挚ؐ
	//����������挚ؐ��Ԓ���؂�true����֮false

	//�K����ÿ�NBlock���������

	//�A�O�ǻ؂�false�����������@��virtual function�����Ʒ�(override)��
	virtual bool IsEncounter()
	{
		return false;
	}

	//ȡ�����������挚ؐ

	//���������Ԓ�ŕ�ʹ���@����ʽ

	//�A�O�ǻ؂�nullptr�����������@��virtual function�����Ʒ�(override)��
	virtual Interface_Pokemon* GetEncounteredPokemon()
	{
		//�A�O�؂�null pointer �յ�ָ��
		return nullptr;
	};

	//�ί���ҵ����挚ؐ

	//�K����ÿ�NBlock�����ί���ҵ����挚ؐ

	//�A�O�ǿպ�ʽ(ʲ�N������)�����������@��virtual function�����Ʒ�(override)��
	virtual void Heal(PlayerInfo *p)
	{
	}


	
};

#endif