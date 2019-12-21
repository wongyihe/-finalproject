#include <iostream>
#include "GameManager.h" 
using namespace std;


void main()
{
	GameManager gm;

	//先畫一次不然一開始是全黑的畫面
	gm.Draw();

	//無窮迴圈
	while (true)
	{
		//讓GameManager處理使用者輸入
		gm.HandleInput();
		
		//刷新畫面
		gm.Draw();
	}
}