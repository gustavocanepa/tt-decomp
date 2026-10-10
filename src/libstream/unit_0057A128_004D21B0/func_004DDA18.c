/* compiler: ee-gcc2.9-991111 */
extern char D_00789D40[];
extern int D_00789E40[];

int func_004FE530(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

int func_004DDA18(void) {
    func_004FE530(D_00789D40, 0x80001363, 0, D_00789E40, 0x90, D_00789E40, 0x90, 0, 0);
    return D_00789E40[0];
}
