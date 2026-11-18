#include "types.h"

struct Obj {
    char pad0[0x78];
    s32 unk78;
};

extern "C" s32 func_001058A0(char *arg0) {
    arg0 = arg0 + 0xC0;
    arg0 = arg0 + (((Obj *)arg0)->unk78 * 0x3C);
    return *(s32 *)(arg0 + 0x8);
}
