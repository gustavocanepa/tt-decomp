/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x100]; char m[0x84]; float x,y,z,scale; };
extern "C" void func_0046E150();
extern "C" void func_0046E1B0();
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" void func_004751FC();
extern "C" void func_004752F8(void *);
extern "C" void func_004755EC(float,float,float);
extern "C" void func_00475638(float,float,float);
extern "C" void func_00475730(float);
extern "C" int func_0032DBD8(Obj *p) {
 float one=1.0f;
 float s=p->scale;
 func_0046E150();
 func_00473050();
 func_004751FC();
 func_00475638(s,s,one);
 func_00475730(90.0f);
 func_004755EC(-p->x,-p->y,-p->z);
 func_00475638(one,0.0f,one);
 func_004752F8(p->m);
 func_004730A8();
 func_0046E1B0();
 return 1;
}
