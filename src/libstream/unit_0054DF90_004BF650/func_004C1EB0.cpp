extern "C" char *func_004C1EB0(char *s) {
    char *p = s + 0x1c0;
    s += 0x100;
    int i = 0;
    do {
        if (*(int *)(p + 8) == 0) {
            *(int *)(p + 8) = 1;
            return s;
        }
        ++i;
        s += 0x100;
        p += 0x100;
    } while (i < 32);
    return 0;
}
