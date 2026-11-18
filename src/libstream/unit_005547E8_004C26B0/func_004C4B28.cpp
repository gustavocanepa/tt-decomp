#include "types.h"

extern void func_004C8220(s32);

extern "C" void func_004C4B28(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        func_004C8220(temp_v0);
    }
}
