#pragma once
#include"Exp.h"
class expFactory
{
public:
	expFactory();
	~expFactory();
	Exp *CreateIden(char *id) {
		return new Iden(id);
	}
	Exp *CreateConst(int val) {
		return  new Const(val);
	}
	Exp *CreateAssign(Exp *var, Exp *ex) {
		return  new Assign(var, ex);
	}
	Exp *CreateCall(char *fun) {
		return new Call(fun);
	}

};