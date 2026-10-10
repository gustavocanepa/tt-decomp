struct S { char pad[0x1c]; unsigned char f[0x80]; };
int func_00443E00(struct S *s, unsigned i) {
    if (i >= 0x80) return 0;
    return s->f[i] & 1;
}
