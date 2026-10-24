#include "types.h"
struct Gear {
    char pad0[0x18];
    char osc[0x20];
    char fader[0x1C];
    s8 s54;
    u8 u55;
    char pad56;
    u8 u57;
};
extern "C" void Oscillator__update(void *, float);
extern "C" void Oscillator__setCount(void *, s32, u8);
extern "C" void AutomaticFader__update(void *, float);
extern "C" void AutomaticFader__fadein(void *, float);
extern "C" void AutomaticFader__fadeout(void *, float);
extern "C" void RaceSuggestedGearDisplay__virtual_10(struct Gear *self, float dt) {
    s32 a = 0;
    if (self->u57 != 0 || self->s54 <= 0) a = -1;
    Oscillator__setCount(self->osc, a, 1);
    if (self->s54 > 0) {
        self->u55 = self->s54;
        AutomaticFader__fadein(self->fader, 0.2f);
    } else {
        AutomaticFader__fadeout(self->fader, 0.2f);
    }
    Oscillator__update(self->osc, dt);
    AutomaticFader__update(self->fader, dt);
}
