#pragma once
#include"iostream"
#include "expTrans.h"
#include"vector"
using namespace std;
class Exp
{
public:
	Exp();
	~Exp();
	Exp *Accept(expTrans &t);
	virtual void Add(Exp*);
};
class Iden :public Exp {
	string name;
	string text;
public:
	Iden();
	~Iden();
	Iden(char *nm);
	Exp *Accept(expTrans &t);
};
class Const : public Exp {
	int val;
public :
	Const(int);
	Exp  *Accept(expTrans &t) {
		return t.VisitConst(val);
	}

};
class Assign : public Exp {	// 赋值语句
	Exp *var;
	Exp *expr;
	Iden *id;
	Exp* exp;
public:
	Assign(Exp *v, Exp *ex);
	Exp  *Accept(expTrans &t) {
		return  t.VisitAssign(id, exp);
	}

};
class Call : public Exp {	// 函数调用
	string func; 
	vector<Exp*> args;
public:
	Call(char *fn);
	void Add(Exp *arg);
	Exp *Accept(expTrans &t);
};
