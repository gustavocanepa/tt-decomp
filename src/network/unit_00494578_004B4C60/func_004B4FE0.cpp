extern "C" char *func_004B4F28(char *dst, unsigned short c, int mode);

extern "C" char *func_004B4FE0(char *dst, const unsigned short *src)
{
    char *p = dst;
    while (*src)
        p = func_004B4F28(p, *src++, 1);
    *p = 0;
    return dst;
}
