typedef int s32;

extern "C" void func_00445598(s32 arg0, void *arg1);

struct func_0043AFA8_pair {
    s32 a;
    s32 b;
};

struct func_0043AFA8_src {
    char pad0[0x10];
    struct func_0043AFA8_pair p;
};

struct func_0043AFA8_loc {
    s32 z0;
    s32 z1;
    struct func_0043AFA8_pair p;
};

extern "C" void func_0043AFA8(void *arg0, s32 arg1) {
    struct func_0043AFA8_loc loc;
    struct func_0043AFA8_src *src = (struct func_0043AFA8_src *)arg0;

    loc.z0 = 0;
    loc.z1 = 0;
    loc.p = src->p;
    func_00445598(arg1, &loc);
}
