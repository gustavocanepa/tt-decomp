extern char D_005B42E0[]; struct T { int a,b; };
struct S { int p,value,data,v; S(T *p) __asm__("func_00216940"); };
S::S(T *arg) { p=(int)arg; v=(int)D_005B42E0; int n=arg->b; data=(int)(arg+1); value=n; }
