struct Obj {
    char pad0[4];
    int unk4;
    int unk8;
};

extern "C" void func_001783C8(Obj *arg0) {
    arg0->unk8 = 0;
    arg0->unk4 = 0;
}
