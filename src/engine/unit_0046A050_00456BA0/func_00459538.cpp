/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rd { char pad0[0x10]; u32 f10; char pad14[0xC]; int f20; };
struct Q { int flag; int v[64]; int padq; };
struct Obj {
    int f0, f4;
    char pad8[0xA88 - 8];
    Rd rd;
    char pad_[0xDDC - 0xA88 - sizeof(Rd)];
    u32 flags;
    Q q[3];
};
extern int D_00602718[];
extern "C" void func_00458778(Obj *) throw();
extern "C" int func_004587A0(Obj *) throw();
extern "C" int func_004599A8(Rd *);
extern "C" int func_00459A38(Rd *);

static inline void error(Obj *o, const int &code) { o->f0 = code; o->f4 = 1; }
static inline void set(Q *q, int flag) { q->flag = flag; }
extern "C" int func_00459538(Obj *o) {
    Rd *r = &o->rd;
    u32 end = r->f10 + (func_00459A38(r) - 2);
    for (;;) {
        int v = func_004599A8(r);
        u32 pq = (u32)v >> 4;
        u32 tq = v & 0xF;
        if (pq < 2 && tq < 3) {
            Q *q = &o->q[tq];
            set(q,1);
            int *zp;
            int i;
            if (pq == 0) {
                for (i = 0, zp = D_00602718; i < 64; i++) {
                    int idx = *zp++;
                    q->v[idx] = func_004599A8(r);
                }
            } else {
                zp = D_00602718;
                for (i = 63; i >= 0; i--) {
                    int idx = *zp++;
                    q->v[idx] = func_00459A38(r);
                }
            }
            if (!func_004587A0(o)) return 0;
            if (r->f10 >= end) {
                if (r->f10 == end && r->f20 == 0) {
                    o->flags |= 2;
                    return 1;
                }
                func_00458778(o);
                return 0;
            }
        } else {
            goto invalid;
        }
    }
invalid:
    o->f0 = 5;
    o->f4 = 1;
    return 0;
}
