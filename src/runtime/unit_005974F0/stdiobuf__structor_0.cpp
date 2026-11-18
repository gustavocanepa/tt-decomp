/* compiler: ee-gcc2.96-no-strict-aliasing */
struct IOFile {
    int flags;
    void *fields[12];
    IOFile *chain;
    int fd;
    char rest[0x14];
} __attribute__((aligned(8)));
struct Fake {
    struct { IOFile file; void *vt; } s;
    void *stdio_file;
};
struct Reent { int x; void *in; void *out; void *err; };
extern Reent *D_005A30A8;
extern IOFile D_005A2B30;
extern Fake D_005A2B88, D_005A2BE8, D_005A2C48;
extern char D_005DB608[];
extern "C" void *func_004F6678(void *, int, unsigned);
extern "C" void stdiobuf__structor_0(int init, int prio) {
    Fake a, b, c;
    if (prio == 65535 && init == 1) {
        Fake *dest = &D_005A2B88;
        func_004F6678(&a.s.file, 0, 0x50);
        a.s.file.flags = (int)0xFBAD208A;
        a.s.file.chain = &D_005A2B30;
        a.s.vt = D_005DB608;
        a.stdio_file = D_005A30A8->in;
        *dest = a;
    }
    if (prio == 65535 && init == 1) {
        Fake *dest = &D_005A2BE8;
        func_004F6678(&b.s.file, 0, 0x50);
        b.s.file.flags = (int)0xFBAD2086;
        b.s.file.chain = &D_005A2B88.s.file;
        b.s.file.fd = 1;
        b.s.vt = D_005DB608;
        b.stdio_file = D_005A30A8->out;
        *dest = b;
    }
    if (prio == 65535 && init == 1) {
        Fake *dest = &D_005A2C48;
        func_004F6678(&c.s.file, 0, 0x50);
        c.s.file.flags = (int)0xFBAD2086;
        c.s.file.chain = &D_005A2BE8.s.file;
        c.s.file.fd = 2;
        c.s.vt = D_005DB608;
        c.stdio_file = D_005A30A8->err;
        *dest = c;
    }
}
