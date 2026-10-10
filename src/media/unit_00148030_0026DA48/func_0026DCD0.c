#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00205D10(void *);                          /* extern */
s32 func_00243440();                            /* extern */

struct func_0026DCD0_arg0 {
    char pad0[0x180];
    s32 unk180;
    f32 unk184;
};

void func_0026DCD0(struct func_0026DCD0_arg0 *arg0) {
    f32 temp_f0;

    func_00243440();
    temp_f0 = func_00205D10(arg0);
    arg0->unk180 = 0;
    arg0->unk184 = temp_f0;
}
