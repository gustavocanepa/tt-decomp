/* compiler: ee-gcc2.9-991111 */
int func_004FFD78(int, void *, int);
int func_00505B78(void *, int);
int func_004D8798(int unused, int a, void *b, int c) {
    int r = func_004FFD78(a, b, c);
    if (r < 0) r = func_00505B78(0, r);
    return r;
}
