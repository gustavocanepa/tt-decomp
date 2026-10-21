typedef int s32;
typedef unsigned int u32;

struct Ctx {
    char p0[0x38];
    char *a38;
    char p1[0x40 - 0x3C];
    char *a40;
    char p2[0x58 - 0x44];
    char *a58;
    char p3[0xB8 - 0x5C];
    char *aB8;
};
struct Node {
    short type;
    short p2;
    short p4;
    short idx;
};
struct Obj {
    Ctx *ctx;
    Node *node;
    char p[0x58 - 8];
    void *n58;
};
struct Env {
    char p[0x6E14];
    void *v6E14;
    unsigned char d6E18[0x6E7C - 0x6E18];
    s32 v6E7C;
};

extern "C" void func_004399A8(void *);
extern "C" void func_00439EC8(void *, u32);
extern "C" s32 func_0043C9F0(s32);
extern "C" void func_00440620(void *, void *);
extern "C" void *func_00444A30(void *);
extern "C" unsigned func_00445370(const unsigned char *, const unsigned char *);
extern "C" void func_00445720(void *, void *);
extern "C" void func_00445F88(void *, void *);
extern "C" void func_00447F50(s32, void *, void *, void *);

extern "C" void func_00444428(Obj *o, Env *e)
{
    switch (o->node->type) {
    case 0:
        func_00445720(o->ctx->a38 + o->node->idx * 0x18, e);
        break;
    case 1:
        func_00445F88(o->ctx->a40 + o->node->idx * 0x28, e);
        break;
    case 4:
        func_00440620(o->ctx->a58 + o->node->idx * 0x30, e);
        break;
    case 7: {
        unsigned char c[4];
        *(u32 *)c = 0x80FFFFFF;
        func_00439EC8(e->v6E14, func_00445370(e->d6E18, c));
        func_004399A8(e->v6E14);
        void *s = func_00444A30(o->n58);
        func_00447F50(func_0043C9F0(e->v6E7C), e->v6E14, s, o->ctx->aB8 + o->node->idx * 0x18);
        break;
    }
    }
}
