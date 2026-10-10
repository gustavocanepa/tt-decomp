extern int D_00579318;
extern "C" void func_00109768(int);
extern "C" void func_004A58A0(int);

extern "C" void func_001099E0(int ms) {
    if (D_00579318 != 0) {
        func_00109768(D_00579318);
        if (ms != 0)
            func_004A58A0(ms * 1000);
    }
}
