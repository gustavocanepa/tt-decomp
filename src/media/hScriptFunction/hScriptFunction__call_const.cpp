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
extern "C" void func_002A7A30(void *);
extern "C" void hThread__execCode(void *, s32, void *, void *, s32, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002B1578(void *, s32);

extern "C" void hScriptFunction__call_const(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s6;
    s32 v_s0;
    s32 *p_s5;
    s32 newVal;
    s32 oldVal;
    func_002B2030(buf0);
    p_s6 = buf2;
    v_s0 = buf0[0];
    p_s5 = buf1;
    func_002A7A30(p_s6);
    hThread__execCode(p_s5, v_s0, (char *)arg0 + 0xc, p_s6, arg2, (s32)arg3);
    if ((char *)arg1 != (char *)p_s5) {
        newVal = *p_s5;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *(s32 *)(char *)arg1;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *(s32 *)(char *)arg1 = newVal;
    }
    func_002A75A8(p_s5, 0x2);
    func_002A75A8(p_s6, 0x2);
    func_002B1578(buf0, 0x2);
}
