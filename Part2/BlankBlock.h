#ifndef BLANKBLOCK
#define BLANKBLOCK
#include<iostream>
#include"Block.h"  //因為要繼承class Interface_Block 必須引入定義class Interface_Block的標頭檔
#include"Pokemon.h"
using namespace std;

//空白地板，沒有功能只能移動

//空白地板會顯示"■"

class BlankBlock : public Interface_Block
{
public:
	
	
};

#endif 