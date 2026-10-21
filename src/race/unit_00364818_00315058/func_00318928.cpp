#include "types.h"

extern "C" void func_003188C8(void);
extern "C" void func_00318908(void);

extern "C" void func_00318928(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        return func_003188C8();
    }
    return func_00318908();
}
