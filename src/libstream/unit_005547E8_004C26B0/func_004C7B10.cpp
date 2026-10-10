/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Context {
    void *result;
    void *key;
    int depth;
};

struct Index {
    void *root;
    int pad4;
    unsigned long hash;
};

extern "C" void *func_004C71B0(void *root, unsigned long hash);
extern "C" void func_004C73F8(void *root, Index *self, int (*visit)(void *, Context *), Context *ctx,
                              int (*leave)(void *, Context *));
extern "C" int func_004C7AD0(void *node, Context *ctx);
extern "C" int func_004C7A88(void *node, Context *ctx);

extern "C" void *func_004C7B10(Index *self, void *key)
{
    void *r = func_004C71B0(self->root, self->hash);
    if (r != 0)
        return r;
    Context ctx;
    ctx.key = key;
    ctx.result = 0;
    ctx.depth = 0;
    func_004C73F8(self->root, self, func_004C7AD0, &ctx, func_004C7A88);
    return ctx.result;
}
