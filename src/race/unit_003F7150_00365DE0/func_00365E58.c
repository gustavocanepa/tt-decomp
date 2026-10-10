#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00357310(s32);                         /* extern */

extern char D_005F5C58[];
extern char D_005F5C68[];
struct func_00365E58_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x4];
    s32 unk18;
};

void func_00365E58(struct func_00365E58_arg0 *arg0) {
    arg0->unk10 = func_00357310((s32)D_005F5C58);
    arg0->unk18 = func_00357310((s32)D_005F5C68);
}
