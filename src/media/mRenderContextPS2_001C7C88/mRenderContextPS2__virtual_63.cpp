#include "types.h"

extern "C" s32 func_001058A0(char *arg0);
extern "C" s32 func_001058C0(char *arg0);
extern "C" char D_005794F0[];

extern "C" void mRenderContextPS2__virtual_63(void *arg0, s32 *arg1, s32 *arg2) {
    char *p = D_005794F0;
    *arg1 = func_001058A0(p);
    *arg2 = func_001058C0(p);
}
