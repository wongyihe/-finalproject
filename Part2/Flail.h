#ifndef FLAIL
#define FLAIL

#include"Skill.h"
#include"Pokemon.h"

//手足慌亂
class Flail :public Interface_Skill
{
private:
	//你可能會需要一些變數來存東西
	Interface_Pokemon *pokemon;
public:
	//請注意必須傳入使用這招的神奇寶貝

	//因為它的威力(power)是隨使用這招的神奇寶貝所剩餘的hp百分比計算
	Flail(Interface_Pokemon *pokemon)
	{
		
	}
	float GetPower()
	{
		//記得要將int轉型成float
		//因為在int的除法裡   3/4是0
		
		//如果你忘了怎麼轉型可以參考動態記憶體配置 malloc 的投影片

		
	}
};

#endif