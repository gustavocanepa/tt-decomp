/* compiler: ee-gcc2.9-991111 */
struct RpcBuf {
    int result;
    int pad;
    char name[0x100];
};

extern struct RpcBuf D_0078F500;
extern int D_0078F700;

extern int func_00502898(void);
extern int func_00502998(void);
extern char *func_004F8588(char *dst, const char *src, unsigned int n);
extern int func_004FE530(void *cd, int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);

int func_00502F00(const char *name)
{
    if (func_00502898() < 0) {
        return -0x10000;
    }
    if (func_00502998() != 0) {
        return -0x10004;
    }
    func_004F8588(D_0078F500.name, name, 0xFC);
    D_0078F500.name[0xFB] = 0;
    if (func_004FE530(&D_0078F700, 9, 0, &D_0078F500, 0x200, &D_0078F500, 4, 0, 0) < 0) {
        return -0x10001;
    }
    return D_0078F500.result;
}
