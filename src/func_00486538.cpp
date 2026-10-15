/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00605B50[], D_00605B80[];
extern "C" int func_004A8368(const char *);
extern "C" int func_00486538(int a, int b) {
    int n = func_004A8368(D_00605B50);
    int i = 0;
    if (n > 0) {
        char *p = D_00605B50 + 1;
        do {
            if (p[-1] == a && p[0] == b) {
                int h = i / 2;
                int l = func_004A8368(D_00605B80);
                return h + l + 1;
            }
            i += 2;
            p += 2;
        } while (i < n);
    }
    return -1;
}
