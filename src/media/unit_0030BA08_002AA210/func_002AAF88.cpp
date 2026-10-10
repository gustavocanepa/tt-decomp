extern "C" char *func_004F7B74(char *dst, const char *src); /* strcpy */
extern "C" char *func_004F87D0(const char *s, int c);       /* strrchr */
extern const unsigned char D_00616779[];                    /* ctype table */
struct Two {
    char c[2];
};

extern const char D_005F14C8[];                             /* "." */

extern "C" void func_002AAF88(char *path, const char *src) {
    func_004F7B74(path, src);
    char *p = path;
    if ((D_00616779[(int)p[0]] & 3) && p[1] == ':')
        p += 2;
    char *slash = func_004F87D0(p, '/');
    if (slash != 0) {
        if (slash == p)
            p[1] = 0;
        else
            *slash = 0;
    } else {
        *(Two *)p = *(const Two *)D_005F14C8;
    }
}
