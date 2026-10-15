typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Tbl {
    char pad0[4];
    s32 count;
    char pad8[4];
    u8 *codes;
    u16 *keys;
    u8 *vals;
};

struct Huff {
    s32 f0;
    char pad4[0xA70 - 4];
    Tbl *tbl;
    s32 fA74;
    void *fA78;
};

extern "C" s32 func_00459C30(void *s, s32 n, s32 *flag);

extern "C" s32 func_0045BC20(Huff *arg0) {
    s32 sp0 = 0;
    s32 bit = 1;
    s32 code = 0;
    s32 idx = 0;
    void *src = arg0->fA78;
    Tbl *t = arg0->tbl;
    u8 *cp = t->codes;
    u16 *kp = t->keys;
    if (t->count > 0) {
        do {
            s32 v = func_00459C30(src, 1, &sp0);
            if (sp0 != 0) {
                arg0->fA74 = 1;
                return v;
            }
            code |= v;
            if (*cp == bit) {
                do {
                    u16 k = *kp;
                    kp++;
                    if (k == code) {
                        return arg0->tbl->vals[idx];
                    }
                    cp++;
                    idx++;
                } while (*cp == bit);
            }
            bit += 1;
            code <<= 1;
            if (idx >= arg0->tbl->count) {
                break;
            }
        } while (bit < 0x11);
    }
    arg0->f0 = 1;
    return 0;
}
