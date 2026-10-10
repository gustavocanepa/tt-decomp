typedef int s32;

extern void *D_005B5BF8;
extern "C" void *mEvent__structor_0(void *);

struct mCallbackEvent__structor_0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x18];
    void *unk20;
};

extern "C" void *mCallbackEvent__structor_0(struct mCallbackEvent__structor_0_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *r0 = mEvent__structor_0(arg0);
    arg0->unk4 = &D_005B5BF8;
    arg0->unk20 = (void *)(arg3);
    return r0;
}
