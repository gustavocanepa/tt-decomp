/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct V { unsigned x, y, z; } V;
int func_004692D8(unsigned long, unsigned long, unsigned long);
void func_0046BE80(void);
#define CLIP(p, q, r) do { bits &= func_004692D8((p)->x, (q)->y, (r)->z); if (!bits) return 1; } while (0)
int func_00469340(V *a, V *b) {
    int bits = 0x3f;
    func_0046BE80();
    CLIP(a, a, a);
    CLIP(b, b, b);
    CLIP(a, a, b);
    CLIP(b, b, a);
    CLIP(a, b, a);
    CLIP(b, a, b);
    CLIP(a, b, b);
    bits &= func_004692D8(b->x, a->y, a->z);
    return bits == 0;
}
