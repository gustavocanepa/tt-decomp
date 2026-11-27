#include "types.h"

extern "C" void func_00318840(void);
extern "C" void func_00318888(void);

extern "C" void func_003188A0(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        return func_00318840();
    }
    return func_00318888();
}
