#include "types.h"

extern char D_005D2EF0[];
extern char D_005D6710[];

struct Slot { char b[8]; };
struct Obj {
    char pad0[0x64];
    char *vt;
    char pad1[0xF280 - 0x68];
    Slot slots[6];
};

extern "C" void DynamicsConductor__structor_1(void *, s32);
extern "C" void func_00389110(void *, int);
extern "C" void func_0034F970(void *, int);
extern "C" void RacePause__structor_1(void *, int);
extern "C" void func_0037D460(void *, int);
extern "C" void func_00386198(void *, s32);
extern "C" void func_0050E1A8(void *) throw();

extern "C" void func_00372F48(Obj *self, s32 flags) {
    char *q = (char *)self + 0x14FB0;
    Slot *arr = self->slots;
    self->vt = D_005D2EF0;
    *(char **)(q + 0x241CC) = D_005D6710;
    DynamicsConductor__structor_1(q, 0);
    func_0034F970((char *)self + 0xFAF4, 2);
    func_0037D460((char *)self + 0xF2E8, 2);
    RacePause__structor_1((char *)self + 0xF2B0, 2);
    if (arr != 0) {
        Slot *p = arr + 6;
        if (arr != p) {
            do {
                p--;
                func_00389110(p, 2);
            } while (arr != p);
        }
    }
    func_00386198(self, 0);
    if ((flags & 1) == 0) return;
    return func_0050E1A8(self);
}
