#include "types.h"

extern void *D_005ADCF8;
extern "C" void *func_002A7618(void *);

struct func_001B1790_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x8];
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

extern "C" void func_001B1790(struct func_001B1790_arg0 *arg0) {
    func_002A7618(arg0);
    arg0->unk4 = &D_005ADCF8;
    arg0->unk24 = 0x0;
    arg0->unk10 = 0x0;
    arg0->unk14 = 0x0;
    arg0->unk18 = 0x0;
    arg0->unk20 = 0x0;
    arg0->unk1C = (void *)(0x1);
}
