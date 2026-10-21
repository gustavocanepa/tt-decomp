typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

extern "C" void func_00187170(void *arg0, void *arg1);
extern "C" void func_00187118(void *arg0, s32 arg1);

extern "C" void func_001876D8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s0;
    if (arg2 > 0) {
        func_00187170(buf0, arg1);
        v_s0 = buf0[0];
        *(s32 *)((char *)v_s0 + 0x1F70) = vcall_58((char *)(*(s32 *)(char *)arg3)) != 0;
        func_00187118(buf0, 0x2);
    }
}
