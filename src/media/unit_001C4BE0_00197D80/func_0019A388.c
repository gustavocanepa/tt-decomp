extern char D_005DCFA0[];
extern const char D_005E67B0[], D_005E6868[], D_005E67D0[], D_005E6880[], D_005E67F0[], D_005E6898[], D_005E68B0[];
int func_004A8268(const char *a, const char *b);

const char *func_0019A388(void) {
    if (func_004A8268(D_005DCFA0, D_005E67B0) == 0)
        return D_005E6868;
    if (func_004A8268(D_005DCFA0, D_005E67D0) == 0)
        return D_005E6880;
    if (func_004A8268(D_005DCFA0, D_005E67F0) == 0)
        return D_005E6898;
    return D_005E68B0;
}
