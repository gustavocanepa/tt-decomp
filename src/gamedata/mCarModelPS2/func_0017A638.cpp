typedef int s32;

struct Obj {
    char pad[0xB24];
    s32 unk89C;
};

struct Target;

extern "C" void func_0041CF28(Target *arg0, s32 arg1, s32 arg2);

extern "C" void func_0017A638(Obj *arg0, s32 arg1) {
    s32 t = arg0->unk89C;
    func_0041CF28((Target *)((char *)arg0 + 0x2DC), arg1, t);
}
