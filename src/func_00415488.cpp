extern "C" char *func_00415488(char *d, char *s) {
    char c;
    while ((c = *s++) != 0 && c != '#' && c != '*' && c != ',') {
        *d++ = c;
    }
    *d = 0;
    return s - 1;
}
