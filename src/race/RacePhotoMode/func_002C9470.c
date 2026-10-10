/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0034A668(s32);                         /* extern */
s32 func_0034AA18(s32, s64);                    /* extern */

struct func_002C9470_arg0 {
    char pad0[0x6C];
    void *unk6C;
    char pad70[0x3272C];
    s32 unk3279C;
};
struct func_002C9470_temp_v0_2 {
    char pad0[0x78];
    s64 unk78;
    s32 unk80;
};

void func_002C9470(struct func_002C9470_arg0 *arg0) {
    s32 temp_v0;
    struct func_002C9470_temp_v0_2 *temp_v0_2;

    temp_v0 = arg0->unk3279C;
    if (temp_v0 != 0) {
        func_0034A668(temp_v0);
    }
    temp_v0_2 = arg0->unk6C;
    arg0->unk3279C = 0;
    func_0034AA18(temp_v0_2->unk80, temp_v0_2->unk78);
}
