#include "types.h"

struct Obj00353EB8;

extern "C" s32 func_002F8688(struct Obj00353EB8 *arg0);

extern "C" void func_00315968(struct Obj00353EB8 *arg0, s32 arg1) {
    *(s8 *)func_002F8688(arg0) = (s8)arg1;
}
