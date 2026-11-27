#include "types.h"

extern void *D_005CCAD8;
extern "C" void *func_002CE108(void *);

struct RaceBasic__structor_0_arg0 {
    char pad0[0x64];
    void *unk64;
    char pad68[0xE458];
    void *unkE4C0;
    void *unkE4C4;
    void *unkE4C8;
    void *unkE4CC;
    void *unkE4D0;
    void *unkE4D4;
    void *unkE4D8;
    void *unkE4DC;
    void *unkE4E0;
    void *unkE4E4;
};

extern "C" void *RaceBasic__structor_0(struct RaceBasic__structor_0_arg0 *arg0) {
    void *r0 = func_002CE108(arg0);
    arg0->unkE4C0 = 0x0;
    arg0->unk64 = &D_005CCAD8;
    arg0->unkE4C4 = 0x0;
    arg0->unkE4CC = 0x0;
    arg0->unkE4D4 = 0x0;
    arg0->unkE4C8 = 0x0;
    arg0->unkE4D0 = 0x0;
    arg0->unkE4D8 = 0x0;
    arg0->unkE4DC = 0x0;
    arg0->unkE4E0 = 0x0;
    arg0->unkE4E4 = 0x0;
    return r0;
}
