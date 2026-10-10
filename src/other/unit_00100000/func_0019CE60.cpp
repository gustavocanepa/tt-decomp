extern "C" int func_0019BD98(int);
extern "C" void func_004F7B74(int, int);
extern "C" void func_004F7A30(int, const char *);

extern "C" int func_0019CE60(int arg0) {
    int s0 = arg0 + 0x24;
    func_004F7B74(s0, func_0019BD98(arg0));
    func_004F7A30(s0, "LSTSLIDE");
    return 1;
}
