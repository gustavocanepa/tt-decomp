#include "types.h"
extern "C" char D_0057C5D0[];

extern "C" void func_002A2BE8(s32 *buf, void *src);
extern "C" void func_002C0FE8(s32 obj);
extern "C" void func_002C1050(s32 obj);
extern "C" void func_002A2770(s32 *buf, s32 flags);

extern "C" void func_002A3410(s32 *ret)
{
    s32 buf[4];

    func_002A2BE8(buf, D_0057C5D0);
    if (ret != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_002C0FE8(obj);
        s32 old = *ret;
        if (old != 0)
            func_002C1050(old);
        *ret = obj;
    }
    func_002A2770(buf, 2);
}
