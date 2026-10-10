extern "C" int func_004A8268(const char *a, const char *b);
extern const char D_005F70F8[];
extern const char D_005F7100[];
extern const char D_005F7108[];

extern "C" int func_00379FA8(const char *s) {
    if (func_004A8268(s, D_005F70F8) == 0)
        return 0;
    if (func_004A8268(s, D_005F7100) == 0)
        return 1;
    if (func_004A8268(s, D_005F7108) == 0)
        return 2;
    return 3;
}
