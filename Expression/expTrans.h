#pragma once
#include"Exp.h"
class expTrans
{
public:
	expTrans();
	~expTrans();
	vector <Exp*>  asgns;
	Exp *VisitConst(int c) {
		return new Const(c);
	}
	Exp *VisitIden(char *t) {
		return new Iden(t);
	}
	Exp  *VisitAssign(Iden *id, Exp *e) {
		Exp *a = e->Accept(this->VisitAssign);
		asgns.push_back(new Assign(id, a));
		return	 new Iden(*id);
	}
	Exp *VisitCall(char* fn, vector<Exp*> &es) {
		Exp *q = new Call(fn);
		vector <Exp*>::iterator it;
		for (it = es.begin(); it != es.end(); it++) {
			q->Add((*it)->Accept(this->VisitCall));
			return  q;
		}
	}
};

