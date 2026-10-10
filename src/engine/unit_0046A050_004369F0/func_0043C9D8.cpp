struct Obj {
    char pad0[0x38];
    int unk38;
    int unk3C;
};

extern "C" void func_0043C9D8(Obj *arg0, int arg1, int arg2) {
    arg0->unk38 = arg1;
    arg0->unk3C = arg2;
}
