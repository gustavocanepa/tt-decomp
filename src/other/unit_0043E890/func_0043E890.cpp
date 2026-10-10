typedef int s32;

struct Val;
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);

struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_0043D3B8(this, &o); }
    ~Val() { func_0043D510(this); }
};
struct Ctx { char pad[0x164]; s32 f164; };

extern "C" void func_0043D658(Val *);
extern "C" Val func_0044B708(s32 v, s32 x, s32 y, Val *self, s32 z, s32 w, Ctx *ctx);
extern "C" Val func_004425C8(s32 *v, s32 x, s32 z, s32 w, Ctx *ctx);
extern "C" Val func_00443820(s32 *v, s32 x, s32 c, s32 z);
extern "C" Val func_004430E0(s32 x, s32 c, s32 z);
extern "C" Val func_00443490(s32 *v, s32 x, s32 c, s32 z);
extern "C" Val func_00443B58(Val *self, s32 x, s32 c, s32 z);

extern "C" Val func_0043E890(Val *self, s32 x, s32 y, s32 z, s32 w, Ctx *ctx) {
    switch (self->type) {
    case 7:
        return func_0044B708(self->v, x, y, self, z, w, ctx);
    case 10:
        return func_004425C8(&self->v, x, z, w, ctx);
    case 11:
        return func_00443820(&self->v, x, ctx->f164, z);
    case 8:
        return func_004430E0(x, ctx->f164, z);
    case 9:
        return func_00443490(&self->v, x, ctx->f164, z);
    case 3:
    case 4:
        return func_00443B58(self, x, ctx->f164, z);
    default: {
        Val tmp;
        func_0043D658(&tmp);
        return tmp;
    }
    }
}
