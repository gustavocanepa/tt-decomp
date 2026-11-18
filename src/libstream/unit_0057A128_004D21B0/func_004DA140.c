/* compiler: ee-gcc2.9-991111 */
typedef struct Out Out;
typedef struct Blk Blk;
typedef struct Sub Sub;
typedef struct Hdr Hdr;
struct Hdr {
    char pad0[4];
    unsigned short u4;
    char pad6[0xA];
    unsigned short u10;
    unsigned short u12;
    char pad14[8];
    int off1C;
    char pad20[0xA];
    unsigned short u2A;
    unsigned short u2C;
};
struct Sub {
    int w0;
    int w4;
    char pad8[0x20];
    int w28;
    char pad2C[8];
    int w34;
    char pad38[4];
    int w3C;
};
struct Blk { int w[10]; };
struct Out {
    int code;
    int w4;
    int w8;
    int wC;
    Blk blk;
};

int func_004DA140(Hdr *h, Out *o) {
    int off = h->off1C;
    Sub *t = (Sub *)((char *)h + off);
    if (h->u4 == 0x101 && h->u12 == 8 && h->u2A == 0x20) {
        unsigned a0 = h->u2C;
        if (a0 == 2 && t->w0 == 0x70000090) {
            Blk *b;
            unsigned v1 = h->u10;
            if (v1 != 0xFF91) {
                if (v1 != a0) {
                    goto fail;
                }
                o->code = 1;
            } else {
                o->code = a0;
            }
            b = (Blk *)((char *)h + t->w4);
            o->w4 = t->w28;
            o->w8 = t->w34;
            o->wC = t->w3C;
            o->blk.w[0] = b->w[0];
            o->blk.w[1] = b->w[1];
            o->blk.w[2] = b->w[2];
            o->blk.w[3] = b->w[3];
            o->blk.w[4] = b->w[4];
            o->blk.w[5] = b->w[5];
            o->blk.w[6] = b->w[6];
            o->blk.w[7] = b->w[7];
            o->blk.w[8] = b->w[8];
            o->blk.w[9] = b->w[9];
            return o->code;
        }
    }
fail:
    o->code = -1;
    return -1;
}
