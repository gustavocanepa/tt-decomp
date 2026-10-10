/* compiler: ee-gcc2.9-991111 */
extern int func_004FE530(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize,
                         void *recv, int rsize, void *end, void *arg);
extern int func_004DEC40(const char *fmt, ...);
extern char D_00789D40[];
extern int D_00789E40[];
extern char D_00614910[];

int func_004DDDB8(int arg)
{
    D_00789E40[1] = arg;
    if (func_004FE530(D_00789D40, 0x80001304, 0, D_00789E40, 0x90, D_00789E40, 0x90, 0, 0) < 0) {
        func_004DEC40(D_00614910);
        return 0;
    }
    return D_00789E40[0];
}
