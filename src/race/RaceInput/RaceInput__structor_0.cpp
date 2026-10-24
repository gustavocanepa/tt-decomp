#include "types.h"

extern void *D_005D7378;
extern "C" void *func_004CA090(void *);
extern "C" void *func_002E8778(void *);
extern "C" void *func_00400A28(void *, void *);
extern "C" void *func_004009E0(void *);

struct RaceInput__structor_0_arg0 {
    char pad0[0xD0];
    void *unkD0;
    char padD4[0x70];
    void *unk144;
    void *unk148;
    void *unk14C;
    char pad150[0x44];
    void *unk194;
    char pad198[0x4];
    void *unk19C;
    char pad1A0[0x24];
    void *unk1C4;
    void *unk1C8;
    void *unk1CC;
    void *unk1D0;
    void *unk1D4;
    void *unk1D8;
    void *unk1DC;
};

extern "C" void RaceInput__structor_0(void *arg0) {
    func_004CA090(arg0);
    ((struct RaceInput__structor_0_arg0 *)arg0)->unkD0 = &D_005D7378;
    func_002E8778((char *)arg0 + 0xd4);
    func_00400A28((char *)arg0 + 0x170, (char *)arg0 + 0x150);
    func_004009E0((char *)arg0 + 0x1a0);
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk1C4 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk1CC = (void *)(0x1);
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk1C8 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk1D0 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk1D4 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk144 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk148 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk14C = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk194 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk19C = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk1D8 = 0x0;
    ((struct RaceInput__structor_0_arg0 *)arg0)->unk1DC = 0x0;
}
