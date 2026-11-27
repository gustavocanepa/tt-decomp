#include "types.h"

struct S {
    void *unk0;
    s32 unk4;
};

extern "C" void func_00422818(S *arg0, s32 arg1);

extern S D_00768E10;
extern char D_005D5D88;

extern "C" void func_0039D1D8(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            D_00768E10.unk4 = 0;
            D_00768E10.unk0 = &D_005D5D88;
        }
        if (arg0 == 0) {
            D_00768E10.unk0 = &D_005D5D88;
            func_00422818(&D_00768E10, 0);
        }
    }
}
