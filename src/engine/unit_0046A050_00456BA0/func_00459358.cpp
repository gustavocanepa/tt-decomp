/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Reader { char p0[0x10]; u32 f10; char p1[0xC]; int f20; };
struct Elem { char p[0x14]; char *p14; };
struct Obj { int f0, f4; char p0[0xA88 - 8]; Reader rd; char p1[0xDDC - 0xA88 - sizeof(Reader)]; u32 fDDC; };
extern "C" {
void func_00458778(Obj *) throw();
int func_004587A0(Obj *) throw();
u32 func_004599A8(Reader *);
int func_00459A38(Reader *);
int func_0045D308(Elem *, int);
int func_0045D3D8(Elem *, u32 *);
void func_0045D4D8(Elem *);
}
static inline void error(Obj *self, const int &code) { self->f0=code; self->f4=1; }
extern "C" int func_00459358(Obj *self) {
    Reader *rd = &self->rd;
    u32 limit = rd->f10 + (func_00459A38(rd) - 2);
    u32 cur;
    do {
        u32 v = func_004599A8(rd);
        u32 a = v >> 4;
        u32 b = v & 0xF;
        u32 buf[16];
        int sum, n;
        int r;
        Elem *e;
        if (a >= 2) goto invalid;
        if (b >= 3) goto invalid;
        sum = 0;
        u32 *p = buf;
        n = 0xF;
        do {
            n--;
            u32 x = func_004599A8(rd);
            *p = x;
            p++;
            sum += x;
        } while (n >= 0);
        r = func_004587A0(self);
        if (r == 0) return r;
        if (sum == 0) goto invalid;
        char *row = (char *)self + a * 0x6C;
        e = (Elem *)(row + b * 0x24 + 0x10F8);
        r = func_0045D308(e, sum);
        if (r == 0) { error(self,2); return r; }
        r = func_0045D3D8(e, buf);
        if (r == 0) { error(self,4); return r; }
        for (int j = 0; j < sum; j++) e->p14[j] = func_004599A8(rd);
        func_0045D4D8(e);
        r = func_004587A0(self);
        if (r == 0) return r;
        cur = rd->f10;
    } while (cur < limit);
    if (cur == limit && rd->f20 == 0) {
        self->fDDC |= 4;
        return 1;
    }
    func_00458778(self);
    return 0;
invalid:
    self->f0=4;
    self->f4=1;
    return 0;
}
