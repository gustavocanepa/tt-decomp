typedef int s32;

extern void *D_005C7BB8;
extern "C" void *func_0029BCC0(void *);

struct func_002C2540_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x4];
    void *unkC;
};

extern "C" void *func_002C2540(struct func_002C2540_arg0 *arg0, s32 arg1, s32 arg2) {
    void *r0 = func_0029BCC0(arg0);
    arg0->unk4 = &D_005C7BB8;
    arg0->unkC = (void *)(arg2);
    return r0;
}
