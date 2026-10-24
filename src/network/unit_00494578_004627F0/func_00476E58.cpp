typedef unsigned long U64;struct Pair{U64 a,b;};union S{struct{int a;Pair*p;int n,x,count;}f;U64 wide[3];};
extern "C" int func_00476E58(S*self,U64 a,U64 b){Pair*p=self->f.p+self->f.n;p->b=b;p->a=a;int old=self->f.count;self->f.count=old+1;self->f.n++;return old;}
