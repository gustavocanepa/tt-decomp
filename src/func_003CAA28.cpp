/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { float f0, f4; int count; float v0[4], v1[4], v2[4], v3[4]; float pad; };
struct Ctx { char p[0x38]; float f38; char p3C[0xEF0 - 0x3C]; float mat[1]; };
extern "C" void func_0034E018(void *, float, float);
extern "C" void func_003CAB90(float *, float *, float) throw();
extern "C" void func_0046F0F8(int);
extern "C" void func_00473A08(int, int, void *);
extern "C" void func_00473AD0(int, void *);
extern "C" void func_00478C98(int);

extern "C" void func_003CAA28(char *self, Ctx *ctx) {
    float m[4];
    float inv = 1.0f / ctx->f38;
    func_003CAB90(m, ctx->mat, inv);
    func_00473AD0(0, m);
    Entry *e = (Entry *)self;
    int count = e->count;
    if (count > 0) {
        int id = 0x65;
        int i;
        for (i = 0; i < e->count; i++, id++) {
            func_0046F0F8(id);
            func_00473A08(id, 0xD, e[i].v0);
            func_003CAB90(m, e[i].v1, inv);
            func_00473A08(id, 0, m);
            func_003CAB90(m, e[i].v2, inv);
            func_00473A08(id, 1, m);
            func_003CAB90(m, e[i].v3, inv);
            func_00473A08(id, 4, m);
        }
        for (; i < 8; i++) func_00478C98(id++);
    } else {
        func_0034E018(ctx, *(float *)self, *(float *)(self + 4));
    }
}
