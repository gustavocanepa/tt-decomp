extern "C" char *func_004A8290(const char *s, int c); /* strchr */
extern "C" const char *D_00579F10;

extern "C" int func_0019B130(char c)
{
    if (c == 0)
        return -1;
    const char *p = func_004A8290(D_00579F10, c);
    if (p == 0)
        return -1;
    return p - D_00579F10;
}
