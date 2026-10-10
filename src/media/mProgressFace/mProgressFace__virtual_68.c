/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00205D40(void *, f32);                 /* extern */
s32 func_00243750();                            /* extern */

struct mProgressFace__virtual_68_arg0 {
    char pad0[0x184];
    f32 unk184;
};

void mProgressFace__virtual_68(struct mProgressFace__virtual_68_arg0 *arg0) {
    func_00243750();
    func_00205D40(arg0, arg0->unk184);
}
