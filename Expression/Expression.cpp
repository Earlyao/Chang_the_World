// Expression.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "expFactory.h"

int main()
{
	Exp *consty = new Const(10);
	Exp *id = new Iden("Identify");
	Exp *assigen = new Assign(id, consty);
    return 0;
}

