typedef int s32;

struct Obj {
    char pad[0xD8C];
    s32 unk6C;
};

extern "C" void func_0033D258();
extern "C" void RaceInput__setRunMode(void *arg0, s32 arg1);

extern "C" void func_0037AD00(Obj *arg0) {
    Obj *s0 = arg0;
    func_0033D258();
    RaceInput__setRunMode((char *)s0 + 0x13A0C, s0->unk6C);
}
