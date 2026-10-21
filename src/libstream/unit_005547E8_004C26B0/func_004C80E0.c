extern void func_004C7FB8(char *, int, int, int);
void func_004C80E0(char *a, int b, int c) {
    func_004C7FB8(a + 0xA0, b, c, *(int *)(a + 0x70));
    a[0x21] = 1;
}
