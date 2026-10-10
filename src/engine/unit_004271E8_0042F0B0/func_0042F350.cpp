extern char D_0076BDB8;

extern "C" void func_0047E588(void *a0);
extern "C" void func_0047E5C0(void *a0, int a1);

extern "C" void func_0042F350(int arg0, int arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_0047E588(&D_0076BDB8);
        }
        if (arg0 == 0) {
            func_0047E5C0(&D_0076BDB8, 2);
        }
    }
}

extern "C" void func_00330900(void) {
    func_0042F350(1, 0xFFFF);
}

extern "C" void func_00330910(void) {
    func_0042F350(0, 0xFFFF);
}
