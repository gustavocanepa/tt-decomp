#include "types.h"

extern "C" void func_00487640(void *, s32, s32);
extern "C" void func_00487968(void *, s32);

extern "C" void func_00487A78(void *arg0, s32 arg1) {
    func_00487640(arg0, arg1, 0);
    func_00487968(arg0, arg1);
}
