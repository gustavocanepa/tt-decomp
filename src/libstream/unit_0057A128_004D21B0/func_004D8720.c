/* compiler: ee-gcc2.9-991111 */
int func_004FFC00(int);
int func_00505B78(void *, int);
int func_004D8720(int unused, int a) {
    int r = func_004FFC00(a);
    if (r < 0) r = func_00505B78(0, r);
    return r;
}
