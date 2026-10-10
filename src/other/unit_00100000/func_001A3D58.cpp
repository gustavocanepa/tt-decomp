extern "C" int func_001A3D58(short *p, short *end)
{
    short *start = p;
    short v = *p++;
    while (*p == v && p < end)
        p++;
    return p - start;
}
