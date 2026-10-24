#include "types.h"

struct Frame {
    char obj[0xD0];
    s32 d0;
    s32 d4;
    s32 d8;
    s32 dc;
    char tail[0x150 - 0xE0];
};

extern "C" void func_0047F748(void *self);
extern "C" s32 func_0047F340(void *self, void *arg);
extern "C" void func_0047F780(void *self, s32 mode);
extern "C" s32 func_0047F7F8(void *self, void *name, s32 mode);
extern "C" s32 func_0047F880(void *self);
extern "C" void func_004F7B74(void *a, void *b);

extern "C" s32 func_004BC018(void *arg0, void *arg1, s32 *arg2, s32 *arg3, void *arg4) {
    struct Frame f;
    s32 var_s0;

    func_0047F748(&f);
    var_s0 = 0;
    if (func_0047F7F8(&f, arg1, 3) >= 0) {
        f.d0 = 0;
        var_s0 = func_0047F340(&f, &f.d0) != 0;
        func_0047F880(&f);
        *arg2 = f.d4;
        *arg3 = f.d8;
        func_004F7B74(arg4, &f.dc);
    }
    func_0047F780(&f, 2);
    return var_s0;
}
