struct S { char p[0x157]; unsigned char f157; unsigned char f158; unsigned char f159; unsigned char f15A; };
extern "C" unsigned char func_0040CDE8(S *s, int a, int b, int c, int d);
extern "C" void func_0039EE90(unsigned char *);
extern "C" void func_0039EEA0(unsigned char *);

extern "C" void func_0040A968(S *s, unsigned char *o, unsigned char *r) {
    int a = s->f157;
    o[0x1BA] = func_0040CDE8(s, r[5], r[6], r[4], a ? a : 1);
    o[0x1BB] = r[8];
    o[0x1BC] = func_0040CDE8(s, r[0xB], r[0xC], r[0xA], s->f158);
    int b = s->f159;
    o[0x1BD] = func_0040CDE8(s, r[0x10], r[0x11], r[0xF], b ? b : 1);
    o[0x1BE] = r[0x13];
    o[0x1BF] = func_0040CDE8(s, r[0x16], r[0x17], r[0x15], s->f15A);
    int t = (r[3] & 3) | ((r[9] & 3) << 2);
    t |= (r[0xE] & 3) << 4;
    t |= (r[0x14] & 3) << 6;
    o[0x1B8] = t;
    if (s->f157 == 0) func_0039EE90(o);
    if (s->f159 == 0) func_0039EEA0(o);
}
