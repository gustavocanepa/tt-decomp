typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

extern "C" void func_001FCB58(void *arg0, void *arg1);
extern "C" s32 func_00200048(s32 arg0, s32 arg1);
extern "C" s32 func_001DF1C8(s32 *arg0, s32 *arg1);
extern "C" void func_001DF1F8(void *arg0, int arg1);
extern "C" void func_001FCB00(void *arg0, int arg1);
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);

extern "C" void func_001FD190(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 sp20[4];
    s32 *p20;
    s32 v_s0;
    s32 *p_s1;
    s32 r;
    s32 newVal;
    s32 oldVal;
    if (arg2 == 0x1) {
        func_001FCB58(buf0, arg1);
        v_s0 = buf0[0];
        p20 = sp20;
        r = func_00200048(v_s0, vcall_58((char *)*(s32 *)arg3));
        p_s1 = buf1;
        sp20[0] = r;
        func_001DF1C8(p_s1, p20);
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
        func_001DF1F8(p_s1, 0x2);
        func_001FCB00(buf0, 0x2);
    }
}
