#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005C9288[];
void func_004B2CA8(void *, s32);
void func_0050E1A8(void *);
struct func_002E7AE0_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_002E7AE0(struct func_002E7AE0_arg0 *arg0, s32 arg1) {
    arg0->unk50 = (s32)D_005C9288;
    func_004B2CA8(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
