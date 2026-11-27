/* compiler: ee-gcc2.96-no-strict-aliasing */
struct TexData {
    char pad0[0x20];
    unsigned long bits;
};

struct Texture {
    char pad0[0x18];
    TexData *data;
};

struct AutomaticFader {
    float value;
    float get() const { return value; }
};

struct Self {
    char pad0[0x18];
    int mode;
    Texture *tex;
    AutomaticFader fader;
    char pad24[0x3C - 0x24];
    float value;
    float other;
    int width;
};

struct Target {
    int id;
    int flags;
};

struct Font {
    int unk0;
    int flags;
    float x;
    float y;
    char pad10[8];
    float sx;
    float sy;
};

extern Font D_00585CC8;
extern char D_005F55D0[];
extern char D_005F55D8[];
extern char D_005F5600[];

extern "C" {
void func_00104BA8(Target *t);
void func_00104A48(Target *t, int w, int h);
int func_00104B10(Target *t);
void func_00104C88(Target *t);
void func_0038EC28(Texture *t, float x0, float y0, float x1, float y1, int filter, int blend);
unsigned int func_0038F5F8(unsigned int color, float alpha);
void func_00415540(Font *f);
void func_00415578(Font *f);
void func_004155A8(Font *f, const char *name);
void func_00415B10(Font *f, unsigned int color);
float func_00415C58(Font *f, const char *s);
void func_00415D18(Font *f, const char *fmt, ...);
void func_00416010(Font *f, float sx, float sy);
int func_00416030(Font *f, int w, int h);
void func_0046F0F8(int mode);
void func_00470220(int mode, float ref);
void func_00470298(int mode);
void func_004702D8(int mode, float ref);
void func_00470450(int mask);
void func_00470478(int on);
void func_00470B48(int on);
void func_00470E60(int on);
void func_00473178(int mode);
void func_00473050(void);
void func_004730A8(void);
void pglPushAttrib(int mask);
void func_00473498(void);
void func_004738A0(float l, float r, float b, float t, float n, float f);
void func_004751FC(void);
void func_00477DC0(unsigned int color);
void func_00477E30(float r, float g, float b, float a);
void func_00478C98(int mode);
}

extern "C" void RaceMTRMultiFunctionDisplay__render_buffer(Self *self, Target *target)
{
    int w = 8;
    int h = 1;

    pglPushAttrib(1);
    if (self->tex) {
        unsigned long bits = self->tex->data->bits;
        w = ((bits >> 14) & 0x3FF) + 1;
        h = ((bits >> 34) & 0x3FF) + 1;
    }
    if (target->id == -1) {
        func_00104BA8(target);
        func_00104A48(target, w, h);
        target->flags = 0;
        func_00104B10(target);
    }
    func_00104C88(target);
    func_00470450(-1);
    func_00470B48(0);
    func_00470E60(1);
    if (!self->tex)
        return func_00473498();

    float fw = (float)w;
    float fh = (float)h;
    func_00477DC0(0x80FFFFFF);
    func_0046F0F8(6);
    func_00478C98(15);
    func_00478C98(5);
    func_00470478(0);
    func_004702D8(0x44, 0.0f);
    func_00473178(1);
    func_00473050();
    func_004751FC();
    func_004738A0(0.0f, fw, fh, 0.0f, -1.0f, 1.0f);
    func_00473178(0);
    func_00473050();
    func_004751FC();
    func_00477E30(1.0f, 1.0f, 1.0f, self->fader.get());
    func_0038EC28(self->tex, 0.0f, 0.0f, fw, fh, 0, 0);
    func_0046F0F8(4);
    func_00470220(6, self->fader.get() * 0.5f);
    func_00470298(0);

    Font *font = &D_00585CC8;
    float sx = font->sx;
    float sy = font->sy;
    func_00416010(font, 1.0f, 1.0f);
    func_004155A8(font, D_005F5600);
    func_00416030(font, w, h);
    func_00415540(font);
    if ((float)self->width == 0.0f)
        self->width = (int)func_00415C58(font, D_005F55D0);

    unsigned int color = 0;
    int value = 0;
    switch (self->mode) {
    case 0:
        break;
    case 1:
        value = (int)self->other;
        color = 0x800255D8;
        break;
    case 2:
        value = (int)self->value;
        color = 0x80B58E43;
        break;
    case 3:
        value = (int)self->value;
        color = 0x800000C6;
        break;
    }
    if (value < 0)
        value = 0;
    else
        value = value >= 1000 ? 999 : value;

    func_00415B10(&D_00585CC8, func_0038F5F8(color, self->fader.get()));
    float x = (float)((w >> 1) + self->width);
    float y = (float)((h >> 1) - 1);
    D_00585CC8.flags = 6;
    D_00585CC8.y = y;
    D_00585CC8.x = x;
    func_00415D18(&D_00585CC8, D_005F55D8, value);
    D_00585CC8.flags = 0;
    func_00415578(&D_00585CC8);
    func_00478C98(4);
    func_00473178(0);
    func_004730A8();
    func_00473178(1);
    func_004730A8();
    func_00473178(0);
    func_00416010(&D_00585CC8, sx, sy);
    func_00473498();
}
