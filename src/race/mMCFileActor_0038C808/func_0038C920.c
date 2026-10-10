/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00352C10();                            /* extern */
s32 RaceValueDisplayBase__update(void *);                      /* extern */
s32 func_0038C960(void *);                      /* extern */

struct func_0038C920_temp_v0 {
    char pad0[0xC];
    f32 unkC;
};

struct func_0038C920_arg0 {
    char pad0[0xCC];
    f32 unkCC;
};

void func_0038C920(void *arg0) {
    struct func_0038C920_temp_v0 *temp_v0;

    func_00352C10();
    temp_v0 = arg0 + 0x54BC;
    temp_v0->unkC = (f32) ((struct func_0038C920_arg0 *)arg0)->unkCC;
    RaceValueDisplayBase__update(temp_v0);
    func_0038C960(arg0);
}
