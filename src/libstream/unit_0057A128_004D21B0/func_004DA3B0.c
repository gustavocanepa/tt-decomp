/* compiler: ee-gcc2.9-991111 */
struct Ent { int p0; int p4; int p8; int pc; int p10; unsigned p14; int p18; int p1c; int p20; unsigned p24; };
struct Sec { char pad[0x24]; int p24; int pad2[2]; unsigned p30; unsigned p34; };
struct Hdr { char pad[0x1c]; int p1c; int p20; char pad2[0xC]; unsigned short p30; };
struct Blk { int p0; int p4; int p8; int pc; int p10; int p14; int p18; int p1c; int p20; int p24; int p28; int p2c; int p30; };
extern void func_004DA528(int, void *, unsigned, int, int);
extern void func_004F64C4(int, void *, unsigned);
extern void func_004F6678(int, int, unsigned);

void func_004DA3B0(struct Hdr *h, struct Blk *b, int n) {
    struct Sec *sec = (struct Sec *)((char *)h + h->p1c);
    char *tab = (char *)h + h->p20;
    int i;
    struct Ent *en;
    if (b->p14 + 1 != 0) b->p14 += n;
    if (b->p28 + 1 != 0) b->p28 += n;
    if (b->p30 + 1 != 0) b->p30 += n;
    b->p18 += n;
    if (b->p10 + 1 != 0) b->p10 += n;
    func_004F64C4(b->p4, (char *)h + sec->p24, sec->p30);
    {
        unsigned hi = sec->p34;
        unsigned lo = sec->p30;
        if (lo < hi) func_004F6678(b->p4 + lo, 0, hi - lo);
    }
    i = 1;
    if (i < h->p30) {
        do {
            en = (struct Ent *)tab + i;
            if (en->p4 == 9) {
                unsigned cnt = en->p14 / en->p24;
                struct Ent *o = (struct Ent *)tab + en->p1c;
                func_004DA528(n, (char *)h + en->p10, cnt, o->pc, o->p14);
            }
            i++;
        } while (i < h->p30);
    }
}
