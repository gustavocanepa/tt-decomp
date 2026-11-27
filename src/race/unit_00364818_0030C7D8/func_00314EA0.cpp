/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
struct C { char pad[0x242]; u8 f236; };
struct B { char pad[0x483 - 0]; s8 f463; };
struct O { char pad[0x10]; C *f10; };
extern "C" int func_00314EA0(O *o) {
    char *b = (char *)o + 0x104;
    C *c = o->f10;
    int v = *(u8 *)(b + 0x546);
    int a = *(u8 *)(b + 0x540);
    if (v != 0) {
        int nv = v + 0xFF;
        *(u8 *)(b + 0x546) = nv;
        u8 low = nv;
        if (low == 0 && *(s8 *)(b + 0x483) != 0) {
            *(u8 *)(b + 0x546) = 1;
        }
    } else {
        if (*(s8 *)(b + 0x483) > 0 && a < c->f236) {
            *(u8 *)(b + 0x546) = 1;
            return a + 1;
        }
        if ((s8)*(u8 *)(b + 0x483) < 0 && a > 0) {
            *(u8 *)(b + 0x546) = 1;
            return a - 1;
        }
    }
    return -1;
}
