/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0034AD80(void *);                      /* extern */
s32 func_0034C5E0(s32);                         /* extern */
s32 func_003799F0(void *);                      /* extern */
s32 func_0042FAD8(s32, s32);                /* extern */

extern char D_00584038[];
struct func_0034A9B0_arg0 {
    s32 unk0;
    s32 unk4;
};

void RaceCourse__clearData(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = ((struct func_0034A9B0_arg0 *)arg0)->unk4;
    if (temp_v0 != 0) {
        func_0034C5E0(temp_v0);
    }
    temp_v0_2 = ((struct func_0034A9B0_arg0 *)arg0)->unk0;
    if (temp_v0_2 != 0) {
        func_0042FAD8((s32)D_00584038, temp_v0_2);
    }
    ((struct func_0034A9B0_arg0 *)arg0)->unk4 = 0;
    ((struct func_0034A9B0_arg0 *)arg0)->unk0 = 0;
    func_003799F0(arg0 + 0x1C);
    func_0034AD80(arg0);
}
