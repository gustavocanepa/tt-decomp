/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_002E88B0(void *, int);
extern "C" void func_002E8AB0(char *, char *);
extern "C" void func_003868E8(char *);
extern "C" void func_0036DB78(char *self) {
    char *logger = self + 0xE9E0;
    func_002E88B0(logger, 0);
    char *ghost = self + 0xE90C;
    func_002E8AB0(logger, *(char **)(self + 0xE690));
    *(int *)(ghost + 0x1D0) = 0;
    func_003868E8(self);
}
