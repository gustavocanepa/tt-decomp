struct Tex {
    char pad0[8];
    int width;
    int height;
    char pad10[0x30];
    Tex(int format, int width, int height) __asm__("func_001048C8");
    ~Tex() __asm__("func_00104868");
};

extern "C" float func_002D3288(void *self, float t) throw();
extern "C" void func_00104D10(Tex *tex);
extern "C" void func_00104C88(Tex *tex);
extern "C" void func_00475A88(int *x, int *y, int *w, int *h);
extern "C" void func_00478C98(int mode);
extern "C" void func_00470478(int on);
extern "C" void func_00477E30(float r, float g, float b, float a);
extern "C" void func_00472268(int k, int v);
extern "C" void func_00474318(float x0, float y0, float x1, float y1, float u0, float v0, float u1, float v1);
extern "C" void func_004707F0(int x, int y, int w, int h);
extern "C" void func_0046F0F8(int mode);
extern "C" void func_00470328(int mode, float value);

extern "C" void func_002D6748(void *self, Tex *target, float t) {
    float scale = func_002D3288(self, t);
    if (scale == 0.0f)
        return;

    int r[4];
    func_00475A88(&r[0], &r[1], &r[2], &r[3]);
    int h = (int)(r[3] * 27.0f / scale);
    int lo = r[3] / 20;
    if (h > 128)
        h = 128;
    if (h < lo)
        h = lo;
    int w = h * r[2] / r[3];
    if (w > 128)
        w = 128;
    Tex tex(2, 128, 128);

    func_00104D10(target);
    func_00104C88(&tex);
    func_00478C98(6);
    func_00478C98(5);
    func_00470478(0);
    func_00478C98(4);
    func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
    func_00472268(2, 0);
    func_00472268(3, 0);
    func_00474318(-0.5f, -0.5f, w - 0.5f, h - 0.5f, r[0], r[1], r[0] + r[2], r[1] + r[3]);
    func_00104C88(target);
    func_00104D10(&tex);
    func_004707F0(0, 0, target->width, target->height);
    func_0046F0F8(3);
    func_00470328(5, 0.5f);
    func_00474318(r[0], r[1], r[0] + r[2], r[1] + r[3], -0.5f, -0.5f, w - 0.5f, h - 0.5f);
    func_00478C98(3);
    func_00470478(1);
    func_00104C88(target);
}
