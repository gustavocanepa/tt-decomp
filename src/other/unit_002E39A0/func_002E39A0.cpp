typedef int s32;

extern char D_002E3948;

struct Pair {
    s32 a;
    s32 b;
};

extern "C" void func_0043ACE0(s32 arg0, Pair *arg1);

extern "C" void func_002E39A0(s32 arg0) {
    if (arg0 != 0) {
        Pair local;
        local.b = 0;
        local.a = (s32)&D_002E3948;
        func_0043ACE0(arg0, &local);
    }
}
