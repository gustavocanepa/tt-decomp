#include "types.h"

extern "C" void func_00318A00(void);
extern "C" void func_00318A40(void);

extern "C" void func_00318A60(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        return func_00318A00();
    }
    return func_00318A40();
}
