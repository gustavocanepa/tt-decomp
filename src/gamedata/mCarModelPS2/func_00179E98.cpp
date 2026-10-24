#include "types.h"

struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct StateBlock_00156340 { u32 words[50]; };
struct VEntry { short delta, index; void *fn; };
struct Object { char pad[4]; char *vtable; };

extern char D_005E4AA0[];
extern char D_005E4A98[];
extern "C" const char *func_0041A650(void *);
extern "C" s32 func_004E5700(const char *, const char *, s32);
extern "C" s32 func_004A8268(const char *, const char *);
extern "C" void func_0041DB78(const char *, void *, s32);
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4F00(void *);
extern "C" void func_004A4DD8(void *);

static inline const char *str_data(Str *str) {
    Rep *rep = (Rep *)(str->p - 0x10);
    if (rep->len == 0) return D_005E4AA0;
    str->p[rep->len] = 0;
    return str->p;
}

extern "C" s32 func_00179E98(void *arg0, Str *arg1) {
    StateBlock_00156340 state;
    const char *name = str_data(arg1);
    const char *key = (const char *)func_0041A650((char *)arg0 + 0x2DC);
    if (func_004E5700(name, key, 8) == 0) return 0;

    if (func_004A8268(name, D_005E4A98) == 0) {
        state.words[0] = 7;
    } else {
        state.words[0] = 5;
        func_0041DB78(name, &state.words[1], 1);
    }

    void *render = (char *)arg0 + 0x124;
    func_004A4D68(render);
    if (*(s32 *)((char *)arg0 + 0x164) == 0) {
        *(StateBlock_00156340 *)((char *)arg0 + 0x214) = state;
        *(s32 *)((char *)arg0 + 0x164) = 1;
        func_004A4F00(render);
    } else {
        *(s32 *)((char *)arg0 + 0x210) = 0;
    }
    func_004A4DD8(render);
    return 1;
}
