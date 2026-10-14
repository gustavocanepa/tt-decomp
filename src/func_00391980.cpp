struct Obj {
    char p0;
    unsigned char b1;
    unsigned char b2;
    char p3;
    short h4;
    short h6;
    short h8;
    short hA;
    float fC;
    char p10[0x14];
    int i24;
    int i28;
};

extern "C" int func_0038F5F8(int a0, float f12);
extern "C" void func_00477DC0(int a0);
extern "C" void func_004702D8(int a0, float f12);
extern "C" void func_0038E838(int a0, unsigned char a1, unsigned char a2, float f12, float f13, float f14, float f15);

extern "C" void RaceRoundMeterBase__virtual_05(struct Obj *arg0) {
    func_00477DC0(func_0038F5F8(arg0->i28, arg0->fC));
    func_004702D8(0x44, 1.0f);
    func_0038E838(arg0->i24, arg0->b1, arg0->b2, (float)arg0->h4, (float)arg0->h6, (float)arg0->h8, (float)arg0->hA);
}
