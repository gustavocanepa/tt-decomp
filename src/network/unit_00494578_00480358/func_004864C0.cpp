extern "C" int func_004A8368(const char *s);
extern const char D_00605B80[];

extern "C" int func_004864C0(int c) {
    int n = func_004A8368(D_00605B80);
    for (int i = 0; i < n; i++) {
        if (D_00605B80[i] == c)
            return i + 1;
    }
    return -1;
}
