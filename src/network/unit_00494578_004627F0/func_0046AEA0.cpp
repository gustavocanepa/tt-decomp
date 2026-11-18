/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0046AC48(void *) throw();
extern "C" void func_0046BCC8(void *);
extern int D_00587144, D_00587148, D_0058714C, D_00587150;
extern char *D_0076E748, *D_0076E74C, *D_0076E750, *D_0076E754;
extern "C" void func_0046AEA0(int arg0) {
    int a = arg0 & 0x1ff;
    int b = (arg0 >> 9) & 0x7f;
    if (a == 0x1ff) a += D_0058714C;
    if (a != 0 && a != D_00587144) {
        if (a >= 0x1ff) {
            char *p = D_0076E750;
            if (p) func_0046AC48(p + D_0058714C * 40);
        } else {
            char *p = D_0076E748;
            if (p) func_0046AC48(p + a * 40 - 40);
        }
        D_00587144 = a;
    }
    if (b == 0x1ff) b += D_00587150;
    if (b != 0 && b != D_00587148) {
        if (b >= 0x7f) {
            char *p = D_0076E754;
            if (p) func_0046BCC8(p + D_00587150 * 80);
        } else {
            char *p = D_0076E74C;
            if (p) func_0046BCC8(p + b * 80 - 80);
        }
        D_00587148 = b;
    }
}
