/* compiler: ee-gcc2.9-991111 */
struct Ops { char pad[16]; int (*func_005AE2E8)(int, int, void *, unsigned); int (*seek)(int, int, int, int); };
int __attribute__((register_precision ($16, 128))) func_004D78A8(struct Ops *ops, int a, int b, int off, void *buf, unsigned size, int *error) {
    int r;
    if (off >= 0) {
        r = ops->seek(a, b, off, 0);
        if (r < 0) goto fail;
    }
    if (size != 0) {
        r = ops->func_005AE2E8(a, b, buf, size);
        if (r != size) {
            if (r >= 0) r = 0x81050005;
            goto fail;
        }
    }
    return 0;
fail:
    *error = r;
    return -1;
}
