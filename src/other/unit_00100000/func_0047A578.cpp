struct A { int w[4]; };
struct B { int w[4]; };
struct Obj { char pad[0xC4]; B b; A a; };
extern "C" void *func_0047C330(A *a);
extern "C" void *func_0047BF70(B *b);
extern "C" void func_004A45D0(void *p);
extern "C" void func_00481030(Obj *self);

extern "C" void func_0047A578(Obj *self)
{
    B *pb = &self->b; func_004A45D0(func_0047C330(&self->a)); func_004A45D0(func_0047BF70(pb)); func_00481030(self);
}
