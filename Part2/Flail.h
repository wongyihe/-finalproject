#ifndef FLAIL
#define FLAIL

#include"Skill.h"
#include"Pokemon.h"

//�⨬�W��
class Flail :public Interface_Skill
{
private:
	//�A�i��|�ݭn�@���ܼƨӦs�F��
	Interface_Pokemon *pokemon;
public:
	//�Ъ`�N�����ǤJ�ϥγo�۪����_�_��

	//�]�������¤O(power)�O�H�ϥγo�۪����_�_���ҳѾl��hp�ʤ���p��
	Flail(Interface_Pokemon *pokemon)
	{
		
	}
	float GetPower()
	{
		//�O�o�n�Nint�૬��float
		//�]���bint�����k��   3/4�O0
		
		//�p�G�A�ѤF����૬�i�H�ѦҰʺA�O����t�m malloc ����v��

		
	}
};

#endif