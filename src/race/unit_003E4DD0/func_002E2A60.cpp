/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Texture {
    int resource, flags, width, height, a10, a14, a18, a1c;
    float u, v;
    int a28, a2c, a30, owned, a38;
    Texture(int, int, int) asm("func_001048C8");
    ~Texture() asm("func_00104868");
};
struct Inner { char pad[0x914]; int w; char pad918[4]; int h; };
struct Self { char pad[0x10]; Inner *inner; };
extern "C" void func_002E2CA0(Self *, int, int);
extern "C" void func_001050C0(Texture *, Texture *, int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_00104C88(Texture *);
extern "C" void func_00104CF0(Texture *);
extern "C" void func_00470B48(int);
extern "C" void func_00470E60(int);
extern "C" void func_00473498();
extern "C" void func_00104D10(Texture *);
extern "C" void func_00478C98(int);
extern "C" void func_0046F0F8(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00470478(int);
extern "C" void func_00477E30(float, float, float, float);
extern "C" int GSBuffer__getBufferWidth(Texture *);
extern "C" int func_00104E00(Texture *);
extern "C" void func_00474288(int, int, int, int, int, int, int, int);

extern "C" void func_002E2A60(Self *self, Texture *tex, int arg2, int arg3) {
    Inner *in = self->inner;
    int w = in->w;
    int h = in->h;
    if (w >= 0x41) w = 1;
    if (h >= 0x41) h = 1;
    if (w <= 0) w = 1;
    if (h <= 0) h = 1;
    int big = tex->height >= 0x101;
    if ((w == 1 && h == w) || big) {
        func_002E2CA0(self, arg2, arg3);
        return;
    }
    int tw = GSBuffer__getBufferWidth(tex) / w;
    int th = tex->height / h;
    Texture a(0, tw, th);
    Texture b(0x31, tw, th);
    func_001050C0(&b, tex, 0, 0);
    pglPushAttrib(0x887);
    func_00104C88(&a);
    func_00104CF0(&b);
    func_00470B48(0);
    func_00470E60(1);
    func_002E2CA0(self, 1, arg3);
    func_00473498();
    func_00104D10(&a);
    func_00478C98(5);
    func_00478C98(8);
    func_0046F0F8(6);
    func_004702D8(0x68, 1.0f);
    func_00470478(0);
    func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
    int bw = tex->width;
    int bh = func_00104E00(tex);
    func_00474288(0, 0, bw, bh, 0, 0, (b.a10 + b.a18) - (h >= 2), (b.a14 + b.a1c) - (w >= 2));
    func_00470478(1);
}
