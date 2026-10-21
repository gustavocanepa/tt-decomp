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

struct VEntry_60 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline s32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x60);
    return e->fn(o + e->delta);
}
extern char D_005E11E8[];
extern "C" void func_00128470(void *);
extern "C" s32 func_004A8268(s32, void *);
extern "C" s32 func_001324D8(s32);
extern "C" s32 func_004081A8(s32, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_00128418(void *, s32);

extern "C" void func_00138168(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        v_s0 = 0;
        func_00128470(buf0);
        if (*(s32 *)(char *)arg3 != 0) {
            v_s0 = vcall_60((char *)(*(s32 *)(char *)arg3));
            if (func_004A8268(v_s0, &D_005E11E8) == 0) {
                v_s0 = 0;
            }
        }
        t1 = func_004081A8(func_001324D8(buf0[0]), v_s0);
        p_s1 = buf1;
        func_0029EA18(p_s1, t1 != 0);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(p_s1, 0x2);
        func_00128418(buf0, 0x2);
    }
}
