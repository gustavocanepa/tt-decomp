#include "types.h"

extern char D_004F5140[];
extern "C" s32 func_004F6148(s32 arg0, char *arg1);

extern "C" s32 func_004F5478(s32 arg0) {
    return func_004F6148(arg0, D_004F5140);
}
