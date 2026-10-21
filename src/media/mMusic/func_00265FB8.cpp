typedef int s32;
typedef short s16;

struct VEntry_58 { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}

extern "C" void func_002655D8(void *arg0, void *arg1);
extern "C" void func_00265580(void *arg0, s32 arg1);

extern "C" void func_00265FB8(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 v_s0;
    char *w;
    if (arg2 > 0) {
        func_002655D8(buf0, arg1);
        v_s0 = buf0[0];
        w = (char *)v_s0 + 0x18;
        *(s32 *)(w + 0x4) = vcall_58((char *)(*(s32 *)(char *)arg3)) != 0;
        func_00265580(buf0, 2);
    }
}
