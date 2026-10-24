#include "types.h"
extern char D_005D2CF0[];
extern char D_005D13A0[];
extern "C" void func_0034F970(void *, s32);
extern "C" void func_0035A650(void *, s32);
extern "C" void func_0038E308(void *, s32);
extern "C" void func_0050E1A8(void *) throw();
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x14) + 0x8);
    e->fn(o + e->delta, a0);
}
struct Lic { char pad[0x4360]; char s4360[0x1C]; };
extern "C" void func_00371DE8(char *arg0, s32 arg1) {
    *(char **)arg0 = D_005D2CF0;
    func_0035A650(arg0 + 0x58EC, 2);
    char *v = arg0 + 0x5854;
    *(char **)(v + 0x14) = D_005D13A0;
    func_0038E308(v, 0);
    if (arg0 + 0x560C != 0) {
        char *p0 = arg0 + 0x57C8;
        while (arg0 + 0x560C != p0) {
            p0 -= 0x94;
            vcall_0(p0, 2);
        }
    }
    if (arg0 + 0x54BC != 0) {
        char *p1 = arg0 + 0x560C;
        while (arg0 + 0x54BC != p1) {
            p1 -= 0x70;
            vcall_0(p1, 2);
        }
    }
    func_0034F970(arg0, 0);
    if ((arg1 & 1) != 0) {
        return func_0050E1A8(arg0);
    }
}
