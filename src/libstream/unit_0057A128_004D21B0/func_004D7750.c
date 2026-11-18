/* compiler: ee-gcc2.9-991111 */
struct Ops {
    int (*func_005AE360)(int, const char *, int);
    int (*other[5])(void);
    int (*size)(int, int);
};
int func_004FFC00(int);
int func_004D7750(struct Ops *ops, int dev, const char *name, int *out) __attribute__((register_precision (s0, 128)));
int func_004D7750(struct Ops *ops, int dev, const char *name, int *out) {
    int fd = ops->func_005AE360(dev, name, 1);
    if (fd < 0) return fd;
    {
        int size = ops->size(dev, fd);
        if (size <= 0) {
            func_004FFC00(fd);
            return size ? size : 0x8105902c;
        }
        *out = size;
    }
    return fd;
}
