struct S{char pad[296];int*p;char pad2[8];void*q;};extern "C" int func_003BD8D0(int*),func_003BD8E0(int*),func_003BD8F0(int*);extern "C" void func_003BE148(void*,float,float,float*,float*,float*);
extern "C" void func_003BE278(S*s,float a,float b){int x=func_003BD8D0(s->p);int y=func_003BD8E0(s->p);int z=func_003BD8F0(s->p);func_003BE148(s->q,a,b,(float*)x,(float*)y,(float*)z);}
