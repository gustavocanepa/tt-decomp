typedef int s32;

struct Obj001FE288 {
    char pad[0x110];
    s32 unkE0;
};

extern "C" void func_001B2D98(struct Obj001FE288 *arg0, s32 arg1, s32 arg2);

extern "C" void func_001B2D68(struct Obj001FE288 *arg0, s32 arg1) {
    s32 v0 = arg0->unkE0;

    arg0->unkE0 = v0 + 1;
    func_001B2D98(arg0, arg1, v0 < 1);
}
