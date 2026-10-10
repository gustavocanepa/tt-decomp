extern int D_00776B90;
extern "C" int func_005038D8(void); /* lock */
extern "C" void func_00503928(void); /* unlock */
extern "C" void func_004FA740(void); /* yield */

extern "C" void func_004BB840(void) {
    int *busy = &D_00776B90;
    func_005038D8();
    while (*busy) {
        func_00503928();
        func_004FA740();
        func_005038D8();
    }
    return func_00503928();
}
