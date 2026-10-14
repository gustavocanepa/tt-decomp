extern int D_00583FD0;
extern "C" float RaceCarSound__getMasterVolume(void);
extern "C" void func_0042E888(void *a, void *b, unsigned int c, float x, float y);

extern "C" void func_00348510(void *a, void *b, float x, float y) {
    if (D_00583FD0 == 0) {
        float s = RaceCarSound__getMasterVolume();
        func_0042E888(a, b, 0x7FFFFFFF, x * s, y);
    }
}
