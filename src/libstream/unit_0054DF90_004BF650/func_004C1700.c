/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_004A5668(s32);                         /* extern */

struct func_004C1700_arg0 {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
};

void func_004C1700(struct func_004C1700_arg0 *arg0) {
    func_004A5668(arg0->unk5C);
    func_004A5668(arg0->unk60);
}
