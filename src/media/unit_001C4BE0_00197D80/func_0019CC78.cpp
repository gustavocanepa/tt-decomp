#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_0019BD98();
s32 func_004E5700(void *, s32, s32);
struct func_0019CC78_arg0 {
    char pad0[0xC];
    s8 unkC;
};

s8 func_0019CC78(struct func_0019CC78_arg0 *arg0) {
    if (func_004E5700(arg0, func_0019BD98(), 0xC) == 0) {
        return arg0->unkC;
    }
    return 0;
}

}
