struct S { char pad[0x20]; int w; int h; char pad2[0xA68 - 0x28]; int *src; };
extern unsigned char D_00603430[];
extern "C" void func_0045B1E0(S *s, unsigned char *dst, int stride) {
    int w = s->w * 8; int h = s->h * 8; int *p = s->src; unsigned char *tbl = D_00603430;
    int skip = stride - w;
    if (h > 0) {
        do {
            int x = w;
            if (x > 0) {
                do {
                    unsigned char v = tbl[*p++];
                    x--;
                    dst[2] = v; dst[1] = v; dst[0] = v;
                    dst += 3;
                } while (x > 0);
            }
            h--;
            dst += skip * 3;
        } while (h > 0);
    }
}
