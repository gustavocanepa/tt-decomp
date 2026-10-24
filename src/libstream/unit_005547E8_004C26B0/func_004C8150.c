extern void func_004C7FB8(char *, int, int, int);
void func_004C8150(char *a, int b, int c) {
    func_004C7FB8(a + 0xC0, b, c, *(int *)(a + 0x60));
    a[0x23] = 1;
}
