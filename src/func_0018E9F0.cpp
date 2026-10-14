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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}
extern "C" void func_0016E838(void *, void *);
extern "C" void func_0018ACD8(void *, void *);
extern "C" void func_0018AC80(void *, s32);
extern "C" void func_001AF248(s32, s32, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0016E7E0(void *, s32);

extern "C" void func_0018E9F0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s1;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 0x2) {
        func_0016E838(buf0, (char *)arg3 + 0x4);
        p_s1 = buf1;
        func_0018ACD8(p_s1, arg1);
        v_s0 = *p_s1;
        v_s0 = v_s0 + 0x2A0;
        func_001AF248(v_s0, vcall_58((char *)(*(s32 *)(char *)arg3)), buf0[0] + 0x10);
        func_0018AC80(p_s1, 0x2);
        func_0029EA18(p_s1, 0x1);
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
        func_0016E7E0(buf0, 0x2);
    } else {
        func_0029EA18(buf0, 0);
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
        func_0029CEF0(buf0, 0x2);
    }
}
