/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
struct Blk { int n0, n4, d8, dC; u8 s10[0x40], s50[0x40]; };
extern char D_005A0DE0[];
extern void func_004DECD0(void *);
void func_004DEEE0(int address) {
    struct Blk *b = (struct Blk *)(address | 0x20000000);
    int i;
    if (b->n0 > 0) {
        int dst = b->d8;
        int uncached = dst | 0x20000000;
        for (i = 0; i < b->n0; i++) {
            int src = (int)(b->s10);
            u8 v = *(u8 *)(src + i);
            *(u8 *)(uncached + i) = v;
            *(u8 *)(dst + i) = v;
        }
    }
    if (b->n4 > 0) {
        int dst = b->dC;
        int uncached = dst | 0x20000000;
        for (i = 0; i < b->n4; i++) {
            int src = (int)(b->s50);
            u8 v = *(u8 *)(src + i);
            *(u8 *)(uncached + i) = v;
            *(u8 *)(dst + i) = v;
        }
    }
    func_004DECD0(D_005A0DE0);
}
