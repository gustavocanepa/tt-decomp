#include "types.h"

struct func_0041A0C8_unk4 {
    char pad0[0xA4];
    s32 unk8C;
};

struct func_0041A0C8_arg0 {
    char pad0[0x4];
    struct func_0041A0C8_unk4 *unk4;
};

extern "C" s32 func_00422858(void);

extern "C" s32 func_0041A0C8(struct func_0041A0C8_arg0 *arg0) {
    s32 value = arg0->unk4->unk8C;
    if (value >= 0) {
        return value;
    }
    return func_00422858();
}
