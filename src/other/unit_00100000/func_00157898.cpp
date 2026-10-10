typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_00156538(void *);
extern "C" void func_001564E0(void *, s32);
extern "C" void func_001563C8(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00151A90(void *, s32);

extern "C" void func_00157898(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    func_00156538(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x24);
    func_001564E0(buf0, 0x2);
    if (v_s0 != 0) {
        func_001563C8(buf0, v_s0);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_00151A90(buf0, 0x2);
    }
}
