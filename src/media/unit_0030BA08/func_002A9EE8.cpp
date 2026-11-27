#include "types.h"
typedef void (*FnVoid)(void);

extern "C" void func_002A9EE0(void);

extern FnVoid D_0057C42C;

extern "C" void func_002A9EE8(s32 arg0) {
    if (arg0 != 0) {
        D_0057C42C = (FnVoid)arg0;
        return;
    }
    D_0057C42C = func_002A9EE0;
}
