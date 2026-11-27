/* compiler: ee-gcc2.9-991111 */
int func_004FF970(const char *, int);
int func_00505B78(void *, int);
int func_004D86E8(int unused, const char *a, int b) {
    int r = func_004FF970(a, b);
    if (r < 0) r = func_00505B78(0, r);
    return r;
}
