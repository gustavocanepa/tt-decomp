struct Tag {
    int v;
};
struct Comp {
    int id;
    int coef[64];
    Tag tag;
};
struct Src {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
};
struct Pair {
    int a;
    int b;
};
struct Info {
    char p[8];
    int type;
    int f0C;
};
struct Sub {
    char p0[0x430];
    int qp[3][2];
};
struct Obj {
    char p0[8];
    Pair hdr[3];
    int f20;
    int f24;
    int f28;
    char p2C[0x12C - 0x2C];
    Comp blk[3];
    char p444[0xA68 - 0x444];
    char *buf;
    int fA6C;
    char pA70[0xA78 - 0xA70];
    int fA78;
};

extern "C" void func_0045A880(Obj *) throw();
extern "C" void func_0045A8C0(Obj *) throw();
extern "C" char *malloc(int) throw();
extern signed char D_00602468[][6];
extern int D_00602A2C;
extern int D_00602A30[64];

static inline Sub *sub(Obj *o) { return (Sub *)((char *)o + 0x14); }

static inline int *header_words(Obj *self) { return (int *)self->hdr; }
extern "C" int func_0045A8F0(Obj *self, Info *info, Src *src, int w, int h, int *pp, Comp **bp, int extra)
{
    int i, j;
    int type = info->type;
    func_0045A880(self);
    func_0045A8C0(self);
    Pair *hdr = self->hdr;
    for (i = 0; i < 3; i++) {
        hdr[i].a = src[i].b;
        hdr[i].b = src[i].c;
    }
    self->f20 = w;
    self->f24 = h;
    self->f28 = 0;
    if (type == 3) {
        for (i = 1; i < 4; i++) {
            int ok = 1;
            for (j = 0; j < 6; j++) {
                if (D_00602468[i][j] != (header_words(self))[j])
                    ok = 0;
            }
            if (ok)
                self->f28 = i;
        }
    }
    self->buf = malloc(w * h * 0x300);
    if (self->buf == 0)
        return 0;
    for (i = 0; i < type; i++) {
        Comp *c = &self->blk[i];
        for (j = 0; j < 2; j++)
            sub(self)->qp[i][j] = *pp++;
        Tag keep = c->tag;
        *c = **bp;
        c->tag = keep;
        bp++;
    }
    int sh = D_00602A2C - 2;
    for (i = 0; i < type; i++) {
        int *cp = self->blk[i].coef;
        for (j = 0; j < 64; j++) {
            int v = cp[j] * D_00602A30[j];
            if (v < 0)
                v = (v >> sh) | (-1 << -sh);
            else
                v = v >> sh;
            cp[j] = v;
        }
    }
    self->fA6C = 0x80;
    if (info->f0C != 8)
        self->fA6C = 0x800;
    self->fA78 = extra;
    return 1;
}
