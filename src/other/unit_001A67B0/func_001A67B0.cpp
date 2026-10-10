typedef int s32;

struct Obj {
    char pad[0x54];
    s32 unk54;
};

extern "C" void func_0050E890(void);

extern "C" void func_001A67B0(Obj *arg0) {
    if (arg0->unk54 != 0) {
        func_0050E890();
        arg0->unk54 = 0;
    }
}
