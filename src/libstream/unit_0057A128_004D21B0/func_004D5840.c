/* compiler: ee-gcc2.9-991111 */
typedef struct { char p0[0x20]; unsigned tab[1]; } Lib;
typedef struct { char p0[8]; Lib *f8; char pc[10]; unsigned short f16; unsigned *f18; } Stub;

int func_004D5840(Stub *self, Lib *lib) {
    unsigned *tab = lib->tab;
    unsigned *e = self->f18;
    int ret = 1;
    unsigned n = 0;
    if (tab[0] != 0xFFFFFFFF) {
        do {
            n++;
        } while (tab[n] != 0xFFFFFFFF);
    }
    {
        while (e[0] != 0 && (e[1] >> 26) == 9) {
            unsigned idx = (unsigned short)e[1];
            unsigned *target;
            if (idx < n && (target = (unsigned *)((idx * 4) + (unsigned)tab), *target != 0)) {
                e[0] = ((*target >> 2) & 0x03FFFFFF) | 0x08000000;
                *(volatile unsigned *)(((unsigned)e & 0x0FFFFFFF) | 0x20000000) = ((*target >> 2) & 0x03FFFFFF) | 0x08000000;
            } else {
                e[0] = 0x4D;
                ret = 0;
                *(volatile unsigned *)(((unsigned)e & 0x0FFFFFFF) | 0x20000000) = 0x4D;
            }
            e += 2;
        }
    }
    self->f8 = lib;
    self->f16 = (self->f16 & 0xFFFB) | 2;
    return ret;
}
