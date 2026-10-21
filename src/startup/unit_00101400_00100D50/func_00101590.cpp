#include "types.h"

extern "C" void func_00101568(s32 (*arg0)(void));
extern "C" void func_004A59F0(void);
extern "C" s32 func_004D2350(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern s32 D_00578EF8;
extern char D_004E02B0[];
extern char D_0010ADF8[];
extern char D_0010AE18[];
extern char D_0010AE38[];
extern char D_0010AE48[];
extern char D_0010AE88[];
extern char D_0010AE98[];
extern char D_0010AEE8[];

extern "C" void func_00101590(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (D_00578EF8 == 0) {
        D_00578EF8 = 1;
        while (func_004D2350(arg0, arg1, arg2, arg3) < 0) {
            func_004A59F0();
        }
        func_00101568((s32 (*)(void))D_004E02B0);
        func_00101568((s32 (*)(void))D_0010AE38);
        func_00101568((s32 (*)(void))D_0010AE48);
        func_00101568((s32 (*)(void))D_0010AE88);
        func_00101568((s32 (*)(void))D_0010AE98);
        func_00101568((s32 (*)(void))D_0010ADF8);
        func_00101568((s32 (*)(void))D_0010AE18);
        func_00101568((s32 (*)(void))D_0010AEE8);
    }
}
