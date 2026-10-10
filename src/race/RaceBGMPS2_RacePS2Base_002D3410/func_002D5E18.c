/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104C88(void *);                      /* extern */
s32 func_00104F00(void *);                          /* extern */
s32 func_00470478(s32);                     /* extern */
s32 pglPushAttrib(s32);                     /* extern */
s32 func_00473498();                            /* extern */
s32 func_00474090(s32, s32, s32, s32);  /* extern */
s32 func_00478C98(s32);                     /* extern */

struct func_002D5E18_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_002D5E18(struct func_002D5E18_arg0 *arg0) {
    s32 temp_s1;

    pglPushAttrib(2);
    func_00104C88(arg0);
    func_00478C98(5);
    func_00470478(0);
    temp_s1 = arg0->unk18;
    func_00474090(0, 0, temp_s1, func_00104F00(arg0));
    func_00473498();
}
