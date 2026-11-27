#include "types.h"

struct Vec;

extern "C" {
void func_001A5650(void *arg0, s32 arg1);      /* extern */
void func_0051D180(Vec *v);                    /* extern */

struct func_00182B48_arg0 {
    char pad0[0xB4];
    void *unkA0;
    char pad1[0x4];
    char unkA4[0];
};

void func_00182B48(void *arg0) {
    void **p = &((struct func_00182B48_arg0 *)arg0)->unkA0;
    void *temp_v0;

    temp_v0 = *p;
    if (temp_v0 != 0) {
        func_001A5650(temp_v0, 3);
    }
    *p = 0;
    func_0051D180((Vec *)((char *)arg0 + 0xB8));
}
}
