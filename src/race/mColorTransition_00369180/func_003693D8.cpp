#include "types.h"

extern void *D_005A91E8;
extern void *D_005D1548;
extern "C" void func_003695A8(void *, s32);
extern "C" void func_00347028(void *, s32);
extern "C" void func_00343338(void *, s32);
extern "C" void func_003690E8(void *, s32);
extern "C" void RaceLapTime__structor_1(void *, s32);
extern "C" void func_0050E1A8(void *);

struct func_003693D8_arg0 {
    char pad0[0x4850];
    void *unk4850;
    char pad4854[0xD64];
    void *unk55B8;
};

extern "C" void func_003693D8(void *arg0, s32 arg1) {
    ((struct func_003693D8_arg0 *)arg0)->unk55B8 = &D_005D1548;
    func_003695A8(arg0, 0x1);
    func_00347028((char *)arg0 + 0x48C0, 0x2);
    ((struct func_003693D8_arg0 *)arg0)->unk4850 = &D_005A91E8;
    func_00343338((char *)arg0 + 0x12C0, 0x2);
    func_003690E8((char *)arg0 + 0xFD8, 0x2);
    RaceLapTime__structor_1((char *)arg0 + 0x20, 0x2);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
