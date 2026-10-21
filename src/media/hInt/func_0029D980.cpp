typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct RefCounter;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

extern "C" void func_0029CEF0(void *arg0, s32 arg1);
extern "C" void func_0029EA18(void *arg0, void *arg1);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);

extern "C" void func_0029D980(void *arg0, s32 *arg1, void *arg2, void *arg3, void **arg4) {
    s32 buf0[4];
    s32 newVal;
    s32 oldVal;
    s32 flag = 0;

    if (*(s32 *)((char *)arg0 + 0x10) != 0) {
        flag = vcall_58((char *)*arg4) != 0;
    }
    func_0029EA18(buf0, (void *)flag);
    if (arg1 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *arg1;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *arg1 = newVal;
    }
    func_0029CEF0(buf0, 0x2);
}
