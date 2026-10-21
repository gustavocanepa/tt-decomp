typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern "C" void func_00227D20(void *, s32);
extern "C" void func_00227D78(void *, void *);
extern "C" void func_00299AB0(void *, s32);
extern "C" void func_0029B380(void *, f32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

struct VEntry_1C8 { s16 delta; s16 index; f32 (*fn)(void *, s32); };
struct VObj_1C8 { char pad0[4]; VEntry_1C8 *vtbl; };
static inline f32 vcall_1c8(char *o, s32 a) {
    VEntry_1C8 *e = (VEntry_1C8 *)((char *)((VObj_1C8 *)o)->vtbl + 0x290);
    return e->fn(o + e->delta, a);
}

extern "C" void func_002280F8(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s3;
    s32 var_s0;
    s32 newVal;
    s32 oldVal;
    f32 fv;
    func_00227D78(buf0, arg1);
    var_s0 = -1;
    if (arg2 > 0) {
        p_s3 = buf1;
        func_0029CF48(p_s3, arg3);
        var_s0 = func_0029E9F0(p_s3[0]);
        func_0029CEF0(p_s3, 0x2);
    } else {
        p_s3 = buf1;
    }
    fv = vcall_1c8((char *)buf0[0], var_s0);
    func_0029B380(p_s3, fv);
    if (arg0 != p_s3) {
        newVal = *p_s3;
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_00299AB0(p_s3, 0x2);
    func_00227D20(buf0, 0x2);
}
