typedef int s32;
typedef long long s64;

struct Struct_00449D58 {
    s64 unk0;
    s32 unk8;
    s32 unkC;
    void *unk10;
} __attribute__((aligned(8)));

struct List {
    s32 n;
    s32 pad4;
    char **items;
};

struct Ctx {
    char pad0[0x60];
    struct List *list;
    char pad64[0xC];
    void *p70;
};

struct Race {
    char pad0[0x6C];
    struct Ctx *ctx;
};

extern "C" s32 func_0040CFE0(void *arg0);
extern "C" s32 func_0040DE88(void *arg0);
extern "C" s32 func_0040DEC8(void *arg0);
extern "C" void func_0040E4A0(void *arg0, s32 arg1);
extern "C" s32 func_0040F0F8(void *arg0);
extern "C" void func_00411E18(struct Struct_00449D58 *arg0);
extern "C" void func_00411E38(struct Struct_00449D58 *arg0, s32 arg1);
extern "C" s32 func_00411ED0(struct Struct_00449D58 *arg0, s32 arg1);
extern "C" s32 func_00412108(struct Struct_00449D58 *arg0, s32 arg1, s32 arg2);

extern "C" void func_0036D218(struct Race *self) {
    struct Ctx *ctx = self->ctx;
    s32 r = func_0040F0F8(ctx->p70);
    s32 mode;
    s32 i;
    s32 n;
    struct Struct_00449D58 t;

    if (r == 0) {
        return;
    }
    mode = -1;
    switch (r) {
    case 2:
        mode = 0xB;
        break;
    case 3:
        mode = 0xC;
        break;
    }
    if (mode == -1) {
        return;
    }
    n = ctx->list->n;
    func_00411E18(&t);
    for (i = 0; i < n; i++) {
        void *e = ctx->list->items[i] + 0xFD8;
        s32 a = func_0040DE88(e);
        s32 b = func_0040DEC8(e);
        if (a != mode || b != mode) {
            if (func_00411ED0(&t, func_0040CFE0(e)) != 0) {
                s32 v = func_00412108(&t, 0x19, mode);
                if (v != -1) {
                    func_0040E4A0(e, v);
                }
                s32 w = func_00412108(&t, 0x1A, mode);
                if (w != -1) {
                    func_0040E4A0(e, w);
                }
            }
        }
    }
    func_00411E38(&t, 2);
}
