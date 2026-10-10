typedef int s32;

extern void *D_005D71A8;
extern "C" void *func_00393550(void *);

struct func_003935B8_arg0 {
    char pad0[0x4];
    void *unk4;
};

struct func_003935B8_r0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *func_003935B8(struct func_003935B8_arg0 *arg0) {
    void *r0 = func_00393550(arg0);
    if (r0 != 0) {
        ((struct func_003935B8_r0 *)r0)->unk4 = &D_005D71A8;
        *(void **)(r0) = arg0->unk4;
        arg0->unk4 = r0;
    }
    return r0;
}
