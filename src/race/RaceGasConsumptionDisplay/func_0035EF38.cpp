extern char D_005D02F0[];
extern char D_005F57E0[];

extern "C" void *func_0035C548(void *arg0);
extern "C" void RaceDigitalSpeedmeter__structor_1(void *arg0);
extern "C" void func_00359428(void *arg0, const char *arg1);
extern "C" void RaceGasMileageDisplay__structor_0(void *arg0);
extern "C" void func_0035ED10(void *arg0);
extern "C" void RacePriusHybridDisplay__structor_1(void *arg0);
extern "C" int func_0035E778(void *arg0);
extern "C" void Oscillator__setCycle(void *arg0, float f12, float f13);
extern "C" void func_0035E878(void *arg0, float f12, float f13);
extern "C" void Oscillator__setCount(void *arg0, int a1, unsigned char a2);

extern "C" void func_0035EF38(void *arg0) {
    char *s1 = (char *)arg0 + 0x40;
    char *s2 = (char *)arg0 + 0x230;
    func_0035C548(arg0);
    char *s4 = (char *)arg0 + 0xE4;
    *(void **)((char *)arg0 + 0x14) = D_005D02F0;
    RaceDigitalSpeedmeter__structor_1(s1);
    char *s3 = (char *)arg0 + 0x78;
    RaceGasMileageDisplay__structor_0(s3);
    func_0035ED10(s4);
    RacePriusHybridDisplay__structor_1((char *)arg0 + 0x154);
    func_0035E778(s2);
    *(int *)(s1 + 0x2C) = (int)0x80E3B896;
    func_00359428(s1, D_005F57E0);
    *(int *)(s3 + 0x18) = (int)0x80B58F43;
    *(int *)(s4 + 0x18) = (int)0x800363FD;
    Oscillator__setCycle(s2, 0x1.999998p-3f, 0.5f);
    func_0035E878(s2, 0.0f, 0x1.1eb850p-4f);
    return Oscillator__setCount(s2, -1, 0);
}
