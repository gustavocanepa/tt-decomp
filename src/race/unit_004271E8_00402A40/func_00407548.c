/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 SPEC_DATABASE__DatabaseStorage__getRow(s32, s64, s32, void *);   /* extern */

extern char D_00585A30[];
struct func_00407548_temp_a3 {
    char pad0[0x50];
    s64 unk50;
};

struct func_00407548_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

void func_00407548(void *arg0, s32 arg1) {
    struct func_00407548_temp_a3 *temp_a3;

    temp_a3 = arg0 + (((struct func_00407548_arg0 *)arg0)->unk4D8 * 0x190);
    SPEC_DATABASE__DatabaseStorage__getRow((s32)D_00585A30, temp_a3->unk50, arg1 + 0xC, temp_a3);
}
