#include "types.h"

extern "C" s32 func_002A7590(void *arg0, s32 arg1);
extern "C" void *func_002BC190(void *arg0);
extern char D_005C5CC8[];

struct func_002AD7D8_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" s32 func_002AD7D8(void *arg0, s32 arg1, s32 arg2) {
    func_002BC190(arg0);
    ((struct func_002AD7D8_arg0 *)arg0)->unk4 = D_005C5CC8;
    return func_002A7590((char *)arg0 + 0xC, arg2);
}
