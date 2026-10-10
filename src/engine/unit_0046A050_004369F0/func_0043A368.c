#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0045EC58(s32);
extern s32 D_00586EF4;
struct func_0043A368_arg0 {
    char pad0[0x28];
    f32 unk28;
};

void func_0043A368(struct func_0043A368_arg0 *arg0, s32 arg1, f32 fparg0) {
    if (arg1 != 0) {
        func_0045EC58(D_00586EF4);
    }
    arg0->unk28 = fparg0;
}
