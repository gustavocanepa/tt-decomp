typedef int s32;

struct Obj {
    char pad[0xE4C8];
    s32 unkE408;
};

extern "C" void func_0033E130(struct Obj *arg0, s32 arg1);

extern "C" void func_00554738(struct Obj *arg0) {
    func_0033E130(arg0, arg0->unkE408);
}
