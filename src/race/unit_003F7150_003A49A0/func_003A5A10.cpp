struct Race { char pad[0x24116]; short count; };
unsigned char func_003A59F0(Race *);
short func_003A5A10(Race *r)
{
    int n = func_003A59F0(r);
    int v;
    if (n == 0)
        return 0;
    v = r->count;
    if (v < n * 60) {
        int w = v + 1;
        r->count = w;
        v = w;
    }
    return v;
}
