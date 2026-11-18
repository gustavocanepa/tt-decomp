#include "types.h"

extern "C" void func_00216FD8(s32 *buf, s32 a, s32 b);
extern "C" void func_002C0FE8(s32 obj);
extern "C" void func_002C1050(s32 obj);
extern "C" void func_00216BB0(s32 *buf, s32 flags);

extern "C" void func_00216CE0(s32 *ret)
{
    s32 buf[4];

    func_00216FD8(buf, 0, 0);
    if (ret != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_002C0FE8(obj);
        s32 old = *ret;
        if (old != 0)
            func_002C1050(old);
        *ret = obj;
    }
    func_00216BB0(buf, 2);
}
