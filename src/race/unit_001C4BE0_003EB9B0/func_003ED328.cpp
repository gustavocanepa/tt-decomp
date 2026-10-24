#include "types.h"

struct Obj {
    char pad[0xA8];
    s32 unkA8;
    s32 unkAC;
};

extern "C" void func_003EBD70(void *arg0);
extern "C" void func_003EBFB0(void *arg0);

extern "C" void func_003ED328(Obj *arg0) {
    s32 v0 = arg0->unkAC;
    s32 v1 = arg0->unkA8;
    arg0->unkA8 = v0;
    arg0->unkAC = v1;
    func_003EBD70((char *)arg0 + v0 * 0x54);

    s32 v0b = arg0->unkAC;
    func_003EBFB0((char *)arg0 + v0b * 0x54);
}
