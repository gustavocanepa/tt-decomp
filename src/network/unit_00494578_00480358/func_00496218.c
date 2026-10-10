#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004967F8();                                /* extern */

extern char D_004962D8[];
extern char D_00496788[];
struct func_00496218_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

s32 func_00496218(struct func_00496218_arg0 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0x27;
    case 24:
        arg0->unk8 = 0x27;
        arg0->unk0 = (s32)D_00496788;
        return 0x2D;
    case 36:
        arg0->unk8 = 0x27;
        arg0->unk0 = (s32)D_00496788;
        return 0x2E;
    case 21:
        arg0->unk0 = (s32)D_004962D8;
        return 0x27;
    default:
        return func_004967F8();
    }
}
