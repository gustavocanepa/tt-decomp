struct V { int a,b,c; };struct Comp { unsigned char c; };struct S { V values[1024];int count;Comp comp; };
extern "C" void func_0056A600(S *,V *);
extern "C" void func_0056A648(V *,int,int,V *,Comp);
extern "C" void func_0056B050(S *s,int a,int b) {
 V v={a,b,1};struct { V *first;Comp c0,c1; } state;int spare[4];V tmp0,tmp1;
 func_0056A600(s,&v);
 state.first=s->values;state.c1=s->comp;state.c0=state.c1;
 V *end=s->values+s->count;int length=end-s->values;tmp0=*(end-1);func_0056A648(s->values,length-1,0,&tmp0,state.c1);
 v.c=0;func_0056A600(s,&v);
 V *end2=s->values+s->count;state.first=s->values;state.c0=s->comp;state.c1=state.c0;
 int length2=end2-s->values;tmp1=*(end2-1);func_0056A648(s->values,length2-1,0,&tmp1,state.c0);
}
