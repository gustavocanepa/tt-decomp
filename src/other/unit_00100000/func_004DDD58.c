/* compiler: ee-gcc2.9-991111 */
extern char D_00789D40[];       /* SifRpcClientData_t */
extern unsigned int D_00789E40[]; /* rpc buffer */
extern int func_004FE530(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize,
                         void *recv, int rsize, void *end_func, void *end_param); /* sceSifCallRpc */

unsigned int func_004DDD58(void) {
    unsigned int *buf = D_00789E40;
    if (func_004FE530(D_00789D40, 0x80001305, 0, buf, 0x90, buf, 0x90, 0, 0) < 0)
        return 0;
    return buf[1];
}
