/* compiler: ee-gcc2.9-991111 */
struct Ops {
    char pad[0x20];
    int (*func_005AE2E8)(int, void *, int);
    int spare;
    int (*sync)(int, int *, int *);
    int (*error)(int, int);
};
extern struct Ops D_00782940;
int __attribute__((register_precision (s0, 128))) func_004D8B68(void *unused, int fd, void *buffer, int count) {
    int r, result;
    do {
        r = D_00782940.func_005AE2E8(fd, buffer, count);
    } while (r < 0);
    D_00782940.sync(0, 0, &r);
    result = r;
    if (r < 0) { r = D_00782940.error(5, r); return r; }
    return result;
}
