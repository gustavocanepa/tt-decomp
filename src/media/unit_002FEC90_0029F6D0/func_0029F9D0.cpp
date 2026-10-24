#include "types.h"

extern "C" void func_0029F9A8(void *arg0, u8 arg1);

extern "C" void func_0029F9D0(void *arg0, u16 arg1) {
    func_0029F9A8(arg0, arg1 & 0xFF);
    func_0029F9A8(arg0, arg1 >> 8);
}
