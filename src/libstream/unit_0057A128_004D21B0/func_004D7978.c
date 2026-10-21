/* compiler: ee-gcc2.9-991111 */
extern void *func_004D9D78(int, unsigned, int);
extern int func_004D9A50(void *, unsigned, void *, int *);
extern void func_004D9D80(void *);
void * __attribute__((register_precision ($16, 128))) func_004D7978(unsigned char *src, int size, int *error, int mode) {
    int end = size + (int)src;
    unsigned expanded;
    unsigned outer;
    void *dst;
    *error = 0x8105902C;
    outer = (*(unsigned char *)(end - 1) << 24) | *(unsigned char *)(end - 4);
    expanded = outer | ((*(unsigned char *)(end - 3) << 8) | (*(unsigned char *)(end - 2) << 16));
    dst = func_004D9D78(mode, expanded, 0);
    if (dst == 0) {
        *error = 0x8105000C;
        return 0;
    }
    if (func_004D9A50(dst, expanded, src, 0) < 0) {
        func_004D9D80(dst);
        return 0;
    }
    *error = 0;
    return dst;
}
