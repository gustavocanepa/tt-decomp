#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_002A75A8(void *, s32);
void *func_002A7A30(void *);
struct hBuiltinAttribute__virtual_09_arg0 {
    char pad0[0x10];
    void (*unk10)(void *, s32, s32, s32);
};

void hBuiltinAttribute__virtual_09(struct hBuiltinAttribute__virtual_09_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    func_002A7A30(sp);
    arg0->unk10(sp, arg1, 1, arg2);
    func_002A75A8(sp, 2);
}
