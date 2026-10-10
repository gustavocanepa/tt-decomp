extern "C" void func_0047FFF0(void *);
extern "C" void func_004A5668(void *);
extern void *D_0058C5A0;
extern void *D_0058C5A4;
extern char D_0058C5B0[];

static inline void release(void **p)
{
    if (*p) {
        func_004A5668(*p);
        *p = 0;
    }
}

extern "C" void func_00480118(void)
{
    func_0047FFF0(D_0058C5B0);
    release(&D_0058C5A0);
    release(&D_0058C5A4);
}
