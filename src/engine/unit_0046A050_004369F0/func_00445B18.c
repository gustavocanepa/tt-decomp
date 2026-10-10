/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043F830(s32);                         /* extern */
s32 func_00445C18(s32, void *);                 /* extern */

struct func_00445B18_arg1_unk6E20 {
    char pad0[0x68];
    s32 unk68;
};
struct func_00445B18_arg1 {
    char pad0[0x6E20];
    struct func_00445B18_arg1_unk6E20 *unk6E20;
};
struct func_00445B18_arg0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};

void func_00445B18(struct func_00445B18_arg0 *arg0, struct func_00445B18_arg1 *arg1) {
    func_0043F830(arg1->unk6E20->unk68 + (arg0->unk0 * 8));
    func_00445C18(arg0->unk4, arg1);
}
