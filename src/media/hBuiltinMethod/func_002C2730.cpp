typedef int s32;

struct RefCounter;

struct func_002C2730_self {
    char pad0[0xC];
    void (*fn)(void *, s32, s32, s32);
};

struct func_002C2730_sub {
    char pad0[0x8];
    s32 *arr;
    char pad1[0x8];
    s32 cnt;
};

struct func_002C2730_owner {
    char pad0[0x2C];
    struct func_002C2730_sub *sub;
};

extern "C" void func_002A7A30(void *a0);
extern "C" void func_002A75A8(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_002C2730(void *arg0, void **arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    struct func_002C2730_sub *sub;
    s32 *slot;

    func_002A7A30(buf0);
    ((struct func_002C2730_self *)arg0)->fn(buf0, arg2, arg3, arg4);
    sub = ((struct func_002C2730_owner *)*arg1)->sub;
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
    func_002A75A8(buf0, 2);
}
