#ifndef PLAYERBLOCK
#define PLAYERBLOCK
#include<iostream>
#include"Block.h"  //因為要繼承class Interface_Block 必須引入定義class Interface_Block的標頭檔
using namespace std;

//玩家地板，只是顯示玩家位置用 

//在玩家位置會顯示"P "
class PlayerBlock : public Interface_Block
{
	public:
		

};

#endif 