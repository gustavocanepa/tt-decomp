/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct B12 { char c[12]; };
extern B12 D_005F78E8;

extern "C" void func_0038F7D8(char *buf, s32 t) {
    s32 i;
    char *p;
    if ((u32)t >= 0x157529FF) {
        *(B12 *)buf = D_005F78E8;
        return;
    }
    if (t > 0x157529FF) t = 0x157529FF;
    p = t > 0x022550FF ? buf + 0xB : buf + 0xA;
    p[1] = 0;
    for (i = 0; i < 3; i++) {
        *p-- = t % 10 + '0';
        t /= 10;
    }
    p -= 4;
    p[4] = '.';
    p[3] = t % 10 + '0';
    t /= 10;
    p[2] = t % 6 + '0';
    t /= 6;
    p[1] = '\'';
    p[0] = t % 10 + '0';
    t /= 10;
    p--;
    p[0] = t % 6 + '0';
    t /= 6;
    p--;
    p[0] = ':';
    p[-1] = t % 10 + '0';
    t /= 10;
    if (t > 0) buf[0] = t + '0';
}
