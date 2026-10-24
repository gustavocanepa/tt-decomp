#include "types.h"

struct RefCounter;

struct func_002B4DC8_arg0 {
    char pad0[0x8];
    void *unk8;
};

struct func_002B4DC8_sub {
    char pad0[0x8];
    s32 *arr;
    char pad1[0x8];
    s32 cnt;
};

struct func_002B4DC8_arg1 {
    char pad0[0x2C];
    struct func_002B4DC8_sub *sub;
};

extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_002B4DC8(void *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    struct func_002B4DC8_sub *sub;
    s32 *slot;

    func_0029EA18(buf0, ((struct func_002B4DC8_arg0 *)arg0)->unk8);
    sub = ((struct func_002B4DC8_arg1 *)arg1)->sub;
    slot = sub->arr + sub->cnt;
    if (slot != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *slot;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *slot = newVal;
    }
    sub->cnt = sub->cnt + 1;
    func_0029CEF0(buf0, 2);
}
