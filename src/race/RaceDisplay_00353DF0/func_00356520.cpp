/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Table { char pad[8]; char **entries; };
struct Ctx { char pad[0x60]; Table *tbl; };
struct Self {
    char pad0[4];
    Ctx *ctx;
    char pad8[0x17BC - 8];
    char disp[1];
};
struct Globals { char pad[0x18C]; char *fmt; };
struct Disp { char pad[0x20]; unsigned int color; };

extern Globals *D_00584418;
extern char D_005F44E8[];
extern "C" void func_004A6500(char *, char *, ...);
extern "C" void RaceEventDisplay__clear(void *, f32);
extern "C" void func_0035A5F0(void *, char *, s32);
extern "C" void RaceEventDisplay__addEvent(void *, char *, f32, f32, f32, f32);

extern "C" void func_00356520(Self *self, s32 idx) {
    char buf[0x100];
    Disp *d;
    char *fmt = D_00584418->fmt;
    char *b = buf;
    if (fmt) {
        d = (Disp *)((char *)self + 0x177C);
        func_004A6500(b, fmt, self->ctx->tbl->entries[idx] + 0x5464);
        RaceEventDisplay__clear(d, 0.0f);
        d->color = 0x80C8C8C8;
        func_0035A5F0(d, D_005F44E8, 1);
        RaceEventDisplay__addEvent(d, b, 3.0f, 0.0f, 0x1.333332p-3f, 0x1.333332p-3f);
    }
}
