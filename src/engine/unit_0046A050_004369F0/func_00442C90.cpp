/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Val {
    int data[2];
};

struct Ctx {
    int pad0[2];
    Val *sp;
};

extern "C" float func_0043E0B0(Val *v);
extern "C" void func_00447CD8(Ctx *ctx);
extern "C" void func_00447D00(Ctx *ctx, unsigned int n);
extern "C" float func_004A6120(float a, float b);

extern "C" float func_00442C90(unsigned int argc, Ctx *ctx) {
    float r;
    if (argc >= 2) {
        float a = func_0043E0B0(ctx->sp - 1);
        func_00447CD8(ctx);
        float b = func_0043E0B0(ctx->sp - 1);
        func_00447D00(ctx, argc - 1);
        r = func_004A6120(a, b);
    } else {
        func_00447D00(ctx, argc);
        r = 0.0f;
    }
    return r;
}
