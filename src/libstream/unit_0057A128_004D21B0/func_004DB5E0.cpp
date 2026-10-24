/* compiler: ee-gcc2.9-991111 */
extern int D_005A0BF0;
extern "C" int func_004DB4B8(void *, void *, void *, int);
extern "C" int func_004DB5E0(void *a, void *b, void *c) {
    int r = func_004DB4B8(a, b, c, 0x40);
    if (r == 0) D_005A0BF0 = 0xB;
    return r;
}
