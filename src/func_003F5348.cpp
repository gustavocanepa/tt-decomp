/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Out { char p0[8]; u8 cnt; u8 f9; u8 fA; u8 fB; unsigned w[4]; };

extern "C" void func_003F5348(Out *out, unsigned *in) {
    int cnt = 0;
    int k = 0;
    for (; k < 4 && (in[k] & 0x01000000); k++)
        cnt++;
    out->cnt = cnt;
    if ((u8)cnt) {
        const struct Input { unsigned w[4]; } *src = (const Input *)in;
        for (int i = 0; i < 4; i++)
            out->w[i] = (src->w[i] & 0xFFFFFF) | 0x80000000;
        out->fA = ((int)in[0] >> 25) & 1;
        out->f9 = ((int)in[0] >> 26) & 1;
        out->fB = ((int)in[0] >> 27) & 1;
    }
}
