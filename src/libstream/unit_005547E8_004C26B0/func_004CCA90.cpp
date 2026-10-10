struct Callbacks {
    char pad[0x18];
    int (*draw)(void *ctx, int buffer);
    void *ctx;
};

extern "C" Callbacks D_005983E0;
extern "C" int D_005A07E4;
extern "C" int D_005A07E8;
extern "C" int D_005A0810;

extern "C" void func_004CCA90(int enable)
{
    if (enable) {
        if (D_005A0810 == 3)
            D_005983E0.draw(D_005983E0.ctx, D_005A07E8);
        else
            D_005983E0.draw(D_005983E0.ctx, D_005A07E4);
    }
}
