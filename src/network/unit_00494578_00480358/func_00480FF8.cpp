typedef int s32;

struct S {
    char pad0[0xB0];
    s32 unkB0;
};

extern "C" void func_0047D030(void) throw();
extern "C" void func_00480ED8(void) throw();

extern "C" void func_00480FF8(struct S *arg0) {
    struct S *s0 = arg0;
    func_0047D030();
    if (s0->unkB0 != 0) {
        func_00480ED8();
    }
}
