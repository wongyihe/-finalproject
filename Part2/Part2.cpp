#include <iostream>
#include "GameManager.h" 
using namespace std;


void main()
{
	GameManager gm;

	//���e�@�����M�@�}�l�O���ª��e��
	gm.Draw();

	//�L�a�j��
	while (true)
	{
		//��GameManager�B�z�ϥΪ̿�J
		gm.HandleInput();
		
		//��s�e��
		gm.Draw();
	}
}