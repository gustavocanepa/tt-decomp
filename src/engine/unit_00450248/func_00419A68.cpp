struct Obj {
    char pad[0xC];
    int unkC;
    int unk10;
};

extern "C" void func_00419A68(Obj *arg0) {
    arg0->unkC = 0;
    arg0->unk10 = 0;
}
