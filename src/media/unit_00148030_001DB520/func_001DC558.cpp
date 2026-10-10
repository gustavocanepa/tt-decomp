typedef int s32;

struct Obj {
    char pad[0x68];
    s32 unk68;
};

extern "C" void func_001DC258(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_001DC558(Obj *arg0, s32 arg1) {
    func_001DC258(arg0, arg1, arg1);
}
