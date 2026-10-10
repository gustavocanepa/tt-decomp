typedef int s32;

extern void *D_0028CA80;
extern void *D_0028CDC8;
extern void *D_0028CF48;
extern void *D_005C30C0;
extern "C" void *func_002A7618(void *);
extern "C" void *func_0022C3C0(void *);
extern "C" void *func_0028C7C8(void *, void *);
extern "C" void *func_0048BE78(s32);
extern "C" void *func_0048C9C0(void *, void *);
extern "C" void *func_0048CA40(void *, void *, void *);
extern "C" void *func_0048CA60(void *, void *);

struct mXml__structor_0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x424];
    void *unk42C;
};

extern "C" void mXml__structor_0(void *arg0) {
    func_002A7618(arg0);
    ((struct mXml__structor_0_arg0 *)arg0)->unk4 = &D_005C30C0;
    func_0022C3C0((char *)arg0 + 0x10);
    func_0028C7C8((char *)arg0 + 0x14, (char *)arg0 + 0x10);
    void *r3 = func_0048BE78(0x0);
    ((struct mXml__structor_0_arg0 *)arg0)->unk42C = r3;
    func_0048C9C0(r3, (char *)arg0 + 0x14);
    func_0048CA40(((struct mXml__structor_0_arg0 *)arg0)->unk42C, &D_0028CA80, &D_0028CDC8);
    func_0048CA60(((struct mXml__structor_0_arg0 *)arg0)->unk42C, &D_0028CF48); return;
}
