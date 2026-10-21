typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Units;
extern char D_005865D0[];

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}

extern "C" f32 func_004394E8(Units *self, f32 ps);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void func_00189270(s32 *arg0, s32 arg1, void **arg2) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    if (arg1 > 0) {
        f32 r = func_004394E8((Units *)D_005865D0, vcall_60((char *)(*(s32 *)arg2)));
        s32 t = (s32)(r + 0x1.0p-1f);
        func_0029EA18(buf0, (void *)t);
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
