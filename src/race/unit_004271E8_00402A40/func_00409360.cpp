#include "types.h"

struct Src {
    u8 b[0x26];
};

struct Dst {
    u8 b[0x1B0];
};

extern "C" void func_00409360(void *arg0, struct Dst *arg1, struct Src *arg2) {
    u8 t25 = arg2->b[0x25];
    arg1->b[0x182] = 6;
    arg1->b[0x28] = t25;
    arg1->b[0x19C] = arg2->b[0xD];
    arg1->b[0x19D] = arg2->b[0xE];
    arg1->b[0x19E] = arg2->b[0xF];
    arg1->b[0x19F] = arg2->b[0x10];
    arg1->b[0x1A0] = arg2->b[0x11];
    arg1->b[0x1A1] = arg2->b[0x12];
    arg1->b[0x1A2] = arg2->b[0x13];
    arg1->b[0x1A3] = arg2->b[0x14];
    arg1->b[0x1A4] = arg2->b[0x15];
    arg1->b[0x1A5] = arg2->b[0x16];
    arg1->b[0x1A6] = arg2->b[0x17];
    u8 t18 = arg2->b[0x18];
    arg1->b[0x180] = 6;
    arg1->b[0x1A7] = t18;
    arg1->b[0x184] = arg2->b[0x1];
    arg1->b[0x185] = arg2->b[0x2];
    arg1->b[0x186] = arg2->b[0x3];
    arg1->b[0x187] = arg2->b[0x4];
    arg1->b[0x188] = arg2->b[0x5];
    arg1->b[0x189] = arg2->b[0x6];
    arg1->b[0x18A] = arg2->b[0x7];
    arg1->b[0x18B] = arg2->b[0x8];
    arg1->b[0x18C] = arg2->b[0x9];
    arg1->b[0x18D] = arg2->b[0xA];
    arg1->b[0x18E] = arg2->b[0xB];
    u8 tC = arg2->b[0xC];
    arg1->b[0x181] = 6;
    arg1->b[0x18F] = tC;
    arg1->b[0x190] = arg2->b[0x19];
    arg1->b[0x191] = arg2->b[0x1A];
    arg1->b[0x192] = arg2->b[0x1B];
    arg1->b[0x193] = arg2->b[0x1C];
    arg1->b[0x194] = arg2->b[0x1D];
    arg1->b[0x195] = arg2->b[0x1E];
    arg1->b[0x196] = arg2->b[0x1F];
    arg1->b[0x197] = arg2->b[0x20];
    arg1->b[0x198] = arg2->b[0x21];
    arg1->b[0x199] = arg2->b[0x22];
    arg1->b[0x19A] = arg2->b[0x23];
    arg1->b[0x19B] = arg2->b[0x24];
}
