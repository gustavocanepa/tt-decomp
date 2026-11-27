/* compiler: ee-gcc2.9-991111 */
struct RpcBuf { int result; int value; char name[0xFC]; char name2[0xFC]; };
struct Result { int result; int value; };
extern struct RpcBuf D_0078F500;
extern int D_0078F700;
extern int func_00502898(void);
extern int func_00502998(void);
extern char *func_004F8588(char *, const char *, unsigned int);
extern int func_004FE530(void *, int, unsigned int, void *, int, void *, int, void *, void *);
int func_005032D8(const char *name, const char *name2, struct Result *out, int fno) {
    if (func_00502898() < 0) return -0x10000;
    if (func_00502998() != 0) return -0x10004;
    func_004F8588(D_0078F500.name, name, 0xFC);
    D_0078F500.name[0xFB] = 0;
    func_004F8588(D_0078F500.name2, name2, 0xFC);
    D_0078F500.name2[0xFB] = 0;
    if (func_004FE530(&D_0078F700, fno, 0, &D_0078F500, 0x200, &D_0078F500, 0x10, 0, 0) < 0) return -0x10001;
    if (D_0078F500.result == 0) return -0x10003;
    out->result = D_0078F500.result;
    out->value = D_0078F500.value;
    return 0;
}
