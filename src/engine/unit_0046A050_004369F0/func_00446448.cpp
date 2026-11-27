struct Seg { char pad[0x88]; char *tbl; };
struct Item { short idx; unsigned short flag; };
struct Pt { int a, b; };
struct Ctx {
    char pad[0x6E14];
    void *canvas;
    char sub[8];
    Seg *seg;
    int pad2;
    float f28;
    float f2c;
};
extern "C" void func_004399D0(void *, void *, void *);
extern "C" void func_00439BB8(void *, void *, int, int, float);
extern "C" void func_00439EC8(void *, unsigned);
extern "C" void func_0043FCD0(float *, void *, void *, float);
extern "C" unsigned func_00445370(const unsigned char *, const unsigned char *);
extern "C" int func_00446560(Item *, Ctx *, int, float, float);

extern "C" void func_00446448(Item *it, Ctx *c, float t) {
    struct { float v; unsigned char buf[12]; } L;
    int i;
    if (it->idx >= 0) {
        int n = func_00446560(it, c, 0x400, c->f28, t);
        char *e = c->seg->tbl + it->idx * 16;
        func_0043FCD0(&L.v, e, e + 8, t);
        func_00439EC8(c->canvas, func_00445370((unsigned char *)c->sub, L.buf));
        if (L.v * c->f2c < 1.1f) {
            Pt *p = (Pt *)c;
            i = 0;
            int m = n - 1;
            if (m > 0) {
                do {
                    Pt *q = p + 1;
                    func_004399D0(c->canvas, p, q);
                    i++;
                    p = q;
                } while (i < m);
            }
        } else {
            func_00439BB8(c->canvas, c, n, it->flag != 0, L.v);
        }
    }
}
