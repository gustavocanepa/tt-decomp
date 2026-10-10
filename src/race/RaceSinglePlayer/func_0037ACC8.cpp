typedef int s32;

struct Obj {
    char pad[0xD8C];
    s32 unk6C;
};

extern "C" void func_0033CE68();
extern "C" void func_003EB120(void *arg0, s32 arg1);

extern "C" void func_0037ACC8(Obj *arg0) {
    Obj *s0 = arg0;
    func_0033CE68();
    func_003EB120((char *)s0 + 0x13A0C, s0->unk6C);
}
