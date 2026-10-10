#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F64C4(s32);                         /* extern */

struct func_004A6868_arg0 {
    char pad0[0x20];
    s32 unk20;
};

s32 func_004A6868(struct func_004A6868_arg0 *arg0, s32 arg1, s32 arg2) {
    func_004F64C4(arg0->unk20);
    arg0->unk20 = (s32) (arg0->unk20 + arg2);
    return arg2;
}
