#include "types.h"

extern void *D_005D90F0;
extern "C" void func_00400D78(void *, s32);
extern "C" void func_0050E1A8(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x0) + 0x8);
    e->fn(o + e->delta, a0);
}

struct func_00563B90_arg0 {
    void *unk0;
};

extern "C" void func_00563B90(void *arg0, s32 arg1) {
    ((struct func_00563B90_arg0 *)arg0)->unk0 = &D_005D90F0;
    if ((char *)arg0 + 0xC != 0) {
        char *p0 = (char *)arg0 + 0x15C;
        while ((char *)arg0 + 0xC != p0) {
            p0 -= 0x54;
            vcall_0((char *)p0, 0x2);
        }
    }
    func_00400D78(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_0050E1A8(arg0);
    }
}
