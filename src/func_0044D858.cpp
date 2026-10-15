struct V4 { float x, y, z, w; };
extern V4 D_005869D0;
extern char D_005869E0[];
extern char D_00586A10[];
extern "C" void func_00454388(void *, float, float, float, float, float, float, float, float, float);
extern "C" void func_00454CA0(void *, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);

static inline void i1(int ini) {
    if (ini == 1) {
        D_005869D0.x = 1.0f;
        D_005869D0.y = 0.0f;
        D_005869D0.w = 1.0f;
        D_005869D0.z = 0.0f;
    }
}
static inline void i2(int ini) {
    if (ini == 1) {
        float o = 1.0f, z = 0.0f;
        func_00454388(D_005869E0, o, z, z, z, o, z, z, z, o);
    }
}
static inline void i3(int ini) {
    if (ini == 1) {
        float o = 1.0f, z = 0.0f;
        func_00454CA0(D_00586A10, o, z, z, z, z, o, z, z, z, z, o, z, z, z, z, o);
    }
}
extern "C" void func_0044D858(int ini, int pri) {
    if (pri == 0xFFFF) {
        i1(ini);
        i2(ini);
        i3(ini);
    }
}
