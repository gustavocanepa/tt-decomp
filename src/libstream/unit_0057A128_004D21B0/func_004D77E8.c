/* compiler: ee-gcc2.9-991111 */
extern void *func_004D9D78(int, unsigned, int);
extern int func_004D78A8(int, int, int, int, void *, unsigned, int *);
extern void func_004D9D80(void *);
void * __attribute__((register_precision ($16, 128))) func_004D77E8(int a, int b, int c, int *error, unsigned size, int mode) {
    void *dst = func_004D9D78(mode, size, 0);
    if (dst == 0) {
        *error = 0x8105000C;
        return 0;
    }
    if (func_004D78A8(a, b, c, 0, dst, size, error) != 0) {
        func_004D9D80(dst);
        return 0;
    }
    *error = 0;
    return dst;
}
