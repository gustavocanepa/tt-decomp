struct Mat {
    float m[16];
};

struct Obj {
    char pad[0x18];
    char unk18[1];
};

struct Ctx {
    char pad[0x6E18];
    char unk6E18[1];
};

extern "C" void func_00445118(Obj *, Mat *);
extern "C" void func_00475440(Mat *);
extern "C" void func_004453F8(void *, void *);

extern "C" void func_0043BAA0(Obj *self, Ctx *ctx) {
    Mat m;
    func_00445118(self, &m);
    func_00475440(&m);
    func_004453F8(ctx->unk6E18, self->unk18);
}
