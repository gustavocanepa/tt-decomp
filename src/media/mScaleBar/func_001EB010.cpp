typedef int s32;
typedef short s16;
typedef float f32;

struct VEntry_60 { s16 delta; s16 index; f32 (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}

extern "C" void func_001E9E98(void *arg0, void *arg1);
extern "C" f32 func_001EC190(s32 arg0);
extern "C" s32 func_001EC280(s32 arg0, f32 fparg0);
extern "C" void func_001E9E40(void *arg0, int arg1);

extern "C" void func_001EB010(s32 arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    f32 f;
    func_001E9E98(buf0, arg1);
    f = func_001EC190(buf0[0]);
    if (arg2 > 0) {
        f = vcall_60((char *)(*(s32 *)(char *)arg3));
    }
    func_001EC280(buf0[0], f);
    func_001E9E40(buf0, 2);
}
