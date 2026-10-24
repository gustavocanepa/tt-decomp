struct Camera { virtual void dummy(); virtual void first(float); virtual void second(float); };
struct S { char pad[0x64]; char *vt; };
struct REntry { short delta,index; Camera *(*fn)(void *); };
extern "C" int func_002C9998(void *) throw();
extern "C" int func_002D3410(int,float);
extern "C" void func_00473178(int);
extern "C" void func_00473050();
extern "C" void func_004730A8();
extern "C" void func_004751FC();
extern "C" int func_002C9C00(S *s) {
 float z=0.0f;
 REntry *r=(REntry *)(s->vt+0x4E8);
 Camera *p=r->fn((char *)s+r->delta);
 func_00473178(1);
 func_00473050();
 func_004751FC();
 p->first(z);
 func_00473178(0);
 func_00473050();
 func_004751FC();
 p->second(z);
 int ret=func_002D3410(func_002C9998(s),z);
 func_004730A8();
 func_00473178(1);
 func_004730A8();
 func_00473178(0);
 return ret;
}
