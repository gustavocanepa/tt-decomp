struct S{int a,state;char data[4];};
extern "C" char*func_002E8530(void*,char*),*func_002E8CC0(S*,char*);
extern "C" void func_002E88B0(S*,int);
extern "C" char*AutomobileControlRecord__Manager__load(S*s,char*p,int all){int n=*(int*)p;p+=4;if(!n){s->state=0;return func_002E8530(s->data,p);}if(all){int i=0;s->state=1;while(i<n){func_002E88B0(s,i++);p=func_002E8CC0(s,p);}}else{s->state=2;func_002E88B0(s,0);p=func_002E8CC0(s,p);}return p;}
