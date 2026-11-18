#include "types.h"
s32 func_004A81B8(char *a, char *b, u32 c);
s32 func_004152D8(char *arg0, u32 arg1, char *arg2, u32 arg3) {
    if (arg1 != arg3) return 0;
    return func_004A81B8(arg0, arg2, arg1) == 0;
}
