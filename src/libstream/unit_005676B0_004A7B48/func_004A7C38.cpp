#include "types.h"

extern void *D_005DAD28;
extern "C" void *RefCounter__structor_0(void *);

struct func_004A7C38_arg0 {
    char pad0[0x1C];
    void *unk1C;
    void *unk20;
};

extern "C" void *func_004A7C38(struct func_004A7C38_arg0 *arg0, s32 arg1) {
    void *r0 = RefCounter__structor_0(arg0);
    arg0->unk1C = &D_005DAD28;
    arg0->unk20 = (void *)(arg1);
    return r0;
}
