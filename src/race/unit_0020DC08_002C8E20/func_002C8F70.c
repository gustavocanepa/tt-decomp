#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0031C7B8();                            /* extern */

struct func_002C8F70_arg0 {
    char pad0[0xD08];
    s32 unkD08;
};

void func_002C8F70(struct func_002C8F70_arg0 *arg0) {
    if (arg0->unkD08 == 0) {
        func_0031C7B8();
    }
}
