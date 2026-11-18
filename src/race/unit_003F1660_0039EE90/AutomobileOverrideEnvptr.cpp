typedef unsigned char u8;
struct Packed { u8 kind, a, b, c[2], d, e, f; };
struct Expanded { u8 kind; float a, b, c[2], d, e, f; };
extern Packed D_00584AD0[5];
extern Expanded D_00584AF8[5];

extern "C" void AutomobileOverrideEnvptr() {
    const Packed *in = D_00584AD0;
    Expanded *out = D_00584AF8;
    int i;
    for (i = 0; i < 5; i++) {
        const Packed *src = in;
        Expanded *dst = out;
        int j;
        unsigned int v = i * sizeof(Packed) + (unsigned int)src;
        src = (const Packed *)(v);
        unsigned int v2 = i * sizeof(Expanded) + (unsigned int)dst;
        dst = (Expanded *)(v2);
        dst->kind = src->kind;
        dst->a = src->a * 0x1.0624dcp-10f;
        dst->b = src->b / 100.0f;
        for (j = 0; j < 2; j++)
            dst->c[j] = src->c[j] / 100.0f;
        dst->d = src->d * 0x1.0624dcp-10f;
        dst->e = src->e * 0x1.1c71c6p-2f;
        dst->f = src->f * 0x1.1c71c6p-2f;
    }
}
