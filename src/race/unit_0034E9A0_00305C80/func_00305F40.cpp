#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" s32 func_002F04D8(void);
extern "C" void func_003053E8(s32, void *, s32);

struct func_00305F40_arg0 {
    char pad0[0x20A24];
    u8 unk20A24;
};

extern "C" void func_00305F40(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    if (((struct func_00305F40_arg0 *)arg0)->unk20A24 == 0) {
        if (*(u8 *)((char *)(func_002F04D8()) + 0x5D7) == 0) {
            if (*(s32 *)((char *)((*(s32 *)(char *)arg0 + (arg2 << 2))) + 0x928) != 0x157529ff) {
                func_003053E8(*(s32 *)(char *)arg0, arg1, ((s32)arg3 - *(s32 *)((char *)((*(s32 *)(char *)arg0 + (arg2 << 2))) + 0x928)));
            }
        }
    }
}
