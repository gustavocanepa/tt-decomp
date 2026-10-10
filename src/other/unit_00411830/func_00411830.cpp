typedef int s32;

extern char D_005D9818;

struct Obj {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

extern "C" void func_00411830(Obj *arg0) {
    arg0->unk4 = -1;
    arg0->unk8 = &D_005D9818;
    arg0->unk0 = 0;
}
