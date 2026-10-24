/* compiler: ee-gcc2.96-nogcse */
typedef unsigned int u32;
typedef unsigned char u8;
struct Str { u8 *data; u32 size; };
extern "C" int func_004149E8(Str *a, Str *b) {
    u32 lim = a->size;
    u32 bsz = b->size;
    if (lim < bsz) lim = bsz;
    int i = lim - 1;
    if (i >= 0) {
        u32 asz = a->size;
        Str *q = b;
        do {
            u8 va = 0;
            if ((u32)i < asz) va = a->data[i];
            u8 vb = 0;
            if ((u32)i < q->size) vb = b->data[i];
            if (va < vb) return -1;
            if (vb < va) return 1;
            i--;
        } while (i >= 0);
    }
    return 0;
}
