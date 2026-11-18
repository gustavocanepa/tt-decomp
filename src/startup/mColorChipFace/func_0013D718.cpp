#include "types.h"

struct Blk {
    s32 a;
    s32 b;
};

extern struct Blk D_005E18A8;
extern struct Blk D_005E18B0;
extern struct Blk D_005E18B8;
extern struct Blk D_005E18C0;

void func_004F6678(void *, s32, u32);               /* extern */

void func_0013D718(void *arg0) {
    switch (*(s16 *)((char *)arg0 + 0xC4)) {        /* irregular */
    case 1:
        *(struct Blk *)((char *)arg0 + 0xE8) = D_005E18A8;
        return;
    case 2:
        *(struct Blk *)((char *)arg0 + 0xE8) = D_005E18B0;
        return;
    case 3:
        *(struct Blk *)((char *)arg0 + 0xE8) = D_005E18B8;
        return;
    case 4:
        *(struct Blk *)((char *)arg0 + 0xE8) = D_005E18C0;
        return;
    default:
        return func_004F6678((char *)arg0 + 0xE8, 0, 8);
    }
}
