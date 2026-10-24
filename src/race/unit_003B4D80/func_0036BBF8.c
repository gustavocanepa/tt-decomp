struct R { char pad[0x119c]; int v[1]; };
extern void func_00370958(int *, char *, int);
void func_0036BBF8(char *p, int i, int x) {
    int *a = (int *)(p + 0x1264);
    int *e;
    e = a + i;
    *e = x;
    func_00370958(a, p + 0x1220, i);
}
