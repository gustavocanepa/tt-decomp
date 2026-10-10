typedef int s32;

struct Obj {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void func_0033AE38();
extern "C" void func_0038A478(void *arg0, s32 arg1);

extern "C" void func_0034A060(Obj *arg0) {
    Obj *s0 = arg0;
    func_0033AE38();
    func_0038A478((char *)s0 + 0x37DD0, s0->unk6C);
}
