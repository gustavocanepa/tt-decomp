extern "C" int func_0034F6E8(void *);
extern "C" void RaceTimeDisplay__structor_0(void *);
extern "C" void *func_0035A610(void *);
extern "C" void func_0035E910(void *);
extern "C" void RaceRichCountDisplay__structor_0(void *);
extern "C" void RaceValueDisplay__structor_0(void *);
extern "C" char D_005D2CF0[];
extern "C" void *func_00371D18(char *self) {
    func_0034F6E8(self);
    *(void **)self = D_005D2CF0;
    char *p = self + 0x54BC;
    for (int i = 2; i != -1; i--) {
        RaceTimeDisplay__structor_0(p);
        p += 0x70;
    }
    p = self + 0x560C;
    for (int i = 2; i != -1; i--) {
        RaceValueDisplay__structor_0(p);
        p += 0x94;
    }
    p = self + 0x57C8;
    for (int i = 4; i != -1; i--) {
        func_0035E910(p);
        p += 0x1C;
    }
    RaceRichCountDisplay__structor_0(self + 0x5854);
    return func_0035A610(self + 0x58EC);
}
