extern "C" int func_004DBAF8(int port, void *a, void *b);
extern "C" void func_004A59F0(void);

extern "C" void func_004CBA28(void *a, void *b) {
    while (func_004DBAF8(0, a, b) != 1)
        func_004A59F0();
}
