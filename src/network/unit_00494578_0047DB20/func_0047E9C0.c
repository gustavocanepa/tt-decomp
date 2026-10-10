#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_005DA698[];
void func_004AE9F0(void *, s32);
void func_0050E1A8(void *);
struct func_0047E9C0_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

void func_0047E9C0(struct func_0047E9C0_arg0 *arg0, s32 arg1) {
    arg0->unkA8 = (s32)D_005DA698;
    func_004AE9F0(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
