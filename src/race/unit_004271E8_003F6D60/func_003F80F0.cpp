extern "C" int func_004A8268(const char *a, const char *b);

extern "C" int func_003F80F0(const char *name, const char **list, int count) {
    for (int i = 0; i < count; i++) {
        if (func_004A8268(name, list[i]) == 0)
            return i;
    }
    return -1;
}
