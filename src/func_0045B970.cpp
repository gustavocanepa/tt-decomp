/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Src {
    s32 f0;
    s32 f4;
    s32 f8;
    char pad[0x14];
    s32 f20;
};
struct Comp { void *dc; void *ac; };
struct Sub { char pad[0x430]; Comp comp[1]; };
struct Dec {
    s32 f0;
    char pad4[0xA6C];
    void *tbl;
    s32 err;
    Src *src;
};

extern "C" s32 func_00459C30(Src *, s32, s32 *) throw();
extern "C" s32 func_0045BC20(Dec *);
extern "C" s32 func_0045BD40(Dec *);
extern s32 D_0060271C[];

extern "C" s32 func_0045B970(Dec *arg0, s32 arg1) {
    s32 dc = 0;
    Sub *ps = (Sub *)((char *)arg0 + 0x14);
    arg0->err = 0;
    Src *src = arg0->src;
    arg0->tbl = ps->comp[arg1].dc;
    s32 n = func_0045BC20(arg0);
    if (arg0->err != 0) return 2;
    if (n > 0) {
        dc = func_00459C30(src, n, &arg0->err);
        if (arg0->err != 0) return 2;
        if (((dc >> (n - 1)) & 1) == 0) dc = dc - (1 << n) + 1;
    }
    s32 a2 = arg1 << 8;
    char *pb = (char *)arg0 + 0xC;
    *(s32 *)(a2 + (s32)pb + 0x750) = *(s32 *)(pb + arg1 * 4 + 0xA50) + dc;
    if (arg0->f0 != 0) return -1;
    if (src->f20 != 0) return -2;
    s32 *zz = D_0060271C;
    arg0->tbl = ps->comp[arg1].ac;
    ps = (Sub *)((char *)arg0 + a2 + 0x75C);
    s32 k = 1;
    do {
        if (src->f4 - src->f8 >= 0x41) n = func_0045BD40(arg0);
        else n = func_0045BC20(arg0);
        if (arg0->err != 0) return 2;
        s32 r = n >> 4;
        if (n == 0) {
            while (k < 0x40) {
                ((s32 *)ps)[*zz++] = 0;
                k++;
            }
            if (arg0->f0 != 0) return -1;
            return src->f20 != 0 ? -2 : 1;
        }
        n = n & 0xF;
        s32 val = 0;
        s32 end;
        if (n > 0) {
            val = func_00459C30(src, n, &arg0->err);
            if (arg0->err != 0) return 2;
            if (((val >> (n - 1)) & 1) == 0) val = val - (1 << n) + 1;
        } else if (r != 15) {
            return -1;
        }
        end = r + k;
        if (end >= 0x40) return -1;
        while (r-- > 0) {
            ((s32 *)ps)[*zz++] = 0;
            k++;
        }
        ((s32 *)ps)[*zz++] = val;
        k++;
    } while (k < 0x40);
    return src->f20 != 0 ? -2 : 1;
}
