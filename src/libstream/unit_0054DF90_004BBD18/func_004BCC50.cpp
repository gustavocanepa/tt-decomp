#include "types.h"

struct S_0054EEB8 {
    char pad[0x3E8];
    void *p3E8;
};

extern "C" s32 func_004BD7E8(void *);
extern "C" s32 func_004BD7F0(void *);
extern "C" s32 D_00598410;

extern "C" s32 func_004BCC50(struct S_0054EEB8 *arg0, s32 *arg1, s32 *arg2) {
    if (D_00598410 == 0) {
        return 1;
    }
    if (arg1 != 0) {
        *arg1 = func_004BD7E8(arg0->p3E8);
    }
    if (arg2 != 0) {
        *arg2 = func_004BD7F0(arg0->p3E8);
    }
    return 0;
}
