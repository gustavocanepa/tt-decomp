typedef int s32;

extern void *D_00582DF8;
extern void *D_005D5D18;
extern "C" void *func_003921B8(void *);
extern "C" void *exception__structor_0(s32);
extern "C" void func_00392F18(void *);
extern "C" void func_003CD5D8(void *, s32, float, float, float);

struct ParticleManager__structor_0_arg0 {
    char pad0[0x3AC];
    void *unk3AC;
};

extern "C" void ParticleManager__structor_0(void *arg0) {
    ((struct ParticleManager__structor_0_arg0 *)arg0)->unk3AC = &D_005D5D18;
    void *r0 = func_003921B8(arg0);
    void *r1 = exception__structor_0(((s32)r0 << (s32)0x7));
    *(void **)(arg0) = r1;
    *(void **)((char *)&D_00582DF8 + 0x1b44) = 0x0;
    func_00392F18(arg0);
    func_003CD5D8((char *)arg0 + 0xc, 0x1, 0.000999999960186f, 0.11999999918f, 0.11999999918f);
    func_003CD5D8((char *)arg0 + 0x80, 0x2, 0.000999999960186f, 0.129999998957f, 0.129999998957f);
    func_003CD5D8((char *)arg0 + 0xf4, 0x3, 0.000999999960186f, 0.13999998942f, 0.13999998942f);
    func_003CD5D8((char *)arg0 + 0x168, 0x4, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    func_003CD5D8((char *)arg0 + 0x1dc, 0x5, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    func_003CD5D8((char *)arg0 + 0x250, 0x6, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    func_003CD5D8((char *)arg0 + 0x2c4, 0x7, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    return func_003CD5D8((char *)arg0 + 0x338, 0x8, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
}
