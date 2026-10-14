typedef int s32;

struct Node {
    char pad[0xC];
    struct Node *unkC;
};

extern "C" s32 D_0057B8C8;

extern "C" s32 func_0053DD58(struct Node *arg0) {
    if (arg0 != 0) {
        arg0->unkC = (struct Node *)D_0057B8C8;
        D_0057B8C8 = (s32)arg0;
    }
    return D_0057B8C8;
}
