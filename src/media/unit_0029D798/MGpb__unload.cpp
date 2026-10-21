#include "types.h"

struct Buf0029D998 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_0023DD50(struct Buf0029D998 *arg0);
extern "C" void func_0023E598(s32 arg0);
extern "C" void func_0023DCF8(struct Buf0029D998 *arg0, int arg1);

extern "C" void MGpb__unload(s32 arg0, s32 arg1, s32 arg2) {
    struct Buf0029D998 buf;

    if (arg2 > 0) {
        func_0023DD50(&buf);
        func_0023E598((s32)buf.unk0);
        func_0023DCF8(&buf, 2);
    }
}
