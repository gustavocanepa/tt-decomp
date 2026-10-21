/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
extern int D_005A0D90;
extern int D_005A2938;
extern int D_005A293C;
extern u8 D_0078B118[];
extern unsigned int func_004E2370(int, int, int, int, u8 *);
extern void func_004FB898(int);
extern void func_004FD2D0(const char *, ...);
extern void func_004FDAF8(void *, int);

/* sceCddaStRead */
int func_004E2118(unsigned int size, unsigned int *buf, unsigned int mode, unsigned int *err)
{
    unsigned int r, rsize, e, last_err;
    int cur;

    if (D_005A0D90 > 0)
        func_004FD2D0("sceCddaStRead call read size= %d mode= %d\n", size, mode);
    if (D_005A293C == 0)
        return 0;
    last_err = 0;
    cur = 0;
    func_004FDAF8(buf, size * D_005A2938);
    if (mode != 0) {
        do {
            r = func_004E2370(0, size - cur, (int)buf + cur * D_005A2938, 2, D_0078B118);
            rsize = r & 0xFFFF;
            e = r >> 16;
            cur += rsize;
            if (e != 0) {
                last_err = e;
                if (D_005A0D90 > 0)
                    func_004FD2D0("sceCddaStRead BLK Read cur_size= %d read_size= %d req_size= %d err 0x%x\n",
                                  cur, rsize, size, e);
            } else if (rsize == 0) {
                func_004FB898(600);
            }
        } while (cur != size && (e == 0 || rsize != 0));
        *err = last_err;
    } else {
        r = func_004E2370(0, size, (int)buf, 2, D_0078B118);
        e = r >> 16;
        cur = r & 0xFFFF;
        *err = e;
    }
    if (D_005A0D90 > 0)
        func_004FD2D0("sceCddaStRead Read Ended Read:%d err:%02x\n", cur, e);
    return cur;
}
