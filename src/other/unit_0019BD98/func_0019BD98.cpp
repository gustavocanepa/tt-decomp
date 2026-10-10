extern char D_00579F18[];
extern char D_005DCF78[];
extern char D_005DCF90[];
extern "C" char *func_004F7B74(char *, const char *);
extern "C" char *func_004F7A30(char *, const char *);

extern "C" char *func_0019BD98(void) {
    char *buf = D_00579F18;
    if (buf[0] == 0) {
        func_004F7B74(buf, D_005DCF78);
        func_004F7A30(buf, D_005DCF90);
    }
    return buf;
}
