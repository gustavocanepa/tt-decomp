struct func_0043B768_Save {
    int a;
    int b;
};

struct func_0043B768_Key {
    char pad0[0x20];
    float weight;
};

struct func_0043B768_Keys {
    func_0043B768_Key *keys;
    int count;
    func_0043B768_Key *at(int i) { return &keys[i]; }
};

struct func_0043B768_Anim {
    short type;
    short start;
    short pad4;
    short index;
    char pad8[0x18 - 0x8];
    func_0043B768_Keys keys;
};

struct func_0043B768_Tables {
    char pad0[0x30];
    char *t30;
    int pad34;
    char *t38;
    int pad3C;
    char *t40;
    char pad44[0x58 - 0x44];
    char *t58;
    int pad5C;
    char *t60;
    char pad64[0xA0 - 0x64];
    char *tA0;
};

struct func_0043B768_Ctx {
    char pad0[0x6E18];
    func_0043B768_Save save;
    func_0043B768_Tables *tables;
};

extern "C" {
void func_00473050(void);
void func_004730A8(void);
void func_0043BA20(func_0043B768_Key *out, func_0043B768_Key *a, func_0043B768_Key *b, float t);
void func_0043BAA0(func_0043B768_Key *key, func_0043B768_Ctx *ctx);
void func_00445720(void *p, func_0043B768_Ctx *ctx);
void func_00445F88(void *p, func_0043B768_Ctx *ctx, float w);
void func_0043B138(void *p, func_0043B768_Ctx *ctx, float t);
void func_00440620(void *p, func_0043B768_Ctx *ctx);
void func_00440988(void *p, func_0043B768_Ctx *ctx);
void func_0043FE40(void *p, func_0043B768_Ctx *ctx, float t);
}

extern "C" void func_0043B768(func_0043B768_Anim *anim, func_0043B768_Ctx *ctx, int frame, float time) {
    float frac = time - (float)(int)time;
    int k = frame - anim->start;
    func_0043B768_Keys *ks = &anim->keys;
    func_00473050();
    func_0043B768_Save save = ctx->save;
    float w;
    if (k < ks->count - 1) {
        func_0043B768_Key tmp;
        func_0043BA20(&tmp, ks->at(k), ks->at(k + 1), frac);
        func_0043BAA0(&tmp, ctx);
        w = tmp.weight;
    } else if (ks->count != 0) {
        func_0043BAA0(&ks->keys[ks->count - 1], ctx);
        w = ks->keys[ks->count - 1].weight;
    } else {
        w = 0.0f;
    }
    switch (anim->type) {
    case 0:
        func_00445720(ctx->tables->t38 + anim->index * 24, ctx);
        break;
    case 1:
        func_00445F88(ctx->tables->t40 + anim->index * 40, ctx, w);
        break;
    case 2:
        func_0043B138(ctx->tables->t30 + anim->index * 36, ctx, time - (float)anim->start);
        break;
    case 4:
        func_00440620(ctx->tables->t58 + anim->index * 48, ctx);
        break;
    case 5:
        func_00440988(ctx->tables->t60 + anim->index * 52, ctx);
        break;
    case 6:
        func_0043FE40(ctx->tables->tA0 + anim->index * 20, ctx, time - (float)anim->start);
        break;
    }
    ctx->save = save;
    func_004730A8();
}
