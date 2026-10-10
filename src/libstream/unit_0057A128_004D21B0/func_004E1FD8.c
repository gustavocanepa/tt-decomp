/* compiler: ee-gcc2.9-991111 */
typedef struct {
    unsigned char trycount;
    unsigned char spindlctrl;
    unsigned char datapattern;
    unsigned char pad;
} ReadMode;

extern int D_005A293C;
extern int D_005A2938;
extern ReadMode D_0078B118;

int func_004E2370(unsigned int lsn, unsigned int sectors, void *buf, int cmd, ReadMode *mode);

int func_004E1FD8(unsigned int lsn, unsigned int sectors, void *buf, int pattern)
{
    D_005A293C = 0;
    D_0078B118.datapattern = pattern;
    switch (pattern) {
    case 0:
        D_005A2938 = 0x930;
        break;
    case 1:
        D_005A2938 = 0x940;
        break;
    case 2:
        D_005A2938 = 0x990;
        break;
    default:
        D_005A2938 = 0x930;
        break;
    }
    return func_004E2370(lsn, sectors, buf, 5, &D_0078B118);
}
