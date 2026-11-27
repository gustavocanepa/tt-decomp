/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Sub {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
};
struct Arg1 {
    char pad0[0x4C];
    Sub *unk4C;
    char pad50[0x84 - 0x50];
    s32 unk84;
};
extern "C" s32 func_0017A258(void *);
extern "C" void *func_0041A538(void *, s32, s32);
extern "C" void func_0041F840(void *);
extern "C" void func_0047F670(void *);
extern "C" void free(s32) throw();
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void *func_004F64C4(void *, void *, s32);
extern "C" void func_004FAAA0(s32);

extern "C" void func_001796D8(char *arg0, Arg1 *arg1, u32 arg2) {
    char *s5 = arg0 + 0xF4;
    func_004A4D68(s5);
    *(s32 *)(arg0 + 0x158) = 0;
    Sub *sub = arg1->unk4C;
    if (arg1->unk84 == 0) {
        s32 n = sub->unk34;
        s32 p = sub->unk30;
        void *o = func_0041A538(arg0 + 0x2DC, arg2 == 0, n);
        func_004F64C4(o, (void *)p, n);
        free(p);
        func_0041F840(o);
        func_004FAAA0(0);
        *(s32 *)(arg0 + arg2 * 4 + 0x1FC) = 1;
        if (*(s32 *)(arg0 + 0x210) != 0) {
            func_0017A258(arg0);
        }
    } else {
        func_0047F670(sub);
    }
    func_004A4DD8(s5);
}
