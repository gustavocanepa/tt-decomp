struct RaceRoundMeterBase {
    char p0[0x14];
    void *vtbl;
    char p18[0xC];
    int u24;
    int u28;
    int u2C;
    float u30;
    unsigned char u34;
    char p35[0x1B];
    float u50;
    float u54;
};

extern char D_005D5C28[];
extern float D_005F7950;

extern "C" void *RaceMeterBase__structor_1(struct RaceRoundMeterBase *self);
extern "C" void func_00391890(struct RaceRoundMeterBase *self, float a, float b);
extern "C" void func_00391E68(struct RaceRoundMeterBase *self, float a, float b);
extern "C" void func_00391E78(struct RaceRoundMeterBase *self, float a, float b);
extern "C" void func_00391E88(struct RaceRoundMeterBase *self, float a, float b);

extern "C" void RaceRoundMeterBase__structor_0(struct RaceRoundMeterBase *arg0) {
    RaceMeterBase__structor_1(arg0);
    float f = D_005F7950;
    arg0->vtbl = D_005D5C28;
    arg0->u28 = (int)0x80000000;
    arg0->u30 = f;
    arg0->u2C = (int)0x80FFFFFF;
    arg0->u34 = 8;
    arg0->u24 = 0;
    func_00391E68(arg0, 0.5f, 0.5f);
    func_00391E78(arg0, 150.0f, 1.0f);
    func_00391890(arg0, 0.0f, 1.0f);
    func_00391E88(arg0, 65.0f, 295.0f);
    arg0->u50 = -0x1.999998p-4f;
    arg0->u54 = 0x1.e66666p-1f;
}
