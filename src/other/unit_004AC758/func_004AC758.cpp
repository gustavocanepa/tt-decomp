typedef int s32;

struct S {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

extern char D_005DADE0;

void func_004AC758(struct S *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk8 = &D_005DADE0;
}
