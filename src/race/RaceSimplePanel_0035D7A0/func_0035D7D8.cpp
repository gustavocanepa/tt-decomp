/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Indicator { char pad[0x40]; signed char enabled : 8; };
extern "C" void func_0035BEE0(void *, float) throw();
extern "C" void RaceShiftTimingLampDisplay__update(void *, float) throw();
extern "C" void RaceSuggestedGearDisplay__virtual_10(void *, float) throw();
extern "C" void func_0038E378(void *);
extern "C" void func_0035BD90(void *, float) throw();
extern "C" void func_0035D7D8(signed char *self, float dt) {
    func_0035BEE0(self + 0xA0C, dt);
    RaceShiftTimingLampDisplay__update(self + 0xA9C, dt);
    RaceSuggestedGearDisplay__virtual_10(self + 0xA44, dt);
    func_0038E378(self + 0xAD8);
    Indicator *p = (Indicator *)(self + 0xB08);
    signed char v_self2 = self[0x1F];
    p->enabled = v_self2;
    func_0035BD90(p, dt);
    Indicator *p2 = (Indicator *)(self + 0xB4C);
    signed char v_self3 = self[0x23];
    p2->enabled = v_self3;
    func_0035BD90(p2, dt);
    Indicator *p3 = (Indicator *)(self + 0xB90);
    signed char v_self = self[0x21];
    p3->enabled = v_self;
    func_0035BD90(p3, dt);
}
