extern "C" int func_004E5700(const char *a, const char *b, unsigned int n);
extern const char D_005F39D0[];

extern "C" int func_0033CB60(const char *s)
{
    int r = 0;
    if (func_004E5700(s, D_005F39D0, 2) != 0) {
        return 0;
    }
    switch (s[2]) {
    case '4':
        r = 0x10;
        break;
    case '1':
        r = 0x11;
        break;
    case 'm':
        r = 0x12;
        break;
    }
    return r;
}
