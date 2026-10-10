extern "C" int func_0045F678(const char *s) {
    if (!s)
        return 0;
    int n;
    for (n = 0; *s != 0 && *s != '\n'; s++)
        n++;
    return n;
}
