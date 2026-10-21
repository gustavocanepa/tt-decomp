typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct VEntryF {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObjF {
    char pad0[4];
    char *vtbl;
};

static inline f32 vcallf(VObjF *o) {
    VEntryF *e = (VEntryF *)(o->vtbl + 0x70);
    return e->fn((char *)o + e->delta);
}

extern "C" void func_002027E0(void *arg0, void *arg1);
extern "C" void func_00202788(void *arg0, int arg1);
extern "C" s32 func_00206CF0(s32 arg0, f32 fparg0, f32 fparg1);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_00204130(s32 *arg0, void *arg1, s32 arg2, VObjF **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s0;
    f32 f20;
    s32 *p_s1;
    s32 r;
    s32 newVal;
    s32 oldVal;
    if (arg2 >= 0x2) {
        func_002027E0(buf0, arg1);
        v_s0 = buf0[0];
        f20 = vcallf(arg3[0]);
        r = func_00206CF0(v_s0, f20, vcallf(arg3[1]));
        p_s1 = buf1;
        func_0029EA18(p_s1, (void *)(s32)(r != 0));
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
        func_00202788(buf0, 0x2);
    }
}
