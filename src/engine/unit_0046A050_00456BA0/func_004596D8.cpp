struct Rec { int tag; int pad[3]; int a; int b; };
struct S {
    int f0, f4;
    char pad8[0xA88 - 8];
    char reader[0x40];
    int count;
    char pad2[0xD84 - 0xAC8 - 4];
    Rec recs[3];
    char pad3[0xDDC - 0xD84 - 3 * 0x18];
    unsigned flags;
};
extern "C" int func_00459A38(void *);
extern "C" int func_004599A8(void *);
extern "C" int func_004587A0(S *);

extern "C" int func_004596D8(S *s) {
    void *r = s->reader;
    func_00459A38(r);
    int n = func_004599A8(r);
    if (n == s->count) {
        int i = 0;
        if (n > 0) {
            int *pa = &s->recs[0].a;
            int *pb = &s->recs[0].b;
            do {
                int tag = func_004599A8(r);
                unsigned v = func_004599A8(r);
                if (pa[-4] != tag) goto bad;
                i++;
                *pa = v >> 4;
                *pb = v & 0xF;
                pa += 6;
                pb += 6;
            } while (i < n);
        }
        func_004599A8(r);
        func_004599A8(r);
        func_004599A8(r);
        if (func_004587A0(s)) {
            s->flags |= 0x10;
            return 1;
        }
        return 0;
    }
bad:
    s->f0 = 1;
    s->f4 = 1;
    return 0;
}
