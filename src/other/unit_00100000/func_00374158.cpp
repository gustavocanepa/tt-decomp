typedef int s32;

struct Obj {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void func_00388498();
extern "C" void func_0038A478(void *arg0, s32 arg1);

extern "C" void func_00374158(Obj *arg0) {
    Obj *s0 = arg0;
    func_00388498();
    func_0038A478((char *)s0 + 0x37E10, s0->unk6C);
}
