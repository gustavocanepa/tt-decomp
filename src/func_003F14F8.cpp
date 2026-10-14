/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Rec { char p0[4]; short s4; short s6; short s8; char pa[6]; };
struct Blk { char p0[8]; char *data; char pc[4]; };
struct O { char p0[0x10]; Blk *blks; char p14[8]; Rec *recs; };
struct Src {
    int w0;
    float f4;
    int w8;
    float fC;
    u16 h10;
    char p12[6];
    int w18;
    int w1C;
};
struct Dst {
    int w0;
    float f4;
    float f8;
    int wC;
    int w10;
    int w14;
};
extern "C" u16 func_003F1A08(u16 *);
extern "C" Src *func_003F1A10(void *, int);
extern "C" int func_003F14F8(Dst *out, O *o, int idx, int id) {
    if (idx >= 0 && id >= 0) {
        Rec *rec = (Rec *)((idx << 4) + (int)o->recs);
        int e = rec->s8;
        if (e >= 0) {
            Blk *b = (Blk *)((char *)o->blks + (rec->s4 << 4));
            char *el = b->data + (e << 5);
            int n = func_003F1A08((u16 *)el);
            int r = 0;
            if (id < n) {
                Src *s = func_003F1A10(el, id);
                if (s) {
                    out->w0 = s->w18;
                    float x = s->f4;
                    float y = s->fC;
                    out->f4 = x;
                    out->f8 = x + y;
                    out->wC = s->h10;
                    out->w10 = s->w1C;
                    out->w14 = s->w0;
                    return 1;
                }
            } else
                return r;
        }
    }
    return 0;
}
