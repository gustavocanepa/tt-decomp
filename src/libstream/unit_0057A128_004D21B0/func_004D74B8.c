/* compiler: ee-gcc2.9-991111 */
struct Module { char pad[0xa]; unsigned short flags; char pad2[0x18]; char *base; unsigned size, bss, extra; };
int func_005038D8(unsigned short);
int func_00503928(void);
void *func_004F6678(void *, int, unsigned);
int func_004D9E10(struct Module *);
void func_004D86B0(struct Module *, unsigned short);
int func_004D74B8(struct Module *m) __attribute__((register_precision (s0, 128)));
int func_004D74B8(struct Module *m) {
    unsigned short flags = m->flags;
    int state = flags & 15;
    int intr;
    if (!(flags & 16) && state != 1) return 0x81059035;
    if ((unsigned)(state - 6) >= 2 && state != 1) return 0x81059033;
    intr = func_005038D8(flags);
    if (m->flags & 64) {
        func_004F6678(m->base, 0x4d, m->size);
        func_004F6678(m->base + m->size, 0xff, m->bss + m->extra);
    }
    func_004D9E10(m);
    func_004D86B0(m, m->flags);
    if (intr) func_00503928();
    return 0;
}
