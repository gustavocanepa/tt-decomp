/* compiler: ee-gcc2.9-991111 */
struct S {
    char p[8]; int f8; char q[0x24]; int pos; int arg;
    char r[0x14]; int (*fn)(int, int, void *, int, int);
};
extern struct S D_00782940;
int func_004D8DF0(int fd, void *unused, void *buf, int size) __attribute__((register_precision(s0, 128)));
int func_004D8DF0(int fd, void *unused, void *buf, int size) {
    struct S *p = &D_00782940;
    fd = p->fn(p->arg, p->f8, buf, p->pos, size);
    if (fd < 0) return fd;
    p->pos += fd;
    return fd;
}
