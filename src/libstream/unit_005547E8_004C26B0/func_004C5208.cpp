typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Self { char pad[0x58]; u8 *p; };

extern "C" s64 func_004C5208(Self *s) {
    s64 v = 0;
    do {
        v = (v << 7) + (*s->p & 0x7F);
    } while (*s->p++ & 0x80);
    return v;
}
