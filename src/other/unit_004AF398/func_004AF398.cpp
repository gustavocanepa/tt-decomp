typedef int s32;

extern "C" void func_004A56C8(s32 arg0, void *arg1, s32 arg2);

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_004AF398(s32 arg0, s32 arg1) {
    Pair local;
    local.a = 0;
    local.b = 0;
    func_004A56C8(arg0, &local, arg1);
}
