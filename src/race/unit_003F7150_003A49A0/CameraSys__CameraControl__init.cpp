/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cam {
    int w0, w4, w8, wC, w10;
    unsigned w14 : 32;
    unsigned w18, w1C, w20, w24;
    int w28;
    int w2C;
    int w30, w34, w38, w3C, w40, w44, w48, w4C;
    unsigned w50, w54;
};

extern "C" void CameraSys__CameraControl__init(Cam *c, int v)
{
    unsigned char *b = (unsigned char *)c;
    c->w1C = c->w1C & 0xFF00FFFF;
    c->w14 = 2;
    b[0x1F] = 0;
    c->w18 = c->w18 & ~0xFFu;
    b[0x19] = 0;
    c->w20 = c->w20 & ~0xFFu;
    c->w20 = c->w20 & 0xFFFF00FFu;
    c->w1C = c->w1C & ~0xFFu;
    c->w0 = v;
    c->w4 = v;
    c->w8 = v;
    c->w24 = c->w24 & ~0xFFu;
    c->w1C = c->w1C & 0xFFFF00FFu;
    c->w18 = (unsigned short)c->w18;
    c->wC = 0;
    c->w10 = 0;
    b[0x22] = 0;
    b[0x23] = 0;
    c->w28 = 0;
    b[0x2C] = 0;
    c->w30 = 0;
    c->w34 = 0;
    c->w38 = 0;
    c->w3C = 0;
    c->w40 = 0;
    c->w44 = 0;
    c->w48 = 0;
    b[0x4C] = 0;
    b[0x4D] = 0;
    b[0x4E] = 0;
    b[0x50] = 0;
    b[0x51] = 0;
    c->w54 = c->w54 & ~0xFFu;
    c->w54 = c->w54 & 0xFFFF00FFu;
    c->w54 = c->w54 & 0xFF00FFFFu;
    b[0x4F] = 0;
    c->w50 = (unsigned short)c->w50;
    b[0x57] = 0;
}
