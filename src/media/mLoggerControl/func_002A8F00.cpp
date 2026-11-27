#include "types.h"

extern char D_0057C628[];

extern "C" void func_002A8CF8(s32 arg0, void *arg1, void *arg2);

extern "C" void func_002A8F00(void *arg0, void *arg1, s32 *arg2) {
    func_002A8CF8(*arg2, arg1, D_0057C628);
}
