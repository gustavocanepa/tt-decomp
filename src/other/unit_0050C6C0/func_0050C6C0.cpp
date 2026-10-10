typedef int s32;

struct Node {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" char D_005DB6F0[];

extern "C" void func_0050C6C0(struct Node *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != 0) {
        arg0->unk0 = arg1;
        arg0->unk4 = D_005DB6F0;
        arg0->unk8 = arg2;
        arg0->unkC = arg3;
    }
}
