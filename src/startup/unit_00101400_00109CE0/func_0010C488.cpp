#include "types.h"
struct E { char pad0[0x14]; unsigned char b14; };
struct Obj2 { char pad0[0x70]; void *f70; };
struct Self { char pad0[0x498]; s32 f494; };

extern "C" long func_0040F0F0(void *a0);
extern "C" s32 func_0040F0F8(void *a0);
extern "C" int func_0040FED0(unsigned long key, E *out);

extern "C" void func_0010C488(Self *arg0, Obj2 *arg1) {
    s32 s0 = (func_0040F0F8(arg1->f70) == 0);
    E e;
    func_0040FED0(func_0040F0F0(arg1->f70), &e);
    arg0->f494 = (e.b14 == 0) ? 0 : s0;
}
