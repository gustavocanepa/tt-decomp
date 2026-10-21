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

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

extern "C" void func_00120608(void *arg0, void *arg1);
extern "C" void func_001205B0(void *arg0, s32 arg1);
extern "C" s32 func_003F6DC0(s32 arg0);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);
extern "C" void func_0029CEF0(void *arg0, s32 arg1);

extern "C" void func_00120A70(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s1;
    s32 newVal;
    s32 oldVal;
    func_00120608(buf0, arg1);
    v_s1 = *(s32 *)((char *)buf0[0] + 0x10);
    func_001205B0(buf0, 0x2);
    v_s1 = func_003F6DC0(v_s1);
    if (arg2 > 0) {
        v_s1 = v_s1 % vcall_58(arg3[0]);
    }
    func_0029EA18(buf0, v_s1);
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
