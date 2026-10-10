#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D6E48[];
struct func_003ABE48_arg0 {
    char pad0[0x24];
    s32 unk24;
};

s32 func_003ABE48(struct func_003ABE48_arg0 *arg0) {
    arg0->unk24 = (s32)D_005D6E48;
}
