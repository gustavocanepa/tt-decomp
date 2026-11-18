struct Matrix {
    float m[12];
};

struct Inner {
    char pad0[0x80];
    void *value;
};

struct Mid {
    int pad0;
    Inner *inner;
};

struct Outer {
    char pad0[0x80];
    Mid *mid;
};

struct Ghost {
    int active;
};

struct RaceLicense {
    char pad0[0x6C];
    Outer *world;
    char pad70[0x3A8C0 - 0x70];
    Ghost ghost;
};

extern "C" void GSBuffer__getTexture(void *src, Matrix *out);
extern "C" void func_003C8A08(Ghost *g, Matrix *m);
extern "C" void func_003C9F38(Ghost *g, void *value);

extern "C" void RaceLicense__render_concourse(RaceLicense *self, void *src)
{
    Ghost *g = &self->ghost;
    if (g->active) {
        Matrix m;
        GSBuffer__getTexture(src, &m);
        func_003C8A08(g, &m);
        func_003C9F38(g, self->world->mid->inner->value);
    }
}
