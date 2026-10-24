/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct B9 { char c[9]; };
extern B9 D_005F78D8;

extern "C" void RaceDisplayUtil__timeToString(char *buf, s32 t) {
    s32 i;
    char *p;
    if ((u32)t >= 0x157529FF) {
        *(B9 *)buf = D_005F78D8;
        return;
    }
    if (t > 0x039386FF) t = 0x039386FF;
    p = buf + 8;
    if (t > 0x5B8D7F)
        p = buf + 10;
    else if (t > 0x927BF)
        p = buf + 9;
    *p = 0;
    p--;
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
    for (i = 0; i < 3 && (i <= 0 || t != 0); i++) {
        *p-- = t % 10 + '0';
        t /= 10;
    }
}
