#include "types.h"

extern "C" void func_0028C8B8(void *buf);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_0028C268(void *buf, s32 arg1);

extern "C" void func_0028C448(s32 *arg0) {
    s32 buf[4];

    func_0028C8B8(buf);
    if (arg0 != buf) {
        s32 s0 = buf[0];
        if (s0 != 0) {
            func_002C0FE8(s0);
        }
        s32 temp_v0 = *arg0;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        *arg0 = s0;
    }
    func_0028C268(buf, 2);
}
