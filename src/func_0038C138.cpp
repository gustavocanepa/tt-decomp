/* compiler: ee-gcc2.96-no-strict-aliasing */
struct View { int words[15]; };
struct Global { View views[2]; int current; };
extern Global D_005795B0;
extern "C" void func_00104D10(void *);
extern "C" void func_00104C88(void *);
extern "C" void func_00472268(int,int);
extern "C" void func_00478C98(int);
extern "C" int func_00474BC8(float);
extern "C" void func_00477E30(float,float,float,float);
extern "C" void func_00474288(int,int,int,int,int,int,int,int);
static inline View *current(Global *g) { return &g->views[g->current]; }
extern "C" void func_0038C138(void *o,void *p) {
 func_00104D10(current(&D_005795B0));
 func_00104C88(p);
 func_00472268(3,0);
 func_00472268(2,0);
 func_00478C98(4);
 func_00478C98(6);
 func_00478C98(5);
 func_00474BC8(0.0f);
 func_00477E30(1.0f,1.0f,1.0f,1.0f);
 func_00474288(0,0,640,448,0,0,640,448);
}
