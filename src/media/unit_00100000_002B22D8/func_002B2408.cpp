typedef int s32;

extern void *D_005C7138;
extern "C" void *func_002C0EB0(void *);

struct func_002B2408_arg0 {
    char pad0[0x4];
    void *unk4;
    void *unk8;
};

extern "C" void *func_002B2408(struct func_002B2408_arg0 *arg0, s32 arg1) {
    void *r0 = func_002C0EB0(arg0);
    arg0->unk4 = &D_005C7138;
    arg0->unk8 = (void *)(arg1);
    return r0;
}
