#include "types.h"

extern char D_005F55F8[];

struct RaceRichCountDisplay {
    char pad0[0x14];
    RaceRichCountDisplay() __asm__("RaceRichCountDisplay__structor_0");
    virtual ~RaceRichCountDisplay();
};

extern "C" void func_00359638(RaceRichCountDisplay *self, char *text);

struct RaceLapDisplay : public RaceRichCountDisplay {
    RaceLapDisplay() __asm__("RaceLapDisplay__structor_0");
    virtual ~RaceLapDisplay();
    u32 color0;
    u32 color1;
};

RaceLapDisplay::RaceLapDisplay() {
    func_00359638(this, D_005F55F8);
    color0 = 0x80C8C8C8;
    color1 = 0x80B3B3B3;
}
