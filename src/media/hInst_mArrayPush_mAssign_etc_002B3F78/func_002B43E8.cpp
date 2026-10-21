typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct func_002B43E8_arg0 {
    char pad0[0x8];
    f32 unk8;
};

struct func_002B43E8_sub {
    char pad0[0x8];
    s32 *arr;
    char pad1[0x8];
    s32 cnt;
};

struct func_002B43E8_arg1 {
    char pad0[0x2C];
    struct func_002B43E8_sub *sub;
};

extern "C" void func_00299AB0(void *arg0, s32 arg1);
extern "C" void func_0029B380(void *arg0, f32 fparg0);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_002B43E8(void *arg0, void *arg1) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    struct func_002B43E8_sub *sub;
    s32 *slot;

    func_0029B380(buf0, ((struct func_002B43E8_arg0 *)arg0)->unk8);
    sub = ((struct func_002B43E8_arg1 *)arg1)->sub;
    slot = sub->arr + sub->cnt;
    if (slot != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *slot;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *slot = newVal;
    }
    sub->cnt = sub->cnt + 1;
    func_00299AB0(buf0, 2);
}
