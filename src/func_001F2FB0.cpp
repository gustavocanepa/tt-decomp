/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char *func_001F2F30(char *) throw();
extern "C" int func_004A8368(const char *) throw();
extern "C" char *func_001F2FB0(char **s, int *newline) {
    char *start = func_001F2F30(*s);
    *s = start;
    int len = func_004A8368(start);
    int i;
    for (i = 0; i < len; i++) {
        if ((*s)[i] == ' ') {
            *newline = 0;
            (*s)[i] = 0;
            *s += i + 1;
            break;
        }
        if ((*s)[i] == '\n') {
            *newline = 1;
            (*s)[i] = 0;
            *s += i + 1;
            break;
        }
    }
    if (!(i < len)) *s += len;
    return start;
}
