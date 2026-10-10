extern unsigned char D_005834C5;
struct S { char pad[0x1b8]; unsigned char b; };
int func_0039EEF8(struct S *t) {
    unsigned char x = t->b;
    if (D_005834C5) x &= 0x3F;
    return x == 0;
}
