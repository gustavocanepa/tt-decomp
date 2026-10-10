/* compiler: ee-gcc2.9-991111 */
struct Pending {
    char pad0[0x34];
    int arg;
    int pending;
    int f3C;
    int (*fn)(int);
};

extern struct Pending D_00782940;

int func_004D8D98(void) {
    struct Pending *p = &D_00782940;
    int r;
    if (p->pending != 0) {
        p->pending = 0;
        r = p->fn(p->arg);
        if (r < 0) {
            return r;
        }
    }
    return 0;
}
