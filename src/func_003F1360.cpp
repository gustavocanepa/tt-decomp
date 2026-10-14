struct Rec { char p0[4]; short s4; short s6; short s8; char pa[6]; };
struct Blk { char p0[8]; char *data; char pc[4]; };
struct O { char p0[0x10]; Blk *blks; char p14[8]; Rec *recs; };
extern "C" {
void *GT4_Motion__PlayList__getElement(void *);
int func_003F1A70(void *, void *, const char *);
int func_003F1360(O *o, int idx, const char *name) {
    if (name != 0 && idx >= 0) {
        Rec *r = (Rec *)((idx << 4) + (int)o->recs);
        int e = r->s8;
        if (e >= 0) {
            Blk *b = (Blk *)((char *)o->blks + (r->s4 << 4));
            char *el = b->data + (e << 5);
            void *x = GT4_Motion__PlayList__getElement(el);
            return func_003F1A70(el, x, name);
        }
        return 0;
    }
    return 0;
}
}
