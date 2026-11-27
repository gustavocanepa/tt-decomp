/* compiler: ee-gcc2.96-as2004 */
typedef unsigned char u8;
struct Ent { char pad[0x1BE]; u8 status; u8 chs[3]; u8 type; u8 chs2[3]; unsigned lba; } __attribute__((packed));
struct O { Ent *buf; int f4; };
extern "C" unsigned func_00486E98(O *o) {
    Ent *e;
    int i;
    if (o->f4 == 0) return 0;
    e = o->buf;
    i = 0;
    do {
        unsigned lba = e->lba;
        if ((e->status & 0x7F) == 0 && lba != 0) {
            u8 t = e->type;
            if (t == 1 || t == 4 || t == 6 || t == 11 || t == 12 || t == 14) return lba;
        }
        i++;
        e = (Ent *)((char *)e + 0x10);
    } while (i < 4);
    return 0;
}
