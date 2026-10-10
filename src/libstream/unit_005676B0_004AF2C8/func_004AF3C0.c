struct Z { int x, y; };
extern void func_004A56C8(struct Z *, int, int);
void func_004AF3C0(int a, int b) {
    struct Z z;
    z.x = 0; z.y = 0;
    func_004A56C8(&z, a, b);
}
