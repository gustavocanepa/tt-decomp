/* compiler: ee-gcc2.9-991111 */
int func_004FFFB8(int, void *, int);
int func_00505B78(void *, int);
int func_004D8760(int unused, int a, void *b, int c) {
    int r = func_004FFFB8(a, b, c);
    if (r < 0) r = func_00505B78(0, r);
    return r;
}
