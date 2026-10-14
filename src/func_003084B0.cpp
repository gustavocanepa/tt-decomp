/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct In { u8 m0; u8 m1; u8 pad[9]; u8 mB; u8 pad2[0x5C - 0xC]; u8 m5C[4]; u8 m60[4]; u8 m64[24]; };
struct Out { float m0; float m4; float t[24]; char pad[0x68 - 0x68]; float m68; };
extern "C" float func_002FD3D0(void *, float) throw();
extern "C" int func_002FD8A0(void *, int, void *, void *, int, int) throw();
extern "C" float func_003084B0(void *self, char *o, In *in, float f)
{
    float *base = (float *)(o + 8);
    u8 *p = in->m64;
    float *v = base;
    int t0 = in->m0;
    if (!t0) t0 = 100;
    float s = (float)t0 * 0.01f;
    int i = 0x17;
    do {
        u8 b = *p++;
        if (b == 0)
            *v = s;
        else
            *v = (float)b * 0.01f * s;
        v++;
    } while (--i >= 0);
    s = f / s;
    *(float *)(o + 4) = (float)in->m1 * 0.01f;
    *(float *)(o + 0x68) = s;
    if (s > 1.0f) *(float *)(o + 0x68) = 1.0f;
    t0 = in->mB;
    in->m5C[0] = 0;
    if (t0) {
        v = base + 0x70;
        u8 *c = &in->m5C[4];
        u8 *a = &in->m5C[0];
        i = t0;
        do {
            u8 x = *a++;
            i--;
            v[-4] = (float)x * 20.0f * 0x1.399998p+3f;
            u8 y = *c++;
            *v = (float)y / 200.0f;
            v++;
        } while (i);
    }
    func_002FD8A0(o + 0x1AC, t0, o + 0x1B8, o + 0x1C8, 0, 0);
    *(float *)o = func_002FD3D0(o + 0x170, 0.0f) * 0x1.399998p+3f;
}
