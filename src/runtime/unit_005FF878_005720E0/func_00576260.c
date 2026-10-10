struct S { char pad[0x1c]; unsigned w; };
void func_00576260(struct S *s, int x) {
    (void)*(volatile unsigned short *)&s->w;
    s->w = x & 0xFFFF;
}
