/* compiler: ee-gcc2.9-991111 */
extern void func_004FD2D0(const char *, ...);
extern void func_004FDBA8(int);
extern void func_004FDD48(void);
extern int func_005035F8(const char *, int);
extern char D_00617C00[];
extern char D_00617C10[];
int func_005037C8(const char *img) {
    char buf[80];
    const char *prefix = D_00617C00;
    char *out;
    const char *p = img;
    const char *base;
    if (*p) {
        base = img - 11;
        do { p++; } while (*p);
    } else {
        base = img - 11;
    }
    if ((unsigned int)(p - base) > 80) {
        func_004FD2D0(D_00617C10, img);
        return 0;
    }
    func_004FDBA8(0);
    func_004FDD48();
    out = buf;
    while (*prefix) *out++ = *prefix++;
    while (*img) *out++ = *img++;
    *out = 0;
    return func_005035F8(buf, 0);
}
