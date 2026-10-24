/* compiler: ee-gcc2.96-nogcse */
typedef unsigned int u32;
typedef unsigned char u8;
struct Str {
    u8 *data;
    u32 size;
};
extern "C" int func_00414AF8(Str *a, Str *b) {
    u32 lim = a->size;
    if (lim < b->size) lim = b->size;
    u32 i = 0;
    if (lim != 0) {
        u32 asz = a->size;
        Str *q = b;
        do {
            u8 va = 0;
            if (i < asz) va = a->data[i];
            u8 vb = 0;
            if (i < q->size) vb = b->data[i];
            if (va != vb) return 1;
            i++;
        } while (i < lim);
    }
    return 0;
}
