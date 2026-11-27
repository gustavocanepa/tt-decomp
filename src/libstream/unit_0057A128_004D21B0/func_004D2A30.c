/* compiler: ee-gcc2.9-991111 */
typedef struct E { struct E *next; unsigned flags; int val; } E;
typedef struct G {
    int pad0;
    int pad4;
    unsigned unk8;
    int unkC;
    int unk10;
    int pad14;
    unsigned unk18;
    unsigned unk1C;
} G;
extern G D_0077A008;
extern int *func_004D2FD8();

int func_004D2A30(void)
{
    int *pool;
    E *p;
    int *r;
    int *next, *zero, *value;
    G *g = &D_0077A008;
    G *h;

    pool = (int *)g->unkC;
    if (pool == 0) {
        return 0;
    }
    pool[0] = 0;
    g->unk18 = 0xFFFFFFFF;
    g->unk1C = 0xFFFFFFFF;
    zero = pool;
    next = pool + 1;
    value = pool + 4;
    do {
        *next = (int)value;
        zero[2] = 0;
        next += 3;
        zero[3] = 0;
        value += 3;
        zero += 3;
    } while ((int)next < (int)(pool + 61));
    h = &D_0077A008;
    pool[3] = (pool[3] & 1) | ((h->unk8 >> 8) << 1);
    pool[0x3A] = 0;
    h->unk10 = 1;
    if (func_004D2FD8(0, h->unkC, 0) != 0) {
        h->unkC = 0;
        return 0;
    }
    r = func_004D2FD8(0, 0xF4, 0);
    if (r != (int *)h->unkC) {
        h->unkC = 0;
        return 0;
    }
    p = (E *)(r + 1);
    while (p) {
        if (!(p->flags & 1)) {
            return (p->flags >> 1) << 8;
        }
        p = p->next;
    }
    return 0;
}
