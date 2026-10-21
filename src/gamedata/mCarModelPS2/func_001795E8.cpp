/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Sub { char pad[0x30]; void *f30; };
struct Arg { char pad[0x4C]; Sub *f4C; char pad50[0x34]; s32 f84; };
extern "C" void func_00178310(void *) throw();
extern "C" void func_001783D8(void *,void *) throw();
extern "C" s32 func_0017A258(void *);
extern "C" void func_0041D1F0(void *,void *);
extern "C" void func_0041F840(void *);
extern "C" void func_0047F670(void *);
extern "C" void free(void *) throw();
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_004FAAA0(s32);
extern "C" void func_001795E8(char *self, Arg *arg) {
    char *lock = self + 0xF4;
    void *old = 0;
    func_004A4D68(lock);
    *(s32 *)(self + 0x158) = 0;
    Sub *sub = arg->f4C;
    if (arg->f84 == 0) {
        void *p = sub->f30;
        func_0041F840(p);
        *(s32 *)(self + 0x1A8) = 0;
        func_001783D8(self + 0x1E8,self + 0x198);
        old = *(void **)(self + 0xB2C);
        *(void **)(self + 0xB2C) = p;
        func_0041D1F0(self + 0x2DC,p);
        func_004FAAA0(0);
        *(s32 *)(self + 0x1A8) = 1;
        *(s32 *)(self + 0x208) = 1;
        if (*(s32 *)(self + 0x210)) func_0017A258(self);
    } else {
        func_0047F670(sub);
    }
    func_004A4DD8(lock);
    if (old) {
        if (*(s32 *)(self + 0x16C) == 0) func_00178310(self + 0x1E8);
        free(old);
    }
}
