struct Arg {
    int a;
    int b;
    char *p;
};

extern "C" float func_0043E0B0(void *v);
extern "C" void func_00447D00(Arg *arg, void *ctx);

extern "C" float func_00442800(void *ctx, Arg *arg)
{
    float v;
    if (ctx != 0) {
        v = func_0043E0B0(arg->p - 8);
    } else {
        v = 0.0f;
    }
    func_00447D00(arg, ctx);
    if (v < 0.0f) {
        return (float)(int)(v + -0.5f);
    }
    return (float)(int)(v + 0.5f);
}
