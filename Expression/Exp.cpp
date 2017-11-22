#include "stdafx.h"
#include "Exp.h"


Exp::Exp()
{
}


Exp::~Exp()
{
}

void Exp::Add(Exp *)
{
}

Iden::Iden()
{
}

Iden::~Iden()
{
}

Iden::Iden(char * nm)
{
	name = nm;
}

Assign::Assign(Exp * v, Exp * ex)
{
	var = v;
	expr = ex;
}

Exp * Assign::Accept(expTrans & t)
{
	return  t.VisitAssign(id, exp);
}

Call::Call(char * fn)
{
	func = fn;
}

void Call::Add(Exp * arg)
{
	args.push_back(arg);
}

Const::Const(int c)
{
	val = c;
}
