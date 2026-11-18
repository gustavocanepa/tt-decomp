struct N9 { char c[9]; };
struct R {
    unsigned time;
    unsigned short m4;
    unsigned char m6;
    unsigned char m7;
    unsigned char m8;
    N9 name;
};
extern "C" {
extern N9 D_005F9E60;
void func_003F8FB8(R *r) {
    const N9 *src = &D_005F9E60;
    r->time = 0x157529FF;
    r->m8 = 0xF;
    r->m4 = 0;
    do { r->m6 = 0; } while (0);
    r->m7 = 0;
    r->name = *src;
}
}
