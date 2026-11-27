/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Huff {
    int pad0;
    int n;
    int pad8;
    unsigned char *sizes;
    unsigned short *codes;
};
extern "C" int func_0045D3D8(Huff *h, int *counts) {
    Huff *self = h;
    int k = 0;
    int n = self->n;

    int len;
    for (len = 1; len < 17; len++) {
        int j = 1;
        if (counts[len - 1] > 0) {
            do {
                if (!(k < n)) return 0;
                self->sizes[k] = len;
                j++;
                k++;
            } while (!(counts[len - 1] < j));
        }
    }
    if (k != n) return 0;
    int i = 0;
    int code = 0;
    int sz = self->sizes[0];
    for (;;) {
        while (self->sizes[i] == sz) {
            self->codes[i] = code;
            i++;
            code++;
            if (!(i < n)) goto success;
        }
        int v = self->sizes[i];
        if (v < sz) return 0;
        do {
            sz++;
            code <<= 1;
        } while (v != sz);
    }
success:
    return 1;
}
