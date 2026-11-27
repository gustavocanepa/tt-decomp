/* Hand-written from the listing of func_002EA2D8 (not a library match). */

struct Src {
    unsigned char flags;   /* 0x00: lbu, bit 0 and bit 1 tested */
    char pad1[3];
    short v4;              /* 0x04: lh */
    char pad2[2];
    short v8;              /* 0x08: lh */
};

struct Dst {
    char pad0[0x480];
    signed char a;         /* 0x460: sb */
    signed char b;         /* 0x481: sb */
};

extern "C" void func_002EA2D8(void *arg0, void *arg1) {
    struct Dst *d = (struct Dst *)arg0;
    struct Src *s = (struct Src *)arg1;

    if ((unsigned char)(s->flags & 1) == 0) {
        short v = s->v4;
        if (v == 0) {
            d->a = 0;
        } else if (v > 0) {
            d->a = 0x64;
        } else {
            d->a = -0x64;
        }
    } else {
        int t = s->v4 * 100;
        int adj = (t < 0) ? (t + 0xFFF) : t;
        d->a = (signed char)(adj >> 12);
    }

    if (!(s->flags & 2)) {
        if (s->v8 == 0) {
            d->b = 0;
        }
    } else {
        if (s->v8 != 0x1000) {
            d->b = 0;
        }
    }
}
