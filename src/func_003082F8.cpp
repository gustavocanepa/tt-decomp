/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Output { char pad[0x78]; float a[8]; float b[8]; char gap[0x10]; float c[6]; float d[6]; };
extern "C" int func_002FD8A0(char *, int, float *, float *, u8 *, u8 *) throw();

extern "C" int func_003082F8(Output *self, u8 *p) {
    p[0x10] = 0;
    int u = p[2];
    if (u == 0) u = 0x5A;
    float f = (float)u * 0x1.1df468p-6f;
    p[0x18] = 0;
    if (f > 0x1.921fb4p+0f) f = 0x1.921fb4p+0f;
    int n = p[8];
    int i = 0;
    if (n != 0) {
        u8 *q = p + 8;
        do {
            unsigned o = i + 0x10;
            self->a[i] = ((float)p[o] * f) / 255.0f;
            self->b[i] = (float)q[o] / 200.0f;
            i++;
        } while (i < n);
    }
    func_002FD8A0((char *)self + 0x6C, n, (float *)((char *)self + 0x78), (float *)((char *)self + 0x98), 0, 0);
    p[0x50] = 0;
    n = p[0xC];
    i = 0;
    f = 0x1.921fb2p+0f;
    p[0x56] = 0;
    if (n != 0) {
        u8 *q = p + 6;
        do {
            unsigned o = i + 0x50;
            self->c[i] = ((float)p[o] * f) / 255.0f;
            self->d[i] = (float)q[o] / 200.0f;
            i++;
        } while (i < n);
    }
    return func_002FD8A0((char *)self + 0xBC, n, (float *)((char *)self + 0xC8), (float *)((char *)self + 0xE0), 0, 0);
}
