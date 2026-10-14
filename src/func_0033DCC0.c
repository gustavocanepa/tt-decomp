#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D0890(s32, s32, f32);                 /* extern */
s32 func_002D7E30(s32);                             /* extern */

struct RaceBasic__virtual_53_arg0 {
    char pad0[0xE4E4];
    s32 unkE4E4;
};

void RaceBasic__render_world(struct RaceBasic__virtual_53_arg0 *arg0, s32 arg1, f32 fparg0) {
    s32 temp_v0;

    if ((arg0->unkE4E4 == 0) || (temp_v0 = arg0->unkE4E4, func_002D7E30(temp_v0) == 0)) {
        func_002D0890((s32) arg0, arg1, fparg0);
    }
}
