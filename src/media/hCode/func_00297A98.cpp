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

extern "C" void func_002B2030(void *);
extern "C" void func_00297910(void *, void *);
extern "C" void func_002A7A30(void *);
extern "C" void hThread__execCode(void *, s32, void *, void *, s32, void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002978B8(void *, s32);
extern "C" void func_002B1578(void *, s32);

extern "C" void func_00297A98(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 *p_s6;
    s32 *p_s5;
    s32 v_s0;
    s32 *p_s4;
    s32 newVal;
    s32 oldVal;
    func_002B2030(buf0);
    p_s6 = buf1;
    func_00297910(p_s6, arg1);
    p_s5 = buf3;
    v_s0 = buf0[0];
    p_s4 = buf2;
    func_002A7A30(p_s5);
    hThread__execCode(p_s4, v_s0, p_s6, p_s5, arg2, arg3);
    if (arg0 != p_s4) {
        newVal = *p_s4;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_002A75A8(p_s4, 0x2);
    func_002A75A8(p_s5, 0x2);
    func_002978B8(p_s6, 0x2);
    func_002B1578(buf0, 0x2);
}
