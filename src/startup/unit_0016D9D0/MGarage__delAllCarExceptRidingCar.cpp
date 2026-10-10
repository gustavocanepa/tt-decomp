typedef int s32;

struct Obj { char pad[0x10]; s32 m10; };
struct Guard { Obj *p; s32 pad[3]; };

extern "C" void func_0014D580(Guard *);
extern "C" void func_0014D528(Guard *, s32);
extern "C" void func_003FBC88(s32);

extern "C" void MGarage__delAllCarExceptRidingCar(void) {
    Guard g;
    s32 v;
    func_0014D580(&g);
    v = g.p->m10;
    func_0014D528(&g, 2);
    func_003FBC88(v);
}
