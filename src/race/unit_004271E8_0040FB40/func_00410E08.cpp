extern "C" char D_007695E8[];
extern "C" char D_007695F0[];
extern "C" char D_007695F8[];
extern "C" char D_005FC3E8[];
extern "C" char D_005FC788[];
extern "C" char D_005FCB58[];
extern "C" void func_004AC338(void *self, void *data);

extern "C" void func_00410E08(int init, int prio) {
    if (prio == 0xFFFF && init == 1)
        func_004AC338(D_007695E8, D_005FC3E8);
    if (prio == 0xFFFF && init == 1)
        func_004AC338(D_007695F0, D_005FC788);
    if (prio == 0xFFFF && init == 1)
        func_004AC338(D_007695F8, D_005FCB58);
}
