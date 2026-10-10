extern "C" void func_0036C688(void *arg0);
extern "C" void func_004A48C0(void);
extern "C" char D_005D1590[];

struct RaceEventQueue__structor_0_arg0 {
    char pad0[0x828];
    void *unk828;
};

extern "C" void RaceEventQueue__structor_0(struct RaceEventQueue__structor_0_arg0 *arg0) {
    arg0->unk828 = D_005D1590;
    func_004A48C0();
    return func_0036C688(arg0);
}
