#include "types.h"

extern f32 D_00579EA4;
extern f32 D_00579EA8;

extern "C" void func_00299B08(s32 *buf, s32 arg);
extern "C" f32 func_0029B188(s32 arg0);
extern "C" void func_00299AB0(s32 *buf, s32 arg1);

extern "C" void MMemorycardProgress__setProgress(s32 arg0, s32 argc, s32 argv) {
    if (argc > 0) {
        s32 buf[4];
        func_00299B08(buf, argv);
        D_00579EA4 = D_00579EA8 = func_0029B188(buf[0]);
        func_00299AB0(buf, 2);
    }
}
