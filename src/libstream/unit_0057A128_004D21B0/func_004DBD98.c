/* compiler: ee-gcc2.9-991111 */
extern char D_00782AC0[]; /* client data */
extern char D_00782B40[]; /* send buffer */
extern int D_00784080[];  /* receive buffer */
extern char D_006147D8[];
extern void func_004DB328(void *arg);
extern int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize,
                         void (*end)(void *), void *arg); /* sceSifCallRpc */
extern int func_004FD2D0(const char *fmt, ...);        /* printf */

int func_004DBD98(void)
{
    if (func_004FE530(D_00782AC0, 0x35, 0, D_00782B40, 0x30, D_00784080, 4, func_004DB328, 0) != 0) {
        func_004FD2D0(D_006147D8);
        return -0x5B;
    }
    return D_00784080[0];
}
