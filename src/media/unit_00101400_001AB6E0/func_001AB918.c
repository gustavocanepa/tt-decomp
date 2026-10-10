#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00468938(f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */

struct func_001AB918_arg0 {
    char pad0[0x28];
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
};

void func_001AB918(struct func_001AB918_arg0 *arg0) {
    func_00468938(arg0->unk28, arg0->unk2C, arg0->unk30, arg0->unk34, arg0->unk38, arg0->unk3C, arg0->unk40, arg0->unk44, arg0->unk48);
}
