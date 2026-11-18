/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Wheel { char p0[0x20]; f32 f20; char p1[0x64 - 0x24]; f32 f64; char p2[0x80 - 0x68]; f32 f80; char p3[0xEC - 0x84]; };
struct Sub { char p[0x51A]; short s4FA; };
extern f32 D_007673A4;
extern f32 D_00767384;
extern f32 D_0076738C;
extern f32 D_00767394;
extern "C" f32 func_002F9EC8(void *) throw();
extern "C" void func_002F9B80(void *, f32) throw();
extern "C" f32 func_002F9C00(void *, f32) throw();

extern "C" f32 func_002FA8B0(void *arg0) {
    char *base = (char *)arg0;
    Sub *sub = (Sub *)(base + 0x104);
    f32 res = 0.0f;
    f32 r = func_002F9EC8(arg0);
    f32 c = 9542.84f;
    f32 acc = 0.0f;
    f32 k = *(f32 *)(base + 0x56C);
    int i;
    for (i = 0; i < 2; i++) {
        Wheel *w = (Wheel *)(base + 0x34C + i * 0xF4);
        if (w->f64 != 0.0f) {
            f32 t = w->f80 * w->f20;
            if (t < 0.0f) t = -t;
            t *= 0.0010006767f;
            acc += t;
        }
    }
    if (D_007673A4 < acc) acc = D_007673A4;
    f32 z = 0.0f;
    func_002F9B80(arg0, acc * k);
    if (r > z) {
        f32 q = (f32)sub->s4FA;
        res = D_00767384 * c / q;
        if (D_0076738C < res) res = D_0076738C;
        f32 f = res * q / c * r * k;
        res = res * r;
        f = func_002F9C00(arg0, f) / f;
        res = res * f;
    } else {
        f32 q = (f32)sub->s4FA;
        res = D_00767384 * c / q;
        if (D_00767394 < res) res = D_00767394;
        f32 f = res * q / c * r;
        res = res * r;
        func_002F9B80(arg0, -f * k);
    }
    return res;
}
