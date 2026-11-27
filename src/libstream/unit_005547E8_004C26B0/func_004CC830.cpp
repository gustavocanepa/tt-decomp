/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Hook { char pad[0x18]; void (*fn)(int, int); int arg; };
extern Hook D_005983E0;
extern int D_005A07E0;
extern int D_005A07F8;
extern int D_005A07FC;
extern "C" void func_004CC930();
extern "C" void func_004CCA78();
extern "C" int func_004CCBB8();
extern "C" void func_004CD220(int);
extern "C" void func_004FA840(int);
extern "C" int func_004FA860(int);
extern "C" int func_004CC830() {
    while (func_004CCBB8() != 0) {
        int n = 0;
        func_004CC930();
        do {
            func_004CD220(n++);
            func_004FA860(D_005A07FC);
            int flag = D_005A07F8;
            if (flag == 1) {
                D_005A07F8 = 0;
                func_004FA840(D_005A07FC);
                func_004CCA78();
                return 0;
            }
            func_004FA840(D_005A07FC);
        } while (func_004CCBB8() != 0);
        if (n != 0) D_005983E0.fn(D_005983E0.arg, D_005A07E0);
    }
    func_004CCA78();
    return 0;
}
