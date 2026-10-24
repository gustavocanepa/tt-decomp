#include "types.h"
struct Rec { char p0[4]; short s4; short s6; short s8; char pa[6]; };
struct Blk { char p0[8]; char *data; char pc[4]; };
struct O { char p0[0x10]; Blk *blks; char p14[8]; Rec *recs; };
extern "C" u16 func_003F1A08(u16 *) throw();
extern "C" u16 func_003F13F0(O *o, int idx) {
    if (idx < 0) return 0;
    idx = idx * sizeof(Rec) + (int)o->recs;
    int e = ((Rec *)idx)->s8;
    if (e >= 0) {
        Blk *b = o->blks;
        b += ((Rec *)idx)->s4;
        return func_003F1A08((u16 *)(b->data + (e << 5)));
    }
    return 0;
}
