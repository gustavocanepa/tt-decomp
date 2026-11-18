#include "types.h"

struct Obj {
    char pad[0x20A26];
    u8 state;
};

extern "C" void func_0030E6F8(int x);
extern "C" int func_002F04D8(Obj *o, int i);

extern "C" void func_0030E7B8(Obj *o, int a, int n)
{
    if (o->state != 2) {
        for (int i = a; i < n; i++)
            func_0030E6F8(func_002F04D8(o, i));
    }
}
