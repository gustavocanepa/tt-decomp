/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x16];
    unsigned short n;
    char pad18[0x20];
    char *tbl;
    char pad3c[0x20];
    int unk5C;
};
struct Arg2 {
    char pad[0x14];
    int unk14;
};
extern "C" int func_00421D48(void *, void *) throw();
extern "C" void func_00421D68(void *, int, int, int) throw();

extern "C" void func_00422678(Obj *o, int idx, Arg2 *a2) {
    char buf[0x10];
    if (a2) {
        func_00421D48(buf, a2);
        int i = 0;
        int n = o->n;
        if (n) {
            int off = 0;
            int base = idx * 4 + 0x10;
            do {
                int e = off + (int)o->tbl;
                off += 0x28;
                int v = *(int *)(e + base + 0xC);
                if (v >= 0) {
                    func_00421D68(buf, o->unk5C, v, a2->unk14);
                    n = o->n;
                }
                i++;
            } while (i < n);
        }
    }
}
