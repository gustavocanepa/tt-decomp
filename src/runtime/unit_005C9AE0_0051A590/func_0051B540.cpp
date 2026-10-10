typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_003FD808(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_0051B540(struct Obj *arg0, s32 arg1) {
    func_003FD808(arg0->unk10, arg1, 0);
}
