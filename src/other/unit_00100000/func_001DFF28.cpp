typedef int s32;

struct Target {
    char pad[0x10];
    s32 id;
};

struct Handle {
    Target *p;
    s32 pad[3];
};

extern "C" Handle *func_001DF250(Handle *);
extern "C" void func_001DF1F8(Handle *, s32);
extern "C" s32 func_0024EA40(void);
extern "C" void func_001FEE48(s32, s32);

extern "C" void func_001DFF28(void) {
    Handle h;
    func_001DF250(&h);
    s32 id = h.p->id;
    func_001FEE48(id, func_0024EA40());
    func_001DF1F8(&h, 2);
}
